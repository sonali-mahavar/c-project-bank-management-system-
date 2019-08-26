#include<iostream>
#include<conio.h>
#include<stdlib.h>

class bank {
    public:
    int ac,new_ac;
    static int reset;
    float balance, amount, shorta;

    public:
    int create();
    void deposit();
    void withdraw();
    void chkbalance();
    int menu();
};

int bank::reset=0;
int bank::create()
{
    char name[10];
    char address[20];
    int aadhar;
    int phone_no;
 std::cout<<"enter customer name"<<std::endl;
 std::cin>>name;
 std::cout<<"enter customer's address"<<std::endl;
 std::cin>>address;
 std::cout<<"enter aadhar"<<std::endl;
 std::cin>>aadhar;
 std::cout<<"enter phone no.";
 std::cin>>phone_no ;
 new_ac=++ac;
 return new_ac;

}
void bank::deposit() {
    std::cout<<"\nEnter Account Number:";
    std::cin>>ac;
    if(ac==1001||(ac>=1001&&ac<=new_ac))
    {
        std::cout<<"\nEnter Amount you want to Deposit:";
        std::cin>>amount;
        balance=balance+amount;
        std::cout<<"\n\nMessage: You have successfully deposited Rs."<<amount<<" into your account.\n\nYour Current Balance is:"<<balance<<"\n\n";
        reset++;
    }
    else
    {
        std::cout<<"You have entered invalid account number";
    }
}

void bank::withdraw() {
    std::cout<<"Enter Account Number:";
    std::cin>>ac;
    if(ac==1001||(ac>=1001&&ac<=new_ac))
    {
        std::cout<<"Enter Amount you want to Withdraw:";
        std::cin>>amount;
        if(amount>balance)
        {
            shorta=amount-balance;
            std::cout<<"\n\nYou cannot withdraw Rs."<<amount<<" as your account balance is Rs."<<balance<<"\n\nYou are short of Rs."<<shorta;
        }
        else
        {
            balance=balance-amount;
            std::cout<<"You have Withdrawn Rs."<<amount<<" Successfully\n\n Your account balance is:"<<balance<<"\n\n";
        }
    }
    else
    {
        std::cout<<"You have entered invalid account number";
    }
}

void bank::chkbalance() {
    std::cout<<"Enter Account Number:";
    std::cin>>ac;
    if(reset==0)
    {
        balance=0;
    }
    if(ac==1001||(ac>=1001&&ac<=new_ac))
    {
        std::cout<<"Your Account balance is Rs."<<balance<<"\n\n";
    }
    else
    {
        std::cout<<"Account Doesn't Exist!!";
    }
}


int main()
{
    bank ob;
    ob.ac=1001;
    int ch;
    std::cout<<"Bank Management System"<<std::endl;
    std::cout<<"Submitted to: Ms.Shaziya Sidiqui"<<std::endl;
    std::cout<<"Submitted by: Mansi,Rupali,Sandhya,Sonali(cse IV sem)"<<std::endl;
    std::cout<<"\n";
    std::cout<<"welcome to SBI"<<std::endl;
    std::cout<<"Branch : BU Bhopal";

    do {
        std::cout<<"\n\n\n1.Deposit\n2.Withdraw\n3.Balance Enquiry\n4.Create\n5.Exit\n\n";
        ch=ob.menu();
        switch(ch)
        {
        case 1:ob.deposit();
            break;
        case 2:ob.withdraw();
            break;
        case 3:ob.chkbalance();
            break;
        case 4:
        std::cout<<"customer's a/c no. is"<<ob.create();
        break;
        case 5: exit(1);
        default:std::cout<<"Invalid Choice!!";
        }
    }while(1);
    return 0;
}

int bank::menu()
{
    int ch;
    std::cout<<"\nEnter your Choice:";
    std::cin>>ch;
    return ch;
}

