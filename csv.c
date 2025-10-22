#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

shitty_csv parse_csv_string(char* string) {
    if (string == NULL) {
        fprintf(stderr, "parse csv arg was NULL\n");
        return NULL;
    }

    char* tmpstr = strdup(string);
    if (tmpstr == NULL) {
        fprintf(stderr, "strdup fail\n");
        return NULL;
    }

    shitty_csv result = NULL;
    size_t count = 0;

    char* saveptr1;
    for (
        char* line_token = strtok_r(tmpstr, "\n", &saveptr1);
        line_token != NULL;
        line_token = strtok_r(NULL, "\n", &saveptr1)
    ) {
        char* linecpy = strdup(line_token);
        if (linecpy == NULL) {
            fprintf(stderr, "strdup fail\n");
            free(tmpstr);
            return NULL;
        }

        for (char* p = linecpy; *p; ++p) {
            if (*p == '\r') *p = '\0';
        }

        char* saveptr2;
        for (
            char* comma_token = strtok_r(linecpy, ",", &saveptr2);
            comma_token != NULL;
            comma_token = strtok_r(NULL, ",", &saveptr2)
        ) {
            shitty_csv new_result = realloc(result, (count + 1) * sizeof(char*));
            if (new_result == NULL) {
                fprintf(stderr, "realloc fail\n");
                for (size_t i = 0; i < count; i++) {
                    free(result[i]);
                }
                free(result);
                free(linecpy);
                free(tmpstr);
                return NULL;
            }

            result = new_result;
            result[count] = strdup(comma_token);
            if (result[count] == NULL) {
                fprintf(stderr, "strdup fail\n");
                for (size_t i = 0; i < count; i++) {
                    free(result[i]);
                }
                free(result);
                free(linecpy);
                free(tmpstr);
                return NULL;
            }
            count++;
        }

        free(linecpy);
    }

    free(tmpstr);

    shitty_csv new_result = realloc(result, (count + 1) * sizeof(char*));
    if (new_result == NULL) {
        fprintf(stderr, "realloc fail\n");
        for (size_t i = 0; i < count; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }

    result = new_result;
    result[count] = NULL;

    return result;
}

void free_csv(shitty_csv csv) {
    if (csv == NULL) {
        return;
    }
    for (shitty_csv p = csv; *p != NULL; ++p) {
        free(*p);
    }
    free(csv);
}
