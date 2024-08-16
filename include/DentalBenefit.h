#pragma once
#include "benefit.h"

class DentalBenefit :public benefit
{
private:
	string info;
	
public:
	double caculateBenefit();
	void displayBenefit();
	void getDetails();
	string getInfo();
};

