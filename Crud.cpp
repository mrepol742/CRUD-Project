/*
 *
 * Copyright (c) 2022 Melvin Jones Repol (mrepol742.github.io). All Rights Reserved.
 *
 * License under the Mrepol742 License, version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://github.com/mrepol742/CRUD-Project/blob/master/LICENSE
 *
 * Unless required by the applicable law or agreed in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int cls = 1;
bool isDebug = true;
int dataLoc = 0;

int main();
void updateStudents();

class Students {

    string name;
    int yearLevel = -3;
    string campus;
    string program;
    string city;
    string emailAddress;

    public:
    int nonNull(Students *student, int loc) {
        if (student[loc].yearLevel == -3) {
            return 0;
        }
        return 1;
    }

    void getEmailAddress(Students *student, int loc) {
        string email;
        cout << "\nEmail Address: ";
        cin >> email;
        if (email.find("@") != string::npos && email.find(".") != string::npos) {
            student[loc].emailAddress += email;
        } else {
            cout << "Invalid Email Address. Try Again.";
            getEmailAddress(student, loc);
        }
        if (isDebug) {
            cout << ">> Entered email address is " << student[loc].emailAddress;
        }
    }

    int create(Students *student, int loc) {
        if (isDebug) {
            cout << ">> Location " << loc;
        }
        cout << "\n\t\t   \033[1;31mNew Students\033[0m\n\tPlease Fill up the following required information.";
        cout << "\n\nName (Last Name, First Name, MI.): ";
        cin.ignore();
        getline(cin, student[loc].name);
        if (isDebug) {
            cout << ">> Entered name is " << student[loc].name;
        }
        cout << "\nYear Level: ";
        cin >> student[loc].yearLevel;
        if (isDebug) {
            cout << ">> Entered year level is " << student[loc].yearLevel;
        }
        cout << "\nCampus: ";
        cin.ignore();
        getline(cin, student[loc].campus);
        if (isDebug) {
            cout << ">> Entered campus is " << student[loc].campus;
        }
        cout << "\nProgram/Course: ";
        getline(cin, student[loc].program);
        if (isDebug) {
            cout << ">> Entered program/course is " << student[loc].program;
        }
        cout << "\nCity: ";
        getline(cin, student[loc].city);
        if (isDebug) {
            cout << ">> Entered city is " << student[loc].city;
        }
        getEmailAddress(student, loc);
        cout << "\nStudent successfully added.";
        cout << "\nDo you want to \e[1m[1]\e[0m Add another student, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        dataLoc++;
        string op2;
        cin >> op2;
        if (op2 == "1" || op2 == "a") {
            return 1;
        } else if (op2 == "3" || op2 == "e") {
            exit(0);
        }
        return 0;
    }

    void read() {
         cout << "\n" << name << "\t" << yearLevel << "\t\t" << campus << "\t" << program << "\t" << city << "\t" << emailAddress;
    }

    void update(Students *student, int loc, int type, string newName, int newYearLevel) {
        if (isDebug) {
            cout << ">> Location was at " << loc << " type: " << type << " params: " << newName << " && " << newYearLevel;
        }
        if (type == 1) {
            student[loc].name = newName;
        } else if (type == 2) {
            student[loc].yearLevel = newYearLevel;
        } else if (type == 3) {
            student[loc].campus = newName;
        } else if (type == 4) {
            student[loc].program = newName;
        } else if (type == 5) {
            student[loc].city = newName;
        } else if (type == 6) {
            student[loc].emailAddress = newName;
        }
    }

    string backup() {
         return "\n" + name +  "\t" + to_string(yearLevel) + "\t\t" + campus + "\t" + program + "\t" + city + "\t" + emailAddress;
    }
};

Students student[230];

void checkStudents() {
    if (dataLoc == 0) {
        cout << "\n\t>> There was no student yet on the database.";
        cout << "\n\tPress Enter to Continue";
        cin.ignore();
        cin.get();
        main();
    }
}

void readDatabase() {
    string str;
    ifstream MyReadFile("students.txt");
    while (getline (MyReadFile, str)) {
        cout << "\n" << str;
    }
    cout << "\n";
    MyReadFile.close();
    cout << "\n\tPress Enter to Continue";
    cin.ignore();
    cin.get();
    main();
}

void exportDatabase() {
    checkStudents();
    ofstream MyFile("students.txt");
    MyFile << "\t\tLearning Module System (LMS)\n\tA simple program in managing students LMS accounts.\nTotal students: "<< dataLoc << "\n\nName\t\t\tYear Level\t\tCampus\tProgram\t  City\t\tEmail Address";
    for (int i = 0; i < dataLoc; i++) {
        MyFile << student[i].backup();
    }
    MyFile.close();
    cout << "\tSuccessfully backup Students database to \e[student.txt\e[0m.\n";
    cout << "\tDo you want to \e[1m[1]\e[0m Read the file, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
    string op;
    cin >> op;
    if (op == "1" || op == "r") {
        readDatabase();
    } else if (op == "2" || op == "m") {
        main();
    } else if (op == "3" || op == "e") {
        exit(0);
    } else {
        cout << "\n\tInvalid action. Try again.";
        main();
    }
}

void readStudents() {
    checkStudents();
    cout << "\n\t\t      \033[1;31mRead Students\033[0m\n\tReads Students LMS accounts informations.";
    cout << "\n\n\t--------------------------------------------";
    cout << "\n\t| \e[1m[1]\e[0m All Students \t\e[1m[2]\e[0m Find a Student |\n\t| \e[1m[3]\e[0m Main Menu\t        \e[1m[4]\e[0m Exit           |";
    cout << "\n\t--------------------------------------------";
    cout << "\n\n\tAction: ";
    string num2;
    cin >> num2;
    if (num2 == "1" || num2 == "a") {
        cout << "\n\n\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
        int i;
        for (i = 0; i < dataLoc; i++) {
             student[i].read();
        }
        cout << "\n\tPress Enter to Continue";
        cin.ignore();
        cin.get();
        readStudents();
    } else if (num2 == "2" || num2 == "f") {
        cout << "\tEnter student number: ";
        int stun;
        cin >> stun;
        if (stun > dataLoc || stun < 0 || student[0].nonNull(student, stun) == 0) {
            cout << "\n\tStudent doesn't exists. Try again.";
        } else {
            cout << "\n\n\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
            student[stun].read();
        }
        cout << "\n\tPress Enter to Continue";
        cin.ignore();
        cin.get();
        readStudents();
    } else if (num2 == "3" || num2 == "m") {
        main();
    } else if (num2 == "4" || num2 == "e") {
        exit(0);
    } else {
        cout << "\n\tInvalid action. Try again.";
        readStudents();
    }
}

void addStudents() {
    int con = 1;
    while (con) {
        if (student[dataLoc].create(student, dataLoc) != 1) {
            main();
            con = 0;
        }
    }
}

void deleteStudents() {
    checkStudents();
    cout << "\tEnter student number: ";
    int stun;
    cin >> stun;
    if (stun > dataLoc || stun < 0 || student[0].nonNull(student, stun) == 0) {
        cout << "\t>> Student doesn't exists.";
        cout << "\n\t>> Do you want to \e[1m[1]\e[0m Try Again, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        string op;
        cin >> op;
        if (op == "1" || op == "t") {
            deleteStudents();
        } else if (op == "2" || op == "m") {
            main();
        } else if (op == "3" || op == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            main();
        }
    } else {
        cout << "\n\n\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
        student[stun].read();
        cout << "\n\tConfirmation for data deletion [Y/n]: ";
        char op;
        cin >> op;
        if (op == 'Y' || op == 'y') {
            int i;
            for (i = 0; i < dataLoc; i++) {
                if (i == stun && i < dataLoc) {
                    dataLoc--;
                    int j;
                    for (j = i; j < dataLoc; j++) {
                        student[j] = student[j+1];
                    }
                }
            }
            cout << "\tSuccessfully deleted...";
        } else {
            cout << "\tDeletion aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Delete another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        string op2;
        cin >> op2;
        if (op2 == "1" || op2 == "d") {
            deleteStudents();
        } else if (op2 == "2" || op2 == "m") {
            main();
        } else if (op2 == "3" || op2 == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            deleteStudents();
        }
    }
}

void isValidEmaillAddressUpdate(int snum) {
    string newName;
    char choices;
    cout << "\n\tEnter Email Address: ";
    cin >> newName;
    if (newName.find("@") != string::npos && newName.find(".") != string::npos) {
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 6, newName, 0);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        string op7;
        cin >> op7;
        if (op7 == "1" || op7 == "u") {
            updateStudents();
        } else if (op7 == "2" || op7 == "m") {
            main();
        } else if (op7 == "3" || op7 == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else {
        cout << "\tInvalid Email Address. Try Again.";
        isValidEmaillAddressUpdate(snum);
    }
}

void updateStudents() {
    checkStudents();
    cout << "\n\t\t\033[1;31mUpdate Students\033[0m\n\tUpdate Students LMS informations.";
    cout << "\n\n\t-----------------------------------";
    cout << "\n\t| \e[1m[1]\e[0m Name \t\e[1m[2]\e[0m Year Level    |\n\t| \e[1m[3]\e[0m Campus\t\e[1m[4]\e[0m Program       |\n\t| \e[1m[5]\e[0m City\t\e[1m[6]\e[0m Email Address |\n\t| \e[1m[7]\e[0m Main Menu\t\e[1m[8]\e[0m Exit          |";
    cout << "\n\t-----------------------------------";
    cout << "\n\n\tAction: ";
    string num2;
    cin >> num2;
    if (num2 == "7" || num2 == "m") {
        main();
    } else if (num2 == "8" || num2 == "x") {
        exit(0);
    }
    cout << "\tEnter student number: ";
    int snum;
    cin >> snum;
    if (snum > dataLoc || snum < 0 || student[0].nonNull(student, snum) == 0) {
        cout << "\tStudent doesn't exists. Try again.\n\n";
        updateStudents();
    }
    string newName;
    char choices;
    int newYearLevel;
    string actions;
    if (num2 == "1" || num2 == "n") {
        cout << "\n\tEnter Name: ";
        cin.ignore();
        getline(cin, newName);
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 1, newName, 0);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        cin >> actions;
        if (actions == "1" || actions == "u") {
            updateStudents();
        } else if (actions == "2" || actions == "m") {
            main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else if (num2 == "2" || num2 == "y") {
        cout << "\n\tEnter Year Level: ";
        cin >> newYearLevel;
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 2, "", newYearLevel);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        cin >> actions;
        if (actions == "1" || actions == "u") {
            updateStudents();
        } else if (actions == "2" || actions == "m") {
            main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else if (num2 == "3" || num2 == "c") {
        cout << "\n\tEnter Campus: ";
        cin.ignore();
        getline(cin, newName);
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 3, newName, 0);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        cin >> actions;
        if (actions == "1" || actions == "u") {
            updateStudents();
        } else if (actions == "2" || actions == "m") {
            main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else if (num2 == "4" || num2 == "p") {
        cout << "\n\tEnter Program/Course: ";
        cin.ignore();
        getline(cin, newName);
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 4, newName, 0);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        cin >> actions;
        if (actions == "1" || actions == "u") {
            updateStudents();
        } else if (actions == "2" || actions == "m") {
            main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else if (num2 == "5" || num2 == "i") {
        cout << "\n\tEnter City: ";
        cin.ignore();
        getline(cin, newName);
        cout << "\n\tConfirmation for data update [Y/n]: ";
        cin >> choices;
        if (choices == 'Y' || choices == 'y') {
            student[snum].update(student, snum, 5, newName, 0);
            cout << "\tSuccessfully updated...";
        } else {
            cout << "\tUpdate aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Update another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        cin >> actions;
        if (actions == "1" || actions == "u") {
            updateStudents();
        } else if (actions == "2" || actions == "m") {
             main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            updateStudents();
        }
    } else if (num2 == "6" || num2 == "e") {
        isValidEmaillAddressUpdate(snum);
    } else {
        cout << "\n\tInvalid action. Try again.";
        cout << "\n\tPress Enter to Continue";
        cin.ignore();
        cin.get();
        updateStudents();
        
    }
}

int main() {
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\t   \033[1;31mLearning Module System (LMS)\033[0m";
   cout << "\n\tA simple program in managing students LMS accounts.";
   cout << "\n\n\t---------------------------------------------";
   cout << "\n\t| \e[1m[1]\e[0m Add New Students\t\e[1m[2]\e[0m List Students   |\n\t| \e[1m[3]\e[0m Update Students\t\e[1m[4]\e[0m Delete Students |\n\t| \e[1m[5]\e[0m Export Database   \e[1m[6]\e[0m Read Database   |\n\t| \e[1m[7]\e[0m Exit                                  |";
   cout << "\n\t---------------------------------------------";
   if (dataLoc > 0) {
       cout << "\n\t\tThere's been " << dataLoc << " enrolled students.";
   }
   cout << "\n\n\tAction: ";
   string action;
   cin >> action;
   cls = 0;
   if (action == "1" || action == "a") {
       addStudents();
   } else if (action == "2" || action == "l") {
       readStudents();
   } else if (action == "3" || action == "u") {
       updateStudents();
   } else if (action == "4" || action == "d") {
       deleteStudents();
   } else if (action == "5" || action == "e") {
       exportDatabase();
   } else if (action == "6" || action == "r") {
       readDatabase();
   } else if (action == "7" || action == "x") {
       cout << "\033[2J\033[1;1H";
       exit(0);
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}