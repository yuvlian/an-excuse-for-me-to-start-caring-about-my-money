#include "csv.h"
#include "fs.h"
#include "ftable.h"
#include "tm.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("unix tmstamp 2025-12-01: %lld\n", make_time_t(2025, 12, 1));

    char* contents = read_file_to_string("data.csv");
    if (contents == NULL) {
        fprintf(stderr, "fs read fail\n");
        return 1;
    }

    shitty_csv csv = parse_csv_string(contents);
    free(contents);

    if (csv == NULL) {
        fprintf(stderr, "csv parse fail\n");
        return 1;
    }

    for (shitty_csv p = csv; *p; ++p) {
        printf("[%s]\n", *p);
    }

    free_csv(csv);
    return 0;
}
