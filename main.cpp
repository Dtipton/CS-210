/*
 * main.cpp
 * Creates a student object and then uses built in methods to gather information and print
 * out compound interest information based on interest, monthly deposit, and years
 * Created on: Aug 2, 2020
 * Author: Daniel.Tipton
 */
#include<iostream>
#include"InvestedAmount.h"
using namespace std;

int main(){

	InvestedAmount Student; // create a InvestedAmount object

	Student.gatherInvestment(); // gather it
	if ( Student.getInvestment() == 0){ // if gatherInvestment has an error it kicks it out before storing values
		Student.gatherInvestment();
	}

	// print everything out
	Student.printBalanceNoDeposits();
	Student.printBalanceWithDeposits();
	cin.ignore();
	Student.testDifferent();


	return 0;
}



