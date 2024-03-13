#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxiliaryMethods::convertStringToDouble(string amount) {
 double amountDouble = atof(amount.c_str());
 return amountDouble;
}

string AuxiliaryMethods::loadLine()
{
    string entry = "";
    cin.sync();
    getline(cin, entry);
    return entry;
}
/*
string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}*/
char AuxiliaryMethods::loadCharacter()
{
    string entrance = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            character = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
string AuxiliaryMethods::saveDateWithoutHyphen (string date) {

string dateWithoutHyphen = (date.substr(0,4)) + (date.substr(5,2)) + (date.substr(8,2));

return dateWithoutHyphen;
}
string AuxiliaryMethods::saveDateWithHyphen (string date) {

string dateWithHyphen = (date.substr(0,4)) + (date.substr(4,2)) + (date.substr(6,2));
dateWithHyphen.insert(4, "-");
dateWithHyphen.insert(7, "-");

return dateWithHyphen;
}

string AuxiliaryMethods::replaceCommaToDot (string amount) {
int sizeOfAmount = amount.size();
cout << "sizeOfAmount:" << sizeOfAmount << endl;
    for (int i = 0; i < sizeOfAmount; i++) { // rzutowanie typu?? (int) przy amount.length()

        if ((amount[i] == ',')||(amount[i]== '.')) {
            amount[i] = '.';
            if (sizeOfAmount > i+3) {
                    //int l = sizeOfAmount-i-3;
                    if (amount[i+2]>4)
                        amount[i+2]++;
                amount.erase(i+3, sizeOfAmount-i-3);
                break;
            }
        }
       // if (amount[i] == '.') {
         //   if (sizeOfAmount > i+3) {
           //     amount.erase(i+3, sizeOfAmount-i-3);
        //}

        //}
    }

    return amount;
}
/*
string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
*/
