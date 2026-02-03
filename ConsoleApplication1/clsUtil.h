#pragma once
#include<iostream>
#include<string>
#include"ClsData.h"
using namespace std;

class ClsUtil
{

 public:

	  enum enSmalCarDij { smallettel = 1, capitaltettel, dijit, spcialcaracter, MixCaracte };
	  
	  static void Srand()
	 {
		 srand((unsigned)time(0));
	 }
	  static int RandomNumber(int From,int to)
	  {
		  int Random = 0;
		  Random = rand() % (to - From + 1) + From;
		  return Random;

	  }
	  static char GetRandomCaracter(enSmalCarDij enChar)
	  {
		  if (enChar==MixCaracte)
		  {
			  enChar= enSmalCarDij(RandomNumber(1, 3));
		  }
		  switch (enChar)
		  {
		      case smallettel:
			  {
				  return char(RandomNumber(97,122));
				  break;
			  }
			  case capitaltettel:
			  {
				  return char(RandomNumber(65,90));
				  break;
			  }
			  case spcialcaracter:
			  {
				  return char(RandomNumber(33,47));
				  break;
			  }
			  case dijit:
			  {
				  return char(RandomNumber(48,57));
				  break;
			  }
			
		  
		 

		  }

	  }
	  static string GeneratWord(enSmalCarDij charType,int WordLength)
	  {
		  string word = "";
		  char Char;

		  for (int i=0;i<WordLength;i++)
		  {
			  Char = GetRandomCaracter(charType);
			  word += +Char;
		  }


		  return word;

	  }
	  static string GeneratKey(enSmalCarDij charType)
	  {
		  string Key = "";
		  Key += GeneratWord(charType, 4) + "-";
		  Key += GeneratWord(charType, 4) + "-";
		  Key += GeneratWord(charType, 4) + "-";
		  Key += GeneratWord(charType, 4);

		  return Key;

	  }
	  static void GeneratKeys(int NumberKey, enSmalCarDij charType)
	  {
		  for (int i=1;i<=NumberKey;i++)
		  {
			  cout << "Key[" << i << "] = " << GeneratKey(charType) << endl;

		  }
	  }
	  static void Swap(int &number1,int &number2)
	  {
		  int swap;
		  swap = number1;
		  number1 = number2;
		  number2 = swap;

	  }
	  static void Swap(double& number1, double& number2)
	  {
		  double swap;
		  swap = number1;
		  number1 = number2;
		  number2 = swap;
	  }

	  static void Swap(string& number1, string& number2)
	  {
		  string swap;
		  swap = number1;
		  number1 = number2;
		  number2 = swap;
	  }

	  static void Swap(ClsDate& number1, ClsDate& number2)
	  {
		  ClsDate swap;
		  swap = number1;
		  number1 = number2;
		  number2 = swap;
	  }
	  static void ShuflleArray(int arr[],int lengtharr)
	  {
		  for (int i=0;i<lengtharr;i++)
		  {
			  Swap(arr[RandomNumber(0, lengtharr - 1)], arr[RandomNumber(0, lengtharr - 1)]);
		  }

		  

	  }

	  static void ShuflleArray(string arr[], int lengtharr)
	  {
		  for (int i = 0; i < lengtharr; i++)
		  {
			  Swap(arr[RandomNumber(0, lengtharr - 1)], arr[RandomNumber(0, lengtharr - 1)]);
		  }



	  }

	  static void FillArrayWithRandomNumber(int arr[],int lengtharry,int FromNum,int ToNum)
	  {
		  for (int i=0;i<lengtharry;i++)
		  {
			  arr[i] = RandomNumber(FromNum, ToNum);
		  }
	  }
	  static void FillArrayWithRandomWords(string arr[],int Lengtharr, enSmalCarDij charType, int WordLength)
	  {
		  for (int i=0;i<Lengtharr;i++)
		  {
			  arr[i] = GeneratWord( charType,  WordLength);
		  }
	  }
	  static string Tabs(int LengthTabs)
	  {
		  string tabs = "";
		  for (int i=0;i<LengthTabs;i++)
		  {
			  tabs += "\t";
		  }
		  return tabs;
	  }
	  static string EncryptText(string Text,int EncrypKey=0)
	  {
		  string EncryptWord = "";

		  for (int i=0;i<Text.size();i++)
		  {
			  EncryptWord += char(Text[i]+EncrypKey);
		  }
		  return EncryptWord;
	  }
	  static string DecryptText(string Text, int EncrypKey=0)
	  {
		  string DecryptWord = "";

		  for (int i = 0; i < Text.size(); i++)
		  {
			  DecryptWord += char(Text[i] - EncrypKey);
		  }
		  return DecryptWord;
	  }
	  static string NumberToText(long long int number)
	  {
		  if (number >= 0 && number <= 19)
		  {
			  string arr[20] = { "","One", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
			  "eleven", "twelve", "thirteen", "fourtee", "fifteen", "sixteen", "seventeen", "twelve", "nineteen" };

			  return arr[number];

		  }

		  if (number >= 20 && number <= 99)
		  {
			  string arr[10] = { "","","Twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

			  return arr[number / 10] + " " + NumberToText(number % 10);
		  }

		  if (number >= 100 && number <= 999)
		  {
			  return NumberToText(number / 100) + " " + "hundred" + " " + NumberToText(number % 100);

		  }

		  if (number >= 1000 && number <= 999999)
		  {
			  return NumberToText(number / 1000) + " " + "thousand" + " " + NumberToText(number % 1000);

		  }

		  if (number >= 1000000 && number <= 999999999)
		  {
			  return NumberToText(number / 1000000) + " " + "million" + " " + NumberToText(number % 1000000);

		  }

		  if (number >= 1000000000)
		  {
			  return NumberToText(number / 1000000000) + " " + "billion" + " " + NumberToText(number % 1000000000);

		  }


	  }
	



};

