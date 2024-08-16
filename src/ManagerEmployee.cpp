
#include "managerEmployee.h"

managerEmployee::managerEmployee()
{
}
double managerEmployee::getSalary()
{
	return salary+bouns;
}

void managerEmployee::getEmployeeDetails()
{
	SalaryEmployee::getEmployeeDetails();
	cout << "bouns: "; cin >> bouns;
	

}

double managerEmployee::caculatePay()
{
	return getSalary() + totalBene;
}
void managerEmployee::dispalyDetails()
{
	Employee::dispalyDetails();
	cout << "\tSalary: " << getSalary();
	cout << "\tTotal pay (Benefits + Salary) = " << caculatePay();
}
