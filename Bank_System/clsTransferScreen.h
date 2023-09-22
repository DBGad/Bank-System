#pragma once
#include "clsHeaderScreen.h"
#include "clsTransferLogFile.h"

class clsTransferScreen :protected clsHeaderScreen
{

    static void _Printclient2(clsBankClient& client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";

    }
public:
	static void Transfer() {
		_HeaderScreen("\t Transfer Screen");
        string Acc = clsInputValidate::ReadString("Enter Acc Number To Tranfer From : \n");
        while (!clsBankClient::IsClientExist(Acc)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient client1 = clsBankClient::Find(Acc);
        _Printclient2(client1);
        string Acc2 = clsInputValidate::ReadString("Enter Acc Number To Tranfer To : \n");
        while (!clsBankClient::IsClientExist(Acc2)) {
            Acc = clsInputValidate::ReadString("There is No Acc ,Pls Try Agian \n");
        }
        clsBankClient client2 = clsBankClient::Find(Acc2);
        _Printclient2(client2);

        double Amount = clsInputValidate::ReadDblNumber("Enter Transfer Amount\n");
        while ((Amount>client1.GetAccountBalance()))
        {
            Amount = clsInputValidate::ReadDblNumber("Amount Exceeds the avilabale Balance, Enter Another Transfer Amount\n");
        }

        if (toupper(clsInputValidate::Readchar("Do You Want Perform This Opration ? [Y/N]\n")) == 'Y') {

            client1.AccountBalance -= Amount;
            client2.AccountBalance += Amount;

            clsBankClient::enSaveResult r1, r2;
                bool Result;
            r1 = client1.Save();
            r2 = client2.Save();
            Result = (r1 == r2);
            if (Result==true) {
                clsTransferLogFile::SaveToTransFile(Acc,Acc2,Amount,client1.AccountBalance,client2.AccountBalance,CurrentUser.UserName);
                cout << "Transfer completed\n";
                _Printclient2(client1);
                _Printclient2(client2);
            }
            else {
                cout << "Transfer not completed\n";
            }
        }


	}

};

