#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsFindClientScreen:protected clsScreen
{
 private:
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

	 static void ShowFindClientScreen()
	 {
		 if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		 {
			 return;
		 }

		 clsScreen::_DrawScreenHeader("\t\tFind Clinet");

		 string AccountNumber;
		 cout <<"\nPlease Enter Account Number: " ;
		 AccountNumber = ClsInputValidate::ReadString();

		 while (!clsBankClient::IsClientExist(AccountNumber))
		 {
			 cout << "\nAccount number is not found, choose another one: ";
			 AccountNumber = ClsInputValidate::ReadString();
		 }

		 clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		 if (!Client1.IsEmpty())
		 {
			 cout <<"\nClient Found :-)\n" ;
		 }
		 else
		 {
			 cout << "\nClient Was not Found :-(\n";
		 }

		 _PrintClient(Client1);
	 }

};

