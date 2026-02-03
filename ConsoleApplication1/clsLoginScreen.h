#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
using namespace std;


class clsLoginScreen:protected clsScreen
{
 private:

	 static bool _Login()
	 {
		 bool LoginFaild = false;
		 short FaildLoginCount = 0;
		 

		 string Username, Password;
		 

		 do
		 {
			 if (LoginFaild)
			 {
				 FaildLoginCount++;

				 cout << "\n\t\t\t\t\t"<< "\033[38;5;208m" <<"Invlaid Username / Password!";
				 cout << "\n\t\t\t\t\tYou have " << (3-FaildLoginCount) << " trial(s) to login.\n\n"<< "\033[0m" ;
				

			 }

			 if (FaildLoginCount == 3)
			 {
				 cout << "\n\t\t\t\t\t"<< "\033[31;6;1m" <<"You are locked after 3 faile trials.\n\n"<< "\033[0m";
				 return false;

			 }

			 cout   << "\n\t\t\t\t\t"<<"Enter Username ? ";
			 cin >> Username;

			 cout << "\t\t\t\t\t" << "Enter Password? ";
			 cin >> Password;

			 CurrentUser = clsUser::Find(Username, Password);

			 LoginFaild = CurrentUser.IsEmpty();

			 
		 } while (LoginFaild);
		 CurrentUser.RegisterLogIn();

		 clsMainScreen::ShowMainMenue();
		 return true;
	 }

	 
	 
	 

 public:
	 static bool ShowLoginScreen()
	 {
		 system("cls");
		 _DrawScreenHeader("\t  Login Screen");
		return _Login();
		 
	 }


};

