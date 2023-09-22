#pragma once
#include "clsHeaderScreen.h"
class clsDepsiteScreen :protected clsHeaderScreen
{
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
	static void DepsiteScreen() {
        _HeaderScreen("\t\tDeposite Screen");
        string Acc = clsInputValidate::ReadString("Enter Acc Number To Depsite \n");
        while (!clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient client1 = clsBankClient::Find(Acc);
        _Printclient(client1);
        double Money = clsInputValidate::ReadDblNumber("How much do You Want to Depsite ? ");
        if (toupper(clsInputValidate::Readchar("Are you sure you want Deposite ? [Y/N] ")) == 'Y') {
            client1.AccountBalance += Money;
            clsBankClient::enSaveResult Result;
            Result = client1.Save();
            switch (Result)
            {
            case clsBankClient::SvFiled:
                cout << "\nsorry We Cant Deposite\n";
                break;
            case clsBankClient::svsuccessd:
                cout << "\nDeposited Done \n";
                _Printclient(client1);
                break;
            default:
                break;
            }

        }

	}


};

