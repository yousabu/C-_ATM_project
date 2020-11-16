#include <iostream>
using namespace std;

int main()
{
    int password;
    int choice;
    int balance=1000;
    int withdraw;
    int deposit;
    int correct = true;

    cout << "--------------------------------------------------WELCOME TO YOUSSEF ATM------------------------------------------------\n";
    cout << "**********************----The Default Password Is 1234----***********************\n";

  while (password!=1234){
    cout<<"Enter your Password :\n";
    cin >> password;
  }

    do {
        cout << "\n1. Check Account " <<endl;
        cout << "\n2. Withdraw Cash" <<endl;
        cout << "\n3. Deposit Cash " <<endl;
        cout << "\n4. Quit\n" <<endl;
    cout << "Choose from the menu : ";
        cin>> choice;

           switch (choice) {

  case 1 :
      cout << "\n----your balance is = " << balance <<"$------"<<endl;
      break;
  case 2 :
    cout << "\nEnter the amount to withdraw  : \n ";
    cin>> withdraw ;

    if (withdraw > balance){
        cout << "you don't have enough Money.......";
    }else {
    balance = balance - withdraw;
    cout << "*DONE*";

    cout << "\n------your balance is = "<< balance<<" $------" <<endl;
    break;
    }

  case 3:
      cout << "\nEnter the amount you want to Deposit : ...\n";
      cin>> deposit;
      balance = balance + deposit;
      cout<<"\n*DONE*";
       cout << "\n------Your current balance is = " << balance<<" $-------" <<endl;
       break;
  case 4:
    cout << "\n----------------------*THANK FOR USING YOUSSEF ATM*------------------------- \n";
    correct = false;
    break;

  default:
    cout << "\nthe number you Enter is Wrong\n";
    break;





           }
    }while (correct!=false);
}
