#include <iostream>
#include <iomanip>
#include "Account.h"
#include "MonthlyDepositAccount.h"
using namespace std;



void displayMenu();																	//declaration for menu display function

int main() 
{
	double initialInvestment;														//attribute holders
	double monthlyDeposit;
	double annualInterest;
	double numYears;
	double userInput;																//user input holder
	int menuOption = 0;																//user input holder

	cout << std::setfill('*') << std::setw(30) << " " << endl;															//displays data entry header
	cout << std::setfill('*') << std::setw(21) << " Data Input " << std::setfill('*') << std::setw(9) << " " << endl;
	try
	{
		cout << "Initial Investment Amount: " << endl;							//prompts for and recieves initial attribute with error checking
		cin >> initialInvestment;
		if (initialInvestment < 0)
		{
			throw runtime_error("Invalid initial investment.");
		}
		cout << "Monthly Deposit: " << endl;									//prompts for and recieves initial attribute with error checking
		cin >> monthlyDeposit;
		if (monthlyDeposit < 0)
		{
			throw runtime_error("Invalid monthly deposit.");
		}
		cout << "Annual Interest: " << endl;									//prompts for and recieves initial attribute with error checking
		cin >> annualInterest;
		if (annualInterest < 0)
		{
			throw runtime_error("Invalid interest rate.");
		}
		cout << "Number of Years: " << endl;									//prompts for and recieves initial attribute with error checking
		cin >> numYears;
		if (numYears < 1)
		{
			throw runtime_error("Invalid number of years.");
		}
	}
	catch (runtime_error& excpt)												//Prints error message and exits program
	{
		cout << excpt.what() << endl;
		cout << "Cannot compute balance tables." << endl;
		return 1;
	}
	Account nonMonthlyAccount;													//declare the two account objects
	MonthlyDepositAccount monthlyAccount;

	nonMonthlyAccount.setBalance(initialInvestment);							//Initialize the attributes of each object
	nonMonthlyAccount.setInterest(annualInterest);
	nonMonthlyAccount.setMonths(numYears * 12);

	monthlyAccount.setBalance(initialInvestment);								//Initialize the attributes of each object
	monthlyAccount.setInterest(annualInterest);
	monthlyAccount.setMonths(numYears * 12);
	monthlyAccount.setMonthlyDeposit(monthlyDeposit);

	system("pause");															//wait for user input to proceed
	cin.ignore(1);
	
	while (menuOption != 5)														//Loop allows user to try new parameters
	{
		system("CLS");															//Clears old tables from screen

		nonMonthlyAccount.printProjection();									//Displays an account balance table for each account
		monthlyAccount.printProjection();

		system("pause");														//wait for user input to proceed

		displayMenu();															//Display menu of user options

		cin >> menuOption;														//Recieve user's choice
																				//choices not within 1-5 will simply reprint menu and prompt for a new choice
		try
		{
			if (menuOption == 1)												//Processes user's menu selection
			{
				cout << "New initial investment amount:" << endl;				//Assigns new attribute value with error checking
				cin >> userInput;
				if (userInput < 0)
				{
					throw runtime_error("Invalid initial investment.");
				}
				nonMonthlyAccount.setBalance(userInput);
				monthlyAccount.setBalance(userInput);
			}
			else if (menuOption == 2)											//Processes user's menu selection
			{
				cout << "New monthly deposit amount: " << endl;					//Assigns new attribute value with error checking
				cin >> userInput;
				if (userInput < 0)
				{
					throw runtime_error("Invalid monthly deposit.");
				}
				monthlyAccount.setMonthlyDeposit(userInput);
			}
			else if (menuOption == 3)											//Processes user's menu selection
			{
				cout << "New annual interest rate: " << endl;					//Assigns new attribute value with error checking
				cin >> userInput;
				if (userInput < 0)
				{
					throw runtime_error("Invalid interest rate.");
				}
				nonMonthlyAccount.setInterest(userInput);
				monthlyAccount.setInterest(userInput);
			}
			else if (menuOption == 4)											//Processes user's menu selection
			{
				cout << "New number of years: " << endl;						//Assigns new attribute value with error checking
				cin >> userInput;
				if (userInput < 1)
				{
					throw runtime_error("Invalid number of years.");
				}
				nonMonthlyAccount.setMonths(userInput * 12);
				monthlyAccount.setMonths(userInput * 12);
			}
		}
		catch (runtime_error& excpt)											//Prints error message and exits program
		{
			cout << excpt.what() << endl;
			cout << "Cannot compute balance tables." << endl;
			return 1;
		}
	}



	return 1;
}

void displayMenu()																//Displays menu with list of user options
{
	cout << "         MENU OPTIONS" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1 Change Initial Investment Amount" << endl;
	cout << "2 Change Monthly Deposit Amount" << endl;
	cout << "3 Change Annual Interest Rate" << endl;
	cout << "4 Change Number of Years" << endl;
	cout << "5 Quit Program" << endl;
	cout << endl;
	return;
}