//samanSadeghyan
//P:simple bank account with 1000$ basic balance.
//with constructor

#include <iostream>

using namespace std;

class BankAccount 
{
public:

	BankAccount (double X)		//
	{							//
								//	constructor!
		A=X;					//
	}							//

	void deposit ()
	{
		cout<<"How much do you want to send to your account:\n";
		cin>>B;
		A+=B;
		cout<<"The operation is done, now your balance is:\n"<<A<<endl;
	}
	void withdraw ()
	{
		cout<<"How much do you want to withdraw from your account:\n";
		cin>>C;
		if (C<=A)
		{
		A-=C;
		cout<<"Operation is done,now balance is:\n"<<A<<endl;
		}
		else
		cout<<"error"<<endl;
	}
	void displayAmount ()
	{
		cout<<"your balance is:\n"<<A<<endl;
	}

private:
	double B;
	double C;
	double A;
};
int main()
{
	double D;
	D=1000;
	
	int X;

	BankAccount myBankAccount(D);

	cout << "1.depositing to account;\n2.withdraw from;\n3.displaying the balance:\n";
	cin>>X;

	if(X==1)
	myBankAccount.deposit();
	else if(X==2)
		 myBankAccount.withdraw();
		 else if(X==3)
			  myBankAccount.displayAmount();
			  else
			  cout<< "error"<<endl;
	system ("pause");
	return 0;
}