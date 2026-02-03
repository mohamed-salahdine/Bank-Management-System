#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsBankClient.h"
using namespace std;


class clsWithdrawScreen:protected clsScreen
{
  private:
	  static string _ReadAccountNumber()
	  {
		  cout << "\nPlease enter AccounNumber ? :";

		  string AccountNumber;
		  cin >> AccountNumber;
		  return AccountNumber;

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

	  static void ShowWithdrawScreen()
	  {
		  _DrawScreenHeader("\t  Withdraw Screen");

		  string AccountNumber = _ReadAccountNumber();

		  while (!clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			  AccountNumber = _ReadAccountNumber();

		  }

		  clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		  _PrintClient(Client1);

		  
		  double Amount = 0;
		  cout << "\nPlease enter Withdraw amount? ";
		  Amount = ClsInputValidate::ReadDblNumber();

		  cout << "\nAre you sure you want to perform this transaction? ";
		  char Answer = 'n';
		  cin >> Answer;


		  if (Answer =='y' || Answer == 'Y')
		  {
			  if (Client1.Withdraw(Amount))
			  {
				  cout << "\nAmount Withdrew Successfully.\n";
				  cout << "\nNew Balance is :" << Client1.AccounBalanc;
			  }
			  else
			  {
				  cout << "\nCannot withdraw, Insuffecient Balance!\n";
				  cout <<"\nAmount to Withdraw is :" << Amount;
				  cout << "\nYour Balance is :" << Client1.AccounBalanc;
				  


			  }

		  }
		  else
		  {
			  cout << "\nThe operation has been cancelled.";
		  }
		  


	  }
};

