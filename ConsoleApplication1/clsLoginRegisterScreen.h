#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsString.h"
#include"clsUser.h"
#include"ClsInputValidate.h"
#include<fstream>

using namespace std;

class clsLoginRegisterScreen:clsScreen
{
 private:

	

	 static void _PrintLoginRegisterRecordLine( clsUser::stLoginRegisterRecord LoginRegisterRecord)
	 {
		 

		 

		 cout << setw(8) << left << "" <<"\033[38;5;208m" << "| "<<"\033[0m" << setw(35) << left << LoginRegisterRecord.DateTime;
		 cout <<"\033[38;5;208m" << "| "<<"\033[0m" << setw(20) << left << LoginRegisterRecord.UserName;
		 cout <<"\033[38;5;208m" << "| "<<"\033[0m" << setw(20) << left << LoginRegisterRecord.Password;
		 cout <<"\033[38;5;208m" << "| "<<"\033[0m" << setw(10) << left << LoginRegisterRecord.Permissions;

		 


	 }

 public:

	 static void ShowLoginRegisterScreen()
	 {
		 if (!CheckAccessRights(clsUser::pShowLogInRegister))
		 {
			 return;
		 }
		 vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		 string Title = "\tLogin Register List Screen";
		 string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		 _DrawScreenHeader(Title, SubTitle);

	

		 cout << setw(8) << left << "" << "\033[38;5;208m" << "\n\t________________________________________________________________________________________________\033[0m" << endl;
		 

		 cout << setw(8) << left << "" << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(35) << "Date/Time";
		 cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(20) << "UserName";
		 cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(20) << "Password";
		 cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(10) << "Permissions";
		 cout << setw(8) << left << "" << "\033[38;5;208m" << "\n\t________________________________________________________________________________________________\033[0m" << endl;
         

		


		 if (vLoginRegisterRecord.size()==0)
		 {
			 cout << "\t\t\t\t\tNo login was recorded in the system.";
		 }
		 else
		 {
			 for (clsUser::stLoginRegisterRecord Record: vLoginRegisterRecord)
			 {
				 _PrintLoginRegisterRecordLine(Record);
				 cout << "\n";

			 }

		 }
		 cout << setw(8) << left << "" <<"\033[38;5;208m"<< "\n\t________________________________________________________________________________________________\n" << "\033[0m";
		

		 



		 

	 }
};

