#pragma once
#include"clsHeaderScreen.h"
class clsFindCurrencyScreen :protected clsHeaderScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.GetName();
        cout << "\nCode       : " << Currency.GetCode();
        cout << "\nName       : " << Currency.GetPoundName();
        cout << "\nRate(1$)   : " << Currency.GetRate();
        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _HeaderScreen("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

         Answer = (short)clsInputValidate::ReadIntNumberBetween(1,2);

        if (Answer == 1)
        {
            string CurrencyCode;
 
            CurrencyCode = clsString::LowerAllString(clsInputValidate::ReadString("\nPlease Enter CurrencyCode: "));
            clsCurrency Currency = clsCurrency::FindBycode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            Country = clsString::LowerAllString(clsInputValidate::ReadString("\nPlease Enter Country Name: "));
            clsCurrency Currency = clsCurrency::FindByName(Country);
            _ShowResults(Currency);
        }






    }










};

