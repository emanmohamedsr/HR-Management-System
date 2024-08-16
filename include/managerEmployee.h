#pragma once
#include "SalaryEmployee.h"
class managerEmployee:public SalaryEmployee
{
private:
	double bouns;
public:
	managerEmployee();
	double getSalary();

	void getEmployeeDetails();

	void dispalyDetails();

	double caculatePay();

};

