#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsBankUser.h"
#include "clsCurrency.h"
#include "global.h"
class clsHeaderScreen
{
protected : 


	static void _HeaderScreen(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        if (!CurrentUser.IsEmpty()) {
            cout << "\t\t\t\t\tUser = " << CurrentUser.GetUserName() <<endl;
        }
        cout << "\t\t\t\t\tDate = " << clsDate::DateToString(clsDate::GetSystemDate());
       
        cout << "\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions perm) {
        if (!CurrentUser.ISIHaveAPermisions(perm)) {
            cout << "\t\t\t\t\t_______________________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied,pls connect to Your Admin ";
            cout << "\n\t\t\t\t\t_______________________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

