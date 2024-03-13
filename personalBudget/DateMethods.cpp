#include "DateMethods.h"

string DateMethods::getTimeFromSystem() {
    char bufor [ 64 ];
    time_t timeTakenFromComputer;
    time( & timeTakenFromComputer );
    tm timeTakenFromComputerTM = * localtime( & timeTakenFromComputer );
    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", & timeTakenFromComputerTM );
    string date = bufor;
    return date;
}
int DateMethods::checkNumberOfDaysPerMonth(int currentYear, int currentMonth) {

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
                        if (((currentYear % 4 == 0) && (currentYear % 100 != 0)) || ((currentYear % 400 == 0)))
                        lastDayOfCurrentDay = 29;
                        else lastDayOfCurrentDay = 28;
                        break;
                }

        }
        return lastDayOfCurrentDay;

}

int DateMethods::getYearFromDate(string date) {

int year = AuxiliaryMethods::convertStringToInt((date.substr(0,4)));
return year;

}

int DateMethods::getMonthFromDate(string date) {

int month = AuxiliaryMethods::convertStringToInt((date.substr(5,2)));
return month;

}
int DateMethods::getDayFromDate(string date) {

int day = AuxiliaryMethods::convertStringToInt((date.substr(8,2)));
return day;
}

bool DateMethods::checkFormatDateIsCorrect(string date) {

if ((date[4]=='-') && (date[7]=='-') && date.size()==10) {
    int year, month, day, lastDayOfMonth, currentYear, currentMonth; string currentDate;

    year = getYearFromDate(date);
    day = getDayFromDate(date);
    month = getMonthFromDate(date);

    currentDate = getTimeFromSystem();
    currentYear = getYearFromDate(currentDate);
    currentMonth = getMonthFromDate(currentDate);
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
/*int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
string AuxiliaryMethods::loadLine()
{
    string entry = "";
    cin.sync();
    getline(cin, entry);
    return entry;
}*/
/*
string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
char AuxiliaryMethods::loadCharacter()
{
    string entrance = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            character = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}*/
/*
string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
*/

