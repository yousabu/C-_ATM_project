#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

void delete_atm()
{

    fstream stud;
    fstream temp;

    stud.open("ATM.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char a[25];
    char phone [25];
    char current[25];
    cin.ignore();
    cout<<" \n\t enter the phone number to delete record : ";
    cin.getline(current,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(current,25);
        if(strcmp(phone,a)==0)
        {
            continue;
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<current<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("ATM.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(current,25);
        stud<< name<<'|'<<phone<<'|'<<current<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void update_atm()
{
    fstream stud;
    fstream temp;

    stud.open("ATM.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char a[25];
    char phone [25];
    char current[25];
    cin.ignore();
    cout<<" \n\t enter the phone number to update record : ";
    cin.getline(current,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(current,25);
        if(strcmp(phone,a)==0)
        {

            cout<<" \n\tenter new value of record  \n ";
            cout<<" \n name : ";
            cin.getline(name,25);
            cout<<" \n phone : ";
            cin.getline(phone,25);
            cout<<" \n current balance : ";
            cin.getline(current,25);
            temp<< name<<'|'<<phone<<'|'<<current<<'\n';
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<current<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("ATM.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(current,25);
        stud<< name<<'|'<<phone<<'|'<<current<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void display_all()
{
    char name [25];
    char current[25];
    char phone [25];

    fstream stud;
    stud.open("ATM.txt",ios::in);

    cout<< " \n\t name \t phone \t current balance \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(current,25);
        cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<current<<endl;

    }
}
void search_atm(   )
{

    fstream stud;
    stud.open("ATM.txt",ios::in);
    char name [25];
    char current[25];
    char phone [25];
    char a[25];
    cout<<" \n enter the phone to search about it : ";
    cin.ignore();
    cin.getline(a,25);
    int x=0;
    cout<< " \n\t name \t phone \t current \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(current,25);
        if(strcmp(phone, a)==0)
        {
            cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<current<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    stud.close();
}
void  insert_atm()
{

    char name [25];
    char current[25];
    char phone [25];
    fstream stud;
    stud.open("ATM.txt", ios::app);
    cin.ignore();
    cout<<" \n name : ";
    cin.getline(name,25);
    cout<<" \n phone : ";
    cin.getline(phone,25);
    cout<<" \n current : ";
    cin.getline(current,25);
    stud<< name<<'|'<<phone<<'|'<<current<<'\n';
    cout<< "done !";
    stud.close();
}

int main()
{
    int balance ;
	int pin , choice;
	int withdraw ,deposit ;
	char correct = true ;

    cout<<"\n............................................................................WELCOME TO ATM BANK........................................................................\n";
    cout<< "\tEnter your pin :\t" ;
    cin>> pin ;

	while(pin != 12345)  {

		cerr<< " your pin is false  :"  ;
		exit(1) ;}


	do{

		cout<< "\t\t\t1. insert your data................"<<endl;
		 cout<<"\t\t\t2. check your data ........................."<<endl;
			cout<< "\t\t\t3. withdraw cash.................."<<endl;
				cout<< "\t\t\t4. Deposit cash................"<<endl;
				cout << "\t\t\t5. do want search about your balance......................"<<endl;
				cout << "\t\t\t6. change your current balance ........"<<endl;
				 cout << "\t\t\t7. do want delete your account........."<<endl ;
					cout<< "\t\t\t8. quite....................."<<endl;

		cout<< "\t\t\t\t........................choose from the menu ........................ : \t";
		cin>> choice;

		switch (choice){

			case 1:
			    insert_atm();
            break;


			case 2:
				display_all();
                break;



			case 3:
				cout<<"Enter the amount to withdraw"<<endl;
				cin>>withdraw;
				cout << "please enter your current balance =$";
				cin >> balance;
				if(withdraw > balance){
					cout<<"you don't have enough money"<<endl;
					}
					else{

						balance = balance - withdraw;
						cout<< "your current balance is= $"<<balance<<endl;

					break;
					  }


			case 4:
				cout <<"enter the amount : ";
				cin >> deposit;
				cout << "please enter your current balance =$";
				cin >> balance;
			balance = balance	+ deposit;
				cout<< "your current balance is= $"<< balance<<endl;
				break;

			case 5:
			     search_atm();
            break;
            case 6:
			        update_atm();
                   break;
            case 7:
            	delete_atm();
                break;

		    case 8:
		    	cout<< "\n.................................thanks.................................\n";
				correct = false;
			    break;

			default :
			    cout<<"the number doesn't exist................";
				break;

			}



	}while(correct != false);


	return 0;
}
