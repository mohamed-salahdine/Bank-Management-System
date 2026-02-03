#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"ClsInputValidate.h"
using namespace std;






class clsDeleteClientScreen:protected clsScreen
{
   private:

	   static void _PrintClient(clsBankClient& Clint)
	   {
		




		   cout << "\033[31m" << "\nClient Card:";
		   cout << "\033[38;5;208m" << "\n==================================";
		   cout << "\033[33m" << "\nFirstName     :" << "\033[0m" << Clint.FirtsName << endl;
		   cout << "\033[33m" << "\nLastName      :" << "\033[0m" << Clint.LastName << endl;
		   cout << "\033[33m" << "\nFullName      :" << "\033[0m" << Clint.FullName() << endl;
		   cout << "\033[33m" << "\nEmail         :" << "\033[0m" << Clint.Email << endl;
		   cout << "\033[33m" << "\nPhone         :" << "\033[0m" << Clint.Phone << endl;
		   cout << "\033[33m" << "\nAccountNamber :" << "\033[0m" << Clint.GetAccountNamber() << endl;
		   cout << "\033[33m" << "\nPassWord      :" << "\033[0m" << Clint.GetPinCod() << endl;
		   cout << "\033[33m" << "\nBalanc        :" << "\033[0m" << Clint.GetAccuntBalanc() << endl;
		   cout << "\033[38;5;208m" << "\n==================================\n" << "\033[0m";
		   
	   }


   public:

	   static void ShowDeleteClientScreen()
	   {
		   if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		   {
			   return;
		   }

		   _DrawScreenHeader("\tDelete Client Screen");
		   string AccountNumber = "";

		   cout << "\nPlease Enter Account Number: ";
		   AccountNumber = ClsInputValidate::ReadString();

		   while (!clsBankClient::IsClientExist(AccountNumber))
		   {
			   cout << "\nAccount number is not found, choose another one: ";
			   AccountNumber = ClsInputValidate::ReadString();
		   }

		   clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		   _PrintClient(Client1);

		   
		   cout << "\033[31;1;5m" << "\nAre you sure you want to delete this client y/n ?"<<"\033[0m ";
		   

		   char Answer = 'n';
		   cin >> Answer;

		   if (Answer == 'y' || Answer == 'Y')
		   {
			   if (Client1.Delete())
			   {
				    cout << "\nClient Deleted Successfully :-)\n";
				   _PrintClient(Client1);

			   }
			   else
			   {
				   cout << "\nError Client Was not Deleted\n";
			   }

		   }


	   }

};

