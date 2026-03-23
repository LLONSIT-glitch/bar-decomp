SECTIONS
{
    __romPos = 0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        build/asm/us/header.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    boot_ROM_START = __romPos;
    boot_VRAM = ADDR(.boot);
    .boot : AT(boot_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        boot_DATA_START = .;
        build/bin/us/boot.o(.data);
        boot_DATA_END = .;
        boot_DATA_SIZE = ABSOLUTE(boot_DATA_END - boot_DATA_START);
    }
    __romPos += SIZEOF(.boot);
    boot_ROM_END = __romPos;
    boot_VRAM_END = .;

    entry_ROM_START = __romPos;
    entry_VRAM = ADDR(.entry);
    .entry 0x80000400 : AT(entry_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        entry_TEXT_START = .;
        build/asm/us/1000.o(.text);
        . = ALIGN(., 16);
        entry_TEXT_END = .;
        entry_TEXT_SIZE = ABSOLUTE(entry_TEXT_END - entry_TEXT_START);
        entry_DATA_START = .;
        build/asm/us/1000.o(.data);
        . = ALIGN(., 16);
        entry_DATA_END = .;
        entry_DATA_SIZE = ABSOLUTE(entry_DATA_END - entry_DATA_START);
        entry_RODATA_START = .;
        build/asm/us/1000.o(.rodata);
        . = ALIGN(., 16);
        entry_RODATA_END = .;
        entry_RODATA_SIZE = ABSOLUTE(entry_RODATA_END - entry_RODATA_START);
    }
    entry_bss_VRAM = ADDR(.entry_bss);
    .entry_bss (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        entry_BSS_START = .;
        build/asm/us/1000.o(.bss);
        . = ALIGN(., 16);
        entry_BSS_END = .;
        entry_BSS_SIZE = ABSOLUTE(entry_BSS_END - entry_BSS_START);
    }
    __romPos += SIZEOF(.entry);
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);
    entry_ROM_END = __romPos;
    entry_VRAM_END = .;

    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main entry_VRAM_END : AT(main_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        main_TEXT_START = .;
        build/src/1050.o(.text);
        build/src/17E0.o(.text);
        build/src/clocks.o(.text);
        build/src/1F60.o(.text);
        build/src/filesystem.o(.text);
        build/src/memory.o(.text);
        build/src/mem_allocator.o(.text);
        build/src/3F10.o(.text);
        build/src/unused_props.o(.text);
        build/src/sched.o(.text);
        build/src/main.o(.text);
        build/src/unused.o(.text);
        build/asm/us/mio0Decode.o(.text);
        build/asm/us/setintmask.o(.text);
        build/asm/us/getcount.o(.text);
        build/asm/us/62E0.o(.text);
        . = ALIGN(., 16);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        build/src/1050.o(.data);
        build/src/17E0.o(.data);
        build/src/clocks.o(.data);
        build/src/1F60.o(.data);
        build/src/filesystem.o(.data);
        build/src/memory.o(.data);
        build/src/mem_allocator.o(.data);
        build/src/3F10.o(.data);
        build/src/unused_props.o(.data);
        build/src/sched.o(.data);
        build/src/main.o(.data);
        build/src/unused.o(.data);
        build/asm/us/mio0Decode.o(.data);
        build/asm/us/setintmask.o(.data);
        build/asm/us/getcount.o(.data);
        build/asm/us/62E0.o(.data);
        build/asm/us/data/1A930.data.o(.data);
        . = ALIGN(., 16);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
        main_RODATA_START = .;
        build/src/1050.o(.rodata);
        build/asm/us/data/21B00.rodata.o(.rodata);
        build/src/17E0.o(.rodata);
        build/src/clocks.o(.rodata);
        build/src/1F60.o(.rodata);
        build/src/filesystem.o(.rodata);
        build/src/memory.o(.rodata);
        build/src/mem_allocator.o(.rodata);
        build/src/3F10.o(.rodata);
        build/src/unused_props.o(.rodata);
        build/src/sched.o(.rodata);
        build/src/main.o(.rodata);
        build/src/unused.o(.rodata);
        build/asm/us/mio0Decode.o(.rodata);
        build/asm/us/setintmask.o(.rodata);
        build/asm/us/getcount.o(.rodata);
        build/asm/us/62E0.o(.rodata);
        build/asm/us/data/21C70.rodata.o(.rodata);
        . = ALIGN(., 16);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        main_BSS_START = .;
        build/src/1050.o(.bss);
        build/src/17E0.o(.bss);
        build/asm/us/data/bss_1.bss.o(.bss);
        build/src/clocks.o(.bss);
        build/src/1F60.o(.bss);
        build/asm/us/data/bss_2.bss.o(.bss);
        build/src/filesystem.o(.bss);
        build/src/memory.o(.bss);
        build/src/mem_allocator.o(.bss);
        build/asm/us/data/bss_3.bss.o(.bss);
        build/src/3F10.o(.bss);
        build/src/unused_props.o(.bss);
        build/src/sched.o(.bss);
        build/src/main.o(.bss);
        build/src/unused.o(.bss);
        build/asm/us/mio0Decode.o(.bss);
        build/asm/us/setintmask.o(.bss);
        build/asm/us/getcount.o(.bss);
        build/asm/us/62E0.o(.bss);
        build/asm/us/data/bss_4.bss.o(.bss);
        . = ALIGN(., 16);
        main_BSS_END = .;
        main_BSS_SIZE = ABSOLUTE(main_BSS_END - main_BSS_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    mem_block_ROM_START = __romPos;
    mem_block_bss_VRAM = ADDR(.mem_block_bss);
    .mem_block_bss 0x80033770 (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        mem_block_BSS_START = .;
        build/src/mem_block.o(.bss);
        . = ALIGN(., 16);
        mem_block_BSS_END = .;
        mem_block_BSS_SIZE = ABSOLUTE(mem_block_BSS_END - mem_block_BSS_START);
    }
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);
    mem_block_ROM_END = __romPos;
    mem_block_VRAM_END = .;

    FORM0_ROM_START = __romPos;
    FORM0_VRAM = ADDR(.FORM0);
    .FORM0 main_VRAM_END : AT(FORM0_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        FORM0_DATA_START = .;
        build/bin/us/FORM0.o(.data);
        FORM0_DATA_END = .;
        FORM0_DATA_SIZE = ABSOLUTE(FORM0_DATA_END - FORM0_DATA_START);
    }
    __romPos += SIZEOF(.FORM0);
    FORM0_ROM_END = __romPos;
    FORM0_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
