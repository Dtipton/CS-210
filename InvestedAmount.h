/*
 * InvestedAmount.h
 * Class that takes in Initial Investment, Monthly Deposit, Annual Interest and
 * number of years and shows how money will grow during this time period.
 * Created on: Aug 2, 2020
 *  Author: Daniel.Tipton
 */

#ifndef INVESTEDAMOUNT_H_
#define INVESTEDAMOUNT_H_


class InvestedAmount {
public:
	InvestedAmount(); // constructor
	// setter methods
	void setInvestment (float t_investment);
	void setMonthlyDeposit(float t_deposit);
	void setAnnualInterest(float t_interest);
	void setNumYears(float t_years);
	//getter methods
	float getInvestment();
	float getMonthlyDeposit();
	float getAnnualInterest();
	float getNumYears();
	//prints out compound interest and allows students to change values
	void printBalanceNoDeposits();
	void printBalanceWithDeposits();
	void gatherInvestment();
	void testDifferent();

private:
	//private values accessed by setters / gettters
	float m_initial_investment;
	float m_monthly_deposit;
	float m_annual_interest;
	float m_number_years;
};


#endif /* INVESTEDAMOUNT_H_ */
