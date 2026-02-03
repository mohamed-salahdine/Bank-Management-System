#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsTransferLogScreen :protected clsScreen
{
 private:
     static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
     {
         cout << setw(8) << left << "" << "| " << setw(24) << left << TransferLogRecord.DateTime;
         cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber ;
         cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber ;
         cout << "| " << setw(8) << left << TransferLogRecord.Amount ;
         cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter ;
         cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter ;
         cout << "| " << setw(8) << left << TransferLogRecord.UserName ;


     }


 public:

	 static void ShowTransferLogScreen()
	 {
         vector<clsBankClient::stTrnsferLogRecord>vTransferLogRecord = clsBankClient::GetTransfersLogList();

		 
		 string Title = "\tTransfer Log List Screen";
         string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";
		 _DrawScreenHeader(Title,SubTitle);




         cout << setw(8) <<left<< "" << "\n\t_______________________________________________________";
         cout << "_________________________________________\n" << endl;

         cout << setw(8) <<left<<"" << "| " << setw(24) << left << "Date/Time";
         cout << "| " << setw(8) << left << "s.Acct";
         cout << "| " << setw(8) << left << "D.Acct";
         cout << "| " << setw(8) << left << "Amount";
         cout << "| " << setw(10) << left << "s.Balance";
         cout << "| " << setw(10) << left << "d.Balance";
         cout << "| " << setw(8) << left << "User";

         cout << setw(8) << left << "" << "\n\t_______________________________________________________";
         cout << "_________________________________________\n" << endl;
        


         if (vTransferLogRecord.size()==0)
         {
             cout << "\t\t\t\tNo Transfers Available In the System!";
         }
         else
         {
             for (clsBankClient::stTrnsferLogRecord &Record:vTransferLogRecord)
             {
                 PrintTransferLogRecordLine(Record);
                 cout << endl;

             }

         }

         cout << "\n" << setw(8) << left << "" << "__________________________________________________________";
         cout << "________________________________________" << endl;



	 }

   
     
};

