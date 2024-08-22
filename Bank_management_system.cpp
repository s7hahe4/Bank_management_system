#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class temp{
int accnumber;
string name;
int balance;

public:
void createaccount(){

    cout<<"Enter your name: ";
    getline(cin,name);

    cout<<"Enter your Account number: ";
    cin>>accnumber;

    cout<<"Enter your Balance: ";
    cin>>balance;

    fstream file;
    file.open("new.txt",ios::out|ios::app);

    file<<name<<" "<<accnumber<<" "<<balance<<endl;
    file.close();


}
void depositebalance(){

ofstream tempfile;
ifstream newfile;
tempfile.open("temp.txt",ios::out);
newfile.open("new.txt",ios::in);
int c=0;
int search;
cout<<"Enter the search id: ";
cin>>search;
cout<<"Enter the how much do you want to deposite : ";
int deposite;
cin>>deposite;

while(newfile>>name>>accnumber>>balance){

    if(accnumber==search){

        tempfile<<name<<" "<<accnumber<<" "<<balance+deposite<<endl;
c++;
    }else{
      tempfile<<name<<" "<<accnumber<<" "<<balance<<endl;

    }


}

if(c==0){

    cout<<endl<<endl<<"Account not found!!!!"<<endl<<endl;
}else{
 cout<<endl<<endl<<"deposite successfull--------"<<endl<<endl;
 }
newfile.close();
tempfile.close();

remove("new.txt");
    rename("temp.txt", "new.txt");


}



void withdrawbalance(){

ofstream tempfile;
ifstream newfile;
tempfile.open("temp.txt",ios::out);
newfile.open("new.txt",ios::in);
int c=0;
int search;
cout<<"Enter the search id: ";
cin>>search;
cout<<"Enter the how much do you want to withdraw : ";
int withdraw;
cin>>withdraw;

while(newfile>>name>>accnumber>>balance){

    if(accnumber==search){

        tempfile<<name<<" "<<accnumber<<" "<<balance-withdraw<<endl;
c++;
    }else{
      tempfile<<name<<" "<<accnumber<<" "<<balance<<endl;

    }


}

if(c==0){

    cout<<endl<<endl<<"Account not found!!!!"<<endl<<endl;

}
else{
    cout<<endl<<endl<<"Withdraw successfull--------"<<endl<<endl;

}
newfile.close();
tempfile.close();

remove("new.txt");
    rename("temp.txt", "new.txt");



}

void accountdetails(){

ifstream file;
file.open("new.txt",ios::in);


while(file>>name>>accnumber>>balance){

    cout<<name<<" "<<accnumber<<" "<<balance<<endl;

}
file.close();

}
};



int main(){
cout<<"-----------Welcome to Bank management system---------------";
cout<<endl<<endl<<"press 1 to create an account ";
cout<<endl<<endl<<"press 2 to deposite Balance ";
cout<<endl<<endl<<"press 3 to withdraw from account ";
cout<<endl<<endl<<"press 4 to see account details ";

cout<<endl<<endl<<"your input: ";


temp l;
int a;
cin>>a;

switch(a){

case 1:
    cin.ignore();
l.createaccount();
cout<<"updatad information-----"<<endl<<endl;
l.accountdetails();

    break;

case 2:

    cin.ignore();
l.depositebalance();
cout<<"updatad information-----"<<endl<<endl;
l.accountdetails();

    break;
case 3:
    cin.ignore();
l.withdrawbalance();

cout<<endl<<endl<<"updatad information-----"<<endl<<endl;
l.accountdetails();

    break;
case 4:
  cin.ignore();
l.accountdetails();

    break;
default:
    cout<<"Invalid input";

    break;

}

return 0;
}
