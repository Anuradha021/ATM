#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
class ATM{
    private :
     string accountNumber;
     string pin;
     double balance;
     public:
     ATM(string accNo,string accPin){
        accountNumber = accNo;
        pin = accPin;
        balance = 0.0;
     }
     bool checkPin(string inputPin){
        if(inputPin == pin){
            return true;
        }
        else{
            return false;
        }
     }
     void deposit(double amount ){
        balance += amount;
        cout<<"deposit sucessful your current balance is "<<balance<<endl;
     }
     void withdraw(double amount){
      if(amount <= balance){
         balance -= amount;
         cout<<"Aftre withdraw balance is "<<balance<<endl;
      }
      else{
         cout<<"insufficient balance!!"<<endl;
      }
     }
     void checkBalance(){
      cout<<"Your balance is "<<balance<<endl;
     }
};
int main(){
   string accNo,Pin,inputPin;
   int choice;
   cout<<"welcome to the ATM!!"<<endl;
   cout<<"Enter account number";
   cin>>accNo;
     if (accNo.length() != 11 || !all_of(accNo.begin(), accNo.end(), ::isdigit) ) {
        cout << "Reenter your account number! Account number must be 11 digits!" << endl;
        return 0; 
    }

   cout<<"Enter the pin";
   cin>>Pin;


   ATM obj(accNo,Pin);

   cout<<"Enter pin for ATM process!!"<<endl;
   cin>>inputPin;
   if(!obj.checkPin(inputPin)){
      cout<<"Invalid Pin!! Access Denied "<<endl;

   }
   if(obj.checkPin(inputPin)){
   do{
      cout<<"\n -------ATM MENU------"<<endl;
      cout<< "1. deposit Money "<<endl;
      cout<<"2. withdraw Money"<<endl;
      cout<<"3. check balance"<<endl;
      cout<<"4. exit"<<endl;
      cout<<"Enter your choice"<<endl;
      cin>>choice;
      switch(choice){
         case 1:
            double amount;
            cout<<"Enter amount to deposit";
            cin>>amount;
            obj.deposit(amount);
            break;
         
            case 2:
            
            cout<<"Enter amount to withdraw";
            cin>>amount;
            obj.withdraw(amount);
            break;
            
            case 3:
            obj.checkBalance();
            break;
            
            case 4:
            cout<<"Thank you for visiting ATM!!"<<endl;
            break;
            default:
            cout<<"Invalid choice please try again"<<endl;
      
      }
   } while(choice != 4);}
   return 0;
}