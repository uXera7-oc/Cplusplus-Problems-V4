

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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1 && Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
        Date.Day = 31;
    }
    else if (Date.Day == 1)
    {
        Date.Month--;
        Date.Day = NumberOfDaysInMonth(Date.Year , Date.Month);
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short X)
{

    for (short i = 1; i <= X; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;

}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, short X)
{
    for (short i = 1; i <= (7 * X); i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
    }
    else
    {
        Date.Month --;
    }

    return Date;

}

stDate DecreaseDateByXMonths(stDate Date, short X)
{
    for (short i = 1; i <= X; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;

}

stDate DecreaseDateByXYears(stDate Date, short X)
{
    for (short i = 1; i <= X; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short X)
{
    Date.Year -= X;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    for (int i = 1; i <= 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short X)
{
    for (int i = 1; i <= (10 * X); i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short X)
{
    Date.Year -= X * 10;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}





int main()
{


    stDate Date = ReadFullDate();

    cout << "\nDate After:\n\n";

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01-Subtracting One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Subtracting 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Subtracting One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Subtracting 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Subtracting One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Subtracting 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Subtracting One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08-Subtracting 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Subtracting 10 Years (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Subtracting One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "\n11-Subtracting 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "\n12-Subtracting 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13-Subtracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n14-Subtracting One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    system("pause>0");

    return 0;
}



