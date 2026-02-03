#pragma once
#include<iostream>
#include"clsPerson.h"
#include"ClsString.h"
#include<vector>
#include"ClsData.h"
#include"clsUtil.h"

#include<fstream>

using namespace std;


class clsUser:public clsPerson
{
 private:
	 enum enMode{EmptyMode=0,UpdateMode,AddNewMode};

	 enMode _Mode;
	 string _UserName;
	 string _Password;
	 int _Permissions;
	 bool _MarkedForDelete = false;


	 static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	 {
		 vector<string>VuserData;
		 VuserData = ClsString::SplitString(Line, Seperator);
		 return clsUser(enMode::UpdateMode, VuserData[0], VuserData[1], VuserData[2], VuserData[3], VuserData[4], ClsUtil::DecryptText(VuserData[5]), stof(VuserData[6]));

	 }
	 static clsUser _GetEmptyUserObject()
	 {
		 return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	 static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	 {
		 string stUserRecord = "";

		 stUserRecord = stUserRecord + User.FirtsName + Seperator;
		 stUserRecord = stUserRecord + User.LastName + Seperator;
		 stUserRecord = stUserRecord + User.Email + Seperator;
		 stUserRecord = stUserRecord + User.Phone + Seperator;
		 stUserRecord = stUserRecord + User.GetUserName() + Seperator;
		 stUserRecord = stUserRecord + ClsUtil::EncryptText(User.PassWord) + Seperator;
		 stUserRecord = stUserRecord + to_string(User.Permissions);

		 return stUserRecord;

	 }

	 static void _SaveUsersDataToFile(vector<clsUser>vUsers)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::out);

		 if (MyFile.is_open())
		 {
			 string DataLine;

			 for (clsUser& C : vUsers)
			 {
				 if (C._MarkedForDelete == false)
				 {
					 DataLine = _ConverUserObjectToLine(C);
					 MyFile << DataLine << endl;
				 }


			 }
			 MyFile.close();
		 }


	 }


	 static vector<clsUser>_LoadUsersDataFromFile()
	 {
		 vector<clsUser>vUsers;

		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string line;

			 while (getline(MyFile, line))
			 {
				 clsUser User = _ConvertLinetoUserObject(line);

				 vUsers.push_back(User);


			 }

			 MyFile.close();
		 }

		 return vUsers;

	 }

	 void  _Update()
	 {
		 vector<clsUser>_vUsers;
		 _vUsers = _LoadUsersDataFromFile();

		 for (clsUser& C : _vUsers)
		 {
			 if (C.GetUserName() == GetUserName())
			 {
				 C = *this;
				 break;
			 }
		 }

		 _SaveUsersDataToFile(_vUsers);
	 }

	 void  _AddNewLineToFile(string LineUser)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << LineUser << endl;
			 MyFile.close();

		 }

	 }

	 void  _AddNew()
	 {
		 _AddNewLineToFile(_ConverUserObjectToLine(*this));
	 }

	  string _PrepareLogInRecord(string Seperator="#//#")
	  {
		  string LoginRecord = "";

		 LoginRecord += ClsDate::GetSystemDateTimeString() + Seperator;
		 LoginRecord += UserName + Seperator;
		 LoginRecord += ClsUtil::EncryptText(PassWord) + Seperator;
		 LoginRecord += to_string(Permissions);


		 return LoginRecord;

	  }
	  struct stLoginRegisterRecord;

	  static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line,string Seperator = "#//#")
	  {
		  stLoginRegisterRecord LoginRegisterRecord;

		  vector<string>VloginRegister = ClsString::SplitString(Line, Seperator);

		  LoginRegisterRecord.DateTime = VloginRegister[0];
		  LoginRegisterRecord.UserName = VloginRegister[1];
		  LoginRegisterRecord.Password = ClsUtil::DecryptText(VloginRegister[2]);
		  LoginRegisterRecord.Permissions = stoi(VloginRegister[3]);

		  return LoginRegisterRecord;
	  }

 public:

	 struct stLoginRegisterRecord
	 {
		 string DateTime;
		 string UserName;
		 string Password;
		 int Permissions;
	 };
	 static enum enPermissions{ eAll = -1,pListClients=1,pAddNewClient=2,pDeleteClient=4,pUpdateClients=8,pFindClient=16,pTranactions=32,pManageUsers=64,pShowLogInRegister=128,pCurrencyExchang=256 };

	 clsUser(enMode Mod ,string FirtsName, string LastName, string Email, string Phone,string Username,string Password,int Permissions):clsPerson(FirtsName,LastName,Email,Phone)
	 {
		 _Mode = Mod;
		 _UserName = Username;
		 _Password = Password;
		 _Permissions = Permissions;

	 }

	 void SetUserName(string username)
	 {
		 _UserName = username;
	 }
	 string GetUserName()
	 {
		 return _UserName;
	 }
	 __declspec(property(get=GetUserName,put=SetUserName))string UserName;

	 void SetPassWord(string password)
	 {
		 _Password = password;
	 }
	 string GetPassWord()
	 {
		 return _Password;
	 }
	 __declspec(property(get = GetPassWord, put = SetPassWord))string PassWord;

	 void SetPermissions(int Permissions)
	 {
		 _Permissions = Permissions;
	 }
	 int GetPermissions()
	 {
		 return _Permissions;
		 
	 }
	 __declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	 bool MarkedForDeleted()
	 {
		 return _MarkedForDelete;
	 }

	 string View_permission_results()
	 {
		 if (_Permissions==-1)
		 {
			 return "All permissions";
		 }
		 else
		 {
			return "Some permissions";
		 }
	 }

	 static clsUser Find(string username)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {

				 clsUser User = _ConvertLinetoUserObject(Line);
				 if (User.GetUserName() == username)
				 {
					 MyFile.close();
					 return User;

				 }



			 }
			 MyFile.close();
		 }

		 return _GetEmptyUserObject();


	 }
	 static clsUser Find(string username,string password)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {

				 clsUser User = _ConvertLinetoUserObject(Line);
				 if ((User.GetUserName() == username) && (User.GetPassWord() == password))
				 {
					 MyFile.close();
					 return User;

				 }



			 }
			 MyFile.close();
		 }

		 return _GetEmptyUserObject();


	 }


	 static bool IsEmpty(clsUser User)
	 {
		 return(User._Mode == enMode::EmptyMode);

	 }
	 bool IsEmpty()
	 {
		 return(_Mode == enMode::EmptyMode);

	 }

	 static bool IsUserExist(string Username)
	 {
		 clsUser User = clsUser::Find(Username);
		 return !(User.IsEmpty());
		

	 }


	 static clsUser  GetAddNewUserObject(string username)
	 {
		 return clsUser(enMode::AddNewMode, "", "", "", "", username, "", 0);
	 }


	 static enum enSaveResults { svFaildEmptyObject = 0, svSucceeded , svFaildUserExist  };


	 enSaveResults Save()
	 {
		 switch (_Mode)
		 {
			 if (IsEmpty())
			 {
				 return enSaveResults::svFaildEmptyObject;
			 }

		 case enMode::UpdateMode:
		 {
			 _Update();

			 return enSaveResults::svSucceeded;
			 break;
		 }
		 case  enMode::AddNewMode:
		 {
			 if (clsUser::IsUserExist(_UserName))
			 {
				 return enSaveResults::svFaildUserExist;
			 }
			 else
			 {
				 _AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResults::svSucceeded;
			 }



			 break;
		 }

		 }

	 }

	 bool Delete()
	 {
		 vector<clsUser>_vUsers;

		 _vUsers = _LoadUsersDataFromFile();

		 for (clsUser& U : _vUsers)
		 {
			 if (U.UserName ==_UserName)
			 {
				 U._MarkedForDelete = true;
				 break;
			 }

		 }
		 _SaveUsersDataToFile(_vUsers);

		 *this = _GetEmptyUserObject();

		 return true;
	 }

	 static vector<clsUser>GetUsersList()
	 {
		 return _LoadUsersDataFromFile();
	 }

	 bool CheckAccessPermission(enPermissions Permissions)
	 {
		 if (this->Permissions ==enPermissions::eAll )
		 {
			 return true;

		 }
		 if ((Permissions & this->Permissions)==Permissions)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }

	 }

	  void RegisterLogIn()
	 {
		 string stDataLine = _PrepareLogInRecord();
		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << stDataLine << endl;
			 MyFile.close();

		 }

	 }

	  static vector<stLoginRegisterRecord>GetLoginRegisterList()
	  {
		  vector<stLoginRegisterRecord>vLoginRegisterRecord;

		  fstream MyFile;
		  MyFile.open("LoginRegister.txt", ios::in);

		  if (MyFile.is_open())
		  {
			  string Line;
			  stLoginRegisterRecord LoginRegisterRecord;

			  while (getline(MyFile,Line))
			  {
				  LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				  vLoginRegisterRecord.push_back(LoginRegisterRecord);


			  }
			  MyFile.close();
		  }

		  return vLoginRegisterRecord;

	  }

	 


	
		 


};

