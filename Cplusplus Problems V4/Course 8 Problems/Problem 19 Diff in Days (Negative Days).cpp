

#include <iostream>
#include <string>

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
    stDate Date;
    return DaysFromTheBeginningOfYear(Date1.Day, Date1.Month, Date1.Year) < DaysFromTheBeginningOfYear(Date2.Day, Date2.Month, Date2.Year);

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

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;

}

int DiffInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;

    if (!(IsDate1LessThanDate2(Date1, Date2)))
    {
        SwapDates(Date1,Date2);
        SwapFlagValue = -1;

    }

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}


int main()
{


    stDate Date1 = ReadFullDate();
    cout << endl;
    stDate Date2 = ReadFullDate();


    cout << "\nDifference is : " << DiffInDays(Date1, Date2) << " Day(s)" << endl;
    cout << "\nDifference (Including End Day) is : " << DiffInDays(Date1, Date2, true) << " Day(s)" << endl;


    system("pause>0");

    return 0;
}


