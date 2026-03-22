#ifndef BAR_MODULE_H
#define BAR_MODULE_H
/* Module exports */
#include "uvstring_rom.h"
#include "uvsort_rom.h"


#define MODULE_ENTRY_POINT(func) __entrypoint_##func

#endif /* BAR_MODULE_H */
