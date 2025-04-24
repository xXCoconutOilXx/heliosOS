#include "idt.h"
#include "keyboard.h"

// Define the IDT entry structure
struct idt_entry {
    unsigned short base_low;
    unsigned short sel;
    unsigned char always0;
    unsigned char flags;
    unsigned short base_high;
};

struct idt_entry idt[256];

void idt_set_gate(int num, unsigned long base, unsigned short sel, unsigned char flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

void idt_init(void) {
    idt_set_gate(33, (unsigned long)keyboard_handler, 0x08, 0x8E); // IRQ1 (keyboard)
    // Load the IDT
    asm volatile("lidt %0" : : "m"(idt));
}
