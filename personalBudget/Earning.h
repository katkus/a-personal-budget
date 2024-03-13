#ifndef EARNING_H
#define EARNING_H

#include <iostream>

using namespace std;

class Earning
{
    int earningId, userId, date;
    string item;
    string amount; //double

public:
    Earning (int earningId = 0, int userId = 0, int date = 0, string item = "", string amount = "0.0")
    {
        this->earningId = earningId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setEarningId (int newEarningId);
    void setUserId (int newUserId);
    void setDate (int newDate);
    void setItem (string newItem);
    void setAmount (string newAmount);

    int getEarningId ();
    int getUserId ();
    int getDate ();
    string getItem ();
    string getAmount ();


};
#endif // EARNING_H

