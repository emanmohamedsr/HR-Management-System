
#include "SalaryEmployee.h"

double SalaryEmployee::getSalary()
{
    return salary;
}

SalaryEmployee::SalaryEmployee()
{ }

void SalaryEmployee::getEmployeeDetails()
{
	Employee::getEmployeeDetails();
	cout << "Salary: "; cin >> salary;
	
}
double SalaryEmployee::caculatePay()
{
	return getSalary() + totalBene;
}
void SalaryEmployee::dispalyDetails()
{
	Employee::dispalyDetails();
	cout << "\tSalary: " << getSalary();
	cout << "\tTotal pay (Benefits + Salary) = " << caculatePay();
}

