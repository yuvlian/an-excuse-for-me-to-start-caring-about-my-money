#ifndef TM_H
#define TM_H

#include <time.h>

struct tm make_tm(int year, int month, int day);
time_t make_time_t(int year, int month, int day);

#endif
