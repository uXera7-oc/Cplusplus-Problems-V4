
#include <iostream>
#include <string>

using namespace std;

bool CheckLeapYear(int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadMonth()
{
    short Month;
    do
    {
        cout << "Please Enter a Month to Check?";
        cin >> Month;

    } while (Month <= 0 && Month > 12);

    return Month;

}


int NumberOfDays(int Year, short Month)
{
    //Already Covered By do while in ReadMonth()
    /*if (Month < 1 || Month > 12)
    {
        return 0;
    }*/

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return Month == 2 && CheckLeapYear(Year) ? 29 : Days[Month - 1];

    

}

int NumberOfHours(int Year, int Month)
{
    return NumberOfDays(Year, Month) * 24;
}

int NumberOfMinutes(int Year, int Month)
{
    return NumberOfHours(Year, Month) * 60;
}

int NumberOfSeconds(int Year, int Month)
{
    return NumberOfMinutes(Year, Month) * 60;
}



int ReadYear()
{
    int Year;

    cout << "Please Enter a Year ?";
    cin >> Year;

    return Year;
}


int main()
{
    int Year = ReadYear();
    cout << endl;
    int Month = ReadMonth();
    cout << endl;

    cout << "Number of Days     in Month [" << Month << "] is : " << NumberOfDays(Year, Month) << endl;
    

    system("pause>0");

    return 0;
}

