#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
using namespace std;


class clsUpdateUserScreen:protected clsScreen
{

 private:
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
	 static int _ReadPermissionsToSet()
	 {
		 char Answer = 'n';
		 short Permissions = 0;

		 cout << "\nDo you want to give full access? y/n? ";
		 cin >> Answer;
		 if (Answer == 'y' || Answer == 'Y')
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

		 cout << "\nShow Currency Exchange? y/n? ";
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

 public:
	 static void ShowUpdateUserScreen()
	 {
		 _DrawScreenHeader("\tUpdate User Screen");

		 string UserName = "";

		 cout << "\nPlease Enter User UserName: ";
		 UserName = ClsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nAccount number is not found, choose another one: ";
			 UserName = ClsInputValidate::ReadString();
		 }

		 clsUser User1 = clsUser::Find(UserName);

		 _PrintUser(User1);

		 cout << "\nAre you sure you want to update this User y/n? ";

		 char Answer = 'n';
		 cin >> Answer;

		 if (Answer=='y'||Answer=='Y')
		 {
			 cout << "\n\nUpdate User Info:";
			 cout << "\n____________________\n";

			 _ReadUserInfo(User1);

			 clsUser::enSaveResults SaveResult;

			 SaveResult = User1.Save();
			 switch (SaveResult)
			 {
			   case clsUser::enSaveResults::svSucceeded:
			   {
				   cout << "\nUser Updated Successfully :-)\n";
				   _PrintUser(User1);
				   break;

			   }
			  
			   case clsUser::enSaveResults::svFaildEmptyObject:
			   {
				   cout << "\nError User was not saved because it's Empty";
				   break;
			   }

			 }




		 }
		 else
		 {
			 cout << "\nThe update process has been cancelled.\n";

		 }
		 





	 }


};

