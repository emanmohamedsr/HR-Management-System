#include "HourlyEmployee.h"



HourlyEmployee::HourlyEmployee()
{
}

void HourlyEmployee::addMoreHours(int hours)
{
	hoursWorked += hours;
}

void HourlyEmployee::getEmployeeDetails()
{
	Employee::getEmployeeDetails();
	cout << "worked Hours: "; cin >> hoursWorked;
	cout << "Rate: "; cin >> rate;

}

double HourlyEmployee::getSalary()
{
	return rate * hoursWorked;
}

double HourlyEmployee::caculatePay()
{
	return getSalary() + totalBene;
}

void HourlyEmployee::dispalyDetails()
{
	Employee::dispalyDetails();
	cout << "\tSalary: " << getSalary();
	cout << "\tTotal pay (Benefits + Salary) = "<<caculatePay();
}



