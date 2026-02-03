#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"ClsString.h"
#include<fstream>
using namespace std;

class clsCurrency
{
 private:
	 enum enMode { EmptyMode = 0, UpdateMode = 1 };
	 enMode _Mode;
	 string _Country;
	 string _CurrencyCode;
	 string _CurrencyName;
	 float _Rate;

	 static clsCurrency _ConvertLinetoCurrencyObject(string Line,string Seperator="#//#")
	 {
		 
		 vector<string>vCurrencyData = ClsString::SplitString(Line,Seperator);

		 return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	
	 }

	 static clsCurrency _GetEmptyCurrencyObject()
	 {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	 }

	 static vector<clsCurrency>_LoadCurrencysDataFromFile()
	 {
		 vector<clsCurrency>vCurrencys;

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 

			 while (getline(MyFile,Line))
			 {
				 clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				 vCurrencys.push_back(Currency);


			 }
			 MyFile.close();
		 }

		 return vCurrencys;
	 }
	 static string _ConverCurrencyObjectToLine(clsCurrency Currency,string Seperator="#//#")
	 {
		 string stCurrencyRecord="";

		 stCurrencyRecord += Currency.Country() + Seperator;
		 stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		 stCurrencyRecord += Currency.CurrencyName() + Seperator;
		 stCurrencyRecord += to_string(Currency.Rate());

		 return stCurrencyRecord;


	 }
	 void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencys)
	 {
		 fstream MyFile;

		 MyFile.open("Currencies.txt", ios::out);

		 string DataLine;
		 if (MyFile.is_open())
		 {
			 for (clsCurrency &C:vCurrencys)
			 {
				  DataLine = _ConverCurrencyObjectToLine(C);
				 MyFile << DataLine << endl;
					 
			 }
			 MyFile.close();

		 }

	 }
	 void _Update()
	 {
		 vector<clsCurrency>_vCurrencys = _LoadCurrencysDataFromFile();

		 for (clsCurrency &C:_vCurrencys)
		 {
			 if (C.CurrencyCode()==CurrencyCode())
			 {
				 C = *this;
				 break;
			 }

		 }
		 _SaveCurrencyDataToFile(_vCurrencys);
	 }

 public:

	 clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate)
	 {
		 _Mode = Mode;
		 _Country = Country;
		 _CurrencyCode = CurrencyCode;
		 _CurrencyName = CurrencyName;
		 _Rate = Rate;

	 }
	 clsCurrency()
	 {

	 }

	 string Country()
	 {
		 return _Country;
	 }
	 string CurrencyCode()
	 {
		 return _CurrencyCode;
	 }
	 string CurrencyName()
	 {
		 return _CurrencyName;
	 }

	 float Rate()
	 {
		 return _Rate;
	 }

	 bool IsEmpty()
	 {
		 return (_Mode == enMode::EmptyMode);
			 
	 }

	  void UpdateRate(float NewRate)
	  {
		  _Rate = NewRate;
		  _Update();


	  }

	 static clsCurrency FindByCode(string CurrencyCode)
	 {
		 CurrencyCode = ClsString::UpperAllLetterOfString(CurrencyCode);

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 

			 while (getline(MyFile,Line))
			 {
				 clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				 if (Currency.CurrencyCode()==CurrencyCode)
				 {
					 MyFile.close();
					 return Currency;

				 }

			 }

			 MyFile.close();

			 return _GetEmptyCurrencyObject();
		 }

	 }

	 static clsCurrency FindByCountry(string Country)
	 {
		 Country = ClsString::UpperAllLetterOfString(Country);

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 

			 while (getline(MyFile, Line))
			 {
				 clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				 if (ClsString::UpperAllLetterOfString(Currency.Country())==Country)
				 {
					 MyFile.close();
					 return Currency;

				 }

			 }

			 MyFile.close();
			 return _GetEmptyCurrencyObject();
		 }

	 }

	 static bool IsCurrencyExist(string CurrencyCode)
	 {
		 clsCurrency C1 = FindByCode(CurrencyCode);
		 return (!C1.IsEmpty());

		 


	 }

	 static vector<clsCurrency>GetCurrenciesList()
	 {
		return  _LoadCurrencysDataFromFile();
	 }

	 float ConvertToUSD(float Amount)
	 {
		 return (float)(Amount / Rate());

	 }
	 float ConvertToOtherCurrency(float Amount,clsCurrency Currency2 )
	 {
		 float AmountInUSD = ConvertToUSD(Amount);

		 if (Currency2.CurrencyCode()=="USD")
		 {
			 return AmountInUSD;
		 }
		 return (float)(AmountInUSD * (Currency2.Rate()));



	 }
	


};

