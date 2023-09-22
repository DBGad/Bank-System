#pragma once
#include <bits/stdc++.h>
using namespace std;
#define FileCurrencyPath "Currencies.txt"
#include "clsPerson.h"
#include "clsString.h"

class clsCurrency {
private:
	string _Country;
	string _Code;
	string _CodeFix;
	string _NamePound;
	float _Rate;
	string	_CountryFix;



	static clsCurrency _ConvertLinetoclsCurrency(string line, string sp = "#//#") {
		vector <string> vData;
		vData = clsString::Split(line, sp);
		return clsCurrency(vData[0], vData[1], vData[2], stof(vData[3]));
	}

	string 	_ConvertclsCurrencytoLine(clsCurrency c, string sp = "#//#") {
		string line = "";
		line += c.GetName() + sp;
		line += c.GetCode() + sp;
		line += c.GetPoundName() + sp;
		line += to_string(c.GetRate());
		return line;
	}
	void _SaveToCurrencyFile(vector < clsCurrency > vData, string FilePath) {
		fstream MyFile;
		MyFile.open(FilePath, ios::out);
		if (MyFile.is_open()) {
			string line;
			for (clsCurrency& C : vData) {
				line = _ConvertclsCurrencytoLine(C);
				MyFile << line << endl;
			}
			MyFile.close();
		}
	}


	static vector <clsCurrency> _LoadFromCurrencyFile(string FilePath) {
		vector <clsCurrency> vCurrency;
		fstream MyFile;
		MyFile.open(FilePath, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line))
			{

				vCurrency.push_back(_ConvertLinetoclsCurrency(Line));


			}
			MyFile.close();
		}
		return vCurrency;
	}
	static clsCurrency _emptyCls() {
		return clsCurrency("", "", "", 0);
	}
	void _UpDate() {
		vector <clsCurrency> vData = clsCurrency::GetDataFromFileCurrency();
		for (clsCurrency& C : vData) {
			if (C.GetName() == GetName()) {
				C = *this;
				break;
			}
		}
		_SaveToCurrencyFile(vData, FileCurrencyPath);
	}
public:
	bool IsEmpty()
	{
		return (_Country == "");
	}

	clsCurrency(string country, string code, string namep, float rate) {
		_Country = country;
		_Code = code;
		_NamePound = namep;
		_Rate = rate;
		_CodeFix = clsString::LowerAllString(_Code);
		_CountryFix = clsString::LowerAllString(_Country);
	}
	static clsCurrency FindBycode(string code) {
		vector<clsCurrency> vData = clsCurrency::GetDataFromFileCurrency();
		for (clsCurrency& C : vData) {
			if (C._CodeFix == code) {
				return C;
			}
		}
		return _emptyCls();

	}
	static clsCurrency FindByName(string Name) {
		vector<clsCurrency> vData = clsCurrency::GetDataFromFileCurrency();
		for (clsCurrency& C : vData) {
			if (C._CountryFix == Name) {
				return C;
			}
		}
		return _emptyCls();

	}
	static vector <clsCurrency> GetDataFromFileCurrency() {
		return _LoadFromCurrencyFile(FileCurrencyPath);
	}

	enum eSaveResult { edone = 0 };
	eSaveResult Save() {
		_UpDate();
		return edone;
	}
	string GetName() {
		return _Country;
	}
	string GetCode() {
		return _Code;
	}
	string GetPoundName() {
		return _NamePound;
	}
	void SetRate(float rate) {
		_Rate = rate;
	}
	float GetRate() {
		return _Rate;
	}
};

