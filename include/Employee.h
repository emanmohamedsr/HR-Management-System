#pragma once
#include <Windows.h>///sleep, color
#include <cstdlib>///system("cls") 


#include "Department.h"
#include "benefit.h"
#include "HealthBenefit.h"
#include "Dentalbenefit.h"




class Employee : public Department
{
protected:
	int employee_id;
	string employee_name;
	string employee_phone;
	string employee_email;
	string job_title;

	
	double totalBene=0 ;

private:
	int benfitSize;
	benefit** benefitList;
	int benefitCount;
public:
	
	
	Employee();
	~Employee();

	void setColor(int color);
	void storeBenefitList();
	void getBenefitList();
	bool deleteBenbfit(string );
	bool editBenefit(string );

	int getEmployeeID();

	virtual void dispalyDetails();
	virtual void getEmployeeDetails();
	virtual double getSalary()=0;

	virtual double caculatePay()=0;

};

