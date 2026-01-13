//My Last Solution was Already One Line Of Code So the Expected Code In Problem 02 is : 



//bool IsLeapYear(short Year)
//{
//    // leap year if perfectly divisible by 400
//    if (Year % 400 == 0) {
//        return true;
//    }
//    // not a leap year if divisible by 100
//    // but not divisible by 400
//    else if (Year % 100 == 0) {
//        return false;
//    }
//    // leap year if not divisible by 100
//    // but divisible by 4
//    else if (Year % 4 == 0) {
//        return true;
//    }
//    // all other years are not leap years
//    else {
//        return false;
//    }
//} 


#include <iostream>
#include <string>

using namespace std;

bool CheckLeapYear(int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

void PrintResult(int Year)
{
    if (CheckLeapYear(Year))
    {
        cout << "The Year is Leap ! " << endl;
    }
    else
    {
        cout << "The Year is Not Leap " << endl;
    }
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
    int Year;

    PrintResult(ReadYear());

    system("pause>0");

    return 0;
}

