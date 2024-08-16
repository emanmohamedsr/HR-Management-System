#pragma once
#include "Employee.h"
class CommissionEmployee :public Employee
{
private:
	double target;
	double rate;
public:
	CommissionEmployee();
	void getEmployeeDetails();
	void dispalyDetails();
	double caculatePay();
	double getSalary();
};

