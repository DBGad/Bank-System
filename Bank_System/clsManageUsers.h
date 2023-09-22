#pragma once
#include "clsHeaderScreen.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateuserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsers : protected clsHeaderScreen 
{

    enum eChoiceManageUser{
        eShowUsersList = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eLogout = 6};

    static void _GotoManageUsersMenu() {
        cout << "\n\nPerss Any Key to GO Back to Manage Users Menu ";
        system("pause>0");
        ShowManageUsersScreen();
    }

    static void _ShowUsersList() {
        system("cls");
        clsUserListScreen::ShowUsersList();
        _GotoManageUsersMenu();
    }
    static void _AddNewUser() {
        system("cls");
        clsAddNewUserScreen::ShowAddNewUserScreen();
        _GotoManageUsersMenu(); 
    }
    static void _DeleteUser() {
        system("cls");
        clsDeleteUserScreen::ShowDeleteUserScreen();
        _GotoManageUsersMenu(); 
    }
    static void _UpdateUser() {
        system("cls");
        clsUpdateuserScreen::ShowUpdateUserScreen();
        _GotoManageUsersMenu();
    }
    static void _FindUser() {
        system("cls");
       clsFindUserScreen::ShowFindUserScreen();
        _GotoManageUsersMenu();
    }

    static void _ManageUsersMenu(eChoiceManageUser Choice) {
        switch (Choice)
        {
        case clsManageUsers::eShowUsersList:
            _ShowUsersList();
            break;
        case clsManageUsers::eAddNewUser:
            _AddNewUser();
            break;
        case clsManageUsers::eDeleteUser:
            _DeleteUser();
            break;
        case clsManageUsers::eUpdateUser:
            _UpdateUser();
            break;
        case clsManageUsers::eFindUser:
            _FindUser();
            break;
        case clsManageUsers::eLogout:
            break;
        }
    }

    static int _ReadChoice() {
        cout << setw(37) << left << "" << "Choose What do You Want Between [1/6] ? ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;
    }
public :
    static void ShowManageUsersScreen() {

        system("cls");
        _HeaderScreen("\t Manage Users Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";   
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _ManageUsersMenu(eChoiceManageUser(_ReadChoice()));
    }

};

