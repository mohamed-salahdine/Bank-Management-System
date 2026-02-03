#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsTransferScreen:public clsScreen
{
 private:

	 static void _PrintClient(clsBankClient Client)
	 {
		 cout << "\nClint Card:";
		 cout << "\n___________________\n";
		 cout << "\nFull Name   :" << Client.FullName();
		 cout << "\nAcc.Number  :" << Client.GetAccountNamber();
		 cout << "\nBalance     :" << Client.AccounBalanc;
		 cout << "\n___________________\n";

	 }

	 static string _ReadAccountNumber(string Messag)
	 {
		 string AccountNumber;
		 cout << "\nPlease Enter Account Number to Transferé " << Messag << " :";
		 AccountNumber = ClsInputValidate::ReadString();
		 while (!clsBankClient::IsClientExist(AccountNumber))
		 {
			 cout << "\nAccount number is not found, choose another one: ";
			 AccountNumber = ClsInputValidate::ReadString();
		 }
		 return AccountNumber;
	 }

	 static float ReadAmount(clsBankClient SourceClient)
	 {
		 float Amount;
		 cout << "\nEnter Transfer Amount? ";

		  Amount = ClsInputValidate::ReadFloatNumber();
		 while (Amount>SourceClient.AccounBalanc)
		 {
			 cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			  Amount = ClsInputValidate::ReadFloatNumber();
		 }
		 

		 return Amount;
		

	 }

 public:

	 static void ShowTransferScreen()
	 {
		 _DrawScreenHeader("\tTransfer Screen");

		 clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
		 _PrintClient(SourceClient);

		 clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		 _PrintClient(DestinationClient);

		 float Amount = ReadAmount(SourceClient);


		 
		 cout << "\nAre you sure you want to perform this operation? y/n? ";
		 char Answer = 'n';
		 cin >> Answer;

		 if (Answer=='y'||Answer=='Y')
		 {
			 if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			 {
				 cout << "\nTransfer done successfully\n";
				 
			 }
			

		 }
		 else
		 {
			 
		 }

		
		
		 _PrintClient(SourceClient);
		 _PrintClient(DestinationClient);


	 }
};

