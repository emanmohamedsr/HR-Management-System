
#include "HRSystem.h"

using namespace std;
///color
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);


struct mainDesign
{

    HRSystem s1;


    static inline void print(string s, bool newline = true)
    {
        ///instead of cout
        cout << s << (newline ? "\n" : "\t");
    }


    static void line(char c, int y, int x)
    {
        ///separator
        SetConsoleTextAttribute(cout_handle, x);
        for (int i = 0; i < y; i++)
            cout << c;
        cout << endl;
        SetConsoleTextAttribute(cout_handle, 15);
    }
    static void Back(int x)
    {
        cout << "Back to main page ";
        for (int i = 0; i < x; i++)
        {
            cout << ".";
            Sleep(1000);
        }
        cout << endl;
    }
    void HR()
    {

        system("cls");
        line('_', 55, 13);
        print("\nWelcome to \"HR management system\" \x03, Enter a service...");
        print("1) Employee Information Management ");
        print("2) BenefitsManagement ");
        print("3) Salary Calculation ");
        print("4) Reporting ");
        print("0) Exit ");
        print("your choice ->", false);

    }





    void Employee_Information_Management()
    {

        int c;
        while (true)
        {
            system("cls");
            line('_', 66, 11);
            print("\nWelcome to \"Employee Information Management\" \x03, Enter a service...");
            print("1) Add an employee ");
            print("2) Delete an employee");
            print("3) Modify employee information ");
            print("4) Search for an employee ");
            print("0) Back to previous page ");
            print("your choice ->", false);
            cin >> c;
            line('_', 66, 11);

            switch (c)
            {
            case 1:
                //add employee
                s1.addEmployee();
                break;
            case 2:
                //delete employee
                s1.deleteEmployee();
                break;
            case 3:
                //Modify employee information
                s1.editEmployee();
                break;
            case 4:
                //search employee
                s1.employeeSearch();
                break;
            case 0:
                Back(3);
                return;
            default:
                cout << "Invalid choice,try again \n";
                Sleep(2000);

            }
        }

    }
    void Benefits_Management()
    {

        int c;
        while (true)
        {
            system("cls");
            line('_', 54, 9);
            print("\nWelcome to \"Benefits Management\" \x03, Enter a service...");
            print("1) Add a benefit package ");
            print("2) Delete a benefit package");
            print("3) Modify a benefit package ");
            print("0) Back to main page ");
            print("your choice ->", false);
            cin >> c;
            line('_', 54, 9);
            switch (c)
            {
            case 1:
                //add 
                s1.addBPackage();
                break;
            case 2:
                //delete
                s1.deleteBPackage();
                break;
            case 3:
                //Modify 
                s1.editBPackage();
                break;
            case 0:
                Back(3);
                return;
            default:
                cout << "\nInvalid choice,try again \n";
                Sleep(2000);

            }
        }


    }

    void SalaryCa()
    {
        s1.salaryCaculation();
    }

    void display()
    {
        s1.displayAll();
    }
}E;







int main()
{
    int c;
    while (true)
    {
        E.HR();
        cin >> c;
        mainDesign::line('_', 55,13);
        Sleep(100);

        switch (c)
        {
            
        case 1:
            //Employee Information Management
            E.Employee_Information_Management();
            break;
        case 2:
            //Benefits Management
            E.Benefits_Management();
            break;
        case 3:
            //Salary Calculation
            E.SalaryCa();
            break;
        case 4:
            //Reporting
            E.display();
            break;
        case 0:
            //Exit
            mainDesign::print("\t\t   Thanks \x03");
            return 0;
        default:
            cout<<"\nInvalid choice, Try again \n";
            Sleep(2000);

        }
    }
    return 0;
}




