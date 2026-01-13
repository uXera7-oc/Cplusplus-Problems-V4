#pragma warning(disable : 4996)


#include <iostream>
#include <string>
#include <ctime>

using namespace std;


struct  stDate
{
    short Day;
    short Month;
    short Year;

};

short ReadYear()
{
    short Year;

    cout << "Please Enter a Year ? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month;
    do
    {
        cout << "Please Enter a Month ? ";
        cin >> Month;

    } while (Month <= 0 || Month > 12);

    return Month;

}

short ReadDay()
{
    short Day;
    do
    {
        cout << "Please Enter a Day ? ";
        cin >> Day;

    } while (Day <= 0 || Day > 31);

    return Day;

}

bool CheckLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(short Year, short Month)
{
    //Already Covered By do while in ReadMonth()
    /*if (Month < 1 || Month > 12)
    {
        return 0;
    }*/

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return Month == 2 && CheckLeapYear(Year) ? 29 : Days[Month - 1];

}

short DaysFromTheBeginningOfYear(short Day, short Month, short Year)
{


    short RestOfDays = 0;
    for (int i = 1; i < Month; i++)
    {
        RestOfDays += NumberOfDaysInMonth(Year, i);
    }

    return  Day + RestOfDays;

}


stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsLastDay(stDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonth(stDate Date)
{
    return (Date.Month == 12);
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    if (Date1.Year < Date2.Year)
        return true;

    if (Date1.Year == Date2.Year)
    {
        if (Date1.Month < Date2.Month)
            return true;

        if (Date1.Month == Date2.Month)
            return Date1.Day < Date2.Day;
    }

    return false;
}


stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDay(Date) && IsLastMonth(Date))
    {
        Date.Year++;
        Date.Month = 1;
        Date.Day = 1;
    }
    else if (IsLastDay(Date))
    {
        Date.Day = 1;
        Date.Month++;
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int DiffInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;

}


int main()
{
    cout << "\nPlease Enter Your Date of Birth : \n\n";

    stDate Date1 = ReadFullDate();
    cout << endl;
    stDate Date2 = GetSystemDate();


    cout << "\nYour Age is : " << DiffInDays(Date1, Date2, true) << " Day(s)" << endl;


    system("pause>0");

    return 0;
}


