#include "XMLFile.h"

string XMLFile::getFileName()
{
    return FILE_NAME;
}

bool XMLFile::isFileEmpty(fstream &XMLFile)
{
    XMLFile.seekg(0, ios::end);
    if (XMLFile.tellg() == 0)
        return true;
    else
        return false;
}
int XMLFile::setLastId (int id) { //do spr czy dziala
lastId = id;
return lastId;
}

int XMLFile::getLastId()
{
    return lastId;
}


