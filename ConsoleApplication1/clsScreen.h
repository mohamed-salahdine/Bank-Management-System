#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include"clsUser.h"
#include"Global.h"
#include"ClsData.h"
#include<ctime>
using namespace std;

class clsScreen
{
  protected:

      static void _DrawScreenHeader(string title, string subtitle = "")
      {
          cout << "\t\t\t\t     ===========================================";
          cout << "\n\t\t\t\t\t  " << title;
          if (subtitle != "")
          {
              cout << "\n\t\t\t\t\t  " << subtitle;
          }
          cout << "\n\t\t\t\t     ===========================================\n\n";
          cout << "\033[32m" << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
          cout  << "\t\t\t\t\tDate: " << ClsDate::DateToString(ClsDate());
          cout << "\033[0m" << "\n\n";
          
     
      }

      
  
      static bool CheckAccessRights(clsUser::enPermissions Permissions)
      {
          if (!CurrentUser.CheckAccessPermission(Permissions))
          {
              cout << "\t\t\t\t\t" << "\033[38;5;208m" << "=====================================";
              cout << "\n\t\t\t\t\t" << "\033[31;6m" << " Access Denied! Contact your Admin." << "\033[0m";
              cout << "\n\t\t\t\t\t" << "\033[38;5;208m" << "=====================================\033[0m \n\n";

              return false;

          }

          return true;
      }


};

