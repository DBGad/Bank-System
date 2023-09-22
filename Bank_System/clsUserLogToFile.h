#pragma once
#include "global.h"
#include "clsMainScreen.h"
#include "clsUtil.h"
#define FileLoginPath "LogFile.txt"
class clsUserLogToFile
{
private:
    string _Date;
    string _Username;
    string _Password;
    int _Perm;

    static void _AddNewlinetoFileLog(string line) {
        fstream MyFile;
        MyFile.open(FileLoginPath, ios::out | ios::app);
        if (MyFile.is_open()) {
            MyFile << line << endl;

            MyFile.close();
        }
    }
    static string _ConverUserObjectToLinelog(clsUser User, string Seperator = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText (User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);
        return UserRecord;
    }
    static clsUserLogToFile  _convertLinetoObjectLog(string line, string Seperator = "#//#") {
        vector <string> vclientdata;
        vclientdata = clsString::Split(line, Seperator);
        return clsUserLogToFile(vclientdata[0], vclientdata[1], clsUtil::DecryptText(vclientdata[2]), stoi(vclientdata[3]));
    }
  

    static  vector <clsUserLogToFile> _LoadFromLogFile(string Filepath) {
        fstream Myfile;
        vector <clsUserLogToFile> vUsers;
        Myfile.open(Filepath, ios::in);
        if (Myfile.is_open()) {
            string line;
            while (getline(Myfile, line))
            {
                vUsers.push_back(_convertLinetoObjectLog(line));
            }

            Myfile.close();
        }
        return vUsers;
    }
public:
    clsUserLogToFile(string Time,string User, string Pas,int p){
        _Date = Time;
         _Username = User;
        _Password = Pas;
        _Perm = p;
    }
    string GetDate() {
        return _Date;
    }
    string GetUsername() {
        return _Username;
    }
    string GetPassword() {
        return _Password;
    }
    int GetPerm() {
        return _Perm;
    }


    static void SaveTologinFile(clsUser userlog) {
        string Line = "";
       
        Line += clsDate::GetSystemDateTimeString()+"#//#"+_ConverUserObjectToLinelog(userlog);
        _AddNewlinetoFileLog(Line);
   }
  static  vector <clsUserLogToFile> GetInfoFromFile() {
        return _LoadFromLogFile(FileLoginPath);
    }
};

