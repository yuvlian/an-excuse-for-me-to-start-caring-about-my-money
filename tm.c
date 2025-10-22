#include "tm.h"
#include <time.h>

struct tm make_tm(int year, int month, int day) {
    struct tm my_tm = {0};
    my_tm.tm_year = year - 1900;
    my_tm.tm_mon = month - 1;
    my_tm.tm_mday = day;
    return my_tm;
}

time_t make_time_t(int year, int month, int day) {
    struct tm my_tm = make_tm(year, month, day);
    return mktime(&my_tm);
}
