
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

string MonthShortName(short ReadMonth)
{

    string ArrDays[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

    return ArrDays[ReadMonth - 1];
}

short CalcDayOrder(short Day, short Month, short Year)
{


    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;



    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


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

stDate GetDateAfterAddingDays(short AddDays, stDate Date)
{
    short RemainingDays = AddDays + DaysFromTheBeginningOfYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {

        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }

    }

    return  Date;


}


bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    stDate Date;
    return DaysFromTheBeginningOfYear(Date1.Day, Date1.Month, Date1.Year) < DaysFromTheBeginningOfYear(Date2.Day, Date2.Month, Date2.Year);

}



int main()
{


    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1LessThanDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 is Less than Date2. ";
    }
    else
        cout << "\nNo, Date1 is NOT Less than Date2. ";






    system("pause>0");

    return 0;
}


