#include<iostream>
using namespace std;
/*an abstract class called Employee that stores information common to all employees
* and it's member functions.
*/ 
class Employee
{
protected:
	int salary;
public:
	//a member function that stores an employee's salary.
	Employee(int s = 0)
	{
		salary = s;
	}
	//a member function that helps calculate salary whether it be monthly or weekly.
	virtual int getSalary()
	{
		return salary;
	}
	//a member function that helps calculate vacation days earned.
	virtual double getVacation()
	{
		return 0;
	}
	//a member function that helps calculate health insurance contribution.
	virtual int getInsurance()
	{
		return 0;
	}
};
//A class called Professional that inherits functions from the Employee class.
class Professional : public Employee
{
	//declared protected variables.
protected:
	double vDays;
	int monthlyHealthCareContribution;

public:
	//A function that takes in a double, and an int to be saved into the declared variables above, and uses the Employee function to set the professional's monthly salary.
	Professional(double d = 0, int c = 0) : Employee(5000)
	{
		vDays = d;
		monthlyHealthCareContribution = c;

	}
	//A function that returns how much the professional spends on monthly health insurance.
	int getInsurance()
	{
		return monthlyHealthCareContribution;
	}
	//A function that gets the professional's vacation days and divides it by the amount of workdays in a year (after paid holidays) to get how many hours of vacation time they earn per week. 
	double getVacation()
	{
		double workHours = vDays * 8;
		double profVacaHours = workHours / (40 * 52 - 40);
		
		return profVacaHours * 40;
	}

};
//A class called Nonprofessional that inherits functions from the Employee class.
class Nonprofessional : public Employee
{
protected:
	int hours;
	double vHours;
	float healthCarePercentage;
public:
	//A function that takes in an int, and a float to be saved into the declared variables above, and uses the Employee function to set the nonprofessional's hourly rate.
	Nonprofessional(int h = 0, float p = 0) : Employee(25 * h)
	{
		hours = h;
		healthCarePercentage = p;
	}
	//A function that gets the nonprofessional's vacation hours and divides it by the amount of work hours in a year (after paid holidays) to get how many hours of vacation time they earn per week. 
	double getVacation()
	{
		double workHours = hours * 52 - hours;
		double nonProfVacaHours = hours / workHours;
		vHours = nonProfVacaHours * hours;
		return vHours;
	}
	//A function that returns how much the nonprofessional takes from his weekly salary for insurance.
	int getInsurance()
	{
		return ((25 * hours) * (healthCarePercentage / 100));
	}
};