#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"ClsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen:protected  clsScreen
{
 private:

	 static void _PrintCurrencyCard(clsCurrency Currency,string Title= "Currency Card:")
	 {
		 cout <<"\n" << Title << endl;
		 cout << "_______________________________\n";
		 cout << "\nCountry : " << Currency.Country();
		 cout << "\nCode     :" << Currency.CurrencyCode();
		 cout << "\nName     :" << Currency.CurrencyName();
		 cout << "\nRate(1$) :" << Currency.Rate();
		 cout << "\n_______________________________\n";

	 }

	 static clsCurrency _GetCurrency(string Message)
	 {
		 

		 cout << Message ;

		 string CurrencyCode = ClsInputValidate::ReadString();

		 while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		 {
			 cout << "\nCurrency is not found, choose another one: ";
			 CurrencyCode = ClsInputValidate::ReadString();
				
		 }
		 clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		 return Currency;



		
	 }

	 static float _ReadAmount()
	 {
		 float amount;

		 cout << "\nEnter Amount to Exchange:";
		 cin >> amount;

		 return amount;

	 }

	 static void _PrintCalculationsResults(float Amount,clsCurrency Currency1,clsCurrency Currency2)
	 {
		

		 _PrintCurrencyCard(Currency1, "Convert From:");
		 float AmountInUSD = Currency1.ConvertToUSD(Amount);
		 cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " " << "USD\n";


		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return;

		 }

		 cout << "\nConverting from USD to:\n";
		 
			 _PrintCurrencyCard(Currency2, "Convert To:");
			 float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

			 cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();



		 

	 }
	


 public:
	 static void ShowCurrencyCalculatorScreen()
	 {
		 

		 char Continue = 'y';

		 while (Continue == 'y' || Continue == 'Y')
		 {
			  system("cls");
			 _DrawScreenHeader("\t Currency Calculator");

			 clsCurrency CurrencyFrom = _GetCurrency("\nPleas Enter Currency 1 :");
			 clsCurrency CurrencyTo = _GetCurrency("\nPleas Enter Currency 2 :");
			 float amount = _ReadAmount();

			 _PrintCalculationsResults(amount,CurrencyFrom,CurrencyTo);

			 

			 cout << "\n\nDo you want to perform another calculation? y/n ? ";
			 cin >> Continue;

		 } 

		 

	 }

};

