#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsString.h"
#include"ClsInputValidate.h"
#include"clsUser.h"
using namespace std;


class clsAddNewUserScreen:protected clsScreen
{
 private:

	 static int _ReadPermissionsToSet()
	 {
		 char Answer = 'n';
		 short Permissions = 0;

		 cout << "\nDo you want to give full access? y/n? ";
		 cin >> Answer;
		 if (Answer=='y'||Answer=='Y')
		 {
			 return -1;
		 }
		 cout << "\nDo you want to give access to : \n ";

		 cout << "\nShow Clint List? N/Y ?";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pListClients;
		 }

		 cout << "\nAdd New Client? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pAddNewClient;
		 }

		 cout << "\nDelete Client? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pDeleteClient;
		 }

		 cout << "\nUpdate Client? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pUpdateClients;

		 }

		 cout << "\nFind Client? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pFindClient;
		 }

		 cout << "\nTransactions? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pTranactions;
		 }

		 cout << "\nManage Users? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pManageUsers;
		 }

		 cout << "\nShow Login Register? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pShowLogInRegister;
		 }

		 cout << "\nShow Currency Exchang? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
		 {
			 Permissions += clsUser::pCurrencyExchang;
		 }

		 return Permissions;



	 }

	 static void _ReadUserInfo(clsUser& user)
	 {
		 cout << "\nEnter FirstName:";
		 user.FirtsName = ClsString::ReadString();

		 cout << "\nEnter LastName:";
		 user.LastName = ClsString::ReadString();

		 cout << "\nEnter Email:";
		 user.Email = ClsString::ReadString();

		 cout << "\nEnter Phon:";
		 user.Phone = ClsString::ReadString();

		 cout << "\nEnter PassWord:";
		 user.PassWord = ClsString::ReadString();

		 cout << "\nEnter Permissions:\n";
		 user.Permissions = _ReadPermissionsToSet();

	 }

	 static void _PrintUser(clsUser& User)
	 {
		 cout << "\nClient Card:";
		 cout << "\n---------------------------------";
		 cout << "\nFirstName   :" << User.FirtsName << endl;
		 cout << "\nLastName    :" << User.LastName << endl;
		 cout << "\nFullName    :" << User.FirtsName << endl;
		 cout << "\nEmail       :" << User.Email << endl;
		 cout << "\nPhone       :" << User.Phone << endl;
		 cout << "\nUser Name   :" << User.UserName << endl;
		 cout << "\nPassWord    :" << User.PassWord << endl;
		 cout << "\nPermissions :" << User.Permissions << endl;
		 cout << "\n---------------------------------\n";

	 }


 public:
	 static void ShowAddNewUserScreen()
	 {
		 _DrawScreenHeader("\t  Add New User Screen");

		 string UserName = "";
		 cout << "\nPlease Enter UserName: ";
		 UserName = ClsInputValidate::ReadString();

		 while (clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUserName Is Already Used, Choose another one: ";
			 UserName = ClsInputValidate::ReadString();

		 }

		 clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		 _ReadUserInfo(NewUser);
		 

		 clsUser::enSaveResults SaveResult;

		 SaveResult = NewUser.Save();

		 switch (SaveResult)
		 {
		 case clsUser::enSaveResults::svFaildEmptyObject:
		   {
			   cout << "\nError User was not saved because it's Empty";
			   break;
		   }

		 case clsUser::enSaveResults::svFaildUserExist:
		   {
			   cout << "\nError User was not saved because UserName is used!\n";
			   break;
		   }

		   case clsUser::enSaveResults::svSucceeded:
		   {
			   cout << "\nUser Addeded Successfully :-)\n";
			   _PrintUser(NewUser);

			   break;
		   }

		 }
		 
		 
	 }


};

