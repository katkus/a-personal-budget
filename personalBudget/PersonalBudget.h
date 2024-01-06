#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <string>

#include "UserManager.h"
//#include "AdresatMenedzer.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    //BudgetManager *budgetManager;
    //const string FILE_NAME_WITH_EARNING;


public:
    PersonalBudget(string fileNameWithUsers)//, string fileNameWithEarning)
    : userManager(fileNameWithUsers)//, FILE_NAME_WITH_EARNING(fileNameWithEarning)//nie wiem czy tu nie powinno być rozdzielenie na incomes i expenses??
    {
       // budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        //delete budgetManager;
        //budgetManager = NULL;
    };
    void registerUser();
    void loginUser();
    void logoutUser();
    void changePassword();
    //void addIncome();
    //void addExpense();
   // void displayCurrentMonthsBalanceSheet();
    //void displayPreviousMonthsBalanceSheet();
   // void displayBalanceSheetFromSelectedTimePeriod();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromBudgetMenu();
};
#endif // PERSONALBUDGET_
