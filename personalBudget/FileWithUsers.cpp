#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    bool fileExists = xml.Load(getFileName());

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

    xml.Save(getFileName());

/*string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) =>to chyba jednak zniknie...
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;*/
}
vector <User> FileWithUsers::loadUsersFromFile()
{
   User user;
   vector <User> users;

   bool fileExists = xml.Load(getFileName());

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
    }
    return users;
}

void FileWithUsers::saveChangedPassword(User user)//, string newPassword, int loggedInUserId)
//void FileWithUsers::saveChangedPassword(vector <User> &users, string newPassword, int loggedInUserId) // =>zapis danych po zmianie hasla; wyszukałabym uytkownika o podanym iD i mu zmieniła hasło. Czy tak można??
{//.saveChangePassword(vector <User> &users, string newPassword, int loggedInUserId)
    /*fstream XMLFile;
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
    plikTekstowy.close();*/

   bool fileExists = xml.Load(getFileName());// bool fileExists = xml.Load("users.xml");

       if (fileExists) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.FindChildElem("UserId");
            int userId = atoi( MCD_2PCSZ(xml.GetChildData()));
            if (userId == user.getId())/*loggedInUserId*/ {//if (userId == loggedInUserId)
                xml.FindChildElem("Password");
                xml.SetChildData(user.getPassword());
            }

       xml.Save(getFileName());// xml.Save("users.xml");

        }
}
}

