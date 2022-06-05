#include "Date.h"

int ControlYear();
int ControlMounth();
int ControlDay(int fyear, int fmounth);

Date::Date()
{
    day = 0;
    mounth = 0;
    year = 0;
}

Date& Date::operator=(const Date& equal)
{
    day = equal.day;
    mounth = equal.mounth;
    year = equal.year;
    return *this;
}
istream& operator>> (istream& in, Date& equal)
{
    bool not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.year = ControlYear();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.mounth = ControlMounth();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.day = ControlDay(equal.year, equal.mounth);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    return in;
}

//Date::~Date()
//{

    //delete[] day;
    //delete[] mounth;
    //delete[] year;
    //cout << "почистилась дата";
//}
