#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    fstream XMLFile;
    string lineWithUserData = "";
    XMLFile.open(getFileName().c_str(), ios::app);

    if (XMLFile.good() == true)
    {
        lineWithUserData = //pobierzDane??//zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

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
    XMLFile.close();
}

/*string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
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
   fstream XMLFile;
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
    XMLFile.close();
    return users;
}
User FileWithUsers::getUserData (string oneUserData)//(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
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
                user.setLogin(singleUserData);
                break;
                }
            case 3:
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
}
void FileWithUsers::saveAllUsersToFile(vector <User> &users)
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
}

