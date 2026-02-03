#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<vector>
using namespace std;


class clsUsersListScreen:protected clsScreen
{
  private:

	  static void _PrintUserRecordLine(clsUser User)
	  {
		


		  cout << setw(8) << left << "" << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(12) << User.UserName;
		  cout << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(22) << User.FullName();
		  cout << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(12) << User.Phone;
		  cout << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(26) << User.Email;
		  cout << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(8) << User.PassWord;
		  cout << "\033[38;5;208m" << "| " << "\033[0m" << left << setw(12) << User.View_permission_results();

	  }


  public:

	  static void ShowUsersList()
	  {
		  vector<clsUser>vUsers;
		  vUsers = clsUser::GetUsersList();

		  string Title = "\t  User List Screen";
		  string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";
		  _DrawScreenHeader(Title, SubTitle);

		  

		  cout << setw(8) << left << "" << "\033[38;5;208m" << "\n\t=========================================================";
		  cout << "====================================================\n";
		  cout << setw(8) << left << "" << "| " << "\033[38;5;205m" << left << setw(12) << "UserName";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(22) << "Full Name";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(12) << "Phone";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(26) << "Email";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(8) << "Password";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(12) << "Permissions";
		  cout << setw(8) << left << "" << "\033[38;5;208m" << "\n\t=========================================================";
		  cout << "====================================================\033[0m\n";

		 
		

		  if (vUsers.size()==0)
		  {
			  cout << "\t\t\t\t\tNo Users Available In the System!";
		  }
		  else
		  {
			  for (clsUser &User:vUsers)
			  {
				  _PrintUserRecordLine(User);
				  cout << endl;
			  }

		  }

		  
		  cout << setw(8) << left << "" << "\033[38;5;208m" << "=========================================================";
		  cout << "====================================================\033[0m\n";

		  

		 
	  }
};

