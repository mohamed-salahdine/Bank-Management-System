#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsUser.h"
using namespace std;





class clsClientListScreen:protected clsScreen
{
  private:
	  static void PrintClientRecordLine(clsBankClient Client)
	  {
		  cout << setw(8) << left << "" <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(15) << left << Client.GetAccountNamber();
		  cout <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(20) << left << Client.FullName();
		  cout <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(12) << left << Client.Phone;
		  cout <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(26) << left << Client.Email;
		  cout <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(10) << left << Client.PinCod;
		  cout <<"\033[38;5;208m" << "| " <<"\033[0m" << setw(12) << left << Client.AccounBalanc;
	  }


  public:


	  static void ShowClientsList()
	  {
		  if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		  {
			  return;
		  }

		  vector<clsBankClient>vClients;
		  vClients = clsBankClient::GetClientsList();

		  string Title = "\t  Client List Screen";
		  string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		  clsScreen::_DrawScreenHeader(Title,SubTitle);

	

		  cout << setw(8) << "\033[38;5;208m" << left << "" << "\n\t========================================================================================================\n";


		  cout << setw(8) << left << "" << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(15) << "Accout Number";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(20) << "Client Name";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(12) << "Phone";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(26) << "Email";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(10) << "Pin Code";
		  cout << "\033[38;5;208m" << "| " << "\033[38;5;205m" << left << setw(12) << "Balance ";
		  cout << setw(8) << left << "" << "\033[38;5;208m" << "\t========================================================================================================" << "\033[0m" << endl;

	

		  if (vClients.size()==0)
		  {
			  cout << "\t\t\t\tNo Clients Available In the System!";
		  }
		  else
		  {
			  for (clsBankClient &C:vClients)
			  {
				  PrintClientRecordLine(C);
				  cout << endl;

			  }
		  }
		  cout << setw(8) << "\033[38;5;208m" << left << "" << "\t========================================================================================================\n" << "\033[0m" << endl;
		  
		 
		

		 


	  }
};

