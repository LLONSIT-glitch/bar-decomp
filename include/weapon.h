#ifndef BAR_WEAPON_H
#define BAR_WEAPON_H
typedef struct UnkDobjExports_s {
    char pad[0x40];
    void (*unk40)(s32);
} UnkDobjExports;

typedef struct Weapon_Exports_s {
    /* 0x00 */ void (*func_weapon_004000E0)(void);
} Weapon_Exports;
#endif /* BAR_WEAPON_H */
