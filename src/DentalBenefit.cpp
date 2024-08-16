#include "DentalBenefit.h"

double DentalBenefit::caculateBenefit()
{
	return .1*m_amount ;
}

void DentalBenefit::displayBenefit()
{
	cout << "Basic information: " << info << "\tplan_Type: " << m_planType << "\tAmount: " << m_amount;
	cout << "\tDental_Benefit: " << caculateBenefit();
}

void DentalBenefit::getDetails()
{
	cout << "Enter the infornation : "; cin >> info;
	cout << "Enter Plan_Type  : "; cin >> m_planType;
	cout << "Enter the amount : "; cin >> m_amount;
}
//search
string DentalBenefit::getInfo()
{
	return info;
}

