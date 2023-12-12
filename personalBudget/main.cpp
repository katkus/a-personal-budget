#include <iostream>

#include "PersonalBudget.h"

using namespace std;
/*
int _Main()
{
   PersonalBudget personalBudget ("users.xml", "incomes.txml", "expenses.xml");

  char choice;

    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("read"); // Windows system("pause")
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromBudgetMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthsBalanceSheet();
                break;
            case '4':
                personalBudget.displayPreviousMonthsBalanceSheet();
                break;
            case '5':
                personalBudget.displayBalanceSheetFromSelectedTimePeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }
    }
        return 0;
}*/

//#include "PersonalBudget.h"
#include "UserManager.h" //=> to do testowania
#include "User.h"
#include "FileWithUsers.h"

int main()
{
 //       PlikZAdresatami plikZAdresatami();
        //AdresatMenedzer adresatMenedzer("AdresaciTest.txt",1);
        UserManager userManager("users.xml");
        FileWithUsers fileWithUsers();
        //vector <Adresat> adresaci;
//        AdresatMenedzer adresatMenedzer;

//        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
       // adresatMenedzer.wyszukajAdresatowPoImieniu();
        //adresatMenedzer.wyszukajAdresatowPoNazwisku();
        //adresatMenedzer.wyswietlWszystkichAdresatow();
        //adresatMenedzer.edytujAdresata();
        //adresatMenedzer.usunAdresata();
        //adresatMenedzer.wyswietlWszystkichAdresatow();

        //userManager.registerUser();//("Kasia", "Kuswik", "kaku", "Slonce123");
        //userManager.loginUser();
        userManager.logoutUser();
       // cout << user << endl;//nie wiem czy nie powinno byc cos innego;

    return 0;
}
