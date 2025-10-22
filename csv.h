#ifndef CSV_H
#define CSV_H

typedef char** shitty_csv;
shitty_csv parse_csv_string(char* string);
void free_csv(shitty_csv csv);

#endif
