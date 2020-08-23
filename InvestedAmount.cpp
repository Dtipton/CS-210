/*
 * InvestedAmount.cpp
 * Method definitions for the Invested Amount class
 * Includes all setters / getters as well as the three
 * print functions to show different forms of compound interest.
 * Created on: Aug 2, 2020
 * Author: Daniel.Tipton
 */

#include<iostream>
#include<stdexcept> // used for execptions
#include<iomanip> // used for precision
#include "InvestedAmount.h" // links to the class file
using namespace std;

// default constructor which sets values to 0 by default
InvestedAmount::InvestedAmount(){
	m_initial_investment = 0;
	m_monthly_deposit = 0;
	m_annual_interest = 0;
	m_number_years = 0;

}

// setters and getters for seeing / setting values in the class
void InvestedAmount::setInvestment(float t_investment){
	this->m_initial_investment = t_investment;
}

void InvestedAmount::setAnnualInterest(float t_interest){
	this->m_annual_interest = t_interest;
}

void InvestedAmount::setMonthlyDeposit(float t_deposit){
	this->m_monthly_deposit = t_deposit;
}

void InvestedAmount::setNumYears(float t_years){
	this->m_number_years = t_years;
}

float InvestedAmount::getInvestment(){
	return m_initial_investment;
}

float InvestedAmount::getAnnualInterest(){
	return m_annual_interest;
}

float InvestedAmount::getMonthlyDeposit(){
	return m_monthly_deposit;
}

float InvestedAmount::getNumYears(){
	return m_number_years;
}


/*
 * gatherinvestment: Takes in no arguement and prompts the user for the memeber values for the class object
 * and error checks to make sure that they are real numbers. Then prints out the values entered.
 *  Takes in no value and returns no value.
 */
void InvestedAmount::gatherInvestment(){
	// variables to gather from the user
	float investment;
	float interest;
	float deposit;
	float years;
	char any; // used to continue to the second screen


	cout << "**********************************" << endl;
	cout << "**************Data Input *********" << endl;

	// gathers input and checks that it is a non-negative number.
	try {
	cout <<"Initial Investment Amount: ";
	cin >> investment;
	cout << endl;
	if ( investment < 0 ){
		throw runtime_error("Invalid number");
	}
	cout <<"Monthly Deposit: ";
	cin >> deposit;
	if ( deposit < 0 ){
		throw runtime_error("Invalid number");
	}
	cout << endl;
	cout <<"Annual Interest: ";
	cin >> interest;
	if ( interest < 0){
		throw runtime_error("invalid number");
	}
	cout << endl;
	cout <<"Number of Years: ";
	cin >> years;
	if ( years < 0 ){
		throw runtime_error("Invalid number");
	}
	cout << endl;
	}
	catch ( runtime_error& excpt){
		cout << excpt.what() << endl;
		cout << "Please restart program."<< endl;
		return;
	}
	cout << "Press any key to continue . . .";
	cin >> any;


	// prints out the values on the table for user to see
	cout << "**********************************" << endl;
	cout << "**************Data Input *********" << endl;
	cout <<"Initial Investment Amount: $" << investment << endl;
	cout <<"Monthly Deposit: $ " << deposit << endl;
	cout <<"Annual Interest: % " << interest << endl;
	cout <<"Number of Years: " << years << endl;
	cout << "Press any key to continue . . . *";
	cin >> any;
	cout << endl;


	// uses the gathered information to fill the class with data.
	setInvestment(investment);
	setAnnualInterest(interest);
	setMonthlyDeposit(deposit);
	setNumYears(years);
}


/*
 * printBalanceNoDeposists: Prints data for the years value of the class with no monthly deposits, takes no values
 * and returns no value, prints out a table with Year, year end balance and year end earned interest
 */
void InvestedAmount::printBalanceNoDeposits(){
	float total_amount; // stores total amount for balance
	float interest_amount; // stores earned interest amount

	total_amount = getInvestment(); // set the starting total

	// setup the display
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculates the yearly interest and year end total
	for ( int i = 0; i < getNumYears(); i++){

		//Calculates the yearly interest
		interest_amount = ((total_amount) * (getAnnualInterest() / 100));

		//Finds the year end total
		total_amount = total_amount + interest_amount;

		// Prints it all out with 2 decimal places.
		cout << ( i +1 ) << "\t\t$" << fixed << setprecision(2) << total_amount << "\t\t\t$" << interest_amount << endl;

	}

}



/*
 * printBalanceWithDeposists: Prints out the data for the amount of years including monthly deposits, takes in
 * no value and returns no value, prints out a data table of values set to 2 decimal places.
 */
void InvestedAmount::printBalanceWithDeposits(){

	float total_amount; // total for the year
	float interest_amount; // amount of interest
	float yearly_total_interest; // the accured total interest

	total_amount = getInvestment(); // set the starting total amount

	//print out the display
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculates yearly interest and year end total
	for ( int i = 0; i < getNumYears(); i++){

		//initialize the yearly interest
		yearly_total_interest = 0;


		for ( int j = 0; j < 12; j++) {

			// gets the monthly interest amount
			interest_amount = (((total_amount + getMonthlyDeposit() ) * (getAnnualInterest() / 100)) / 12);

			// month end interest
			yearly_total_interest = yearly_total_interest + interest_amount;

			//gets the month end total
			total_amount = total_amount + getMonthlyDeposit() + interest_amount;
		}

		//prints it all out with 2 decimal places
		cout << ( i + 1) << "\t\t$" << fixed << setprecision(2) << total_amount << "\t\t\t$" << yearly_total_interest << endl;
	}

}


/*
 * testDifferent: Prints out a menu for students to choose a field to enter and from there
 * change up differnt parts of the InvestmentAmount class and see the new results, takes no values
 * and returns nothing.
 */
void InvestedAmount::testDifferent(){
	int choice; // choice from the menu
	float change; // changes ( since all values are being stored a floats
	do{
	cout << "**********************************" << endl;
	cout << "**************Data Input *********" << endl;
	cout << "1.New Interest Rate" << endl;
	cout << "2.New Monthly Deposit" << endl;
	cout << "3.New Amount of Years" << endl;
	cout << "4.Quit" << endl;
	cout <<"*";
	cin >> choice;

	// goes through the different options changing the values and re-printing the tables so the students can see
	if ( choice == 1){
		cout << "Enter new rate: " << endl;
		cin >> change;
		setAnnualInterest(change);
		printBalanceNoDeposits();
		printBalanceWithDeposits();
	}

	else if ( choice == 2){
		cout << "Enter new Deposit" << endl;
		cin >> change;
		setMonthlyDeposit(change);
		printBalanceNoDeposits();
		printBalanceWithDeposits();
	}

	else if ( choice == 3){
		cout << "Enter new amount of years" << endl;
		cin >> change;
		setNumYears(change);
		printBalanceNoDeposits();
		printBalanceWithDeposits();
	}

	//runs until 4 is selected which exits the function
	else{
		return;
	}
	} while ( choice != 4);
}
