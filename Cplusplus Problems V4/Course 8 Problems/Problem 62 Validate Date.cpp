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

    cout << "Please Enter a Month ? ";
    cin >> Month;

    return Month;

}

short ReadDay()
{
    short Day;

    cout << "Please Enter a Day ? ";
    cin >> Day;



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

bool IsValidateDate(stDate Date)
{
    return (Date.Month >= 1 && Date.Month <= 12 && Date.Day >= 1 && Date.Day <= NumberOfDaysInMonth(Date.Year, Date.Month));

}


int main()
{

    stDate Date = ReadFullDate();


    if (IsValidateDate(Date))
        cout << "\nYes, Date is a Valid Date.";
    else
        cout << "\nNo, Date is NOT a Valid Date.";


    system("pause>0");

    return 0;
}