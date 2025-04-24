.section .multiboot
.align 4
    .long 0x1BADB002            # Magic number
    .long 0x00                  # Flags
    .long -(0x1BADB002 + 0x00)  # Checksum

.section .text
.global _start

.extern kernel_main

_start:
    call kernel_main
.hang:
    jmp .hang
