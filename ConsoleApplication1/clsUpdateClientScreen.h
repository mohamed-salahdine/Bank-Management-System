#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"ClsInputValidate.h"
using namespace std;



class clsUpdateClientScreen:protected clsScreen
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

	  static void ShowUpdateClientScreen()
	  {
		  if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		  {
			  return;
		  }

		  _DrawScreenHeader("\tUpdate Client Screen");

		  string AccountNumber = "";
		  cout << "\nPlease Enter client Account Number: ";
		  AccountNumber = ClsInputValidate::ReadString();

		  while (!clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << "\nAccount number is not found, choose another one: ";
			  AccountNumber = ClsInputValidate::ReadString();
		  }

		  clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		  _PrintClient(Client1);

		  cout << "\nAre you sure you want to update this client y/n? ";

		  char Answer = 'n';
		  cin >> Answer;

		  if (Answer=='y' || Answer=='Y')
		  {
			  cout << "\n\nUpdate Client Info:";
			  cout << "\n____________________\n";

			  _ReadClientInfo(Client1);

			  clsBankClient::enSaveResults SaveResult;

			  SaveResult = Client1.Save();

			  switch (SaveResult)
			  {
			    case clsBankClient::svSucceeded:
			    {
					cout << "\nAccount Updated Successfully :-)\n";
					_PrintClient(Client1);

					break;
			    }
				case clsBankClient::svFaildEmptyObject:
				{
					cout << "\nError account was not saved because it's Empty";

					break;
				}
				

			  }



		  }



	  }


};

