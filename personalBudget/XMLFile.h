#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

#include "Markup.h"

using namespace std;

class XMLFile
{
private:
    const string FILE_NAME;

protected:
    int lastId;
    CMarkup xml;
    //mozna dodac int last id; i getLastId(); beda to dziedziczyc wszytskie klasy; do ulepszenia kodu jak juz bedzie wszytsko dzialalo

    string getFileName();
    static bool isFileEmpty(fstream &XMLFile);

    XMLFile(string fileName): FILE_NAME (fileName) { lastId = 0; };
public:
    int setLastId(int id);
    int getLastId();
};
#endif // XMLFILE_H

