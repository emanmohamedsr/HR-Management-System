#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef DEPARTMENT_H
#define DEPARTMENT_H


class Department
{
private:
	string m_departName;
	int m_ID;
public:
	Department();
    ~Department();

	void readDepartment(int , string);
	void printDepartment();



};

#endif // !DEPARTMENT_H