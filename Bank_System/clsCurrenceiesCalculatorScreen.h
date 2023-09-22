#pragma once
#include "clsHeaderScreen.h"
class clsCurrenceiesCalculatorScreen : protected clsHeaderScreen
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

	static void _convertAmount(float Amount ,clsCurrency from ,clsCurrency to ) {
		float To = to.GetRate(), From = from.GetRate();
		cout << " Calc = " << (Amount / From) * To << endl;

	}



public:
	static void CalcCurrecny() {
		_HeaderScreen("Currenceies Calculator Screen");
		clsCurrency c1 = clsCurrency::FindBycode(clsString::LowerAllString(clsInputValidate::ReadString("\nEnter Country Code To Convert From it : ")));
		while (c1.IsEmpty())
		{
			cout << "Country Not Found," << endl;
		clsCurrency c1 = clsCurrency::FindBycode(clsString::LowerAllString(clsInputValidate::ReadString("Pls Enter Country Code To Convert From it : ")));

		}
		_PrintCurrency(c1);
		clsCurrency c2 = clsCurrency::FindBycode(clsString::LowerAllString(clsInputValidate::ReadString("\nEnter Country Code To Convert to it : ")));
		while (c2.IsEmpty())
		{
			cout << "Country Not Found," << endl;
			clsCurrency c2 = clsCurrency::FindBycode(clsString::LowerAllString(clsInputValidate::ReadString("Pls Enter Country Code To Convert to it : ")));

		}
		_PrintCurrency(c2);
		
		float Amount = (float)clsInputValidate::ReadDblNumber("\nHow Much Do You Want to convert ? ");
		_convertAmount(Amount,c1,c2);



	}


};

