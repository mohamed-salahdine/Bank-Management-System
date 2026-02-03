#pragma once
#include<iostream>
#include"clsPerson.h"
#include<fstream>
#include<vector>
#include"ClsData.h"
#include"ClsString.h"
#include"Global.h"
using namespace std;


class clsBankClient : public clsPerson
{
  private:
	  enum enMod{EmptyMode=0,UpdateMode=1,AddNewMode=3};
	  enMod _Mod;

	  string _AccountNumber;
	  string _PinCode;
	  float _AccountBalanc;
	  bool _DeleteMark = false;

	  static clsBankClient _ConvertLinetoClientObject(string Line,string Seperator="#//#")
	  {
		  vector<string>Vclinet;
		  Vclinet = ClsString::SplitString(Line, Seperator);
		  return clsBankClient(enMod::UpdateMode, Vclinet[0], Vclinet[1], Vclinet[2], Vclinet[3], Vclinet[4], Vclinet[5], stof(Vclinet[6]));

	  }
	  static clsBankClient _GetEmptyClinetOpject()
	  {
		  return clsBankClient(enMod::EmptyMode, "", "", "", "", "", "", 0);
	  }

	  static vector<clsBankClient>_LoadClientsDataFromFile()
	  {
		  vector<clsBankClient>vClients;

		  fstream MyFile;
		  MyFile.open("Clinet.txt", ios::in);

		  if (MyFile.is_open())
		  {
			  string line;

			  while (getline(MyFile,line))
			  {
				  clsBankClient Client = _ConvertLinetoClientObject(line);

				  vClients.push_back(Client);


			  }

			  MyFile.close();
		  }

		  return vClients;

	  }

	  static string _ConverClientObjectToLine(clsBankClient clinet, string Seperator = "#//#")
	  {
		  string stClientRecord = "";

		  stClientRecord = stClientRecord+ clinet.FirtsName + Seperator;
		  stClientRecord = stClientRecord + clinet.LastName + Seperator;
		  stClientRecord = stClientRecord + clinet.Email + Seperator;
		  stClientRecord = stClientRecord + clinet.Phone + Seperator;
		  stClientRecord = stClientRecord + clinet.GetAccountNamber() + Seperator;
		  stClientRecord = stClientRecord + clinet.PinCod + Seperator;
		  stClientRecord = stClientRecord + to_string(clinet.AccounBalanc);

		  return stClientRecord;

	  }
	  static void _SaveCleintsDataToFile(vector<clsBankClient>vClients)
	  {
		  fstream MyFile;
		  MyFile.open("Clinet.txt", ios::out);

		  if (MyFile.is_open())
		  {
			  string DataLine;

			  for (clsBankClient &C:vClients)
			  {
				  if (C._DeleteMark==false)
				  {
					  DataLine = _ConverClientObjectToLine(C);
					  MyFile << DataLine << endl;
				  }
				 

			  }
			  MyFile.close();
		  }


	  }

	  void  _Update()
	  {
		  vector<clsBankClient>_vClients;
		  _vClients = _LoadClientsDataFromFile();

		  for (clsBankClient &C:_vClients)
		  {
			  if (C.GetAccountNamber() == GetAccountNamber())
			  {
				  C = *this;
				  break;
			  }
		  }

		  _SaveCleintsDataToFile(_vClients);
	  }
	   void  _AddNewLineToFile(string LineClinet)
	   {
		   fstream MyFile;
		   MyFile.open("Clinet.txt",  ios::out|ios::app);

		   if (MyFile.is_open())
		   {
			   MyFile << LineClinet << endl;
			   MyFile.close();

		   }

	   }
	  void  _AddNew()
	  {
		  _AddNewLineToFile(_ConverClientObjectToLine(*this));
	  }

	  string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,string UserName,string Seperator="#//#")
	  {
		  string TransferLogRecord = "";

		  TransferLogRecord += ClsDate::GetSystemDateTimeString() + Seperator;
		  TransferLogRecord += GetAccountNamber() + Seperator;
		  TransferLogRecord += DestinationClient.GetAccountNamber() + Seperator;
		  TransferLogRecord += to_string(Amount) + Seperator;
		  TransferLogRecord += to_string(AccounBalanc) + Seperator;
		  TransferLogRecord += to_string(DestinationClient.AccounBalanc) + Seperator;
		  TransferLogRecord += UserName;


		  return TransferLogRecord;


	  }

	  void _RegisterTransferLog(float Amount, clsBankClient DestinationClient,string UserName)
	  {
		  string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient,UserName);

		  fstream MyFile;
		  MyFile.open("TransferLog.txt", ios::out | ios::app);

		  if (MyFile.is_open())
		  {
			  MyFile << stDataLine << endl;

			  MyFile.close();

		  }

	  }
	  struct stTrnsferLogRecord;
	  static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line,string Seperator="#//#")
	  {
		  stTrnsferLogRecord TrnsferLogRecord;

		  vector<string>vTrnsferLogRecordLine = ClsString::SplitString(Line, Seperator);
		  TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		  TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		  TrnsferLogRecord.DestinationAccountNumber= vTrnsferLogRecordLine[2];
		  TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		  TrnsferLogRecord.srcBalanceAfter= stod(vTrnsferLogRecordLine[4]);
		  TrnsferLogRecord.destBalanceAfter= stod(vTrnsferLogRecordLine[5]);
		  TrnsferLogRecord.UserName= vTrnsferLogRecordLine[6];

		  return TrnsferLogRecord;
	  }
	  
  public:
	  struct stTrnsferLogRecord
	  {
		  string DateTime;
		  string SourceAccountNumber;
		  string DestinationAccountNumber;
		  float Amount;
		  float srcBalanceAfter;
		  float destBalanceAfter;
		  string UserName;

	  };
	 
	  clsBankClient(enMod Mod,string FirstName, string LastName, string Email, string Phone, string AccountNamber, string PinCod, float AccountBalanc)
		  :clsPerson( FirstName,  LastName,  Email, Phone)
	  {
		  _Mod = Mod;
		  _AccountNumber = AccountNamber;
		  _PinCode = PinCod;
		  _AccountBalanc = AccountBalanc;
	  }

	  string GetAccountNamber()
	  {
		  return _AccountNumber;
	  }

	  void SetPinCod(string pinCod)
	  {
		  _PinCode = pinCod;
	  }
	  string GetPinCod()
	  {
		  return _PinCode;
	  }
	  __declspec(property(get=GetPinCod,put=SetPinCod))string PinCod;


	  void SetAccountBalanc(float AccountBalanc)
	  {
		  _AccountBalanc = AccountBalanc;
	  }
	  float GetAccuntBalanc()
	  {
		  return _AccountBalanc;
	  }
	  __declspec(property(get = GetAccuntBalanc, put = SetAccountBalanc))float AccounBalanc;

	  static clsBankClient Find(string AccountNumber)
	  {
		  fstream MyFile;
		  MyFile.open("Clinet.txt", ios::in);

		  if (MyFile.is_open())
		  {
			  string Line;

			  while (getline(MyFile,Line))
			  {
				  
					  clsBankClient Clinet = _ConvertLinetoClientObject(Line);
					  if (Clinet.GetAccountNamber() == AccountNumber)
					  {
						  MyFile.close();
						  return Clinet;

					  }
				  
				

			  }
			  MyFile.close();
		  }

		  return _GetEmptyClinetOpject();


	  }

	  static clsBankClient Find(string AccountNumber,string PinCode)
	  {
		  fstream MyFile;
		  MyFile.open("Clinet.txt", ios::in);

		  if (MyFile.is_open())
		  {
			  string Line;
			  while (getline(MyFile, Line))
			  {
				  clsBankClient Clinet = _ConvertLinetoClientObject(Line);
				  if (Clinet.GetAccountNamber() == AccountNumber && Clinet.GetPinCod()==PinCode)
				  {
					  MyFile.close();
					  return Clinet;

				  }

			  }
			  MyFile.close();
		  }

		  return _GetEmptyClinetOpject();


	  }

	/*  void Print()
	  {
		  cout << "\nClient Card:";
		  cout << "\n---------------------------------";
		  cout << "\nFirstName      :" << FirtsName << endl;
		  cout << "\nLastName       :" << LastName << endl;
		  cout << "\nFullName       :" << FullName() << endl;
		  cout << "\nEmail          :" << Email << endl;
		  cout << "\nPhone          :" << Phone << endl;
		  cout << "\nAccountNember  :" << _AccountNumber << endl;
		  cout << "\nPassWord       :" << _PinCode << endl;
		  cout << "\nBalance        :" << _AccountBalanc << endl;
		  cout << "\n---------------------------------\n";
	  }*/


	  static bool IsEmpty(clsBankClient Client)
	  {
		  return(Client._Mod == enMod::EmptyMode);

	  }

	  bool IsEmpty()
	  {
		  return(_Mod == enMod::EmptyMode);

	  }

	  static bool IsClientExist(string AccountNumber)
	  {
		  clsBankClient client = clsBankClient::Find(AccountNumber);
		  return !IsEmpty(client);

	  }

	  static clsBankClient  GetAddNewClientObject(string AccountNumber)
	  {
		  return clsBankClient(enMod::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	  }
	  static enum enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2,svFaildClientExist=3 };

	  enSaveResults Save()
	  {
		  switch (_Mod)
		  {
			  if (IsEmpty())
			  {
				  return enSaveResults::svFaildEmptyObject;
			  }
		   
			 case enMod::UpdateMode:
			 {
				 _Update();

				 return enSaveResults::svSucceeded;
				 break;
			 }
			 case  enMod::AddNewMode:
			 {
				 if (clsBankClient::IsClientExist(_AccountNumber))
				 {
					 return enSaveResults::svFaildClientExist;
				 }
				 else
				 {
					 _AddNew();
					 _Mod = enMod::UpdateMode;
					 return enSaveResults::svSucceeded;
				 }
				 


				 break;
			 }

		  }

	  }

	  bool Delete()
	  {
		  vector<clsBankClient>_vClients;
		  _vClients = _LoadClientsDataFromFile();

		  for (clsBankClient &C:_vClients)
		  {
			  if (C._AccountNumber == _AccountNumber)
			  {
				  C._DeleteMark = true;
				  break;
			  }

		  }
		  _SaveCleintsDataToFile(_vClients);

		  *this = _GetEmptyClinetOpject();

		  return true;
	  }

	  static vector<clsBankClient>GetClientsList()
	  {
		  return _LoadClientsDataFromFile();
	  }

	  static double GetTotalBalances(vector<clsBankClient>vClinet)
	  {
		  double TotalBalances = 0;

		  for (clsBankClient &C:vClinet)
		  {
			  TotalBalances += C.AccounBalanc;

		  }
		  return TotalBalances;

	  }

	  void Diposit(double amount)
	  {
		  _AccountBalanc += amount;
		  Save();

	  }

	  bool Withdraw(double amount)
	  {
		  if (amount > _AccountBalanc)
		  {
			  return false;
		  }
		  else
		  {
			  _AccountBalanc -= amount;
			  Save();
			  return true;

		  }
		  

	  }

	  static double GetTotalBalances()
	  {
		  vector<clsBankClient>Vclinet = GetClientsList();

		  double TotalBalances = 0;

		  for (clsBankClient Clinet:Vclinet)
		  {
			  TotalBalances += Clinet.AccounBalanc;

		  }


		  return TotalBalances;
	  }

	  bool Transfer(float Amount,clsBankClient &DestinationClient,string UserName)
	  {
		  if (Amount>AccounBalanc)
		  {
			  return false;
		  }
		  else
		  {
			  Withdraw(Amount);
			  DestinationClient.Diposit(Amount);
			  _RegisterTransferLog(Amount, DestinationClient, UserName);

			  return true;
			  
		  }

	  }

	  static vector<stTrnsferLogRecord>GetTransfersLogList()
	  {

		  vector<stTrnsferLogRecord>vTransferLogRecord;

		  fstream Myfile;
		  Myfile.open("TransferLog.txt", ios::in);

		  if (Myfile.is_open())
		  {
			  string Line;
			  stTrnsferLogRecord TransferRecord;

			  while (getline(Myfile,Line))
			  {
				  TransferRecord = _ConvertTransferLogLineToRecord(Line);

				  vTransferLogRecord.push_back(TransferRecord);

			  }

			  Myfile.close();
		  }

		  return vTransferLogRecord;
	  }

	
	

};

