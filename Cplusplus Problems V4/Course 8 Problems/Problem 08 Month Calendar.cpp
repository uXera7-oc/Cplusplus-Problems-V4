
#include <iostream>
#include <string>

using namespace std;



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

    string ArrDays[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

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


void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    //Index of The Current day from 0 to 6
    int Current = CalcDayOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInMonth(Year, Month);

    //Print The Curren Month Name
    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());

    //Print The Columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    //Print Appropriate Spaces
    int i;
    for ( i = 0; i < Current; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");

        }
    }

    printf("\n  _________________________________\n\n");





}



int main()
{
    short Year = ReadYear();
    cout << endl;
    short Month = ReadMonth();
    cout << endl;
    

    PrintMonthCalendar(Month, Year);







    system("pause>0");

    return 0;
}

