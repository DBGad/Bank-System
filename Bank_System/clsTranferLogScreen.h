#pragma once
#include "clsHeaderScreen.h"
#include "clsTransferLogFile.h"
class clsTranferLogScreen :protected clsHeaderScreen
{

    static void PrintTransRegisterRecordLine(clsTransferLogFile LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << LoginRegisterRecord.Getdate();
        cout << "| " << setw(8) << left << LoginRegisterRecord.GetAcc1();
        cout << "| " << setw(8) << left << LoginRegisterRecord.GetAcc2();
        cout << "| " << setw(8) << left << LoginRegisterRecord.Getamount();
        cout << "| " << setw(10) << left << LoginRegisterRecord.GetBalance1();
        cout << "| " << setw(10) << left << LoginRegisterRecord.GetBalance2();
        cout << "| " << setw(8) << left << LoginRegisterRecord.GetUser();

    }

public:
	static void TransLogScreen() {
		vector <clsTransferLogFile> vTransRegisterRecord = clsTransferLogFile::GetfromTransFile();
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransRegisterRecord.size()) + ") Record(s).";

        _HeaderScreen(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsTransferLogFile Record : vTransRegisterRecord)
            {

                PrintTransRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}


};

