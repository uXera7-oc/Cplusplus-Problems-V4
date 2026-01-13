#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct stDate
{
    short Day;
    short Month;
    short Year;
};



string ReadDate(string Message)
{
    string DateString;

    cout << Message ;
    getline(cin >> ws, DateString);

    return DateString;

}


vector <string> SplitString(string S1, string Space)
{
    vector <string> vString;
    short pos = 0;
    string sWord;


    while ((pos = S1.find(Space)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); //Store the Word
        if (sWord != " ")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Space.length());//Erasing until position and move to the next word

    }

    if (S1 != " ")
    {
        vString.push_back(S1);
    }



    return  vString;
}


string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}


stDate StringToDate(string DateString)
{
    stDate Date;
    vector <string> vDate;

    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;

}


string FormatDate(stDate Date,string Format = "dd/mm/yyyy")
{
    string FormatDateString = Format ;
    FormatDateString = ReplaceWordInString(FormatDateString, "dd",to_string( Date.Day));
    FormatDateString = ReplaceWordInString(FormatDateString, "mm",to_string( Date.Month));
    FormatDateString = ReplaceWordInString(FormatDateString, "yyyy",to_string( Date.Year));

    return FormatDateString;
}


int main()
{
    string DateString = ReadDate("Please Enter a Date dd/mm/yyyy ?");

    stDate Date = StringToDate(DateString);

    cout << "\n" << FormatDate(Date) << "\n";

    cout << "\n" << FormatDate(Date,"yyyy/dd/mm") << "\n";

    cout << "\n" << FormatDate(Date,"mm/dd/yyyy") << "\n";

    cout << "\n" << FormatDate(Date,"mm-dd-yyyy") << "\n";

    cout << "\n" << FormatDate(Date,"dd-mm-yyyy") << "\n";

    cout << "\n" << FormatDate(Date,"Day:dd, Month:mm,  Year:yyyy") << "\n";
    

    system("pause>0");

    return 0;
}