#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee
{
private:
	double hoursWorked;
	double rate;
public:
	HourlyEmployee();
	void addMoreHours(int hours);
	void getEmployeeDetails();
	void dispalyDetails();
	double getSalary();
	double caculatePay();
};

