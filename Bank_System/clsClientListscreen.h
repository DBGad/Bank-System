#pragma once
#include "clsHeaderScreen.h"
#include "clsBankClient.h"
class clsClientListscreen :protected clsHeaderScreen
{

   static void _PrintClientRecordLine(clsBankClient Client)
    {

       cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
       cout << "| " << setw(20) << left << Client.FullName();
       cout << "| " << setw(12) << left << Client.Phone;
       cout << "| " << setw(20) << left << Client.Email;
       cout << "| " << setw(10) << left << Client.PinCode;
       cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:
static void  ClientListscreen() {

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    string Title = "\tClient List Screen";
    string SubTitle = "\tClient (" + to_string(vClients.size()) + ") Client(s).";
        _HeaderScreen(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient &Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	
}

};

