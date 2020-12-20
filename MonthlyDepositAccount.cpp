#include "MonthlyDepositAccount.h"
#include "Account.h"
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

MonthlyDepositAccount :: MonthlyDepositAccount()                    //constructor
{
    m_openingBalance = 0;
    m_annualInterest = 0;
    m_months = 0;
    m_monthlyDeposit = 0;
};

void MonthlyDepositAccount::setMonthlyDeposit(double t_deposit)     //setter
{
    m_monthlyDeposit = t_deposit;
};

double MonthlyDepositAccount::getMonthlyDeposit()                    //getter
{
    return m_monthlyDeposit;
};

void MonthlyDepositAccount::printProjection()                                      //displays a balance table for the account
{
    unsigned int i = 0;                                                            //declare necessary variables for printing table
    unsigned int j = 0;                                                            //Loop indexes
    double balance = m_openingBalance;                                             //initializes balance to starting balance
    vector<double> interestList(this->getMonths());                                //stores interest earned each month
    vector<double> balanceList(this->getMonths());                                 //stores ending balance each month
    double yearEndInterest = 0;

    cout << "                    Balance and Interest With Additional Monthly Deposits" << endl;                                //display table header
    cout << "======================================================================================================" << endl;
    cout << "Year                                Year End Balance                          Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (i = 0; i < balanceList.size(); ++i)                                                                                    //loop through each month
    {
        interestList.at(i) = ((balance + m_monthlyDeposit) * ((this->getInterest() / 100) / 12));                               //calculate interest earned for the month
        balanceList.at(i) = ((balance + m_monthlyDeposit) * ((this->getInterest() / 100) / 12)) + m_monthlyDeposit + balance;   //calculate new balance
        balance = balanceList.at(i);
    }

    
    std::cout << std::fixed;                                                            //format output
    std::cout << std::setprecision(2);

    for (i = 0; i < balanceList.size(); ++i)                                            //loop through each month
    {
        if ((i + 1) % 12 == 0)                                                          // only execute for each year ending
        {   
            for (j = i - 11; j <= i; ++j)                                               //sum interest earned over past twelve months
            {
                yearEndInterest = yearEndInterest + interestList.at(j);
            }
            std::cout <<std::setfill(' ') << std::setw(4) << std::right << (i / 12) + 1 << std::setw(48) << std::right << balanceList.at(i) << std::setw(50) << std::right << yearEndInterest << endl;  //print one line of the table
            yearEndInterest = 0;
        }
    }
    cout << endl << endl;
}