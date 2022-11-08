// C++ program for the above approach
#include <bits/stdc++.h>

#define max 20
using namespace std;

// Structure of Employee
struct employee {
	string name;
	long int code;
	string designation;
	int exp;
	int age;
};

int num;


employee emp[max], tempemp[max],
	sortemp[max], sortemp1[max];

// Function to build the given datatype
void build()
{
	cout << "Maximum Entries can be "
		<< max << "\n";

	cout << "Enter the number of "
		<< "Entries required";
	cin >> num;

/*	if (num > 20) {
		cout << "Maximum number of "
			<< "Entries are 20\n";
		num = 20;
	}*/
	cout << "Enter the following data:\n";

	for (int i = 0; i < num; i++) {
		cout << "Name ";
		cin >> emp[i].name;

		cout << "Employee ID ";
		cin >> emp[i].code;

		cout << "Designation ";
		cin >> emp[i].designation;

		cout << "Experience ";
		cin >> emp[i].exp;

		cout << "Age ";
		cin >> emp[i].age;
	}

}

// Function to insert the data into
// given data type
void insert()
{
	if (num < max) {
		int i = num;
		num++;

		cout << "Enter the information "
			<< "of the Employee\n";
		cout << "Name ";
		cin >> emp[i].name;

		cout << "Employee ID ";
		cin >> emp[i].code;

		cout << "Designation ";
		cin >> emp[i].designation;

		cout << "Experience ";
		cin >> emp[i].exp;

		cout << "Age ";
		cin >> emp[i].age;
	}
	else {
		cout << "Employee Table Full\n";
	}

}

// Function to delete record at index i
void deleteIndex(int i)
{
	for (int j = i; j < num - 1; j++) {
		emp[j].name = emp[j + 1].name;
		emp[j].code = emp[j + 1].code;
		emp[j].designation
			= emp[j + 1].designation;
		emp[j].exp = emp[j + 1].exp;
		emp[j].age = emp[j + 1].age;
	}
	return;
}

// Function to delete record
void deleteRecord()
{
	cout << "Enter the Employee ID "
		<< "to Delete Record";

	int code;

	cin >> code;
	for (int i = 0; i < num; i++) {
		if (emp[i].code == code) {
			deleteIndex(i);
			num--;
			break;
		}
	}
}

void searchRecord()
{
	cout << "Enter the Employee"
		<< " ID to Search Record";

	int code;
	cin >> code;

	for (int i = 0; i < num; i++) {

		// If the data is found
		if (emp[i].code == code) {
			cout << "Name "
				<< emp[i].name << "\n";

			cout << "Employee ID "
				<< emp[i].code << "\n";

			cout << "Designation "
				<< emp[i].designation << "\n";

			cout << "Experience "
				<< emp[i].exp << "\n";

			cout << "Age "
				<< emp[i].age << "\n";
			break;
		}
	}

}
// Employee display
void Display()
{
	for(int i=0; i<20; i++ ){
	if (emp[i].code != 0) {
			cout << "Employee information \n";
			cout << " #Name: ";
			cout << emp[i].name;

			cout << " #Employee_ID: ";
			cout << emp[i].code;

			cout << " #Designation: ";
			cout << emp[i].designation;

			cout << " #Experience; ";
			cout << emp[i].exp;

			cout << " #Age; ";
			cout << emp[i].age;

			continue;
		}
	}
}

// Driver Code
int main()
{
	cout << "Enter The choice:\n\n";
	cout << "1. Create a Table	\n";
	cout << "2. Insert New Employee Information\n";
	cout << "3. Delete employee Information\n";
	cout << "4. Search an Employee\n";
	cout << "5. Display All the Employee\n";
	cout << "5. Exit\n";

	int choice;
    do{
    cout << "\n\nEnter the choice:";
    cin >> choice;
        switch(choice){

        case 1: build();
        break;
        case 2: insert();
        break;
        case 3: deleteRecord();
        break;
        case 4: searchRecord();
        break;
		case 5:	Display();
        break;
		case 6: cout << "\nExit!";
        break;
        default: cout << "\nWrong Choice!! Try Again!!";
        }
    }while(choice != 6);
    return 0;
	return 0;
}
