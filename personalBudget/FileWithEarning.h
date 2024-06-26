#ifndef FILEWITHEARNING_H
#define FILEWITHEARNING_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Earning.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "DateMethods.h"
#include "Type.h"
#include "XMLFile.h"

using namespace std;

class FileWithEarning : public XMLFile {
public:
    FileWithEarning(string fileName) : XMLFile(fileName) { };
    bool addEarningToFile(Earning &earning, const Type &type);
    vector <Earning> loadEarningOfLoggedInUserFromFile(int loggedInUserId);
};
#endif // FILEWITHEARNING_H
