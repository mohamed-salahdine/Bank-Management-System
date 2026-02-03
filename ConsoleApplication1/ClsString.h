#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;



class ClsString
{
  private:
	  string _Value;
  public:
	  ClsString()
	  {
		  _Value = "";

	  }
	  ClsString(string Value)
	  {
		  _Value = Value;
	  }

	  void SetValue(string Value)
	  {
		  _Value = Value;
	  }
	  string GetValue()
	  {
		  return _Value;
	  }

	  __declspec(property(get = GetValue, put = SetValue))string Value;

	  static int CountWord(string Text)
	  {
		  string separation = " ";
		  string Word;
		  int counter = 0;
		  int pos = 0;

		  while ((pos=Text.find(separation))!=string::npos)
		  {
			  Word = Text.substr(0, pos);

			  if (Word!="")
			  {
				  counter++;
			  }

			  Text.erase(0, pos + separation.length());
		  }
		  if (Text!="")
		  {
			  counter++;
		  }
		  return counter;
	  }  
	  int CountWord()
	  {
		 return CountWord(_Value);
	  }

	  static string ReadString()
	  {
		  string st;
		  getline(cin >> ws, st);
		  return st;
	  }

	  static void PrintFristLaterOfEachWord(string Text)
	  {
		  bool isFirstLater = true;

		  for (int i=0;i<Text.length();i++)
		  {
			  if (Text[i]!= ' ' && isFirstLater)
			  {
				  cout << Text[i] << endl;
			  }
			  isFirstLater = (Text[i] == ' ' ? true : false);

		  }
	  }
	  void PrintFristLaterOfEachWord()
	  {
		  PrintFristLaterOfEachWord(_Value);
	  }

	 static string ConvertTheFirstLettersOfEachWordToUppercase(string Text)
	 {
		 bool isFirstLater = true;

		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ' && isFirstLater)
			 {
				 Text[i] = toupper(Text[i]);
			 }
			 isFirstLater = (Text[i] == ' ' ? true : false);

		 }
		 return Text;
	 }
	 string ConvertTheFirstLettersOfEachWordToUppercase()
	 {
		 return  ConvertTheFirstLettersOfEachWordToUppercase(_Value);
	 }

	 static  string ConvertTheFirstLettersOfEachWordToLowerCase(string Text)
	 {
		 bool isFirstLater = true;

		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ' && isFirstLater)
			 {
				 Text[i] = tolower(Text[i]);
			 }
			 isFirstLater = (Text[i] == ' ' ? true : false);

		 }
		 return Text;
	 }
	 string ConvertTheFirstLettersOfEachWordToLowerCase()
	 {
		 return  ConvertTheFirstLettersOfEachWordToLowerCase(_Value);
	 }

	 static  string LowerAllLetterOfString(string Text)
	 {
		 for (int i=0;i<Text.length();i++)
		 {
			 Text[i] = tolower(Text[i]);

		 }
		 return Text;
	 }
	 void LowerAllLetterOfString()
	 {
		 _Value= LowerAllLetterOfString(_Value);
	 }

	 static  string UpperAllLetterOfString(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 Text[i] = toupper(Text[i]);

		 }
		 return Text;
	 }
	 void UpperAllLetterOfString()
	 {
		 _Value =  UpperAllLetterOfString(_Value);
	 }

	 static  int CountCharactInTheString(string Text,char Char,bool MatchCase=true)
	 {
		 int count = 0;

		 for (int i=0;i<Text.length();i++)
		 {
			 if (MatchCase)
			 {
				 if (tolower(Text[i]) == tolower(Char))
				 {
					 count++;
				 }
			 }
			 else
			 {
				 if (Text[i] == Char)
				 {
					 count++;
				 }
			 }
		 }
		 return count;
	 }
	 int CountCharactInTheString(char Char,bool MatchCase = true)
	 {
		 return  CountCharactInTheString(_Value, Char, MatchCase);
	 }


	static bool CheckIsCharactIsVowel(char Later)
	 {
		 return(tolower(Later)=='a' || tolower(Later) == 'e' || tolower(Later) == 'i' || tolower(Later) == 'o');
		 
	 }

	 static int CountAllVowelsInTheString(string Text)
	 {
		 int count = 0;
		 for (int i=0;i<Text.length();i++)
		 {
			 if (CheckIsCharactIsVowel(Text[i]))
			 {
				 count++;
			 }

		 }
		 return count;
	 }
	 int CountAllVowelsInTheString()
	 {
		 return CountAllVowelsInTheString(_Value);
	 }

	 void PrinAllVowelInString(string Text)
	 {
		 
		 for (int i=0;i<Text.length();i++)
		 {
			 if (CheckIsCharactIsVowel(tolower(Text[i])))
			 {
				 cout << Text[i] << " ";
				 
			 }

		 }
		 
	 }
	 void PrinAllVowelInString()
	 {
		return   PrinAllVowelInString(_Value);

	 }

	 void PrintEachWordInString(string Text)
	 {
		 string separation = " ";
		 int pos = 0;
		 string Word = "";

		 while ((pos=Text.find(separation))!=string::npos)
		 {
			 Word = Text.substr(0, pos);
			 if (Word!="")
			 {
				 cout << Word << endl;
			 }

			 Text.erase(0, pos + separation.length());
		 }
		 if (Text!="")
		 {
			 cout << Text << endl;
		 }
		 
	 }
	 void PrintEachWordInString()
	 {
		 PrintEachWordInString(_Value);
	 }

	 static  vector<string>SplitString(string Text,string separation)
	 {
		 vector<string>Words;
		 int pos = 0;
		 string word = "";

		 while ((pos=Text.find(separation))!=string::npos)
		 {
			 word = Text.substr(0, pos);
			 if (word!="")
			 {
				 Words.push_back(word);
			 }

			 Text.erase(0, pos + separation.length());
		 }
		 if (Text!="")
		 {
			 Words.push_back(Text);
		 }
		 return Words;
	 }
	 vector<string>SplitString( string separation)
	 {
		 return SplitString(_Value, separation);
	 }

	 static void PrintToken(vector<string>Text)
	 {
		 cout << "Token:" << Text.size() << endl;
		 for (string Word:Text)
		 {
			 cout << Word << endl;
		 }

	 }
	 void PrintToken(string separation)
	 {

		 PrintToken(SplitString(Value, separation));

	 }

	 string JoinString(string delim,vector<string>String)
	 {
		 string Text = "";

		 for (string Word:String)
		 {
			 Text = Text + Word + delim;
		 }
		 return Text.substr(0, Text.length() - delim.length());

	 }

	 string Reverse_String(string del)
	 {
		 vector<string>Vstring = SplitString(del);
		 string Text = "";

		 vector<string>::iterator itr =  Vstring.end();
		 while (itr!=Vstring.begin())
		 {
			 itr--;
			 Text += *itr + del;
		 }
		 return Text.substr(0, Text.length() - del.length());
		
		 
	 }

	 static string Replace_wordeInString(string Text,string word,string NewWord)
	 {
		 short pos = 0;
		 pos = Text.find(word);

		 while (pos!=string::npos)
		 {
			 Text = Text.replace(pos, word.length(), NewWord);
			 pos = Text.find(word);

		 }
		 return Text;


	 }
	 string Replace_wordeInString( string word, string NewWord)
	 {
		 return  Replace_wordeInString(_Value,  word,  NewWord);
	 }

	 static string Remove_Punctuations_in_string(string Text)
	 {
		 string St = "";
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (!ispunct(Text[i]))
			 {
				 St += Text[i];
			 }
		 }
		 return St;
	 }
	 string Remove_Punctuations_in_string()
	 {
		 return Remove_Punctuations_in_string(_Value);
	 }

};

