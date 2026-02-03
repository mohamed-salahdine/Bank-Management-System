#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsListClientsScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
#include"Global.h"
#include<iomanip>
using namespace std;

class clsMainScreen:protected clsScreen
{
  private:

   static enum  enMainMenueOptions{ eListClients=1,eAddNewClient=2, eDeleteClient, eUpdateClient, eFindClient, eShowTransactionsMenue, eManageUsers,eLoginRegister,eCurrncyExchange, eExit};

   static short _ReadMainMenueOption()
   {
	   short number;
	   cout << "\n\t\t\t\t\tChoose What do you want to do [1 to 10] ?";
	   number = ClsInputValidate::ReadShortNumberBetween(1, 10);
	   return number;

   }
   static void _GoBackToMainMenue()
   {
	   cout << "\n\n\tPress any button to return to the main menu...";
	   system("pause>0");
	   ShowMainMenue();


   }

   static void  _ShowAllClientsScreen()
   {
	   clsClientListScreen::ShowClientsList();

   }
   static void _ShowAddNewClientsScreen()
   {
	  // cout << "Show New Clinet Will be her...";
	   clsAddNewClientScreen::ShowAddNewClientScreen();
   }
   static void _ShowDeleteClientScreen()
   {
	   //cout << "Show Deletd Clinet Will be her...";
	   clsDeleteClientScreen::ShowDeleteClientScreen();
   }
   static void _ShowUpdateClientScreen()
   {
	   //cout << "Show Updat Clinet Will be her...";
	   clsUpdateClientScreen::ShowUpdateClientScreen();
   }
   static void _ShowFindClientScreen()
   {
	   //cout << "Show Find Clinet Will be her...";
	   clsFindClientScreen::ShowFindClientScreen();
   }
   static void _ShowTransactionsMenue()
   {
	   //cout << "Show Transaction will be her...";
	   clsTransactionsScreen::ShowTransactionsMenue();
   }
   static void _ShowManageUsersMenue()
   {
	  // cout << "Show Manag Users will be her...";
	   clsManageUsers::ShowManageUsersMenue();
   }

   static void _ShowLoginRegisterScreen()
   {
	   clsLoginRegisterScreen::ShowLoginRegisterScreen();
	   
   }
   static void _ShowCurrencyExchangeMainScreen()
   {
	   clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();

   }

 
   static void _Logout()
   {
	   CurrentUser = clsUser::Find("","");
	   


   }

   static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
   {
	   switch (MainMenueOption)
	   {
	     case enMainMenueOptions::eListClients:
	     {
			 system("cls");
			 _ShowAllClientsScreen();
			 _GoBackToMainMenue();
			 break;
	     }
		 case enMainMenueOptions::eAddNewClient:
		 {
			 system("cls");
			 _ShowAddNewClientsScreen();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions ::eDeleteClient:
		 {
			 system("cls");
			 _ShowDeleteClientScreen();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions::eUpdateClient:
		 {
			 system("cls");
			 _ShowUpdateClientScreen();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions::eFindClient:
		 {
			 system("cls");
			 _ShowFindClientScreen();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions::eShowTransactionsMenue:
		 {
			 system("cls");
			 _ShowTransactionsMenue();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions::eManageUsers:
		 {
			 system("cls");
			 _ShowManageUsersMenue();
			 _GoBackToMainMenue();
			 break;
		 }

		 case enMainMenueOptions::eLoginRegister:
		 {
			 system("cls");
			 _ShowLoginRegisterScreen();
			 _GoBackToMainMenue();
			 break;
		 }
		 case enMainMenueOptions::eCurrncyExchange:
		 {
			 system("cls");
			 _ShowCurrencyExchangeMainScreen();
			 _GoBackToMainMenue();
			 break;
		 }

		
		 case enMainMenueOptions::eExit:
		 {
			 system("cls");
			// _GoBackToMainMenue();
			 _Logout();
			 break;
		 }



	   }
   }



  public:

	  static void ShowMainMenue()
	  {
		  system("cls");
		  _DrawScreenHeader("\t\tMain Screen");
		  cout << setw(37) << left << "" << "\033[38;5;208m" << "=========================================== \033[0m\n";
		  cout << setw(37) << left << "" << "\t\t\t\033[31m" << "Main Menue\n\033[0m";
		  cout << setw(37) << left << "" << "\033[38;5;208m" << "=========================================== \033[0m\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[1]\033[0m" << "   Show Client List.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[2]\033[0m" << "   Add New Client.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[3]\033[0m" << "   Delete Client.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[4]\033[0m" << "   Update Client Info.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[5]\033[0m" << "   Find Client.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[6]\033[0m" << "   Transactions.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[7]\033[0m" << "   Manage Users.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[8]\033[0m" << "   Login Register.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[9]\033[0m" << "   Currency Exchange.\n";
		  cout << setw(37) << left << "" << "\t\033[33m" << "[10]\033[0m" << "  Logout.\n";
		  cout << setw(37) << left << "" << "\033[38;5;208m" << "=========================================== \033[0m\n";
		 
		

		  _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

		  
		  

	  }


};

