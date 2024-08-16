#pragma once
#include "Employee.h"

class SalaryEmployee  : public Employee
{
public:
	double salary;
	double getSalary();
	SalaryEmployee();
	void getEmployeeDetails();
	void dispalyDetails();
	double caculatePay();
};

 