#pragma once
#include "clsHeaderScreen.h"
#include "clsDepsiteScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalance.h"
#include "clsTransferScreen.h"
#include "clsTranferLogScreen.h"

class clsTransactionsScreen : protected clsHeaderScreen
{
    enum eChoiceTransaction {eDeposite = 1 , eWithdraw = 2 , eTotalBalance = 3 , eTransfer = 4,eTransferlog = 5,elogout = 6 };

    
    static void _GoBackToTransactionMenu() {
        cout << "\n\nPerss Any Key to GO Back to Transaction Menu ";
        system("pause>0");
        ShowTransactionsScreen();
    }

    static void _DepsiteClientScreen() {
        system("cls");
        clsDepsiteScreen::DepsiteScreen();
        _GoBackToTransactionMenu();
    }

    static void _WithdrawClientScreen() {
        system("cls");
        clsWithdrawScreen::WithdrawScreen();
        _GoBackToTransactionMenu();
    }

    static void _TotalBalanceScreen() {
        system("cls");
        clsTotalBalance::ShowTotalBalances();
        _GoBackToTransactionMenu();
    }
    static void _TransferScreen() {
        system("cls");
        clsTransferScreen::Transfer();
        _GoBackToTransactionMenu();
    }

    static void _TransferlogScreen() {
        system("cls");
        clsTransferScreen::Transfer();
        _GoBackToTransactionMenu();
    }
    static void _Transferlog() {
        system("cls");
        clsTranferLogScreen::TransLogScreen();
       _GoBackToTransactionMenu();
    }

    static void _TransactionMenu(eChoiceTransaction Choice) {
        switch (Choice)
        {
        case clsTransactionsScreen::eDeposite:
            _DepsiteClientScreen();
            break;
        case clsTransactionsScreen::eWithdraw:
            _WithdrawClientScreen();
            break;
        case clsTransactionsScreen::eTotalBalance:
            _TotalBalanceScreen();
            break;
        case clsTransactionsScreen::eTransfer:
            _TransferScreen();
            break;
        case clsTransactionsScreen::eTransferlog:
            _Transferlog();
            break;
        case clsTransactionsScreen::elogout:
            break;
        }
     }




    static int _ReadChoice() {
        cout << setw(37) << left << "" << "Choose What do You Want Between [1/6] ? ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;
    }



public:

    static void ShowTransactionsScreen() {
     
            system("cls");
            _HeaderScreen("\t   Transaction Menu");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\tTransaction Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Depsite.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
            cout << setw(37) << left << "" << "\t[4] Tranfer.\n";
            cout << setw(37) << left << "" << "\t[5] Tranfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _TransactionMenu(eChoiceTransaction(_ReadChoice()));
    }

};

