
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

bool CheckLeapYear(stDate Date)
{
    return (Date.Year % 4 == 0 && Date.Year % 100 != 0) || (Date.Year % 400 == 0);
}

short CalculateDayOfWeekOrder(short Day, short Month, short Year)
{

    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


}

//OverLoading
short CalcDayOfWeekOrder(stDate Date)
{
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;


    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short NumberOfDaysInMonth(stDate Date)
{
    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return Date.Month == 2 && CheckLeapYear(Date) ? 29 : Days[Date.Month - 1];

}





string DayShortName(short CalculDayOrder)
{

    string ArrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return ArrDays[CalculDayOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return (CalculateDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6 ) ;
}

bool IsWeekend(stDate Date)
{
    return (CalculateDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 5 || CalculateDayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6 );

}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekend(Date));
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    if (!IsEndOfWeek(Date))
    {
        return 6 - CalcDayOfWeekOrder(Date) ;
    }
    else
        return 0;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    return NumberOfDaysInMonth(Date) - Date.Day;
}

short DaysUntilTheEndOfYear(stDate Date)
{
    return CheckLeapYear(Date) ? (366 - Date.Day ) : (365 - Date.Day);
}


int main()
{
    stDate Date = GetSystemDate();

    //Overload the DayOfWeek to take date structure
    cout << "Today is " << DayShortName(CalcDayOfWeekOrder(Date));
    cout << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;

    //Is End Of Week ?
    cout << "Is it End of Week ? " << endl;
    if (IsEndOfWeek(Date))
    
        cout << "YES it is Saturday, it's End of Week\n" << endl;
    else
        cout << "NO it is NOT End of Week\n" << endl;


    //Is Week End ?
    cout << "Is it Weekend ? " << endl;
    if (IsWeekend(Date))
    
        cout << "YES it is a Weekend\n" << endl;
    else
        cout << "NO it is NOT a Weekend\n" << endl;


    //Is Business Day ?
    cout << "Is it Business Day ? " << endl;
    if (IsBusinessDay(Date))
    
        cout << "YES it is a Business Day\n" << endl;
    else
        cout << "NO it is NOT a Business Day\n" << endl;

    //Days Until The End Of Week
    cout << "Days until end of Week : " << DaysUntilTheEndOfWeek(Date) << " Day(s)." << endl;

    //Days Until The End Of Month
    cout << "Days until end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s)." << endl;

    //Days Until The End Of Year
    cout << "Days until end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s)." << endl;


    




    system("pause>0");

    return 0;
}