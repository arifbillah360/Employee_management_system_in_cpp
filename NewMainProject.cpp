#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;



    struct employee{
        // Variables for employee details
        char name[30];
        char id[5];
        char designation[10];
        int age;
        int ctc;
        int experience;
    };
        char name[30];
        char id[5];
        char designation[10];
        int age;
        int ctc;
        int experience;
        
        
        // Utility functions
        void waitForEnter(void){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listEmployees(void){
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n name  id  designation\n";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
                cout<<"\n"<<name<<"\t"<<id<<"\t"<<designation;
            fclose(file);
            waitForEnter();
        }

        void showDetails(void){
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"Enter employee id: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                    cout<<"\nname: "<<name;
                    cout<<"\nid: "<<id;
                    cout<<"\ndesignation: "<<designation;
                    cout<<"\nage: "<<age;
                    cout<<"\nctc: "<<ctc;
                    cout<<"\nexperience: "<<experience;
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){
            system("cls");
            char checkId[5];
            cout<<"Enter employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"Enter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"Enter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewEmployee(void){
            system("cls");
            cout<<"\n Enter Name of Employee: ";
            cin>>name;
            cout<<"\n Enter Employee ID: ";
            cin>>id;
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }

        void deleteEmployeeDetails(void){
            system("cls");
            char checkId[5];
            cout<<"Enter employee id: ";
            cin>>checkId;
            char ch;
            cout<<"Enter 'y' to confirm deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nDeletion Successful\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }

int main()
{
	int choice;

    do{
	cout << "Enter The choice:\n\n";
	cout << "1. Add new Employee in the\n";
	cout << "2. Update emplOyee details\n";
	cout << "3. Show employee details\n";
	cout << "4. Display all the employee\n";
	cout << "5. Remove employee\n";
	cout << "5. Exit\n";
	
    cout << "\n\nEnter the choice:";
    cin >> choice;
        switch(choice){

        case 1: addNewEmployee();
        break;
        case 2: editExisting();
        break;
        case 3: showDetails();
        break;
        case 4: listEmployees();
        break;
		case 5:	deleteEmployeeDetails();
        break;
		case 6: cout << "\nExit!";
        break;
        default: cout << "\nWrong Choice!! Try Again!!";
        }
    }while(choice != 6);
	return 0;
}
