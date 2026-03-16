#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_reloc_sorts.h"
#include "reloc_sorts.h"

#define MAX_LINE_SIZE 300

void LoadRelocSorts(char* relocSortsFileName) {
    char* relocSortsFileData;
    size_t relocSortsFileSize;
    FILE* relocSortsFile;
    char line[MAX_LINE_SIZE];
    RelocSortInfo info = {0};

    relocSortsFile = fopen(relocSortsFileName, "rb");

    if (relocSortsFile == NULL) {
        perror("Can't open reloc sorts file!\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_SIZE, relocSortsFile) != NULL) {   
        if (sscanf(line, "rom: %x order: %d", &info.address, &info.order) != 2) {
            printf("Parse failed\n");
        }
        RelocSort_AddReloc(info.address, info.order);
    }
}

void LoadRelocSorts_Destroy(void) {
    RelocSort_Destroy();
}

