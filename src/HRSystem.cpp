#include "HRSystem.h"

void HRSystem::setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,color);
}


HRSystem::HRSystem(int Size)
{
	EmployeeSize = Size;
	EmployeeList = new Employee * [EmployeeSize];
	EmployeeCount = 0;
}

HRSystem::~HRSystem()
{
	for (auto i = 0; i < EmployeeCount; i++)
		delete EmployeeList[i];
	delete[] EmployeeList;
    
}








void HRSystem::addBPackage()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}

	system("cls");
	setColor(9);
	cout << "\t\tADDING AN EMPLOYEE BENEFIT PACKAGE" << endl;
	cout << "\t\t__________________________________" << endl;
	setColor(15);
	int id;
	cout << "Enter Employee ID To Add him a PK : ";
	cin >> id;
	bool Found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			Found = true;
			EmployeeList[i]->storeBenefitList();
			cout << "\nAdded Successfully \xFB" << endl;
			break;
		}
		else
			Found = false;
	}
	if (Found == false)
		cout << "Add Failed " << endl;
	Sleep(2000);

}




void HRSystem::deleteBPackage()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}
	int id;
	string info;
	cout << "Enter Employee ID to delete from his packages &  Wnated package information : ";
	cin >>id>> info;
	bool found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			if (EmployeeList[i]->deleteBenbfit(info))
			{
				cout << "Benefit package deleted successfully \xFB\n";
				Sleep(2000);
				return;
			}
		}
		else
			found = false;
	}
	if (found == false)
		cout << "Delete faild " << endl;
	Sleep(2000);
}

void HRSystem::editBPackage()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}
	int id;
	string info;
	cout << "Enter employee ID to edit his packages & Wnated package information : ";
	cin>>id >> info;
	bool found1 = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			if (EmployeeList[i] ->editBenefit(info))
			{
				cout << "\nBenfit package edited successfully \xFB\n";
				Sleep(2000);
				return;
			}
		}
		else
			found1 = false;
	}
	if (found1 == false)
		cout << "Edit faild " << endl;
	Sleep(2000);
}


void HRSystem::addDepart(int x)
{
	int c;
	cout << endl;
	cout << "Chose The Depatrment : \n" << "1) Information Technology\n" << "2) Information System\n"
		<< "3) Computer Science\n" << "4) Back End\n" << "5) Front End\n" << "6) Cyber Security\n" << "0) Another\n" << endl;
    cout << "Your choice -> ";
	cin >> c;

	switch (c)
	{
	case 1:
		EmployeeList[x]->readDepartment(1, "Information Technology");
		break;
	case 2:
		EmployeeList[x]->readDepartment(2, "Information System");
		break;
	case 3:
		EmployeeList[x]->readDepartment(3, "Computer Science");
		break;
	case 4:
		EmployeeList[x]->readDepartment(4, "Back End");
		break;
	case 5:
		EmployeeList[x]->readDepartment(5, "Front End");
		break;
	case 6:
		EmployeeList[x]->readDepartment(6, "Cyber Security");
		break;
	case 0:
		EmployeeList[x]->readDepartment(0, "Another");
		break;
	default:
		cout << "Invalid choice \n";	
		EmployeeList[x]->readDepartment(0, "Another");
		break;
	}

}
void HRSystem::addEmployee()
{
	int c;
	if (EmployeeCount < EmployeeSize)
	{
		cout << "Enter Employee type...\n"
			<< "1) Hourly_Employee \n"
            << "2) commission_Employee \n"
			<< "3) Salary_Employee \n"
			<< "4) Manager_Employee \n"
			
			<< "Your choice -> ";
		cin >> c;
		system("cls");
		switch (c)
		{
		case 1:
			setColor(11);
			cout << "\t\t ADDIND HOURLY EMPLOYEE" << endl;
			cout << "\t\t ______________________" << endl;
			setColor(15);
			EmployeeList[EmployeeCount] = new  HourlyEmployee;
			EmployeeList[EmployeeCount]->getEmployeeDetails();
			addDepart(EmployeeCount);
			EmployeeCount++;
			break;
		case 2:
			setColor(11);
			cout << "\t\t ADDIND COMMISSION EMPLOYEE" << endl;
			cout << "\t\t __________________________" << endl;
			setColor(15);
			EmployeeList[EmployeeCount] = new  CommissionEmployee;
			EmployeeList[EmployeeCount]->getEmployeeDetails();
			addDepart(EmployeeCount);
			EmployeeCount++;
			break;
		case 3:
			setColor(11);
			cout << "\t\t ADDIND SALARY EMPLOYEE" << endl;
			cout << "\t\t ______________________" << endl;
			setColor(15);
			EmployeeList[EmployeeCount] = new  SalaryEmployee;
			EmployeeList[EmployeeCount]->getEmployeeDetails();
			addDepart(EmployeeCount);
			EmployeeCount++;
			break;
		case 4:
			setColor(11);
			cout << "\t\t ADDIND MANAGER EMPLOYEE" << endl;
			cout << "\t\t _______________________" << endl;
			setColor(15);
			EmployeeList[EmployeeCount] = new  managerEmployee;
			EmployeeList[EmployeeCount]->getEmployeeDetails();
			addDepart(EmployeeCount);
			EmployeeCount++;
			break;
		default:
			cout << "Invalid choice \n";
			Sleep(2000);
			break;
		}
		cout << "\nEmployee Added Successfully \x03 " << endl;
		Sleep(2000);
	}
	else
	{
		cout << "Sorry, you can\'t add any more.\n";
		Sleep(2000);
	}
}

void HRSystem::employeeSearch()
{
	if(EmployeeCount==0)
	{
		cout << "There are no employees yet"<<endl;
		Sleep(2000);
		return;
	}
	system("cls");
	setColor(11);
	cout << "\t\tSEARCHING FOR AN EMPLOYEE" << endl;
	cout << "\t\t_________________________" << endl;
	setColor(15);
	int id;
	cout << "Enter Employee ID To Search: ";
	cin >> id;
	bool Found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			Found = true;
			cout << "Employee found successfully \xFB " << endl;
			break;
		}
		else
			Found = false;
	}
	if (Found == false)
		cout << "Search Failed " << endl;
	Sleep(2000);
}
void HRSystem::deleteEmployee()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}
	setColor(11);
	system("cls");
	cout << "\t\tDELETING AN EMPLOYEE" << endl;
	cout << "\t\t____________________" << endl;
	setColor(15);
	int id;
	cout << "Enter Employee ID To Delete: ";
	cin >> id;
	bool Found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			Found = true;
			EmployeeList[i] = EmployeeList[EmployeeCount - 1];
			EmployeeCount--;
			cout << "Employee Deleted Successfully \xFB" << endl;
			break;
		}
		else
			Found = false;
	}
	if (Found == false)
		cout << "Delete Failed " << endl;
	Sleep(2000);

}
void HRSystem::editEmployee()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}
	system("cls");
	setColor(11);
	cout << "\t\tMODIFING AN EMPLOYEE" << endl;
	cout << "\t\t____________________" << endl;
	setColor(15);
	int id;
	cout << "Enter Employee ID To Modify: ";
	cin >> id;
	bool Found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			Found = true;
			cout << "\n***Enter The New Information***\n";
			EmployeeList[i] ->getEmployeeDetails();
			addDepart(i);
			cout << "Employee Modified Successfully \xFB" << endl;
			break;
		}
		else
			Found = false;
	}
	if (Found == false)
		cout << "Modify Failed " << endl;
	Sleep(2000);
}
void HRSystem::displayAll()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet" << endl;
		Sleep(2000);
		return;
	}
	system("cls");
	setColor(14);
	cout << "\t\tReporting of all employees \n";
	cout << "\t\t__________________________"<<endl;
	setColor(15);
	for (int i = 0; i < EmployeeCount; i++)
	{
		
		cout << "[" << i + 1 << "]";
		setColor(14);
		cout << "________________________________" << endl;
		setColor(15);
		EmployeeList[i]->dispalyDetails();
		cout << endl;
		EmployeeList[i]->printDepartment();
		EmployeeList[i]->getBenefitList();
		cout << endl;
	}

	system("pause");
}
void HRSystem::salaryCaculation()
{
	if (EmployeeCount == 0)
	{
		cout << "There are no employees yet " << endl;
		return;
	}
	int id;
	cout << "Enter employee ID to caculate his salary : ";
	cin >> id;
	bool found = false;
	for (int i = 0; i < EmployeeCount; i++)
	{
		if (EmployeeList[i]->getEmployeeID() == id)
		{
			found = true;
			cout << "Employee Salary = ";
			cout << EmployeeList[i]->getSalary() << " $" << endl;
			system("pause");
		}
		else
			found = false;
	}
	if (found == false)
		cout << "There no employee with ID " << id << endl;
}