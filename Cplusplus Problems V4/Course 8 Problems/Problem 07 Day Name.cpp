
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


short CalcDayOrder(short Day , short Month , short Year)
{
    

    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


}

string DayShortName(short CalculDayOrder)
{

    string ArrDays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return ArrDays[CalculDayOrder];
}



int main()
{
    short Year = ReadYear();
    cout << endl;
    short Month = ReadMonth();
    cout << endl;
    short Day = ReadDay();
    cout << endl;

    cout << "Date        : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order   : " << CalcDayOrder(Day, Month, Year) << endl;
    cout << "Day Name    : " << DayShortName(CalcDayOrder(Day, Month, Year)) << endl;
   
    


    


    system("pause>0");

    return 0;
}

