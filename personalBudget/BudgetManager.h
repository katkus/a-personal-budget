#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>//?? => do spr czy wszystkie biblioteki są potrzebne
#include <vector>
#include <cstdlib> //windows.h
//#include <sstream>

#include "Earning.h"
#include "FileWithEarning.h"
//#include "CalculationMethods.h"
#include "DateMethods.h"
#include "AuxiliaryMethods.h"
#include "Type.h"
//należy dodać format checking methods, calculation methods; auxiliary methods niby nie... we wcześniejszym projekcie nie było brane pod uwagę...

using namespace std;

class BudgetManager
{
    const int LOGGED_IN_USER_ID;
    vector <Earning> incomes;
    vector <Earning> expenses;
    FileWithEarning incomeFile;
    FileWithEarning expenseFile;
    DateMethods dateMethods;
//    CalculationMethods calculationMethods;


    Earning addEarningDetails(const Type &type);
    char selectOptionFromDateMenu();
    //void wyswietlDaneAdresata(Adresat adresat);
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //int podajIdWybranegoAdresata();
   // char wybierzOpcjeZMenuEdycja();

public:
    BudgetManager (string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
    : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(fileNameWithIncomes), expenseFile(fileNameWithExpenses)
    {
        incomes = incomeFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = expenseFile.loadEarningOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };
    void addIncome();
    void addExpense();
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //int podajIdWybranegoAdresata();
    //void usunAdresata();
    //char wybierzOpcjeZMenuEdycja();
    //void edytujAdresata();
} ;
#endif // BUDGETMANAGER_H

