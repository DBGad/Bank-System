#pragma once
#include "clsHeaderScreen.h"
class clsAddNewClientScreen : protected clsHeaderScreen
{
   static void  _ReadAddClient(clsBankClient& client) {
        client.SetFirstName(clsInputValidate::ReadString("Enter First Name\n"));
        client.SetLastName(clsInputValidate::ReadString("Enter Last Name\n"));
        client.SetEmail(clsInputValidate::ReadString("Enter Email\n"));
        client.SetPhone(clsInputValidate::ReadString("Enter Phone\n"));
        client.SetPinCode(clsInputValidate::ReadString("Enter PinCode\n"));
        client.SetAccountBalance(clsInputValidate::ReadDblNumber("Enter Balance\n"));
    }
  static void _Printclient(clsBankClient& client) {
       cout << "\nClient Card:";
       cout << "\n___________________";
       cout << "\nFirstName   : " << client.FirstName;
       cout << "\nLastName    : " << client.LastName;
       cout << "\nFull Name   : " << client.FullName();
       cout << "\nEmail       : " << client.Email;
       cout << "\nPhone       : " << client.Phone;
       cout << "\nAcc. Number : " << client.AccountNumber();
       cout << "\nPassword    : " << client.GetPinCode();
       cout << "\nBalance     : " << client.GetAccountBalance();
       cout << "\n___________________\n";

   }


public:


	static void AddNewClientScreen() {
		_HeaderScreen("\t\tAdd Client Screen");
        string Acc = clsInputValidate::ReadString("Enter Account Number \n");
        while (clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is Acc Allready ,Pls Try Agian \n");
        }
        clsBankClient NewClient = clsBankClient::AddClient(Acc);
        _ReadAddClient(NewClient);
        clsBankClient::enSaveResult Result;

        Result = NewClient.Save();
        switch (Result)
        {
        case clsBankClient::SvFiled:
            cout << "\nsorry We Cant Save\n";
            break;
        case clsBankClient::svsuccessd:
            cout << "\nSaved Done \n";
            _Printclient(NewClient);
            break;
        }
    }
	
};

