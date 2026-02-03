#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include"clsUser.h"
#include<iomanip>
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;

class clsManageUsers:protected clsScreen
{
  private:
	  enum enManagerUserOption{eListUsers=1,eAddNewUser=2,eDeleteUser,eUpdateUser,eFindUser,eMainMenue};

	  static short ReadManageUsersMenueOption()
	  {
		  cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 6]";
		  short Number = ClsInputValidate::ReadShortNumberBetween(1, 6);
		  return Number;
	  }

	  static void _ShowListUsersScreen()
	  {
		  //cout << " List User Screen Will be her..";
		  clsUsersListScreen::ShowUsersList();
	  }
	  static void _ShowAddNewUserScreen()
	  {
		  //cout << "Add User Screen Will be her..";
		  clsAddNewUserScreen::ShowAddNewUserScreen();
	  }
	  static void _ShowDeleteUserScreen()
	  {
		  //cout << " Delete  User Screen Will be her..";
		  clsDeleteUserScreen::ShowDeleteUserScreen();
	  }
	  static void _ShowUpdateUserScreen()
	  {
		  //cout << " Update User Screen Will be her..";
		  clsUpdateUserScreen::ShowUpdateUserScreen();
	  }
	  static void _ShowFindUserScreen()
	  {
		  //cout << " Find User Screen Will be her..";
		  clsFindUserScreen::ShowFindUserScreen();
	  }

	  static void _GoBackToManageUsersMenue()
	  {
		  cout << "\n\nPress any key to go back to Manage Users Menue...";
		  system("pause>0");
		  ShowManageUsersMenue();
	  }

	  static void _PerformManageUsersMenueOption(enManagerUserOption ManageUsersMenueOption)
	  {
		  switch (ManageUsersMenueOption)
		  {
		    case enManagerUserOption::eListUsers:
		    {
				system("cls");
				_ShowListUsersScreen();
				_GoBackToManageUsersMenue();

			   break;
		    }
			case enManagerUserOption::eAddNewUser:
			{
				system("cls");
				_ShowAddNewUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}
			case enManagerUserOption::eDeleteUser:
			{
				system("cls");
				_ShowDeleteUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}
			case enManagerUserOption::eUpdateUser:
			{
				system("cls");
				_ShowUpdateUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}
			case enManagerUserOption::eFindUser:
			{
				system("cls");
				_ShowFindUserScreen();
				_GoBackToManageUsersMenue();
				break;
			}
			case enManagerUserOption::eMainMenue:
			{
				
				break;
			}

		  }

	  }

  public:

	  static void ShowManageUsersMenue()
	  {
		  if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		  {
			  return;
		  }

		   system("cls");
		  _DrawScreenHeader("\t   Manager Users Screen");

		

		  cout << setw(37) << left << "" << "\033[38;5;208m" << "============================================\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [1]" << "\033[0m" << " List Users.\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [2]" << "\033[0m" << " Add New User.\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [3]" << "\033[0m" << " Delete User.\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [4]" << "\033[0m" << " Update Users.\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [5]" << "\033[0m" << " Find Users.\n";
		  cout << setw(37) << left << "" << "\033[33m" << " [6]" << "\033[0m" << " Main Menue.\n";
		  cout << setw(37) << left << "" << "\033[38;5;208m" << "============================================\n" << "\033[0m";

		  _PerformManageUsersMenueOption((enManagerUserOption)ReadManageUsersMenueOption());



	  }
};

