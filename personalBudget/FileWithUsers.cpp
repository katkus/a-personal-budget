#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    /*fstream XMLFile;
    string lineWithUserData = "";
    XMLFile.open(getFileName().c_str(), ios::app);

    if (XMLFile.good() == true)
    {
        lineWithUserData = //pobierzDane?? cos trzeba bedzie wpisac...//zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);=>to chyba jednak zniknie...chyba, że sposób zapisu z XML? Do przemyślenia.

        if (isFileEmpty(XMLFile) == true)
        {
            XMLFile << lineWithUserData;
        }
        else
        {
            XMLFile << endl << lineWithUserData;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    XMLFile.close();*/
    //CMarkup xml;
    bool fileExists = xml.Load("users.xml"); // nie wiem czy to nie powinno być w konstruktorze

    if (!fileExists){

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName",user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml");
}

/*string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) =>to chyba jednak zniknie...
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}*/
vector <User> FileWithUsers::loadUsersFromFile()
{
   User user;
   vector <User> users;

   bool fileExists = xml.Load("users.xml");

       if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));
            user.setId(userId);
            xml.FindChildElem("FirstName");
            MCD_STR firstName = xml.GetChildData();
            user.setFirstName(firstName);
            xml.FindChildElem("LastName");
            MCD_STR lastName = xml.GetChildData();
            user.setLastName(lastName);
            xml.FindChildElem("Login");
            MCD_STR login = xml.GetChildData();
            user.setLogin(login);
            xml.FindChildElem("Password");
            MCD_STR password = xml.GetChildData();
            user.setPassword(password);

            users.push_back(user);

        }
    //    wypiszWszystkichUzytkownikow(uzytkownicy);
    }
  /* fstream XMLFile;
   string oneUserData="";//daneJednegoUzytkownikaOddzielonePionowymiKreskami="";

    XMLFile.open(getFileName().c_str(), ios::in);

    if (XMLFile.good() == true)
    {
        while (getline(XMLFile, oneUserData))
        {
            user = getUserData(oneUserData);//pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            users.push_back(user);
        }
    }
    XMLFile.close();*/
    return users;
}
/*User FileWithUsers::getUserData (string oneUserData)//(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    User user;
    string singleUserData ="";
    int singleUserDataNumber =1;
    for (size_t characterPosition = 0; characterPosition < oneUserData.length(); characterPosition++)
    {
        if (oneUserData[characterPosition] != '|')
        {
            singleUserData += oneUserData [characterPosition];
        }
        else
        {
            switch(singleUserDataNumber)
            {
            case 1:
                {
                user.setId (atoi(singleUserData.c_str()));
                break;
                }
            case 2:
               {
                user.setFirstName(singleUserData);
                break;
                }
            case 3:
                {
                user.setLastName(singleUserData);
                break;
                }
            case 4:
               {
                user.setLogin(singleUserData);
                break;
                }
            case 5:
                {
                user.setPassword(singleUserData);
                break;
                }
            }
            singleUserData = "";
            singleUserDataNumber++;

        }
    }
    return user;
}*/
/*void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    fstream XMLFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out);

    if (XMLFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithUserData = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr); //pobierzDane??//zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << pobierzNazwePliku() << endl;
    }
    plikTekstowy.close();
}*/

