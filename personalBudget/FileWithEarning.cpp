#include "FileWithEarning.h"

/*int FileWithEarning::setLastEarningId(int NewLastEarningId)
{
    lastId = NewLastEarningId;
}*/
/*string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId())+ '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}*/
bool FileWithEarning::addEarningToFile(Earning &earning, const Type &type)//=>do uzupelnienia (Adresat adresat) u prowadzacego jest (const Operation &operation) czy na pewno musi byc const??
{
    bool fileExists = xml.Load(getFileName());

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        //xml.AddElem("Earnings"); //Do zastanowienia sie czy nie powinnismi dodac gdzies info, że to są przychody lub wydatki; zostawiam do uzupelnienia;

        /////////////////////////////////////
        switch(type){

    case INCOME:
        xml.AddElem("Incomes");
        //earning.setEarningId((incomeFile.getLastId()+1)); //earning.setEarningId((incomeFile.getLastEarningId()+1));
        //typeDescritpion = "przychod";
        break;
    case EXPENSE:
        xml.AddElem("Expenses");
        //earning.setEarningId((expenseFile.getLastId()+1));
        //typeDescritpion = "wydatek";
        break;

    }
    ////////////////////////
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Earning");
    xml.IntoElem();
    xml.AddElem("EarningId", earning.getEarningId());
    xml.AddElem("UserId", earning.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::saveDateWithHyphen(AuxiliaryMethods::convertIntToString(earning.getDate()))); /////////////zamiania amount na string, zeby . sie dobrze przekonwertowala// tu zmiana z int na string z - //=>do spr czy to dziala
    ////////////////////////////////////
    //earning.setDate(AuxiliaryMethods.convertStringToInt(AuxiliaryMethods.saveDateWithoutHyphen(date)); //do spr czy dziala
    /////////////////////////
    xml.AddElem("Item", earning.getItem());
    xml.AddElem("Amount", earning.getAmount()); //wydaje mi sie, ze amount trzeba bedzie zmienic na string, bo ma kropke. Nie wiem czy to mnie jest znak szczegolny w plikach XML;ewentualnie do spr podczas testow...

    if (xml.Save(getFileName())) {
        cout << "Wartosc dodana do pliku." << endl;
        lastId++; //setLastId(earning.getId());
    }
    else {
        cout << "Nie udalo sie dodac wartosci do pliku." << endl;
    }
    xml.OutOfElem();
 }  // setLastId(user.getId());
/*string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) =>to chyba jednak zniknie...
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;*/
//} //// zapis daty z myslnikiem i przeksztalcenie jako string...

/*int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    return idUzytkownika;
}
int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                {adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;}
            case 2:
                {adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;}
            case 3:
                {adresat.ustawImie(pojedynczaDanaAdresata);
                break;}
            case 4:
                {adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;}
            case 5:
                {adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;}
            case 6:
                {adresat.ustawEmail(pojedynczaDanaAdresata);
                break;}
            case 7:
                {adresat.ustawAdres(pojedynczaDanaAdresata);
                break;}
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
     return adresat;
}*/
vector <Earning> FileWithEarning::loadEarningOfLoggedInUserFromFile(int loggedInUserId) //do zrobienia
{
/*    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
    ////////////////////////////////*/
    Earning earning;//User user;
    vector <Earning> earnings;

   bool fileExists = xml.Load(getFileName());

       if (fileExists) {
            xml.ResetPos();
            xml.FindElem();
            xml.IntoElem();

        while (xml.FindElem("Earning")) { //do usuniecia atoi
            xml.FindChildElem("EarningId");
            int earningId = atoi( MCD_2PCSZ(xml.GetChildData()));  //do sprawdzenia czy nei mozna tego przeksztalcic do int userId = AuxiliaryMethods::convertStringToInt(MCD_2PCSZ(xml.GetChildData()));
            //earning.setEarningId(earningId);
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));//do sprawdzenia czy nei mozna tego przeksztalcic do int userId = AuxiliaryMethods::convertStringToInt(MCD_2PCSZ(xml.GetChildData()));
            if (userId == loggedInUserId) {
                earning.setEarningId(earningId);
                earning.setUserId(userId);

            xml.FindChildElem("Date");
            MCD_STR date = xml.GetChildData();
            earning.setDate(AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::saveDateWithoutHyphen(date))); //earning.setFirstName(date)
            xml.FindChildElem("Item");
            MCD_STR item = xml.GetChildData();
            earning.setItem(item);
            xml.FindChildElem("Amount");
            MCD_STR amount = xml.GetChildData();
            earning.setAmount(amount);//(AuxiliaryMethods::convertStringToDouble(amount));// earning.setAmount(amount);

            earnings.push_back(earning);
            }
        }
        xml.OutOfElem();
        lastId = earning.getEarningId();// ewentualnie sprobowac setLastId(user.getId())
    }
    else
        cout << "Nie mozna otworzyc pliku." << endl;
    //lastId = userId;//setLastId(user.getId());
    return earnings;
}
//}

/*void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami= "PlikTymczasowy.txt";
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int numerUsuwanejLinii = 0;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii

  if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                numerUsuwanejLinii = numerWczytanejLinii;
            }


            if (numerWczytanejLinii == numerUsuwanejLinii) {}

            else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            numerWczytanejLinii++;
            idOstatniegoAdresata=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }

}

void PlikZAdresatami::edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string nazwaTymczasowegoPlikuZAdresatami= "PlikTymczasowy.txt";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idEdytowanegoAdresata != 0)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {

            if (idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(adresat.pobierzId(), liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}*/





