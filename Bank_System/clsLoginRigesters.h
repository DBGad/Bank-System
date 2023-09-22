#pragma once
#include "clsUserLogToFile.h"
#include "clsHeaderScreen.h"
class clsLoginRigesters : protected clsHeaderScreen
{
    static void PrintLoginRegisterRecordLine(clsUserLogToFile LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.GetDate();
        cout << "| " << setw(20) << left << LoginRegisterRecord.GetUsername();
        cout << "| " << setw(20) << left << LoginRegisterRecord.GetPassword();
        cout << "| " << setw(10) << left << LoginRegisterRecord.GetPerm();
    }
public :
    static void LoginRigester() {
        vector <clsUserLogToFile> vLoginRegisterRecord = clsUserLogToFile::GetInfoFromFile();
        string Title = "\tlogin Rigester Screen";
        string SubTitle = "\Rigester (" + to_string(vLoginRegisterRecord.size()) + ") Rigester(s).";
        _HeaderScreen(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUserLogToFile Record : vLoginRegisterRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

