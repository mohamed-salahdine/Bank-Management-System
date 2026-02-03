#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"ClsInputValidate.h"
using namespace std;


class clsDepositScreen:protected clsScreen
{
  private:
	  static string _ReadAccountNumbe()
	  {
		  string AccounNumber;
		  cout << "\nPlease enter AccountNumber ? ";
		  cin >> AccounNumber;
		  return AccounNumber;

	  }

	  static void _PrintClient(clsBankClient& Clint)
	  {
		  cout << "\nClient Card:";
		  cout << "\n---------------------------------";
		  cout << "\nFirstName      :" << Clint.FirtsName << endl;
		  cout << "\nLastName       :" << Clint.LastName << endl;
		  cout << "\nFullName       :" << Clint.FullName() << endl;
		  cout << "\nEmail          :" << Clint.Email << endl;
		  cout << "\nPhone          :" << Clint.Phone << endl;
		  cout << "\nAccountNember  :" << Clint.GetAccountNamber() << endl;
		  cout << "\nPassWord       :" << Clint.PinCod << endl;
		  cout << "\nBalance        :" << Clint.AccounBalanc << endl;
		  cout << "\n---------------------------------\n";
	  }

  public:

	  static void ShowDepositScreen()
	  {
		  _DrawScreenHeader("\t   Deposit Screen");

		  string AccountNumber = _ReadAccountNumbe();


		  while (!clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			  AccountNumber = _ReadAccountNumbe();
		  }

		  clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		  _PrintClient(Client1);

		  double Amount;
		  cout << "\nPlease enter deposit amount? ";
		  Amount = ClsInputValidate::ReadDblNumber();

		  cout << "\nAre you sure you want to perform this transaction? ";
		  char answer;
		  cin >> answer;

		  

		  if (answer=='y'||answer=='Y')
		  {
			  Client1.Diposit(Amount);
			  cout<<"\n\nAmount Deposited Successfully.\n";
			  cout << "\nNew Balance Is: " << Client1.AccounBalanc;

		  }
		  else
		  {
			  cout << "\nOperation was cancelled";
		  }


	  }

};

