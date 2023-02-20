#ifndef DATE_H
#define DATE_H

class date{
    int day;
    int month;
    int year;
public:
    date(int, int, int);
    void SetDate(int, int, int);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
};

#endif
