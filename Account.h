#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;


class Account                           //Class declaration
{
private:                                //private attributes
    double m_openingBalance;
    double m_annualInterest;
    int m_months;

public:                                 //Public member functions
    Account();

    void setBalance(double balance);
    void setInterest(double interest);
    void setMonths(int months);

    double getBalance();
    double getInterest();
    int getMonths();

    void printProjection();
};

#endif