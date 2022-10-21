#pragma once

// creating class to hold financial information
class FinancialInformation {

public:
	//constructor
	FinancialInformation();

	// function to gather user data
	void userDataInput();

	// function to calculate balance with no additional deposits
	double calcBalanceNoDeposit(double t_initialInvestmentAmount, double t_annualInterest, int t_years);

	// function to calculate balance with additional deposits
	double calcBalanceWithDeposit(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_years);

	// setting initial investment amount from user
	void setInitialIvestmentAmount(double t_initialInvestmentAmount);

	// setting monthly deposit amount
	void setMonthlyDeposit(double t_montlyDeposit);

	// setting number of years
	void setNumberOfYears(int t_years);

	// setting interest
	void setInterest(double t_annualInterest);

	// getting investment amount
	double getInitialIvestmentAmount() const;
	
	// getting monthly deposit
	double getMonthlyDeposit() const;

	// getting interest
	double getInterest() const;

	// getting number of years
	int getNumberOfYears() const;



private:

	// private member data
	double m_initialInvestAmount;
	double m_monthlyDeposit;
	int m_numberOfYears;
	double m_interestAmount;
	double m_totalAmount;
	
};