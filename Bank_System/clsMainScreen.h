#pragma once
#include "clsInputValidate.h"
#include "clsHeaderScreen.h"
#include "clsClientListscreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "clsLoginRigesters.h"
#include "clCurrencyMainScreen.h"
#include "global.h"
class clsMainScreen : protected clsHeaderScreen
{
private:
    enum eChoiceMainMenu {eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4,eFindClient=5,eTransactions=6,eManageUsers=7,eLoginRigesters=8,eCurrency=9,eLogout=10};


    static void _GoBackToMainMenu() {
        cout << "\n\nPerss Any Key to GO Back to Main Menu ";
        system("pause>0");
        SHowMainMenu();
   }

    static void _ShowClientList() {
        system("cls");
       
        if (!CheckAccessRights(clsUser::pListClients)) {
            _GoBackToMainMenu();
        }
        else
        {
            clsClientListscreen::ClientListscreen();
            _GoBackToMainMenu();
        }
    }
    static void _AddNewClient() {
        system("cls");
        if (!CheckAccessRights(clsUser::pAddNewClient)) {
            _GoBackToMainMenu();
        }
        else
        {
            clsAddNewClientScreen::AddNewClientScreen();
            _GoBackToMainMenu();
        }
    }
    static void _DeleteClientScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pDeleteClient)) {
            _GoBackToMainMenu();
        }
        
        else
        {
            clsDeleteScreen::DeleteClientScreen();
        _GoBackToMainMenu();
        }
    }
    static void _UpdateClientScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pUpdateClients)) {
            _GoBackToMainMenu();
        }
        else
        {


            clsUpdateClientScreen::UpdateClientScreen();
            _GoBackToMainMenu();
        }
    }
    static void _FindClientScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pFindClient)) {
            _GoBackToMainMenu();
        }
        else {
            clsFindClientScreen::FindClient();
            _GoBackToMainMenu();
        }
    }

    static  void _ShowTransactionsScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pTranactions)) {
            _GoBackToMainMenu();
        }
        else {
            clsTransactionsScreen::ShowTransactionsScreen();
            _GoBackToMainMenu();
        }
    }
    static  void _ShowManageScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pManageUsers)) {
            _GoBackToMainMenu();
        }
        else {
            clsManageUsers::ShowManageUsersScreen();
            _GoBackToMainMenu();
        }
    }
    static void _LoginRigesters() {
        system("cls");
        if (!CheckAccessRights(clsUser::PLoginRegisters)) {
            _GoBackToMainMenu();
        }
        else {
            clsLoginRigesters::LoginRigester();
            _GoBackToMainMenu();
        }
    }
    static void _ShowCurrencyScreen() {
        system("cls");
        if (!CheckAccessRights(clsUser::pCurrency)) {
            _GoBackToMainMenu();
        }
        else {
            clCurrencyMainScreen::CurrencyScreen();
            _GoBackToMainMenu();
        }
    }
  static void _Logout() {
      CurrentUser = clsUser::Find("", "");
  }
    static int _MainMenu(eChoiceMainMenu Choice) {
        switch (Choice)
        {
        case clsMainScreen::eShowClientList:
            _ShowClientList();
                break;

        case clsMainScreen::eAddNewClient:
            _AddNewClient();
            break;

        case clsMainScreen::eDeleteClient:
            _DeleteClientScreen();
            break;

        case clsMainScreen::eUpdateClient:
            _UpdateClientScreen();
            break;

        case clsMainScreen::eFindClient:
            _FindClientScreen();
            break;

        case clsMainScreen::eTransactions:
            _ShowTransactionsScreen();
            break;

        case clsMainScreen::eManageUsers:
            _ShowManageScreen();
            break;
        case clsMainScreen::eLoginRigesters:
            _LoginRigesters();
            break;
        case clsMainScreen::eCurrency:
            _ShowCurrencyScreen();
            break;
        case clsMainScreen::eLogout:
            _Logout();
            return 0;
        }
    }
    static int _ReadChoice() {
        cout <<setw(37)<<left<<"" << "Choose What do You Want Between [1/10] ? ";
        int choice =clsInputValidate::ReadIntNumberBetween(1,10); 
        return choice;
  }

public:
	static void SHowMainMenu() {
            system("cls");
            _HeaderScreen("\t\tMain Menu");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Service.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _MainMenu(eChoiceMainMenu(_ReadChoice()));
	}



};

