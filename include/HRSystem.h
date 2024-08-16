#pragma once

#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalaryEmployee.h"
#include "managerEmployee.h"
#include "CommissionEmployee.h"



class HRSystem 
{
private:
	int EmployeeSize;
	int EmployeeCount;
	Employee**EmployeeList;
public:
	
	HRSystem(int=100);
	~HRSystem();
	void setColor(int color);

	void addEmployee();
	void employeeSearch();
	void deleteEmployee();
	void editEmployee();
	
	void addBPackage();
	void deleteBPackage();
	void editBPackage();
	
	void salaryCaculation();

	void displayAll();

	

	void addDepart(int);


};

