#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cjson/cJSON.h"
#include "symtab.h"

static cJSON* Root;

static size_t getFileSize(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    size_t fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

void MapSymbols_Init(char* mapFileName) {
    char* mapFileData;
    size_t mapFileSize;
    FILE* mapFile;

    mapFile = fopen(mapFileName, "rb");

    if (mapFile == NULL) {
        perror("Can't open map file!\n");
        exit(EXIT_FAILURE);
    }

    mapFileSize = getFileSize(mapFile);
    mapFileData = malloc(mapFileSize);
    if (mapFileData == NULL) {
        perror("Can't alloc memory for map file data!");
        fclose(mapFile);
        exit(EXIT_FAILURE);
    }

    fread(mapFileData, mapFileSize, 1, mapFile);

    Root = cJSON_Parse(mapFileData);
    if (Root == NULL) {
        fclose(mapFile);
        free(mapFileData);
        printf("JSON parse failed!\n");
        exit(EXIT_FAILURE);
    }

    fclose(mapFile);
    free(mapFileData);
}

void MapSymbols_Load(void) {
    cJSON *segments = cJSON_GetObjectItem(Root, "segments");
    cJSON *seg;
    cJSON_ArrayForEach(seg, segments) {
        cJSON *files = cJSON_GetObjectItem(seg, "files");
        cJSON *file;
        cJSON_ArrayForEach(file, files) {
            cJSON *symbols = cJSON_GetObjectItem(file, "symbols");

            cJSON *sym;
            cJSON_ArrayForEach(sym, symbols) {
                const char *name = cJSON_GetObjectItem(sym, "name")->valuestring;

                const char *vram = cJSON_GetObjectItem(sym, "vram")->valuestring;

                uint32_t addr = strtoul(vram, NULL, 16);
                //printf("Loading symbol: %s\n", name);
                Symtab_AddSymbol(name, addr);
            }
        }
    }
}

void MapSymbols_Destroy(void) {
    free(Root);
    Symtab_Destroy();
}