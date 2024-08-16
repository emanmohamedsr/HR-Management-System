#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef BENEFIT_H
#define BENEFIT_H
//base class abstract
class benefit
{
//inheritance
protected:
	string m_planType;
	double m_amount;
public:
	benefit();
	virtual ~benefit();

	virtual string getInfo()=0;
	virtual void getDetails()=0;
	virtual double caculateBenefit()=0;
    virtual void displayBenefit()=0;
	

};

#endif // !BENEFIT_H

