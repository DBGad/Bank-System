#pragma once
#include"clsHeaderScreen.h"
#include "clsCurrency.h"
class clsListCurrencyScreen :protected clsHeaderScreen
{
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetName();
        cout << "| " << setw(8) << left << Currency.GetCode();
        cout << "| " << setw(45) << left << Currency.GetPoundName();
        cout << "| " << setw(10) << left << Currency.GetRate();
      
    }

public:
    static void ListCurrency() {
        vector <clsCurrency> vdata = clsCurrency::GetDataFromFileCurrency();
        string Title = "\tCurrency List Screen";
        string SubTitle = "\tCurrency (" + to_string(vdata.size()) + ") Currency(s).";
        _HeaderScreen(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vdata.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vdata)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;


  
    }
};