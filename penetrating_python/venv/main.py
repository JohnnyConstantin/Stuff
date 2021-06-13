from ctypes import *

libc = CDLL("libc.dylib")
message_string = b"Im here!"
libc.printf(b"Fuck me: %s", message_string)

seitz = c_char_p(b"loves python")# Pointer to byte array

print(seitz.value) # dereferrencing a pointer so getting a contained string

class beer_recipe(Structure):
    _fields_ = [
        ("amt_barley", c_int),
        ("amt_water", c_int)
    ]

class barley_amount(Union):
    _fields_ = [
        ("barley_long", c_long),
        ("barley_int", c_int),
        ("barley_char", c_char * 8)
    ]

value = input("Enter the amount of barley to put into the beer vat:")
my_barley = barley_amount(int(value))
print("Barley amount as a long: %ld" % my_barley.barley_long)
print("Barley amount as an int: %d" % my_barley.barley_int)
print("Barley amount as a char: %s" % my_barley.barley_char)