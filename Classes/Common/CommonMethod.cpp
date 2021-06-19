#include "Common/CommonMethod.h"

clock_t time_record(int begin)
{
    clock_t end, TIME;
    end = clock();
    TIME = end - begin;
    return TIME;
}