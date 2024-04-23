#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string amount);
    static string loadLine();
    static char loadCharacter();
    static string changeDateWithHypenToDateWithoutHyphen(string date);
    static string changeDateWithoutHypenToDateWithHyphen(string date);
    static string saveDateWithHyphen(string date);
    static string replaceCommaToDot (string amount);
};
#endif // AUXILIARYMETHODS_H
