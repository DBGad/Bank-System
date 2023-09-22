#pragma once
#include "clsHeaderScreen.h"
class clsUpdateCurrencyScreen :protected clsHeaderScreen
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

	static void _UpdateRate(clsCurrency& C) {
		C.SetRate((float)(clsInputValidate::ReadDblNumber("\n\nEnter New Rate")));
		cout << "\nNew Rate is  :" << C.GetRate();
	}

public:
	static void UpdateCurrency() {
		_HeaderScreen("\tUpdate Currency Screen");
		clsCurrency c = clsCurrency::FindByName(clsString::LowerAllString(clsInputValidate::ReadString("\nEnter Country Name To Update : ")));
		
			if (!c.IsEmpty()){
				_PrintCurrency(c);
				_UpdateRate(c);

				if (toupper(clsInputValidate::Readchar("\n\nDo You Want Update ?[ Y / N ]")) == 'Y') {
					clsCurrency::eSaveResult R;
					R = c.Save();
					cout << "\nRate Updated ^^";
					_PrintCurrency(c);
				}
		}
			else
			{
				cout << "\nCountry Name Not Found ^^";
			}

	}




};

