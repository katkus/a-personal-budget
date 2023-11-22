#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <clocale>
#include <string>
#include <algorithm>
//co zrobić z bibliotekami?? Potrzebne??
using namespace std;

string getDate ()
{
    char bufor [ 64 ];
    time_t timeTakenFromComputer;
    time( & timeTakenFromComputer );
    tm timeTakenFromComputerTM = * localtime( & timeTakenFromComputer );
    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", & timeTakenFromComputerTM );
    string date = bufor;
    return date;
}
void checkNumberOfDaysPerMonth (string date)
{
    int coefficientForConvertingYearFromStringToChar=1000;
    int year = 0;
    const char* datE;

    datE = (date.c_str());

for (int i = 0; i < 4; i++)
{
    year = year+ (datE [i] - 48)*coefficientForConvertingYearFromStringToChar;
    coefficientForConvertingYearFromStringToChar=coefficientForConvertingYearFromStringToChar/10;
}
int monthNumber =0; int coefficientForConvertingMonthFromStringToChar=10;

for (int i = 5; i < 7; i++)
{
    monthNumber = monthNumber+ (datE [i] - 48)*coefficientForConvertingMonthFromStringToChar;
    coefficientForConvertingMonthFromStringToChar=coefficientForConvertingMonthFromStringToChar/10;
}

        switch (monthNumber)
        {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                        cout << "Ten miesiąc ma 31 dni! "<<endl;;
                        break;
                case 4:
                case 6:
                case 9:
                case 11:
                        cout << "Ten miesiac ma 30 dni! "<<endl;;
                        break;
                case 2:
                {
                        if (((year%4==0)&& (year%100!=0)) || ((year%400 == 0)))
                        cout << "Ten miesiąc ma 29 dni! Jest to rok przestepny!";
                        else cout << "Ten miesiąc ma 28 dni ! "<<endl;
                        break;
                }
                default:
                cout << "Niepoprawny numer miesiąca! "<<endl;
                break;
        }
}
void displayAllDate (string date[])
{
    for (int i=0; i< 5; i++)
    {
        cout << date[i] << endl;
    }
}

int main() {
    string date [] = {"1983-01-22", "1970-06-01", "1970-03-15", "2020-06-15", "" };
    int size = 5;

    date [4] = getDate();
    checkNumberOfDaysPerMonth(date[4]);

    displayAllDate(date);
    sort(date, date+5);
    //sort(vec.begin(), vec.end()); => przy pracy na wektorach;
    cout<< "posortowane: "<<endl;
    displayAllDate(date);

    return 0;
}
