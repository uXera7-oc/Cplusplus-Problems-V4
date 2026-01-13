

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

short CalculateDayOfWeekOrder(short Day, short Month, short Year)
{

    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


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

string DayShortName(short CalculDayOrder)
{

    string ArrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return ArrDays[CalculDayOrder];
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

bool IsWeekend(stDate Date)
{
    return (CalculateDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 5 || CalculateDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6);

}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekend(Date));
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1LessThanDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
        
            DaysCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
        

    }
    return DaysCount;
}


int main()
{
    cout << "Vacation Starts :\n" << endl;

    stDate DateFrom = ReadFullDate();
    cout << endl << endl;
    cout << "Vacation Ends : \n" << endl;
    stDate DateTo = ReadFullDate();
    cout << endl << endl;


    cout << "Vacation From : " << DayShortName(CalculateDayOfWeekOrder(DateFrom.Day,DateFrom.Month , DateFrom.Month));
    cout << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl << endl;


    cout << "Vacation To : " << DayShortName(CalculateDayOfWeekOrder(DateTo.Day, DateTo.Month, DateTo.Month));
    cout << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl << endl;

    
    cout << "\nActual Vacation Days are : " << CalculateVacationDays(DateFrom, DateTo) << " Day(s)" << endl;
    


    system("pause>0");

    return 0;
}


