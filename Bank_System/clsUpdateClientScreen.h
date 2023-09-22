#pragma once
#include"clsHeaderScreen.h"

class clsUpdateClientScreen:protected clsHeaderScreen
{
   static void _ReadUpdateClient(clsBankClient& client) {
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
    static void UpdateClientScreen() {
        _HeaderScreen("\tUpdate Client Screen");
        string Acc = clsInputValidate::ReadString("Enter Acc Number To Update \n");
        while (!clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient client1 = clsBankClient::Find(Acc);
        _Printclient(client1);
        if (toupper(clsInputValidate::Readchar("Do You Watn to Delet This Client ? [Y/N]\n")) == 'Y') {
            _ReadUpdateClient(client1);
            clsBankClient::enSaveResult Result;
            Result = client1.Save();
            switch (Result)
            {
            case clsBankClient::SvFiled:
                cout << "\nsorry We Cant Save\n";
                break;
            case clsBankClient::svsuccessd:
                cout << "\nSaved Done \n";
                _Printclient(client1);
                break;
            default:
                break;
            }


        }
    }
};

