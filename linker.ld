ENTRY(kernel_main)

SECTIONS
{
    . = 0x100000;

    .multiboot ALIGN(4) : AT(0x100000) {
        *(.multiboot)
    }

    .text ALIGN(4) : AT(ADDR(.multiboot) + SIZEOF(.multiboot)) {
        *(.text)
    }

    .data ALIGN(4) : AT(ADDR(.text) + SIZEOF(.text)) {
        *(.data)
    }

    .bss ALIGN(4) : AT(ADDR(.data) + SIZEOF(.data)) {
        *(.bss)
    }

    /DISCARD/ : { *(*) }
}
