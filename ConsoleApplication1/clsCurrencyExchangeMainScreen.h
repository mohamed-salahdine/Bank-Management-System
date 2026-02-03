#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsMainScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
#include<iomanip>

using namespace std;

class clsCurrencyExchangeMainScreen:public clsScreen
{
 private:
	 enum enCurrenciesMainMenueOptions{eListCurrencies=1,eFindCurrency,eUpdateCurrencyRate,eCurrencyCalculator,eMainMenue};
	 static short ReadCurrenciesMainMenueOptions()
	 {
		 
		 cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		 short Choice = ClsInputValidate::ReadShortNumberBetween(1, 5);

		 return Choice;
	 }
	 static void _GoBackToCurrenciesMenue()
	 {
		 cout << "\n\nPress any key to go back to Currencies Menue...";
		 system("pause>0");
		 ShowCurrenciesMenue();

	 }

	 static void _ShowCurrenciesListScreen()
	 {
		 clsCurrenciesListScreen::ShowCurrenciesListScreen();
	 }


	 static void _ShowFindCurrencyScreen()
	 {
		 //cout << "\nHere we will write the code..\n";
		 clsFindCurrencyScreen::ShowFindCurrencyScreen();
	 }


	 static void _ShowUpdateCurrencyRateScreen()
	 {
		// cout << "\nHere we will write the code..\n";
		 clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	 }


	 static void _ShowCurrencyCalculatorScreen()
	 {
		// cout << "\nHere we will write the code..\n";
		 clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	 }
	

		 


	 static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	 {
		 switch (CurrenciesMainMenueOptions)
		 {
		   case enCurrenciesMainMenueOptions::eListCurrencies:
		   {
			   system("cls");
			   _ShowCurrenciesListScreen();

			   _GoBackToCurrenciesMenue();
			   break;
		   }
		   case enCurrenciesMainMenueOptions::eFindCurrency:
		   {
			   system("cls");

			   _ShowFindCurrencyScreen();
			   _GoBackToCurrenciesMenue();
			   break;
		   }
		   case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
		   {
			   system("cls");

			   _ShowUpdateCurrencyRateScreen();
			   _GoBackToCurrenciesMenue();
			   break;
		   }
		   case enCurrenciesMainMenueOptions::eCurrencyCalculator:
		   {
			   system("cls");

			   _ShowCurrencyCalculatorScreen();
			   _GoBackToCurrenciesMenue();
			   break;
		   }
		   case enCurrenciesMainMenueOptions::eMainMenue:
		   {
			   
			   
			   break;
		   }

		 }

	 }

 public:

	 static void ShowCurrenciesMenue()
	 {
		  system("cls");
		 _DrawScreenHeader("    Currancy Exhange Main Screen");

		 cout << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n\033[0m\n";
		 cout << setw(37) << left << "" << "\t\t\033[31m" << "Currency Exchange Menue\033[0m\n\n";
		 cout << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n\033[0m\n";
		 cout << setw(37) << left << "" << "\t\033[33m[1]" << "\033[0m" << " List Currencies.\n";
		 cout << setw(37) << left << "" << "\t\033[33m[2]" << "\033[0m" << " Find Currency.\n";
		 cout << setw(37) << left << "" << "\t\033[33m[3]" << "\033[0m" << " Updat Rate.\n";
		 cout << setw(37) << left << "" << "\t\033[33m[4]" << "\033[0m" << " Currency Calculator.\n";
		 cout << setw(37) << left << "" << "\t\033[33m[5]" << "\033[0m" << " Main Menue.\n\n";
		 cout << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n\033[0m\n";

		
		 _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMainMenueOptions());

	 }

};

