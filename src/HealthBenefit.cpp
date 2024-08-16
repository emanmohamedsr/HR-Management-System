#include "HealthBenefit.h"

double HealthBenefit::caculateBenefit()
{
    return .2*m_amount;
}

void HealthBenefit::displayBenefit()
{
	cout << "Basic information: " << info <<"\tcoverage: "<<coverage << "\tplan_Type: " << m_planType << "\tAmount: " << m_amount;
	cout << "\tDental_Benefit: " << caculateBenefit();
}

void HealthBenefit::getDetails()
{
	cout << "Enter the infornation : "; cin >> info;
	cout << "Enter Coverage : "; cin >> coverage;
	cout << "Enter Plan_Type  : "; cin >> m_planType;
	cout << "Enter the amount : "; cin >> m_amount;
}

string HealthBenefit::getInfo()
{
	return info;
}
