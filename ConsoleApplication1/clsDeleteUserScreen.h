#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
using namespace std;


class clsDeleteUserScreen:protected clsScreen
{

 private:
	 static void _PrintUser(clsUser& User)
	 {
		

		 cout << "\033[31m" << "\nClient Card:";
		 cout << "\033[38;5;208m" << "\n==================================";
		 cout << "\033[33m" << "\nFirstName   :" << "\033[0m" << User.FirtsName << endl;
		 cout << "\033[33m" << "\nLastName    :" << "\033[0m" << User.LastName << endl;
		 cout << "\033[33m" << "\nFullName    :" << "\033[0m" << User.FirtsName << endl;
		 cout << "\033[33m" << "\nEmail       :" << "\033[0m" << User.Email << endl;
		 cout << "\033[33m" << "\nPhone       :" << "\033[0m" << User.Phone << endl;
		 cout << "\033[33m" << "\nUser Name   :" << "\033[0m" << User.UserName << endl;
		 cout << "\033[33m" << "\nPassWord    :" << "\033[0m" << User.PassWord << endl;
		 cout << "\033[33m" << "\nPermissions :" << "\033[0m" << User.Permissions << endl;
		 cout << "\033[38;5;208m" << "\n==================================\n" << "\033[0m";

	 }


 public:
	 static void ShowDeleteUserScreen()
	 {
		 _DrawScreenHeader("\tDelete User Screen");

		 string UserName = "";

		 cout << "\nPlease Enter UserName: ";

		 UserName = ClsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser is not found, choose another one: ";
			 UserName = ClsInputValidate::ReadString();

		 }

		 clsUser User1 = clsUser::Find(UserName);
		 _PrintUser(User1);

		
		 cout << "\033[31;1;5m" << "\nAre you sure you want to delete this User y/n ?" << "\033[0m ";
		 char Answer = 'n';
		 cin >> Answer;

		 if (Answer=='y'||Answer=='Y')
		 {
			 if (User1.Delete())
			 {
				 cout << "\nUser Deleted Successfully :-)\n";
				 _PrintUser(User1);

			 }

		 }
		 else
		 {
			 cout << "\nError User Was not Deleted\n";

		 }


	 }


};

