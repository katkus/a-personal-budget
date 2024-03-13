#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    Earning income;//Adresat adresat;

    system("clear");//Windows system("cls")
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    /*Earning */income = addEarningDetails(INCOME);//adresat = podajDaneNowegoAdresata();

    incomes.push_back(income); // last earning id++ set last earning id set ( get last earning id - incomes). => to do wyliczenia w pliku last earning id
    if(incomeFile.addEarningToFile(income,INCOME) == true) { //incomeFile =>do napisania ta funkcja...............!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        cout << "Nowy przychod zostal dodany do pliku." << endl;
        //incomeFile.setLastEarningId(incomeFile.getLastId());
        }
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("read"); // Windows system("pause")
    //skonczone, ale trzeba jeszcze napsiac metode na zaladowanie pozostalych danych z pliku, zastanowic sie czy nei mozna dodac do pliku nazwy przychod, wydatek => cos z ENUM i trzeba ejszcze napisac metode na ladowanie danych z pliku;
}
void BudgetManager::addExpense()
{
    Earning expense;//Adresat adresat;

    system("clear");//Windows system("cls")
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    /*Earning*/ expense = addEarningDetails(EXPENSE);//adresat = podajDaneNowegoAdresata();

    incomes.push_back(expense); // last earning id++ set last earning id set ( get last earning id - incomes). => to do wyliczenia w pliku last earning id
    if(expenseFile.addEarningToFile(expense, EXPENSE) == true) { //incomeFile =>do napisania ta funkcja...............!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        cout << "Nowy przychod zostal dodany do pliku." << endl;
        //incomeFile.setLastEarningId(incomeFile.getLastId());
        }
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("read"); // Windows system("pause")
    //skonczone, ale trzeba jeszcze napsiac metode na zaladowanie pozostalych danych z pliku, zastanowic sie czy nei mozna dodac do pliku nazwy przychod, wydatek => cos z ENUM i trzeba ejszcze napisac metode na ladowanie danych z pliku;
}
Earning BudgetManager::addEarningDetails(const Type &type)
{
    Earning earning;//Adresat adresat;
    string typeDescritpion, date; char choice; //int earningId, userId; string item, typeDescritpion, date, amount; char choice;

    switch(type){

    case INCOME:
        earning.setEarningId((incomeFile.getLastId()+1)); //earning.setEarningId((incomeFile.getLastEarningId()+1));
        typeDescritpion = "przychod";
        break;
    case EXPENSE:
        earning.setEarningId((expenseFile.getLastId()+1));
        typeDescritpion = "wydatek";
        break;

    }

    earning.setUserId(LOGGED_IN_USER_ID);

    choice = selectOptionFromDateMenu();

    switch (choice) {

    case '1':
        date = dateMethods.getTimeFromSystem();
        break;
    case '2':
        do {
            system("clear");//Windows system("cls")
            cout << "Prosze o wpisanie daty w formacie rrrr-mm-dd. Zostanie dodany " << typeDescritpion << " do Budzetu. Data musi miescic się w zakresie czasowym od 2000-01-01 do maksymalnie ostatniego dnia biezacego miesiaca." << endl << endl;
            date = AuxiliaryMethods::loadLine();
            if (dateMethods.checkFormatDateIsCorrect(date) == false)
                cout << "Niepoprawny format daty lub niepoprawnie podany zakres czasowy." << endl;
        }
        while (dateMethods.checkFormatDateIsCorrect(date)== false);
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("read"); // Windows system("pause")
        break;
    }

//item => Prosze wpisac opis transakcji. Nie wiem jak to wpisac do pliku

    earning.setDate(AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::saveDateWithoutHyphen(date))); //do spr czy dziala

    system("clear");//Windows system("cls")
    cout << " Prosze o wpisanie czego dotyczy " << typeDescritpion << ": " << endl << endl;
    //item = AuxiliaryMethods.loadLine();
    earning.setItem(AuxiliaryMethods::loadLine());

    cout << " Prosze o wpisanie wielkosci z dokladnoscia do dwoch miejsc dziesietnych: " << typeDescritpion << " w zlotych: " << endl << endl;
    earning.setAmount/*(AuxiliaryMethods::convertStringToDouble*/(AuxiliaryMethods::replaceCommaToDot(AuxiliaryMethods::loadLine()));//);
    //powinno byc ok...
    cout << earning.getAmount() << " wpisana wielkosc " << endl;

    return earning;
}
char BudgetManager::selectOptionFromDateMenu()
{
    char choice;

    cout << "Dotyczy dnia dzisiejszego czy chcesz dodac z inna data? " << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Inna data" << endl;
    cout << "9 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
/*void BudgetManager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu()<< endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}*/
/*void BudgetManager::wyswietlWszystkichAdresatow()
{
    system("clear");//Windows system("cls")
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("read"); // Windows system("pause")
}*/

/*void BudgetManager::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}*/

/*void BudgetManager::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("clear");//Windows system("cls")
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (int i=0; i < (int) adresaci.size(); i++)
        {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("read"); // Windows system("pause")
}*/

/*void BudgetManager::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("clear");//Windows system("cls")
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (int i = 0; i < (int) adresaci.size(); i++)
        {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("read"); // Windows system("pause")
}*/

/*int BudgetManager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}*/

/*void BudgetManager::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    system("clear");//Windows system("cls")
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("read"); // Windows system("pause")
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("read"); // Windows system("pause")
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("read"); // Windows system("pause")
    }
}*/

/*char BudgetManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}*/

/*void BudgetManager::edytujAdresata()
{
    system("clear");//Windows system("cls")
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < (int) adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("read"); // Windows system("pause")
}*/





