#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int convertStringToInt (string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string getTimeFromSystem ()
{
    char bufor [ 64 ];
    time_t timeTakenFromComputer;
    time( & timeTakenFromComputer );
    tm timeTakenFromComputerTM = * localtime( & timeTakenFromComputer );
    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", & timeTakenFromComputerTM );
    string date = bufor;
    return date;
}

int checkNumberOfDaysPerMonth (int currentYear, int currentMonth) {

    int lastDayOfCurrentDay;

            switch (currentMonth)
        {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                        lastDayOfCurrentDay = 31;
                        break;
                case 4:
                case 6:
                case 9:
                case 11:
                        lastDayOfCurrentDay = 30;
                        break;
                case 2:
                {
                        if (((currentYear % 4 == 0)&& (currentYear %100 != 0)) || ((currentYear % 400 == 0)))
                        lastDayOfCurrentDay = 29;
                        else lastDayOfCurrentDay = 28;
                        break;
                }

        }
        return lastDayOfCurrentDay;
}
bool checkFormatDateIsCorrect(string date) {

if ((date[4]=='-') && (date[7]=='-') && date.size()==10) {
    int year, month, day, lastDayOfMonth, currentYear, currentMonth; string currentDate;

    year = convertStringToInt((date.substr(0,4)));
    day = convertStringToInt((date.substr(8,2)));
    month = convertStringToInt((date.substr(5,2)));

    currentDate = getTimeFromSystem();
    currentYear = convertStringToInt((currentDate.substr(0,4)));
    currentMonth = convertStringToInt((currentDate.substr(5,2)));
    lastDayOfMonth = checkNumberOfDaysPerMonth(year, month);

    if ((year >= 2000) && (year <= currentYear)) {
            if ((month >= 1) && (month <= 12))
            {
               if ((day >= 1) && (day <= lastDayOfMonth)) {
                        if (year == currentYear) {
                            if (month > currentMonth)
                                return false; }
                    return true;
               }
            }

    }
}
    return false;

}

string saveDateWithoutHyphen (string date) {

string dateWithoutHyphen = (date.substr(0,4)) + (date.substr(5,2)) + (date.substr(8,2));

return dateWithoutHyphen;
}

string replaceCommaToDot (string amount) {
int lengthOfAmount = amount.length();
    for (int i = 0; i < lengthOfAmount; i++) { // rzutowanie typu?? (int) przy amount.length()

        if ((amount[i] == ',') || (amount[i] == '.')) {
            amount[i] = '.';
            if (lengthOfAmount > i+3) {
                amount.erase(i+3, lengthOfAmount-i-3);
            }
        }
    }

    return amount;
}

double convertStringToDouble(string amount) {
 double amountDouble = atof(amount.c_str());
 return amountDouble;
}
float convertStringToFloat(string amount) {
 float amountDouble =  (float) atof(amount.c_str());
 return amountDouble;
}
//////////////////
string convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string saveDateWithHyphen (string date) {

string dateWithHyphen = (date.substr(0,4)) + (date.substr(4,2)) + (date.substr(6,2));
dateWithHyphen.insert(4, "-");
dateWithHyphen.insert(7, "-");

return dateWithHyphen;
}
//////////////////

int main()
{
 int date; //double amountDouble;//string date;/*, yearS, monthS, dayS;*/ //int year, month, day, lastDayOfCurrentMonth;

 cout << "Podaj date w formacie yyyymmdd: " << endl;
    cin >> date;

    cout << saveDateWithHyphen(convertIntToString(date)) << endl;



//    if (checkFormatDateIsCorrect(date) == true)
 //       cout << "Format daty jest poprawny." << endl;
 //   else
 //       cout << "Format daty jest NIEPOPRAWNY." << endl;
    /*cout << "year: " << year << endl;
    cout << "month: " << month << endl;
    cout << "day: " << day << endl;
    cout << "The month has: " << lastDayOfCurrentMonth << " days." << endl;*/

    //cout << "Zapis danej bez myslnika: " << saveDateWithoutHyphen( date) << endl;
 //double amount = convertStringToInt(saveDateWithoutHyphen(date));*/
// cout << "Wprowadz kwote: " << endl;

 //cin >> amount;
 //amount = replaceCommaToDot(amount);

//amountDouble = convertStringToFloat(replaceCommaToDot(amount));

// cout << "Wyswietlenie wysokosci: " << amountDouble << endl;
    return 0;
}
