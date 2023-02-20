#include "date.h"
using namespace std;

date::date(int d, int m, int y)
: day(d), month(m), year(y) {}

void date::SetDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int date::GetDay() const {
    return day;
}

int date::GetMonth() const {
    return month;
}

int date::GetYear() const {
    return year;
}
