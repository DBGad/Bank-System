#pragma once
#include "global.h"
#include "clsMainScreen.h"
#include "clsUserLogToFile.h"

class clsLoginWindow :protected clsHeaderScreen
{
private:
	static bool _Login(){
		bool LoginFaild = false;
        string Username, Password;
        int trail = 2;
        do
        {

                if (LoginFaild)
                {
                    cout << "\nInvlaid Username/Password!\n\n";
                    cout << "You Have " + to_string(trail) + " Trails to login\n";
                    if (trail == 0) {
                        cout << "\nYou Are Locked The System After 3 Trails " << endl;
                        return false;
                    }
                    trail--;
                }

                cout << "Enter Username? ";
                cin >> Username;

                cout << "Enter Password? ";
                cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);

                LoginFaild = CurrentUser.IsEmpty();



		} while (LoginFaild);
        clsUserLogToFile::SaveTologinFile(CurrentUser);
        clsMainScreen::SHowMainMenu();
	
	}

public:

	static bool LoginWindow() {
		system("cls");
		_HeaderScreen("\t\tLogin Screen");
       return _Login();

	}

};

