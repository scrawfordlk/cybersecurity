#!/bin/sh

# 32-bit deps:
# Fedora:
# sudo dnf install glibc-devel.i686 libgcc.i686
#
# Debian:
# sudo apt install gcc-multilib

gcc -o hacked hacked.c secrets.c -fno-stack-protector -m32 -no-pie
