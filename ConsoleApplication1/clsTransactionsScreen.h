#pragma once
#include<iostream>
#include"clsScreen.h"
#include"ClsInputValidate.h"
#include<iomanip>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"




using namespace std;

class clsTransactionsScreen:protected clsScreen
{
  private:
      enum enTransactionsMenueOptions{enDeposit=1,enWithdraw,eShowTotalBalance,eTransfer,eTransferLog,eShowMainMenue};


      static short ReadTransactionsMenueOption()
      {
          short Choice;

          cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
          Choice= ClsInputValidate::ReadShortNumberBetween(1, 6);

          return Choice;

      }

      static void _ShowDepositScreen()
      {
         // cout << "Showe Deposit Screen Will be her..";
          clsDepositScreen::ShowDepositScreen();
      }
      static void _ShowWithdrawScreen()
      {
         // cout << "Showe Withdraw Screen Will be her..";
          clsWithdrawScreen::ShowWithdrawScreen();
      }
      static void _ShowTotalBalancesScreen()
      {
         // cout << "Showe Total Balancecs Screen Will be her..";
          clsTotalBalancesScreen::ShowTotalBalances();
          
      }

      static void _ShowTransferScreen()
      {
          // cout << "Showe Withdraw Screen Will be her..";
          clsTransferScreen::ShowTransferScreen();
          
      }

      static void _ShowTransferLogScreen()
      {
          // cout << "Showe Total Balancecs Screen Will be her..";
          clsTransferLogScreen::ShowTransferLogScreen();
          

      }


      static void _GoBackToTransactionsMenue()
      {
          cout << "\n\nPress any key to go back to Transactions Menue...";
          system("pause>0");
          ShowTransactionsMenue();
      }


      static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
      {
          switch (TransactionsMenueOption)
          {
            case enTransactionsMenueOptions::enDeposit:
            {
                 system("cls");
                _ShowDepositScreen();
                _GoBackToTransactionsMenue();

                break;
            }
            case enTransactionsMenueOptions::enWithdraw:
            {
                 system("cls");
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenue();

                break;
            }
            case enTransactionsMenueOptions::eShowTotalBalance:
            {
                 system("cls");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenue();

                break;
            }
            case enTransactionsMenueOptions::eTransfer:
            {
                 system("cls");
                 _ShowTransferScreen();
                _GoBackToTransactionsMenue();

                break;
            }
            case enTransactionsMenueOptions::eTransferLog:
            {
                system("cls");
                _ShowTransferLogScreen();
                _GoBackToTransactionsMenue();

                break;
            }
            case enTransactionsMenueOptions::eShowMainMenue:
            {


                break;
            }

          }

      }


  public:
	  static void ShowTransactionsMenue()
	  {
          if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
          {
              return;
          }

          system("cls");

		  _DrawScreenHeader("\t  Transactions Screen");
        

          cout << "\n\n\n\n" << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n";
          cout << setw(37) << left << "" << "\033[31m" << "\t\t  Transactions Menue\n";
          cout << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[1]" << "\033[0m" << " Deposit.\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[2]" << "\033[0m" << " Withdraw.\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[3]" << "\033[0m" << " Total Balances.\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[4]" << "\033[0m" << " Transfer.\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[5]" << "\033[0m" << " Transfer Log.\n";
          cout << setw(37) << left << "" << "\033[33m" << "\t[6]" << "\033[0m" << " Main Menue.\n";
          cout << setw(37) << left << "" << "\033[38;5;208m" << "===========================================\n" << "\033[0m";

          _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
          

	  }


};

