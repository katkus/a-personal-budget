#include "FormatCheckingData.h"

bool FormatCheckingData::checkFormatDateIsCorrect(int data)
//=>przejrzec projekt Marka. Nie ma klasy na date; data zapisana jest int w calosci. W jednej metodzie podzielona jest na poszczegolne zmienne i spr. Nie jest to takie trudne. Do zmiany projekt.
{
    //checkFormatDateIsCorrect powinno zawierac:
    //-czy najpierw data zapisana jest z mysliniem -> rrrr-mm-dd
    //-czy pierwszy to rok rowny lub wiekszy od 2000 i mniejszy od ostatniego dnia danego miesiaca z biezacego roku => nalezy pobrac date z systemu i spr jaki jest ostatni dzien danego miesiaca =>nalezy uzyc funkcji pobrania daty z systemu; do przerobienia obecna funkcja pobrania  daty z systemu na dodanie jej do klasy odnosnie czasu;
    //-czy kolejny jest miesiac mieszczacy sie w przedziale 01 do 12
    //-czy kolejny to dzien mieszczacy sie w przedziale 01-31 i czy w zaleznosci od miesiaca zgodny jest z rozpisaka styczen 31, luty w zaleznosci od roku 28 lub 29 dni itd. Wziac pod uwagę rok przestępny.
    //-czy znajduje się w przedziale 2000-01-01 do ostatniego dnia danego miesiaca (pobranie daty z systemu i spr jaki jest ostatni dzien danego miesiaca)=> funkcja pobrania daty z systemu powinna być w klasie ogolnej odnosnie dat=> do poprawy
    //-
    /*
    Przykładowo.

Użytkownik wprowadza datę w takiej postaci: 2018-01-01. Jest ona typu string. Należy ją rozdzielić na pojedyncze zmienne i sprawdzić po kolei czy data jest prawidłowa.

Jeżeli data jest prawidłowa, to nasza propozycja jest taka, aby przekonwertować ją do takiej postaci: 20180101 (czyli dodać do siebie rozdzielone zmienne z daty rok, miesiąc i dzień, które są typu string) a następnie zmienną typu string date = " 20180101 " przekonwertować do typu int i zapisać do odpowiedniego pola. Dzięki temu będziesz mógł sortować vector w oparciu o te pole oraz porównywać ze sobą daty. Należy tutaj pamiętać o uwzględnieniu zera przed cyframi (1-9, dzień lub miesiąc), aby data miała prawidłowy format rrrrmmdd.

Stosując ten sposób należy stworzyć dodatkową metodę, która będzie odpowiedzialna za konwersję z typu int na string (z uwzględnieniem znaku '-'). Szczególnie jest to ważne przy zapisie danych do pliku, ponieważ data ma być zapisywana w takiej postaci: "2018-02-27".

Więcej informacji o tym jak sortować wektor zawierający obiekty znajdziesz w Internecie po wpisaniu np. sort vector c++
*/


    if (idZalogowanegoUzytkownika > 0)///tu powinny być do spr wszystkiem metody odnośnie roku, miesiaca, dnia i spr czy mieszcza sie w przedziale od roku 2000-01-01 do maksymalnie ostatniego dnia bieżącego miesiąca
        return true;
    else
        return false;
}
/*int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}*/
/*string AuxiliaryMethods::loadLine()
{
    string entry = "";
    cin.sync();
    getline(cin, entry);
    return entry;
}*/
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
/*char AuxiliaryMethods::loadCharacter()
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
}*/
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

