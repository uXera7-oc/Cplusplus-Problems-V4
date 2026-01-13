
#include <iostream>
#include <string>

using namespace std;

bool CheckLeapYear(int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDays(int Year)
{
    //return CheckLeapYear(Year) ? 366 : 365 ;

    if (CheckLeapYear(Year))
    {
        return 366;
    }
    else
        return 365;
}

int NumberOfHours(int Year)
{
    return NumberOfDays(Year) * 24;
}

int NumberOfMinutes(int Year)
{
    return NumberOfHours(Year) * 60;
}

int NumberOfSeconds(int Year)
{
    return NumberOfMinutes(Year) * 60;
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

    cout << "Number of Days     in Year [" << Year << "] is : " << NumberOfDays(Year) << endl;
    cout << "Number of Hours    in Year [" << Year << "] is : " << NumberOfHours(Year) << endl;
    cout << "Number of Minutes  in Year [" << Year << "] is : " << NumberOfMinutes(Year) << endl;
    cout << "Number of Seconds  in Year [" << Year << "] is : " << NumberOfSeconds(Year) << endl;

    system("pause>0");

    return 0;
}

