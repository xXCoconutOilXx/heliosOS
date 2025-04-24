ENTRY(_start)

SECTIONS {
    /* Set the start address of the kernel (1MB) */
    . = 1M;

    /* Code section (text) */
    .text : {
        *(.text)
    } > CODE

    /* Read-only data section (rodata) */
    .rodata : {
        *(.rodata)
        *(.rodata.str1.1)  /* Include all the read-only string data */
    } > RO_DATA

    /* Initialized data section (data) */
    .data : {
        *(.data)
    } > DATA

    /* Uninitialized data section (bss) */
    .bss : {
        *(.bss)
    } > BSS

    /* Discard unnecessary sections */
    /DISCARD/ : {
        *(.comment)
    }
}
