#pragma once
#include "clsHeaderScreen.h"
class clsDeleteScreen : protected clsHeaderScreen
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
	static void DeleteClientScreen() {
		_HeaderScreen("\tDelete Client Screen");
        string Acc = clsInputValidate::ReadString("Enter Acc Number \n");
        while (!clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient dclient = clsBankClient::Find(Acc);
        _Printclient(dclient);

        if (toupper(clsInputValidate::Readchar("Do You Watn to Delet This Client ? [Y/N]\n")) == 'Y') {
            if (dclient.Delete()) {
                cout << "Deleted done";
                _Printclient(dclient);
            }
        }
	}

};

