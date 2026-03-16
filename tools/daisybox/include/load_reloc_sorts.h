#ifndef LOAD_RELOC_SORTS_H
#define LOAD_RELOC_SORTS_H
#include <stdint.h>
typedef struct RelocSortInfo_s {
    int32_t address;
    int32_t order;
} RelocSortInfo;

RelocSortInfo LoadRelocSorts_Parse(char *str);
void LoadRelocSorts(char* relocSortsFileName);
void LoadRelocSorts_Destroy(void);
#endif /* LOAD_RELOC_SORTS_H */