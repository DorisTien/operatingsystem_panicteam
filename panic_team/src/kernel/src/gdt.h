//from youtube link in the course
#ifndef GDT_H
#define GDT_H

#include <stdint.h>

// Structure for a GDT entry
struct GDTEntry {
    uint16_t limit_low;     // Segment limit (bits 0-15)
    uint16_t base_low;      // Segment base address (bits 0-15)
    uint8_t base_mid;       // Segment base address (bits 16-23)
    uint8_t access;         // Access flags
    uint8_t granularity;    // Segment limit (bits 16-19) and flags
    uint8_t base_high;      // Segment base address (bits 24-31)
};

// Structure for the GDT pointer
struct GDTPointer {
    uint16_t limit;         // GDT limit (size - 1)
    uint32_t base;          // GDT base address
};

// Initialize the GDT
void init_gdt();


#endif // GDT_H
