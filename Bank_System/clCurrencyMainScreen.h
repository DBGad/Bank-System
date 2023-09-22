#pragma once
#include "clsHeaderScreen.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include "clsCurrenceiesCalculatorScreen.h"
class clCurrencyMainScreen : protected clsHeaderScreen
{
    enum eChoiceCurrencyMenu {eList = 1 , eFind = 2 , eUpdate = 3 , eCalc = 4 ,eLogout = 5 };
    static void _GoBackToCurrencyMenu() {
        cout << "\n\nPerss Any Key to GO Back to Currency Main Menu ";
        system("pause>0");
        CurrencyScreen();
    }

    static void _CurrenceiesCalculator() {
        system("cls");
        clsCurrenceiesCalculatorScreen::CalcCurrecny();
        _GoBackToCurrencyMenu();
    }


    static void  _UpdateCurrency() {
        system("cls");
        clsUpdateCurrencyScreen::UpdateCurrency();
            _GoBackToCurrencyMenu();
    }
    static void  _FindCurrency() {
        system("cls");
       clsFindCurrencyScreen::ShowFindCurrencyScreen();
        _GoBackToCurrencyMenu();
    }

    static void  _listCurrency() {
        system("cls");
        clsListCurrencyScreen::ListCurrency();
        _GoBackToCurrencyMenu();
   }



    static void _CurrencyScreen(eChoiceCurrencyMenu Choice) {
        switch (Choice)
        {
        case clCurrencyMainScreen::eList:
            _listCurrency();
            break;
        case clCurrencyMainScreen::eFind:
            _FindCurrency();
            break;
        case clCurrencyMainScreen::eUpdate:
            _UpdateCurrency();
            break;
        case clCurrencyMainScreen::eCalc:
            _CurrenceiesCalculator();
            break;
        case clCurrencyMainScreen::eLogout:
            break;
        }
    }



    static int _ReadChoice() {
        cout << setw(37) << left << "" << "Choose What do You Want Between [1/6] ? ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;
    }




public:
	static void CurrencyScreen() {
        system("cls");
		_HeaderScreen("\tCurrency Main Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currenceies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currenceies Calculator.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _CurrencyScreen(eChoiceCurrencyMenu(_ReadChoice()));




	}


};