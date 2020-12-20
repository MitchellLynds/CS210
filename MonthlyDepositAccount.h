#pragma once
#include "Account.h"

class MonthlyDepositAccount : public Account                // Derived from Account
{                                                       
private:                                                    //private attributes
    double m_openingBalance;
    double m_annualInterest;
    int m_months;
    double m_monthlyDeposit;

public:                                                     //public member functions
    MonthlyDepositAccount();
    
    double getMonthlyDeposit();

    void setMonthlyDeposit(double deposit);

    void printProjection();
};
