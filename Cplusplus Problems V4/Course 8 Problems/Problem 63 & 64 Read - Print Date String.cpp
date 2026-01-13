#include <iostream>
#include <string>
#include <cctype>
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

	cout << Message << endl;
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


string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}





int main()
{
	string DateString = ReadDate("Please Enter a Date dd/mm/yyyy ?");

	stDate Date = StringToDate(DateString);

    cout << "\nDay    : " << Date.Day << endl;
    cout << "Month  : " << Date.Month << endl;
    cout << "Year   : " << Date.Year << endl;
    
	cout << "\nYou Entered : " << DateToString(Date);

    system("pause>0");

    return 0;
}