#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>//?biblioteka sluzaca do konwersji string na int itd.Do spr czy potrzebna.
#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <clocale>
#include <string>
#include <algorithm>

#include "AuxiliaryMethods.h"

using namespace std;

class DateMethods
{
private:
    int checkNumberOfDaysPerMonth (int currentYear, int currentMonth);

public:
    //string konwerjsaIntNaString(int liczba);
    //int konwersjaStringNaInt(string liczba);
    string getTimeFromSystem(); // w praniu wyjdzie czy musi byc static czy nie musi...
    bool checkFormatDateIsCorrect(string date);
    int getYearFromDate (string date);
    int getMonthFromDate (string date);
    int getDayFromDate (string date);
    //string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    //char loadCharacter();
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //int wczytajLiczbeCalkowita();
};
#endif // DATEMETHODS_H

