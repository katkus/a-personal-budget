#include <iostream>
#include <vector>
#include <ctime>
#include "Markup.h"

using namespace std;
class Uzytkownik {
    int id;
    string login;
    string haslo;

public:
    void ustawId (int noweId) {
        if (noweId >= 0)
            id = noweId;
    }
    void ustawLogin (string nowyLogin) {
        login = nowyLogin;
    }
    void ustawHaslo (string noweHaslo) {
        haslo = noweHaslo;
    }

    int pobierzId () {
        return id;
    }
    string pobierzLogin () {
        return login;
    }
    string pobierzHaslo () {
        return haslo;
    }

};

void wypiszWszystkichUzytkownikow(vector <Uzytkownik> &uzytkownicy) {
    for (int i = 0; i < (int) uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;

    }
    system("read");
}

class Test {
    string data;
    float kwota;

public:
    void ustawData (string noweData) {
        data = noweData;
    }
    void ustawKwota (float nowaKwota) {
        if (nowaKwota >= 0)
            kwota = nowaKwota;
    }
    string pobierzData () {
        return data;
    }
    float pobierzKwota () {
        return kwota;
    }

};

void wypiszDane(vector <Test> &testy) {
    for (int i = 0; i < (int) testy.size(); i++) {
        cout << testy[i].pobierzData() << endl;
        cout << testy[i].pobierzKwota() << endl;

    }
    system("read");
}


int _main() {
    string imie, password;
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    //wprowadzenie danych
    /*
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", "2");
        xml.AddElem("Login", "jarek");
        xml.AddElem("Password", "789");

        xml.Save("users.xml");
    */
    //xml.ResetPos();
    /*    xml.FindElem();
        xml.IntoElem();
       cout << "Podaj imie: " << endl;
       cin >> imie;
       cout << "Podaj haslo: " << endl;
       cin >> password;

        while ( xml.FindElem()) {
            cout << "test" << endl;
            system("read");

            if(xml.FindChildElem("Login")) {

                //}
                MCD_STR strSN = xml.GetChildData();
                cout << "test" << endl;
                cout << strSN << endl;
                system("read");
                if ( xml.GetChildData() == imie) {
                    cout << "test" << endl;
                    system("read");

                    xml.FindChildElem("Password");
                    cout << "test" << endl;
                    system("read");

                    if ( xml.GetChildData() == password) {
                        cout << "Zalogowales sie!" << endl;
                        system("read");
                    }
                }
            } else
                xml.FindChildElem();

        }*/
    //zmiana hasla
    /*     xml.FindElem();
       xml.IntoElem();
      cout << "Podaj nowe haslo: " << endl;
      cin >> password;

       while ( xml.FindElem()) {
           cout << "test" << endl;
           system("read");

           if(xml.FindChildElem("Login")) {

               //}
               MCD_STR strSN = xml.GetChildData();
               cout << "test" << endl;
               cout << strSN << endl;
               system("read");
               if ( xml.GetChildData() == "jarek") {
                   cout << "test" << endl;
                   system("read");

                   xml.FindChildElem("Password");
                   cout << "test" << endl;
                   system("read");

                   xml.SetChildData(password);
                   //if ( xml.GetChildData() == password) {
                       cout << "Haslo zostalo zmienione." << endl;
                       cout << password<< endl;
                       xml.Save("users.xml");
                       system("read");
           //        }
               }
           } else
               xml.FindChildElem();
    */
//usuwanie uzytkownika
    /*   xml.FindElem();
      xml.IntoElem();
     cout << "Podaj uzytkownika, ktorego chcesz usunac: " << endl;
     cin >> imie;

      while ( xml.FindElem()) {
          cout << "test" << endl;
          system("read");

          if(xml.FindChildElem("Login")) {

              MCD_STR strSN = xml.GetChildData();
              cout << "test" << endl;
              cout << strSN << endl;
              system("read");
              if ( xml.GetChildData() == imie) {
                  system("read");

                  xml.RemoveElem();
                      xml.Save("users.xml");
              }
          } else
              xml.FindChildElem();

      }
    */
//załadowanie wszystkich użytkowników do obiektu
    /*
    class Uzytkownik
    {
        int id;
        string login;
        string haslo;

    public:
        void ustawId (int noweId);
        void ustawLogin (string nowyLogin);
        void ustawHaslo (string noweHaslo);

        int pobierzId ();
        string pobierzLogin ();
        string pobierzHaslo ();

        void wypiszWszystkichUzytkownikow();

    };
    void ustawId (int noweId)
    {
        if (noweId >= 0)
            id = noweId;
    }
    void ustawLogin (string nowyLogin)
    {
        login = nowyLogin;
    }
    void ustawHaslo (string noweHaslo)
    {
        haslo = noweHaslo;
    }
    int pobierzId ()
    {
        return id;
    }
    string pobierzLogin ()
    {
        return login;
    }
    string pobierzHaslo ()
    {
        return haslo;
    }
     void wypiszWszystkichUzytkownikow()
     {
        for (int i = 0; i < (int) uzytkownicy.size(); i++)
        {
            cout << uzytkownicy[i].pobierzId() << endl;
            cout << uzytkownicy[i].pobierzLogin() << endl;
            cout << uzytkownicy[i].pobierzHaslo() << endl;

        }
     }
    */
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));
            uzytkownik.ustawId(userId);
            xml.FindChildElem("Login");
            MCD_STR name = xml.GetChildData();
            uzytkownik.ustawLogin(name);
            xml.FindChildElem("Password");
            MCD_STR password = xml.GetChildData();
            uzytkownik.ustawHaslo(password);

            uzytkownicy.push_back(uzytkownik);


        }
        wypiszWszystkichUzytkownikow(uzytkownicy);
    }
    xml.OutOfElem();

    return 0;
}

int main() {
    Test test;
    vector <Test> testy;
    CMarkup xml;

    bool fileExists = xml.Load( "dataKwota.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Budzet");
        xml.IntoElem();
        xml.AddElem("Jarek");
        xml.IntoElem();
        xml.AddElem("Data", "2020-10-18");
        xml.AddElem("Kwota", "2.99");
        xml.OutOfElem();
        xml.AddElem("Jarek");
        xml.IntoElem();
        xml.AddElem("Data", "2020-10-17");
        xml.AddElem("Kwota", "1.99");

        xml.Save("dataKwota.xml");
    }

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Jarek")) {

            xml.FindChildElem("Data");
            MCD_STR data = xml.GetChildData();
            test.ustawData(data);
            xml.FindChildElem("Kwota");
            float przejscie = atof( MCD_2PCSZ(xml.GetChildData()));
            test.ustawKwota(przejscie);


            testy.push_back(test);
        }

        wypiszDane(testy);
    }

    return 0;
}
