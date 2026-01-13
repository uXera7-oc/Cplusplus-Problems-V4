
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

stDate IncreaseDateByXDays(stDate Date ,short X)
{

    for (short i = 1; i <= X; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
           
    return Date;
   
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date,short X)
{
    for (short i = 1; i <= (7*X); i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == IsLastMonth(Date))
    {
        Date.Year++;
        Date.Month = 1;
    }
    else
    {
        Date.Month++;
    }

    return Date;

}

stDate IncreaseDateByXMonths(stDate Date, short X)
{
    for (short i = 1; i <= X; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;

}

stDate IncreaseDateByXYears(stDate Date, short X)
{
    for (short i = 1; i <= X; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short X)
{
    Date.Year += X;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    for (int i = 1; i <= 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date,short X)
{
    for (int i = 1; i <= (10*X); i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short X)
{
    Date.Year += X * 10;
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}





int main()
{


    stDate Date = ReadFullDate();

    cout << "\nDate After:\n\n";

    Date = IncreaseDateByOneDay(Date);
    cout << "\n01-Adding One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date,10);
    cout << "\n02-Adding 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date,10);
    cout << "\n04-Adding 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date,5);
    cout << "\n06-Adding 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "\n07-Adding One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date,10);
    cout << "\n08-Adding 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date,10);
    cout << "\n09-Adding 10 Years (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date,10);
    cout << "\n11-Adding 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecadesFaster(Date,10);
    cout << "\n12-Adding 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "\n13-Adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "\n14-Adding One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    system("pause>0");

    return 0;
}


