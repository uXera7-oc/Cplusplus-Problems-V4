
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


int NumberOfDays(int Year , short Month )
{
    if (Month == 2)
    {
    return (CheckLeapYear(Year) ? 29 : 28);

    }
    else if (Month == 1 || 3 || 5 || 7 || 8 || 10 || 12)
    {
        return 31;
    }
    else
    {
        return 30;
    }


    //Another Way

    //if (Month == 2)
    //{
    //    return CheckLeapYear(Year) ? 29 : 28;
    //}

    //short Arr31Days[7] = { 1,3,5,7,8,10,12 };

    //for (short i = 1; i <= 7; i++)
    //{
    //    if(Arr31Days[i - 1] == Month)
    //        return 31
    //}

    ////if You Reach Here then it is 30 Days

    //return 30
    
}

int NumberOfHours(int Year,int Month)
{
    return NumberOfDays(Year ,Month) * 24;
}

int NumberOfMinutes(int Year , int Month)
{
    return NumberOfHours(Year , Month) * 60;
}

int NumberOfSeconds(int Year , int Month)
{
    return NumberOfMinutes(Year , Month) * 60;
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
    cout << endl ;
    int Month = ReadMonth();
    cout << endl ;

    cout << "Number of Days     in Month [" << Month << "] is : " << NumberOfDays(Year,Month) << endl;
    cout << "Number of Hours    in Month [" << Month << "] is : " << NumberOfHours(Year,Month) << endl;
    cout << "Number of Minutes  in Month [" << Month << "] is : " << NumberOfMinutes(Year,Month) << endl;
    cout << "Number of Seconds  in Month [" << Month << "] is : " << NumberOfSeconds(Year,Month) << endl;

    system("pause>0");

    return 0;
}

