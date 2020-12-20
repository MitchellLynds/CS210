#include "Account.h"
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

Account::Account()                                          //constructor
{
    m_openingBalance = 0;
    m_annualInterest = 0;
    m_months = 0;
}

void Account::setBalance(double t_balance)                  //setter functions
{
    m_openingBalance = t_balance;
}

void Account::setInterest(double t_interest)
{
    m_annualInterest = t_interest;
}

void Account::setMonths(int t_months)
{
    m_months = t_months;
}

double Account::getBalance()                                //getter functions
{
    return m_openingBalance;
}

double Account::getInterest()
{
    return m_annualInterest;
}

int Account::getMonths()
{
    return m_months;
}

void Account::printProjection()                                                     //displays a balance table for the account
{
    unsigned int i = 0;                                                            //declare necessary variables for printing table
    unsigned int j = 0;                                                            //Loop indexes
    double balance = m_openingBalance;                                             //initializes balance to starting balance
    vector<double> interestList(m_months);                                         //stores interest earned each month
    vector<double> balanceList(m_months);                                          //stores ending balance each month
    double yearEndInterest = 0;

    cout << "                    Balance and Interest Without Additional Monthly Deposits" << endl;                           //display table header
    cout << "======================================================================================================" << endl;
    cout << "Year                                Year End Balance                          Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    
    for (i = 0; i < balanceList.size(); ++i)                                            //loop through each month
    {
        interestList.at(i) = ((balance) * ((m_annualInterest / 100) / 12));             //calculate interest earned for the month
        balanceList.at(i) = ((balance) * ((m_annualInterest / 100) / 12)) + balance;    //calculate new balance
        balance = balanceList.at(i);
    }

    std::cout << std::fixed;                                                            //format output
    std::cout << std::setprecision(2);

    for (i = 0; i < balanceList.size(); ++i)                                            //loop through each month
    {
        if ((i +1) % 12 == 0)                                                           //only print for each year ending
        {
            for (j = i - 11; j <= i; ++j)                                               
            {
                yearEndInterest = yearEndInterest + interestList.at(j);                 //sum interest earned in previous 12 months
            }
            std::cout << std::setfill(' ') << std::setw(4) << std::right << (i / 12) + 1 << std::setw(48) << std::right << balanceList.at(i) << std::setw(50) << std::right << yearEndInterest << endl;     //outputs one line of the table
            yearEndInterest = 0;    
        }
    }
    cout << endl << endl;
    return;
}