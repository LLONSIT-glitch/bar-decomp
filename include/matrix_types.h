#ifndef MATRIX_TYPES_H
#define MATRIX_TYPES_H
typedef union {
    float m[4][4];
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} Mtx4F;

typedef struct Mtx_u {
    s16 i[4][4];
    s16 f[4][4];
} Mtx_u;

typedef union {
    Mtx_t m;
    Mtx_u u;
    long long int force_structure_alignment;
} uvMtx;
#endif /* MATRIX_TYPES_H */
