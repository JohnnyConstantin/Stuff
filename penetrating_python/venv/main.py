from ctypes import *

libc = CDLL("libc.dylib")
message_string = b"Im here!"
libc.printf(b"Fuck me: %s", message_string)

