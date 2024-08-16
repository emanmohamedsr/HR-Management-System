#include "Employee.h"

void Employee::setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Employee::Employee()
{
	benfitSize = 20;
	benefitCount = 0;
	//new.........|| ÈÊÇÚå ÇáÇÑÇí
	benefitList = new benefit * [benfitSize];

}

Employee::~Employee()
{
	//delete elements -> ( pointers ) inside dynamic array
    //(auto) returns ambiguous type automatically
	for (auto i = 0; i < benefitCount; i++)
		delete benefitList[i];
	//delete dynamic array itself
	delete[] benefitList;
}

int Employee::getEmployeeID()
{
	return employee_id;
}



void Employee::dispalyDetails()
{
	cout << "Employee ID: " << employee_id << "\tName: " << employee_name
		<< "\tJob_titel: " << job_title
		<< "\tPhone : " << employee_phone << "\tEmail: " << employee_email ;
}

void Employee::getEmployeeDetails()
{
	cout << "Enter employee ID: "; cin >> employee_id;
	cout << "employee Name: "; cin >> employee_name;
	cout << "Job_title: "; cin >> job_title;
	cout << "Email: "; cin >> employee_email;
	cout << "Phone: "; cin >> employee_phone;
}


void Employee::storeBenefitList()
{

	if (benefitCount < benfitSize)
	{
		int c;
		char ch;
		setColor(9);
		cout << "______________________________________________" << endl;
		setColor(15);
		cout << "\n*BENEFIT BACKAGES*, you can add up to 20 BK... \n";
		cout << "1) Add HealthBenefit \n"
			<<  "2) Add DentalBenefit \n"
			<<  "0) Add \"Null\" \n";
		setColor(9);
		cout << "______________________________________________" << endl;
		setColor(15);

		do
		{
			cout << "Your choice -> ";
			cin >> c;
			cout << endl;
			switch (c)
			{
			case 1:
				
				benefitList[benefitCount] = new HealthBenefit;
				benefitList[benefitCount]->getDetails();
				totalBene += benefitList[benefitCount++]->caculateBenefit();
				break;
			case 2:
				benefitList[benefitCount] = new DentalBenefit;
				benefitList[benefitCount]->getDetails();
				totalBene += benefitList[benefitCount++]->caculateBenefit();
				break;
			case 0:
				return;
			default:
				cout << "invalid choice !\n";
				break;
			}
			cout << "\nAnother ? (y/n) : ";
			cin >> ch;
			cout << endl;
		} while (ch != 'n');
	}
	else
	{
		cout << "sorry, You can\'t add anymore " << endl;

	}

}

void Employee::getBenefitList()
{
	if (benefitCount == 0)
	{
		cout << ":-> There is\'t any benefit packages yet \n";
		return;
	}
	cout << "\n\n:-> Benefit_List : "<<endl;
	for (int i = 0; i < benefitCount; i++)
	{
		cout << "[" << i + 1 << "]\t";
		benefitList[i]->displayBenefit();
		cout << endl;
	}
}

bool Employee::deleteBenbfit(string inf)
{
	if (benefitCount == 0)
	{
		return false;
	}
	bool found = false;
	for (int i = 0; i < benefitCount; i++)
	{
		if (benefitList[i]->getInfo() == inf)
		{
			found = true;
			//delete old benefit from totalbene
			totalBene -= benefitList[i]->caculateBenefit();

			benefitList[i] = benefitList[benefitCount - 1];
			--benefitCount;
			

			return true;
		}
		else
			found = false;
	}
	if (found == false)
		return false;
}



bool Employee::editBenefit(string inf)
{
	if (benefitCount == 0)
	{
		return false;
	}
	bool found = false;
	for (int j = 0; j < benefitCount; j++)
	{
		if (benefitList[j]->getInfo() == inf)
		{
			//delete old benefit from totalbene
			totalBene -= benefitList[j]->caculateBenefit();
			cout << "Enter the new package...\n";
			benefitList[j]->getDetails();
			//add the new one to totalbene
			totalBene += benefitList[j]->caculateBenefit();

			return true;
		}
		else
			found = false;
	}
	if (found == false)
		return false;

}

