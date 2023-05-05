#include "gdt.h"

// Define the GDT entries
static GDTEntry gdt_entries[3];

// Define the GDT pointer
static GDTPointer gdt_ptr;


// Load the GDT into the processor
void load_gdt(GDTPointer* gdt_ptr) {
    asm volatile("lgdt (%0)" : : "r"(gdt_ptr));
    /*asm volatile("mov $0x10, %ax \n\t"
                 "mov %ax, %ds \n\t"
                 "mov %ax, %es \n\t"
                 "mov %ax, %fs \n\t"/usr/bin/watcom/binl/wcc -4 -d3 -s -wx -ms -zl -zq  -fo=/root/aop2023may/build/stage2/c/main.obj main.c
/usr/bin/watcom/binl/wcc: invalid option -- '4'
                 "mov %ax, %gs \n\t"
                 "mov %ax, %ss \n\t"
                 "ljmp $0x08, $1f \*/
}


// Initialize the GDT
void init_gdt() {
    // Null segment descriptor
    gdt_entries[0].limit_low = 0;
    gdt_entries[0].base_low = 0;
    gdt_entries[0].base_mid = 0;
    gdt_entries[0].access = 0;
    gdt_entries[0].granularity = 0;
    gdt_entries[0].base_high = 0;

    // Code segment descriptor
    gdt_entries[1].limit_low = 0xFFFF;
    gdt_entries[1].base_low = 0;
    gdt_entries[1].base_mid = 0;
    gdt_entries[1].access = 0x9A;
    gdt_entries[1].granularity = 0xCF;
    gdt_entries[1].base_high = 0;

    // Data segment descriptor
    gdt_entries[2].limit_low = 0xFFFF;
    gdt_entries[2].base_low = 0;
    gdt_entries[2].base_mid = 0;
    gdt_entries[2].access = 0x92;
    gdt_entries[2].granularity = 0xCF;
    gdt_entries[2].base_high = 0;

    // Set up the GDT pointer
    gdt_ptr.limit = sizeof(gdt_entries) - 1;
    gdt_ptr.base = (uint32_t)gdt_entries;

    // Load the GDT into the processor
    load_gdt(&gdt_ptr);
}
