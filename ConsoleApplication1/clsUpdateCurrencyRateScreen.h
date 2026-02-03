#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"ClsInputValidate.h"
#include"ClsString.h"
using namespace std;

class clsUpdateCurrencyRateScreen:protected clsScreen
{
  private:

	  static void _PrintCurrency(clsCurrency Currency)
	  {
		  cout << "\nCurrency Card:\n";
		  cout << "_______________________________\n";
		  cout << "\nCountry : " << Currency.Country();
		  cout << "\nCode     :" << Currency.CurrencyCode();
		  cout << "\nName     :" << Currency.CurrencyName();
		  cout << "\nRate(1$) :" << Currency.Rate();
		  cout << "\n_______________________________\n";

	  }
	  static float _ReadRate()
	  {
		  float NewRate;

		  cout << "\nEnter New Rate :";
		  NewRate = ClsInputValidate::ReadFloatNumber();

		  return NewRate;
		  

	  }
	


  public:

	  static void ShowUpdateCurrencyRateScreen()
	  {
		  _DrawScreenHeader("\tUpdate Currency Screen");

		  
		  cout << "\nPlease Enter Currency Code: ";

		  string CurrencyCode = ClsString::ReadString();

		  while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		  {
			  cout << "\nCurrency is not found, choose another one: ";
			  CurrencyCode = ClsString::ReadString();
		  }


		  clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		  _PrintCurrency(Currency);

		  cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
		  char Answer = 'n';
		  cin >> Answer;

		  if (Answer=='y'||Answer=='Y')
		  {
			  cout << "\n\nUpdate Currency Rate:";
			  cout << "\n____________________\n";
			  Currency.UpdateRate(_ReadRate());

			  cout << "\nCurrency Rate Updated Successfully :-)\n";
			  _PrintCurrency(Currency);

			  
		  }


	  }
};

