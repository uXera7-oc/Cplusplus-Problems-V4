
#include <iostream>
#include <string>

using namespace std;


struct  stDate
{
    short Day;
    short Month;
    short Year;

};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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


stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

stPeriod ReadFullPeriod()
{
    stPeriod Period;

    cout << "Enter Start Date : \n\n";
    Period.StartDate = ReadFullDate();

    cout << "\n\nEnter End Date : \n\n";
    Period.EndDate = ReadFullDate();

    return Period;

}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
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

bool IsDate1EqualesToDate2(stDate Date1, stDate Date2)
{

    return  (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);

}


bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1EqualesToDate2(Date1, Date2) && (!IsDate1BeforeDate2(Date1, Date2)));

}


bool IsPeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
    return !(IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) || IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate));

}

int main()
{

    cout << "Enter Period 1 : \n";
    stPeriod Period1 = ReadFullPeriod();


    cout << "\nEnter Period 2 : \n";
    stPeriod Period2 = ReadFullPeriod();

    if (IsPeriodsOverlap(Period1, Period2))
        cout << "\nYes, Period Overlap ";
    else
        cout << "\nNo, Period Not Overlap ";


    system("pause>0");

    return 0;
}




