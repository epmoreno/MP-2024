#ifndef C_DATE_HPP
#define C_DATE_HPP

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date &date);

        int getDay();
        int getMonth();
        int getYear();

        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
};

#endif