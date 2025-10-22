#include "ftable.h"
#include "csv.h"
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

const char* fcategory_to_string(FCategory cat) {
    switch (cat) {
        case FCAT_FOOD:
            return "food";
        case FCAT_TRANSPORT:
            return "transport";
        case FCAT_UTILITIES:
            return "utilities";
        case FCAT_ENTERTAINMENT:
            return "entertainment";
        case FCAT_TOOLS:
            return "tools";
        case FCAT_CHORES:
            return "chores";
        case FCAT_OTHER:
            return "other";
        default:
            return "unknown";
    }
}

FCategory fcategory_from_string(char* str) {
    if (str == NULL)
        return FCAT_UNKNOWN;
    if (strcasecmp(str, "food") == 0)
        return FCAT_FOOD;
    if (strcasecmp(str, "transport") == 0)
        return FCAT_TRANSPORT;
    if (strcasecmp(str, "utilities") == 0)
        return FCAT_UTILITIES;
    if (strcasecmp(str, "entertainment") == 0)
        return FCAT_ENTERTAINMENT;
    if (strcasecmp(str, "tools") == 0)
        return FCAT_TOOLS;
    if (strcasecmp(str, "chores") == 0)
        return FCAT_CHORES;
    if (strcasecmp(str, "other") == 0)
        return FCAT_OTHER;
    return FCAT_UNKNOWN;
}

FTable parse_ftable_csv(shitty_csv csv) {
    (void)csv;
    FTable table = {0};
    return table;
}

FTable load_ftable_from_file(char* path) {
    (void)path;
    FTable table = {0};
    return table;
}

void save_ftable_to_file(FTable table, char* path) {
    (void)table;
    (void)path;
}

FRow* find_in_ftable(
    FTable table,
    int id,
    time_t time_start,
    time_t time_end,
    char* title,
    char* description,
    FCategory category,
    int amount
) {
    (void)table; (void)id; (void)time_start; (void)time_end;
    (void)title; (void)description; (void)category; (void)amount;
    return NULL;
}

FRow find_one_in_ftable(
    FTable table,
    int id,
    time_t time_start,
    time_t time_end,
    char* title,
    char* description,
    FCategory category,
    int amount
) {
    (void)table; (void)id; (void)time_start; (void)time_end;
    (void)title; (void)description; (void)category; (void)amount;

    FRow empty = {0};
    return empty;
}

void insert_into_ftable(FTable* table, FRow new_row) {
    (void)table;
    (void)new_row;
}

void update_ftable_row_by_id(FTable* table, int id, FColumns to_update) {
    (void)table;
    (void)id;
    (void)to_update;
}

void delete_ftable_row_by_id(FTable* table, int id) {
    (void)table;
    (void)id;
}

void delete_ftable_rows(FTable* table, FRow* matches, size_t match_count) {
    (void)table;
    (void)matches;
    (void)match_count;
}

int get_next_ftable_id(FTable table) {
    (void)table;
    return 0;
}

void sort_ftable_by_time(FTable* table) {
    (void)table;
}

void sort_ftable_by_id(FTable* table) {
    (void)table;
}

FTable clone_ftable(FTable table) {
    FTable clone = {0};
    (void)table;
    return clone;
}

int sum_ftable_amount(FTable table) {
    (void)table;
    return 0;
}

int sum_ftable_amount_in_period(FTable table, time_t start, time_t end) {
    (void)table;
    (void)start;
    (void)end;
    return 0;
}

int sum_ftable_amount_in_current_month(FTable table) {
    (void)table;
    return 0;
}

void free_ftable(FTable table) {
    (void)table;
}
