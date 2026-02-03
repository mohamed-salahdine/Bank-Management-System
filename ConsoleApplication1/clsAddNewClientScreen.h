#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"ClsInputValidate.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
  private:
	  static void _ReadClientInfo(clsBankClient& Client)
	  {
		  cout << "\nEnter FirstName: ";

		  Client.FirtsName = ClsInputValidate::ReadString();

		  cout << "\nEnter LastName: ";
		  Client.LastName = ClsInputValidate::ReadString();

		  cout << "\nEnter Email: ";
		  Client.Email = ClsInputValidate::ReadString();

		  cout << "\nEnter Phone: ";
		  Client.Phone = ClsInputValidate::ReadString();

		  cout << "\nEnter PinCode: ";
		  Client.PinCod = ClsInputValidate::ReadString();

		  cout << "\nEnter Account Balance: ";
		  Client.AccounBalanc = ClsInputValidate::ReadFloatNumber();


	  }

	  static void _PrintClient(clsBankClient &Clint)
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

	  static void ShowAddNewClientScreen()
	  {
		  if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		  {
			  return;
		  }
		  _DrawScreenHeader("\t  Add New Client Screen");
		  string AccountNumber="";

		  cout << "\nPlease Enter Account Number: ";
		  AccountNumber = ClsInputValidate::ReadString();

		  while (clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << "\nAccount Number Is Already Used, Choose another one: ";
			  AccountNumber = ClsInputValidate::ReadString();

		  }

		  clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		  _ReadClientInfo(NewClient);

		  clsBankClient::enSaveResults SaveResult;

		  SaveResult = NewClient.Save();

		  switch (SaveResult)
		  {
		    case clsBankClient::svSucceeded:
		    {
				
				 cout << "\nAccount Addeded Successfully :-)\n";
				_PrintClient(NewClient);
				break;
		    }
			case clsBankClient::svFaildClientExist:
			{
				cout << "\nError account was not saved because account number is used!\n";
				break;
			}
			case clsBankClient::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because account number is used!\n";
				break;
			}


		  }







	  }

	 

};

