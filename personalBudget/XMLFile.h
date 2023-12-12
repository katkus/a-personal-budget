#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile
{
    const string FILE_NAME;

public:
    string getFileName();
    static bool isFileEmpty(fstream &XMLFile);

    XMLFile(string nameFile): FILE_NAME (nameFile) {};
};
#endif // XMLFILE_H

