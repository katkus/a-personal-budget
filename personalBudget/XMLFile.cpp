#include "XMLFile.h"

string XMLFile::getFileName()
{
    return NAME_FILE;
}

bool XMLFile::isFileEmpty(fstream &XMLFile)
{

    XMLFile.seekg(0, ios::end);
    if (XMLFile.tellg() == 0)
        return true;
    else
        return false;
}


