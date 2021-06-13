from ctypes import *

libc = CDLL("libc.dylib")
message_string = b"Im here!"
libc.printf(b"Fuck me: %s", message_string)

seitz = c_char_p(b"loves python")# Pointer to byte array

print(seitz.value) # dereferrencing a pointer so getting a contained string

