#pragma once
#include "clsHeaderScreen.h"
class clsWithdrawScreen :protected clsHeaderScreen
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
    static  void WithdrawScreen() {
        _HeaderScreen("\t\tWithdraw Screen");
        string Acc = clsInputValidate::ReadString("Enter Acc Number To Withdraw \n");
        while (!clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient client1 = clsBankClient::Find(Acc);
        _Printclient(client1);
        double Money = clsInputValidate::ReadDblNumber("How much do You Want to Withdraw ? ");
        if (toupper(clsInputValidate::Readchar("Are you sure you want Withdraw ? [Y/N] ")) == 'Y') {
            client1.AccountBalance -= Money;
            clsBankClient::enSaveResult Result;
            Result = client1.Save();
            switch (Result)
            {
            case clsBankClient::SvFiled:
                cout << "\nsorry We Cant Withdraw\n";
                break;
            case clsBankClient::svsuccessd:
                cout << "\nWithdraw Done \n";
                _Printclient(client1);
                break;
            default:
                break;
            }

        }
   }



};

