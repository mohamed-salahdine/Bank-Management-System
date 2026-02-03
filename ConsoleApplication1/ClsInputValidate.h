#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"ClsData.h"
using namespace std;


class ClsInputValidate
{
  public:
	  static bool IsNumberBetween(short number, short From, short To)
	  {
		  if (number >= From && number <= To)
		  {
			  return true;
		  }

		  else
		  {
			  return false;
		  }

	  }
	  static bool IsNumberBetween(int number,int From,int To)
	  {
		  if (number>=From&&number<=To)
		  {
			  return true;
		  }
			  
		  else
		  {
			  return false;
		  }

	  }
	  static bool IsNumberBetween(float number, float From, float To)
	  {
		  if (number >= From && number <= To)
		  {
			  return true;
		  }

		  else
		  {
			  return false;
		  }

	  }
	  static bool IsNumberBetween(double number, double From, double To)
	  {
		  if (number >= From && number <= To)
		  {
			  return true;
		  }

		  else
		  {
			  return false;
		  }
	  }
	  static bool IsDateBetween(ClsDate number, ClsDate From, ClsDate To)
	  {
		  if ((ClsDate::IsDat1AfterDat2(number,From)||ClsDate::Check_If_Dat1_Equals_To_Dat2(number,From))
			                                                    &&
		     (ClsDate::IsDate1BeforeDate2(number,To)||ClsDate::Check_If_Dat1_Equals_To_Dat2(number,To))
			  )
		       {
			     return true;
		       }


		  if ((ClsDate::IsDat1AfterDat2(number, To) || ClsDate::Check_If_Dat1_Equals_To_Dat2(number, To))
			                                                    &&
			  (ClsDate::IsDate1BeforeDate2(number, From) || ClsDate::Check_If_Dat1_Equals_To_Dat2(number, From))
			  )
		  {
			  return true;
		  }
		  else
		  {
			  return false;
		  }
		 
	  }

	  static string ReadString()
	  {
		  string st;
		  getline(cin >> ws, st);
		  return st;
	  }
	  static int ReadIntNumber(string ErrorMessag="Invalid Number,Enter again:\n")
	  {
		  int number;
		  while (!(cin>>number))
		  {
			  cin.clear();
			  cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  cout << ErrorMessag;

		  }
		  return number;
	  }
	  static double ReadDblNumber(string ErrorMessag = "Invalid Number,Enter again:\n")
	  {
		  double number;

		  while (!(cin >> number))
		  {

			  cin.clear();
			  cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  cout << ErrorMessag;

		  }

		  return number;

	  }

	  static float ReadFloatNumber(string ErrorMessag = "Invalid Number,Enter again:\n")
	  {
		  float number;

		  while (!(cin >> number))
		  {

			  cin.clear();
			  cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  cout << ErrorMessag;

		  }

		  return number;

	  }


	  static int ReadIntNumberBetween(int From,int To,string ErrorMessag="Number Is Not Within rang,enter again\n")
	  {
		  int number = ReadIntNumber();

		  while (!IsNumberBetween(number,From,To))
		  {
			  cout << ErrorMessag;
			  number = ReadIntNumber();
			  

		  }
		  return number;
	  }
	  static double ReadDblNumberBetween(double From, double To, string ErrorMessag = "Number Is Not Within rang,enter again")
	  {
		  double number = ReadDblNumber();

		  while (!IsNumberBetween(number,From,To))
		  {
			  cout << ErrorMessag << endl;
			  number = ReadDblNumber();


		  }
		  return number;
	  }

	  static short ReadShortNumberBetween(short From, short To, string ErrorMessag = "Number Is Not Within rang,enter again")
	  {
		  short number = ReadDblNumber();

		  while (!IsNumberBetween(number, From, To))
		  {
			  cout << ErrorMessag << endl;
			  number = ReadDblNumber();


		  }
		  return number;
	  }


	  static bool IsValideDate(ClsDate date)
	  {
		 
		  if (ClsDate::IsValidDate(date))
			  return true;

	  }


};

