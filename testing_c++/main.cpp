#include <cstdio>
#include <cstdlib>
#include <mach-o/loader.h>
#include <mach-o/swap.h>

void dump_segments(FILE *obj_file);
uint32_t get_magic(FILE *obj_file, int offset);
int should_swap_bytes(uint32_t magic);


int main(int argc, char *argv[]) {
    const char *filename = argv[1];
    FILE *obj_file = fopen(filename, "rb");
    dump_segments(obj_file);
    fclose(obj_file);

    return 0;
}

int is_magic_64(uint32_t magic) {
    return magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
}

int should_swap_bytes(uint32_t magic) {
    return magic == MH_CIGAM || magic == MH_CIGAM_64;
}

uint32_t get_magic(FILE *obj_file, int offset){
    uint32_t magic;
    fseek(obj_file, offset, SEEK_SET);
    fread(&magic, sizeof(uint32_t), 1, obj_file);
    return magic;
}

void *load_bytes(FILE *obj_file, int offset, int size) {
    void *buf = calloc(1, size);
    fseek(obj_file, offset, SEEK_SET);
    fread(buf, size, 1, obj_file);
    return buf;
}

void dump_segment_commands(FILE *obj_file, int offset, int is_swap, uint32_t ncmds) {
    int actual_offset = offset;
    for (int  i = 0; i < ncmds; i++) {
        struct load_command *cmd = static_cast<load_command *>(load_bytes(obj_file, actual_offset,
                                                                          sizeof(struct load_command)));
        if (is_swap) {
            swap_load_command(cmd, static_cast<NXByteOrder>(0));
        }

        if (cmd->cmd == LC_SEGMENT_64) {
            struct segment_command_64 *segment = static_cast<segment_command_64 *>(load_bytes(obj_file, actual_offset,
                                                                                              sizeof(struct segment_command_64)));
            if (is_swap) {
                swap_segment_command_64(segment, static_cast<NXByteOrder>(0));
            }

            printf("segname: %s\n", segment->segname);

            free(segment);
        } else if (cmd->cmd == LC_SEGMENT) {
            struct segment_command *segment = static_cast<segment_command *>(load_bytes(obj_file, actual_offset,
                                                                                        sizeof(struct segment_command)));
            if (is_swap) {
                swap_segment_command(segment, static_cast<NXByteOrder>(0));
            }

            printf("segname: %s\n", segment->segname);

            free(segment);
        }

        actual_offset += cmd->cmdsize;

        free(cmd);
    }
}

void dump_mach_header(FILE *obj_file, int offset, int is_64, int is_swap) {
    uint32_t ncmds;
    int load_commands_offset = offset;

    if (is_64) {
        int header_size = sizeof(struct mach_header_64);
        struct mach_header_64 *header = static_cast<mach_header_64 *>(load_bytes(obj_file, offset, header_size));
        if (is_swap) {
            swap_mach_header_64(header, static_cast<NXByteOrder>(0));
        }
        ncmds = header->ncmds;
        load_commands_offset += header_size;

        free(header);
    } else {
        int header_size = sizeof(struct mach_header);
        struct mach_header *header = static_cast<mach_header *>(load_bytes(obj_file, offset, header_size));
        if (is_swap) {
            swap_mach_header(header, static_cast<NXByteOrder>(0));
        }

        ncmds = header->ncmds;
        load_commands_offset += header_size;

        free(header);
    }

    dump_segment_commands(obj_file, load_commands_offset, is_swap, ncmds);
}

void dump_segments(FILE *obj_file) {
    uint32_t magic = get_magic(obj_file, 0);
    bool is_64 = is_magic_64(magic);
    int is_swap = should_swap_bytes(magic);
    dump_mach_header(obj_file, 0, is_64, is_swap);
}