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

using namespace std;

class FileWithEarning : public XMLFile
{
  // int lastEarningId; //lastId jest w pliku File i getLastId; do napisania metodana setLast Id;=> tak jest zrobione w Users;

   //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
   //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
   //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
   //Adresat pobierzDaneAdresata(string AdresataOddzielonePionowymiKreskami);
   //void usunPlik(string nazwaPlikuZRozszerzeniem);
   //void zmienNazwePliku(string staraNazwa, string nowaNazwa);
   //void edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);


public:
    FileWithEarning(string fileName) : XMLFile(fileName) { };
    //int setLastEarningId(int newLastEarningId); //do spr czy nie wystarczy w pliku XML i dziedziczenie po nim...
    bool addEarningToFile(Earning &earning, const Type &type);
    vector <Earning> loadEarningOfLoggedInUserFromFile(int loggedInUserId);
   // void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    //void zaktualizujDaneWybranegoAdresata(Adresat adresat);
};
#endif // FILEWITHEARNING_H
