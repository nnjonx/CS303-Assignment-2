#include "Business.h"
#include <iostream>

int main()
{
	//the arguments for professional are vacation days, and how much they spend on insurance monthly (500 being the average an employee spends on health insurance)
	Professional p(20, 500);
	//the arguments for nonprofessional are hours worked in a week, and the percentage of their weekly salary that goes to insurance (11.6%  being the average an employee spends on health insurance)
	Nonprofessional n(40, 11.6);
	cout << "A professional's salary is calculated to be $" << p.getSalary() / 4 << " dollars per week but they are paid $" << p.getSalary() << " dollars monthly." << endl;
	cout << "A professional contributes $" << p.getInsurance() << " dollars to health insurance per month." << endl;
	cout << "A professional earns " << p.getVacation() << " vacation hours week, which is calculated to be about " << p.getVacation() * 52 / 8 << " vacation days per year as agreed upon with their employer" << endl;
	cout << "A nonprofessional's salary is $" << n.getSalary() << " dollars per week since they are paid hourly." << endl;
	cout << "A nonprofessional contributes $" << n.getInsurance() << " dollars to health insurance per week." << endl;
	cout << "A nonprofessional gets " << n.getVacation() << " vacation hours per week, which roughly equals to 5 vacation days (days off work days) per year." << endl;
	return 0;
}