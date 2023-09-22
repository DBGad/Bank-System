#pragma once
#include <bits/stdc++.h>
#include "clsPerson.h"
#include "clsstring.h"
using namespace std;
#define FileClientPath "Clients.txt"

class clsBankClient : public clsPerson {

private:
    enum enMode { mempty = 0,mactive = 1,mAdd=2};
    enMode _mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _markedfordeleted = false;

    static clsBankClient _convertLinetoObject(string line, string sparetor = "#//#") {
        vector <string> vclientdata;
        vclientdata = clsString::Split(line, sparetor);
        return clsBankClient(enMode::mactive, vclientdata[0], vclientdata[1], vclientdata[2], vclientdata[3], vclientdata[4], vclientdata[5], stod(vclientdata[6]));
    }

    static string _convertObjecttoLine(clsBankClient client, string sparetor = "#//#") {
        string line = "";
        line += client.GetFirstName() + sparetor;
        line += client.GetLastName() + sparetor;
        line += client.GetEmail() + sparetor;
        line += client.GetPhone() + sparetor;
        line += client.AccountNumber() + sparetor;
        line += client.GetPinCode() + sparetor;
        line += to_string(client.GetAccountBalance());
        return line;
    }
    static  vector <clsBankClient> _LoadFromFile(string Filepath) {
        fstream Myfile;
        vector <clsBankClient> vclients;
        Myfile.open(Filepath, ios::in);
        if (Myfile.is_open()) {
            string line;
            while (getline(Myfile, line))
            {
                vclients.push_back(_convertLinetoObject(line));
            }

            Myfile.close();
        }
        return vclients;
    }
  static  void _SavetoFile(string Filepath, vector <clsBankClient>& vclients) {
        fstream MyFile;
        MyFile.open(Filepath, ios::out);
        if (MyFile.is_open()) {
            string line;
            for (clsBankClient & Dataline : vclients) {
                if (Dataline._markedfordeleted == false) {
                    line = _convertObjecttoLine(Dataline);
                    MyFile << line << endl;
                }
            }
            MyFile.close();
        }
    }
  void _AddNewlinetoFile(string line) {
      fstream MyFile;
      MyFile.open(FileClientPath, ios::out | ios::app);
      if (MyFile.is_open()) {
              MyFile << line << endl;

          MyFile.close();
      }
  }
  
    void  _Update() {
        vector <clsBankClient> vclients =_LoadFromFile(FileClientPath);
        for (clsBankClient& C : vclients)
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        _SavetoFile(FileClientPath, vclients);
    }
    void  _AddNew() {
        _AddNewlinetoFile(_convertObjecttoLine(*this));
   }
    static clsBankClient _GetAnEmpetyClient() {
        return clsBankClient(enMode::mempty, "", "", "", "", "", "", 0);
    }
    static clsBankClient _GetAnNewClient(string Acc) {
        return  clsBankClient(enMode::mAdd, "", "", "", "", Acc, "", 0);
    }
public:
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }
    bool IsEmpty()
    {
        return (_mode == enMode::mempty);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string Acc) {
        vector <clsBankClient> vclients = _LoadFromFile(FileClientPath);
        for (clsBankClient& C : vclients)
            if (C.AccountNumber() == Acc)
                return C;

        return _GetAnEmpetyClient();
    }
   static clsBankClient AddClient(string Acc) {
        return  _GetAnNewClient(Acc);
    }
   static double GetTotalBalances() {
       vector <clsBankClient> vclients = _LoadFromFile (FileClientPath);
       double TotalBalance = 0;
       for (clsBankClient& C : vclients)
       {
           TotalBalance += C.AccountBalance;

       }
       return TotalBalance;
  }
    enum enSaveResult {SvFiled = 0 , svsuccessd = 1 };

    enSaveResult Save() {
        switch (_mode)
        {
        case clsBankClient::mactive:
            _Update();
            return enSaveResult::svsuccessd; 

        case clsBankClient::mempty:
            return enSaveResult::SvFiled;
        case clsBankClient::mAdd:
            _AddNew();
            return enSaveResult::svsuccessd;

        }
    }
    bool Delete() {
        vector <clsBankClient>vclients= _LoadFromFile(FileClientPath);
        for (clsBankClient& C : vclients) {
            if (C.AccountNumber() == AccountNumber()) {
                C._markedfordeleted = true;
                break;
            }
        }
        _SavetoFile(FileClientPath, vclients);
        *this = _GetAnEmpetyClient();
        return true;
    }
    static vector <clsBankClient> GetClientsList() {
        return _LoadFromFile(FileClientPath);
  }
    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    
};

