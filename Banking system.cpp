#include<iostream>
#include<conio.h>
#include<fstream>
//#include<string.h>
using namespace std;
class bank
{

	char name[20];
	char type;
	int mybalance;
	int account_no;
	public:
		
		void menu();
		void get();
		void deposite();
		void searchdata();
		void withdraw();
		void log_out();
		void showdata()
		{
			cout<<"ACCOUNT_NO:"<<account_no<<endl;
			cout<<"NAME:"<<name<<endl;
			cout<<"YOUR ACCOUNT BALANCE"<<mybalance<<endl;
		}
		
};
void bank::menu()
{system("cls");
	int i;
	int choose;
	cout<<"\n\n\t 1.NEW ACCOUNT \n";
	cout<<"\n\n\t 2.DEPOSIT AMOUNT \n";
	cout<<"\n\n\t 3.WITHDRAW AMOUNT \n";
	cout<<"\n\n\t 4.BALANCE ENQUIRY \n";
	cout<<"\n\n\t 5.LOG OUT \n";
	cout<<"\n\n\t CHOOSE YOUR OPTION\n";
	cin>>choose;
	switch(choose)
	{
		case 1:
			get();
			break;
		case 2:
				deposite();
				break;
		case 3:
				withdraw();
				break;
		case 4:
			searchdata();
			break;
		case 5:
			log_out();
			break;
			
	}
};
void bank::log_out()
{
	system("cls");
	int x;
	cout<<"\n\n\tENTER YOUR ACCOUNT NUMBER:";
	cin>>x;
	cout<<"\n\n\t\t THANK'S FOR USING ONLINE BANKING";
	getch();
}
void bank::withdraw()
{system("cls");
	int i,l=0;
	int y=0,k;
	cout<<"enter your account number";
	cin>>i;
	bank b1;
	fstream fin,fin2;
	fin.open("abcde.txt",ios::in|ios::binary);
	fin2.open("abcdef.txt",ios::out|ios::binary);
	fin.read((char*)&b1,sizeof(b1));
	while(!fin.eof())
	{
		
		if(b1.account_no==i)
		{
			cout<<"HOW MUCH MONEY YOU WANt TO WITHDRAW?";
			cin>>y;
			b1.mybalance=b1.mybalance-y;
			cout<<"\n YOUR UPDATED BALANCE:"<<b1.mybalance<<endl;
			fin2.write((char*)&b1,sizeof(b1));
			l++;
		}
		else
		{
		fin2.write((char*)&b1,sizeof(b1));
	    }  
		 fin.read((char*)&b1,sizeof(b1));  
	}
	if(l==0)
	cout<<"ACCOUNT DOESN'T EXIST"<<endl;
	fin.close();
	fin2.close();
	remove("abcde.txt");
	if(rename("abcdef.txt","abcde.txt")==0)
	cout<<"YOUR RECORD IS UPDATED"<<endl;
	cout<<"\t\t\t press 0 to go to menu ";
 cin>>k;
 if(k==0)
   menu();
   else
   return;
}
void bank::deposite()
{system("cls");
	int i,l=0;
	int y=0,k;
	cout<<"enter your account number";
	cin>>i;
	bank b1;
	fstream fin,fin2;
	fin.open("abcde.txt",ios::in|ios::binary);
	fin2.open("abcdef.txt",ios::out|ios::binary);
	fin.read((char*)&b1,sizeof(b1));
	while(!fin.eof())
	{
		
		if(b1.account_no==i)
		{
			cout<<"HOW MUCH MONEY YOU WANt TO ADD?";
			cin>>y;
			b1.mybalance=b1.mybalance+y;
			fin2.write((char*)&b1,sizeof(b1));
			l++;
		}
		else
		{
		fin2.write((char*)&b1,sizeof(b1));
	    }  
		 fin.read((char*)&b1,sizeof(b1));  
	}
	if(l==0)
	cout<<"ACCOUNT DOESN'T EXIST"<<endl;
	
	fin.close();
	fin2.close();
	if(remove("abcde.txt")==0)
	cout<<"removed";
	if(rename("abcdef.txt","abcde.txt")==0)
	cout<<"RENAMED";
	cout<<"\t press 0 to go to menu ";
 cin>>k;
 if(k==0)
   menu();
   else
   return;
}
void bank::searchdata()
{system("cls");
	double i;
	int k,l=0;
	cout<<"ENTER your account number=";
	cin>>i;
     bank b;
	fstream fin;
	fin.open("abcde.txt",ios::binary|ios::in);
	fin.read((char*)&b,sizeof(b));
	while(!fin.eof())
	{
	
		if(b.account_no==i)
		{
			b.showdata();
			l++;
		}
			fin.read((char*)&b,sizeof(b));
	}
	if(l==0)
	cout<<"ACCOUNT DOESN'T EXIST"<<endl;
	fin.close();
	cout<<"\t press 0 to go to menu ";
 cin>>k;
 if(k==0)
   menu();
   else
   return;
	
}
void bank::get()
{ 
system("cls");
  int i;
  bank c;
 fstream outfile;
 outfile.open("abcde.txt",ios::app|ios::binary);
 cout<<"\t CREATE YOUR ACCOUNT NUMBER :";
 cin>>c.account_no;
 cout<<"\t Enter your name :-";
 cin>>c.name;
 cout<<"\t choose your account_type(c/s):-";
 cin>>c.type;
 cout<<"\t How much money u want save in your account :-";
 cin>>c.mybalance;
 	outfile.write((char*)&c,sizeof(c));
 outfile.close();
 cout<<"\t \tpress 0 to go to menu ";
 cin>>i;
 if(i==0)
   menu();
   else
   return;
}
void intro()
{
	cout<<"\n\n\n\n\t\t       WELCOME TO MINI BANKING";
}
int main()
{
	bank b;
	intro();
	
	getch();
	system("cls");
	b.menu();
	
	return 0;
}
