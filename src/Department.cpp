#include "Department.h"


Department::Department()
{
}


Department::~Department()
{}



void Department::readDepartment(int i , string n)
{
	m_ID = i;
	m_departName = n;
}

void Department::printDepartment()
{
	cout << "\n:-> Deartment ID: " << m_ID << "\tName: " << m_departName << endl;
}

