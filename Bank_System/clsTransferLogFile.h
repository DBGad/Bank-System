#pragma once
#include"clsHeaderScreen.h"
#define FileTLoginPath "TransferLog.txt"
class clsTransferLogFile
{
    string _date;
    string _Acc1;
    string _Acc2;
    string _amount;
    string _Balance1;
    string _Balance2;
    string _User;



    static void _AddNewlinetoFiletLog(string line) {
        fstream MyFile;
        MyFile.open(FileTLoginPath, ios::out | ios::app);
        if (MyFile.is_open()) {
            MyFile << line << endl;

            MyFile.close();
        }
    }
    static clsTransferLogFile  _convertLinetoTranseLog(string line, string Seperator = "#//#") {
        vector <string> vclientdata;
        vclientdata = clsString::Split(line, Seperator);
        return clsTransferLogFile(vclientdata[0], vclientdata[1], vclientdata[2], vclientdata[3],vclientdata[4], vclientdata[5], vclientdata[6]);
    }


    static  vector <clsTransferLogFile> _LoadFromTransFile(string Filepath) {
        fstream Myfile;
        vector <clsTransferLogFile> vUsers;
        Myfile.open(Filepath, ios::in);
        if (Myfile.is_open()) {
            string line;
            while (getline(Myfile, line))
            {
                vUsers.push_back(_convertLinetoTranseLog(line));
            }

            Myfile.close();
        }
        return vUsers;
    }

public:
    clsTransferLogFile(string date ,string Acc1 ,string Acc2 , string amount , string Balance1 ,string Balance2 ,string User) {
        _date = date;
        _Acc1 = Acc1;
        _Acc2 = Acc2;
        _amount = amount;
        _Balance1 = Balance1;
        _Balance2 = Balance2;
        _User = User;
    }
    static void SaveToTransFile(string acc1,string acc2,double Amount,double b1 , double b2 , string us) {
        string Line = "";

        Line += clsDate::GetSystemDateTimeString() + "#//#" + acc1 + "#//#" + acc2 + "#//#" + to_string(Amount) +"#//#"+
            to_string(b1) + "#//#"+to_string(b2) +"#//#"+ us;
        _AddNewlinetoFiletLog(Line);
    }
    static vector <clsTransferLogFile> GetfromTransFile() {
        return _LoadFromTransFile(FileTLoginPath);
    }


    string Getdate() {
        return _date;
    }
    string GetAcc1() {
        return _Acc1;
    }
    string GetAcc2() {
        return _Acc2;
    }
    string Getamount() {
        return _amount;
    }
    string GetBalance1() {
        return _Balance1;
    }
    string GetBalance2() {
        return _Balance2;
    }
    string GetUser() {
        return _User;
    }

};

