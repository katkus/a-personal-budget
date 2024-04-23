#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Income
{
public:
   int userId, date, amount;
};
string convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

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
int getYearFromDate(string date) {

int year = convertStringToInt((date.substr(0,4)));
return year;

}
string getPreviousMonthFromDate(string currentDate) {
string currentMonth, previousMonth; int currentMonthInt;

cout << "currentDate :" << currentDate << endl;
currentMonth = currentDate.substr(5,2);
cout << "currentMonth :" << currentMonth << endl;
currentMonthInt = (currentMonth[0]-48)*10 + currentMonth[1] - 48;
cout << "currentMonthInt :" << currentMonthInt << endl;

    if((currentMonthInt > 1)&&(currentMonthInt <= 12)) {
        currentMonthInt--;
    }
    else if (currentMonthInt == 1) {
        currentMonthInt = 12;
    }
    else {
        cout << "Blad daty." << endl;
    }

previousMonth = convertIntToString(currentMonthInt);
cout << "previousMonth: " << previousMonth << endl;


    return previousMonth;
}

int getMonthFromDate(string date) {

int month =convertStringToInt((date.substr(5,2)));
return month;

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

string saveDateWithHyphen (string date) {

string dateWithHyphen = (date.substr(0,4)) + (date.substr(4,2)) + (date.substr(6,2));
dateWithHyphen.insert(4, "-");
dateWithHyphen.insert(7, "-");

return dateWithHyphen;
}
/*void printClass() {
   for (int i=0; i < 4; i++) {
        cout << lIncomes[i].userId << endl;
        cout << lIncomes[i].date << endl;
        cout << lIncomes[i].amount << endl;
    }
}*/
//////////////////

int main()
{
    //void TransactionManager::getBalance(int startDate, int endDate)
//{
    //some local helping variables here
    //vector<Expense> lExpenses {};
   // Income lIncome;
    //vector<Income> lIncomes;
   // double sumExp{0},sumInc{0};
  /*  for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (itr->dayNr >= startDate && itr->dayNr<=endDate &&itr->userId==LOGGED_USER_ID)
        {
            lExpenses.push_back(*itr);
            sumExp+=itr->amount;
        }
    }
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr->dayNr >= startDate && itr->dayNr<=endDate &&itr->userId==LOGGED_USER_ID)
        {
            lIncomes.push_back(*itr);
            sumInc+=itr->amount;
        }
    }*/

/*    lIncome = {1, 20240231, 125};
    lIncomes.push_back(lIncome);

    lIncome = {1, 20200522, 6};
    lIncomes.push_back(lIncome);

    lIncome = {1, 20210508, 386500};
    lIncomes.push_back(lIncome);

    lIncome = {1, 20230508, 8550};
    lIncomes.push_back(lIncome); */

       // printClass();
  /*  for (int i=0; i < 4; i++) {
        cout << lIncomes[i].userId << endl;
        cout << lIncomes[i].date << endl;
        cout << lIncomes[i].amount << endl;
    }
    //sort
    sort(lIncomes.begin(), lIncomes.end(), [](const Income& lhs, const Income& rhs) {
          return lhs.date < rhs.date;
       });

          for (int i=0; i < 4; i++) {
        cout << lIncomes[i].userId << endl;
        cout << lIncomes[i].date << endl;
        cout << lIncomes[i].amount << endl;
    } */

    //////////////////////////////////////////
   /* string enteredStartDate, enteredEndDate;
    cin >> enteredStartDate; cin >> enteredEndDate;

    //enteredStartDate = saveDateWithoutHyphen(enteredStartDate);
    string startDate = (enteredStartDate.substr(0,4) + enteredStartDate.substr(5,2) + "01");
    //string d = (enteredEndDate.substr(4,2));
   // int da = checkNumberOfDaysPerMonth(convertStringToInt(d));
    //string endDate = ((enteredEndDate.substr(0,6) + (convertIntToString(d));
    cout << startDate << endl;

    //enteredEndDate = saveDateWithoutHyphen(enteredEndDate);
    //string lastDayOfMonth = convertIntToString(checkNumberOfDaysPerMonth(getYearFromDate(enteredEndDate),getMonthFromDate(enteredEndDate)));

    string endDate = (enteredEndDate.substr(0,4) + enteredEndDate.substr(5,2) + convertIntToString(checkNumberOfDaysPerMonth(getYearFromDate(enteredEndDate),getMonthFromDate(enteredEndDate))));
    cout << endDate << endl; //yu musi byc funckja, jesli jeden znak to dodaj 0 przed*/


       //printClass();
 //   sort(lExpenses.begin(), lExpenses.end(), [](const Expense& lhs, const Expense& rhs) {
 //            return lhs.dayNr < rhs.dayNr;
 //         });
    //printExpenses(lExpenses);
    //printIncomes(lIncomes);
    //cout<<"Total expenses for selected period: "<<sumExp<<endl;
    //cout<<"Total incomes for selected period: "<<sumInc<<endl;
    //cout<<"Balance for the selected period: "<<sumInc-sumExp<<endl;
//}
 //int date; //double amountDouble;//string date;/*, yearS, monthS, dayS;*/ //int year, month, day, lastDayOfCurrentMonth;

 //cout << "Podaj date w formacie yyyymmdd: " << endl;
//    cin >> date;

//    cout << saveDateWithHyphen(convertIntToString(date)) << endl;



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

//string previousMonth = getPreviousMonthFromDate(getTimeFromSystem());

//cout << previousMonth << endl;
/*string date = getTimeFromSystem();
cout << "Data z systeemu: " << date << endl;
string dateWithoutHyphen = saveDateWithoutHyphen(date);
cout << "Data bez myslinikow" << dateWithoutHyphen << endl;
int dateInt = convertStringToInt(dateWithoutHyphen);
cout << "Data w zmiennej int: " << dateInt << endl;
string dateWithHypen = (saveDateWithHyphen(convertIntToString(dateInt)));
cout << "Data z myslnikami" << dateWithHypen << endl;
    string startDate = (dateWithHypen.substr(0,4) + dateWithHypen.substr(5,2) + "01");
cout << "StartDate" << startDate << endl;*/
///////////////////////////////////
    string currentDate = "";
    cin >> currentDate;

    string previousMonth = getPreviousMonthFromDate(currentDate);
        if (previousMonth=="12") {
                if (currentDate[3]=='0') {
                    currentDate[2]--;
                    currentDate[3]='9';
                }
                else
                currentDate[3]--;
    }
    string startDate = (currentDate.substr(0,4) + previousMonth + "01");//+"01" mozna tez zamienic na wyraz.insert(nrLiniOdKtorejWstawiamy, "co wstawiamy");
    string endDate = (currentDate.substr(0,4) + previousMonth + convertIntToString(checkNumberOfDaysPerMonth(getYearFromDate(currentDate),convertStringToInt(previousMonth))));

    cout << "startDate" << startDate << endl;
    cout << "endDate" << endDate << endl;

    return 0;
}
