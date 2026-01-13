
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

short ReadAddDays()
{
    short Day;
    do
    {
        cout << "How Many Days to add ? ";
        cin >> Day;

    } while (Day <= 0);

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

short CalcDayOrder(short Day, short Month, short Year)
{


    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;



    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


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





int main()
{


    stDate Date = ReadFullDate();

    if (IsLastDay(Date))
    {
        cout << "\nYes, Day is Last Day in Month. ";
    }
    else

        cout << "\nNo, Day is NOT Last Day in Month. ";

    if (IsLastMonth(Date))
    {
        cout << "\nYes, Month is Last Month in Year. ";
    }
    else

        cout << "\nNo, Month is NOT Last Month in Year. ";




    system("pause>0");

    return 0;
}


