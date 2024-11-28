// Banking System
// Make constructors to input balance and ROI and destructor that destroys class objects created by constructors

// Functions: 
//   Deposit - To make deposit
//   Withdraw – To withdraw an amount
//   Compound – To find compound interest
//   getBalance – To know the balance amount
//   Menu – To display menu options

#include<iostream>
using namespace std;

class BalanceAndROI{
  double balance , roi;
  public:
  BalanceAndROI(double b, double r){
    balance = b; 
    roi = r;
  };
  ~BalanceAndROI(){
    cout << "Objects destroyed!!!!!!!" << endl;
  };

  void deposit(double amount){
    if(amount>0){ 
      balance+=amount;
      cout << "\nCredited: " << amount << endl
            << "New Balance: " << balance << endl;
    } else cout<< "Invalid amount" << endl;
  }

  void withdraw(double amount){
    if(amount>0 && amount < balance){ 
      balance-=amount;
      cout << "\nDebited: "<< amount << endl 
            << "New Balance: " << balance << endl;
    } 
    else if(balance<amount) cout << "\nInsufficient Balance!!" << endl;
    else cout<< "\nInvalid amount" << endl;
  }

  void compound(int years){
    if (years > 0) {
        double compoundedAmount = balance * pow(1 + roi / 100, years);
        cout << "\nAfter " << years << " years, the compounded balance will be: " << compoundedAmount << endl;
      } else {
          cout << "\nInvalid number of years for compounding." << endl;
      }
  }

  void getBalance(){
    cout<<"\nBalance: " << balance << endl;
  }

  void menu(){
    cout << "\nBanking System Menu:" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Compound Interest" << endl;
    cout << "4. Get Balance" << endl;
    cout << "5. Exit\n" << endl;
  }
};

int main(){
  double b=0, r=0;
  cout << "Enter Balance and Rate of Interest: ";
  cin >> b >> r;
  BalanceAndROI account(b,r);
  int choice;
  do{
    account.menu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        account.deposit(amount);
        break;
    }
    case 2: {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        account.withdraw(amount);
        break;
    }
    case 3: {
        int years;
        cout << "Enter number of years for compounding: ";
        cin >> years;
        account.compound(years);
        break;
    }
    case 4:
        account.getBalance();
        break;
    case 5:
        cout << "Exiting the program." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
  } while(choice != 5);
  return 0;
}