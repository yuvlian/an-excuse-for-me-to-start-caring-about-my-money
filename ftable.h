#ifndef FTABLE_H
#define FTABLE_H

#include "csv.h"
#include <time.h>
#include <stddef.h>

typedef enum {
    FCAT_UNKNOWN = 0,   // Default / unrecognized
    FCAT_FOOD,          // e.g. rice, frozen food, wtv
    FCAT_TRANSPORT,     // bensin, parking, public transport
    FCAT_UTILITIES,     // bills, internet, electricity
    FCAT_ENTERTAINMENT, // games, streaming, movies, etc.
    FCAT_TOOLS,         // mouse, keyboard, saucepans, etc.
    FCAT_CHORES,        // laundry, cleaning supplies
    FCAT_OTHER          // miscellaneous uncategorized
} FCategory;

char* fcat_to_string(FCategory cat);
FCategory fcategory_from_string(char* str);

typedef struct {
    time_t timestamp;
    char* title;
    char* description;
    FCategory category;
    int amount;
} FColumns;

typedef struct {
    int id;
    FColumns col;
} FRow;

typedef struct {
    FRow* rows;
    size_t count;
} FTable;

FTable parse_ftable_csv(shitty_csv csv);
FTable load_ftable_from_file(char* path);
void save_ftable_to_file(FTable table, char* path);

FRow* find_in_ftable(
    FTable table,
    int id,
    time_t time_start,
    time_t time_end,
    char* title,
    char* description,
    FCategory category,
    int amount
);

FRow find_one_in_ftable(
    FTable table,
    int id,
    time_t time_start,
    time_t time_end,
    char* title,
    char* description,
    FCategory category,
    int amount
);

void insert_into_ftable(FTable* table, FRow new_row);

void update_ftable_row_by_id(
    FTable* table,
    int id,
    FColumns to_update
);

void delete_ftable_row_by_id(FTable* table, int id);
void delete_ftable_rows(FTable* table, FRow* matches, size_t match_count);

int get_next_ftable_id(FTable table);

void sort_ftable_by_time(FTable* table);
void sort_ftable_by_id(FTable* table);

FTable clone_ftable(FTable table);

int sum_ftable_amount(FTable table);
int sum_ftable_amount_in_period(FTable table, time_t start, time_t end);
int sum_ftable_amount_in_current_month(FTable table);

void free_ftable(FTable table);

#endif
