#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"ClsInputValidate.h"
using namespace std;


class clsFindUserScreen:protected clsScreen
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
 public:

	 static void ShowFindUserScreen()
	 {
		 _DrawScreenHeader("\t  Find User Screen");

		 string UserName = "";
		 cout << "\nPlease Enter UserName: ";

		 UserName = ClsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser is not found, choose another one: ";
			 UserName = ClsInputValidate::ReadString();

		 }
		 clsUser User1 = clsUser::Find(UserName);

		 if (!User1.IsEmpty())
		 {
			 cout << "\nUser Found :-)\n";
		 }
		 else
		 {
			 cout << "\nUser Was not Found :-(\n";
			 

		 }
		 _PrintUser(User1);



	 }
};

