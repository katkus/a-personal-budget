#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XMLFile
{
    CMarkup xml;//nie wiem czy nie powinno to być bezpośrednio w metodach.
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
   User getUserData (string oneUserData);


public:
    FileWithUsers(string fileNameWithUsers) : XMLFile(fileNameWithUsers) {};
    void addUserToFile (User users);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile (vector <User> &users);
};
#endif // FILEWITHUSERS_H
