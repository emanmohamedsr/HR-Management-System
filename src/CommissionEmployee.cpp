#include "CommissionEmployee.h"

double CommissionEmployee::getSalary()
{
    return rate*target;
}


CommissionEmployee::CommissionEmployee()
{ }

void CommissionEmployee::getEmployeeDetails()
{
	Employee::getEmployeeDetails();
	cout << "Target: "; cin >> target;
	cout << "Rate: "; cin >> rate;

}
double CommissionEmployee::caculatePay()
{
	return getSalary() + totalBene;
}

void CommissionEmployee::dispalyDetails()
{
	Employee::dispalyDetails();
	cout << "\tSalary: " << getSalary();
	cout << "\tTotal pay (Benefits + Salary) = " << caculatePay();
}

