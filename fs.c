#include "fs.h"
#include <stdio.h>
#include <stdlib.h>

char* read_file_to_string(char* path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "fopen fail\n");
        goto fail;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    rewind(file);

    if (fsize == -1) {
        fprintf(stderr, "file size get fail\n");
        goto fail;
    }

    char* buffer = (char*)malloc(fsize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "malloc fail\n");
        goto fail;
    }

    size_t bytes_read = fread(buffer, 1, fsize, file);
    if (bytes_read != (size_t)fsize) {
        fprintf(stderr, "fread fail\n");
        goto fail;
    }

    buffer[fsize] = '\0';
    fclose(file);
    return buffer;

    fail:
        if (file != NULL)
            fclose(file);
        return NULL;
}
