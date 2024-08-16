#pragma once
#include "benefit.h"
class HealthBenefit :public benefit
{
private:
	string info;
	string coverage;
public:
	double caculateBenefit();
	void displayBenefit();
    void getDetails();
	string getInfo();

};

