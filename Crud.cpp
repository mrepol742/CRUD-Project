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
            student[loc].emailAddress == email;
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
        int op2;
        cin >> op2;
        if (op2 == 1) {
            return 1;
        } else if (op2 == 3) {
            exit(0);
        }
        return 0;
    }

    void read() {
         cout << "\n" << name << " " << yearLevel << " " << campus << " " << program << " " << city << " " << emailAddress;
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
};

Students student[230];

void readStudents() {
    cout << "\n\t\t      \033[1;31mRead Students\033[0m\n\tReads Students LMS accounts informations.";
    cout << "\n\n\t--------------------------------------------";
    cout << "\n\t| \e[1m[1]\e[0m All Students \t\e[1m[2]\e[0m Find a Student |\n\t| \e[1m[3]\e[0m Main Menu\t        \e[1m[4]\e[0m Exit           |";
    cout << "\n\t--------------------------------------------";
    cout << "\n\n\tAction: ";
    int num2;
    cin >> num2;
    if (num2 == 1) {
        cout << "\n\n\e[1mName\e[0m\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t  \e[1mEmail Address\e[0m";
        for (int i = 0; i < dataLoc; i++) {
             student[i].read();
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Main Menu or \e[1m[2]\e[0m Exit: ";
        int op;
        cin >> op;
        if (op == 1) {
            main();
        } 
        exit(0);
    } else if (num2 == 2) {
        cout << "\tEnter student number: ";
        int stun;
        cin >> stun;
        if (stun > dataLoc || stun < 0 || student[0].nonNull(student, stun) == 0) {
            cout << "\n\tStudent doesn't exists. Try again.";
        } else {
            cout << "\n\n\e[1mName\e[0m\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t  \e[1mEmail Address\e[0m";
            student[stun].read();
        }
        readStudents();
    } else if (num2 == 3) {
        main();
    } else if (num2 == 4) {
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
    cout << "\tEnter student number: ";
    int stun;
    cin >> stun;
    if (stun > dataLoc || stun < 0 || student[0].nonNull(student, stun) == 0) {
        cout << "\tStudent doesn't exists. Try again.\n\n";
        deleteStudents();
    } else {
        cout << "\n\n\e[1mName\e[0m\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t  \e[1mEmail Address\e[0m";
        student[stun].read();
        cout << "\n\tConfirmation for data deletion [Y/n]: ";
        char op;
        cin >> op;
        if (op == 'Y' || op == 'y') {
            for (int i = 0; i < dataLoc; i++) {
                if (i == stun) {
                    if (i < dataLoc) {
                        dataLoc--;
                        for (int j = i; j < dataLoc; j++) {
                            student[j] = student[j+1];
                        }
                    }
                }
            }
            cout << "\tSuccessfully deleted...";
        } else {
            cout << "\tDeletion aborted...";
        }
        cout << "\n\tDo you want to \e[1m[1]\e[0m Delete another data, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
        int op2;
        cin >> op2;
        if (op2 == 1) {
            deleteStudents();
        } else if (op2 == 2) {
            main();
        } else if (op2 == 3) {
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
        int op7;
        cin >> op7;
        if (op7 == 1) {
            updateStudents();
        } else if (op7 == 2) {
            main();
        } else if (op7 == 3) {
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
    cout << "\n\t\t\033[1;31mUpdate Students\033[0m\n\tUpdate Students LMS informations.";
    cout << "\n\n\t-----------------------------------";
    cout << "\n\t| \e[1m[1]\e[0m Name \t\e[1m[2]\e[0m Year Level    |\n\t| \e[1m[3]\e[0m Campus\t\e[1m[4]\e[0m Program       |\n\t| \e[1m[5]\e[0m City\t\e[1m[6]\e[0m Email Address |\n\t| \e[1m[7]\e[0m Main Menu\t\e[1m[8]\e[0m Exit          |";
    cout << "\n\t-----------------------------------";
    cout << "\n\n\tAction: ";
    int num2;
    cin >> num2;
    if (num2 == 7) {
        main();
    } else if (num2 == 8) {
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
    switch (num2) {
        case 1:
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
            int op2;
            cin >> op2;
            if (op2 == 1) {
                updateStudents();
            } else if (op2 == 2) {
                main();
            } else if (op2 == 3) {
                exit(0);
            } else {
                cout << "\tInvalid action. Try again.\n\n";
                updateStudents();
            }
        break;
        case 2:
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
            int op3;
            cin >> op3;
            if (op3 == 1) {
                updateStudents();
            } else if (op3 == 2) {
                main();
            } else if (op3 == 3) {
                exit(0);
            } else {
                cout << "\tInvalid action. Try again.\n\n";
                updateStudents();
            }
        break;
        case 3:
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
            int op4;
            cin >> op4;
            if (op4 == 1) {
                updateStudents();
            } else if (op4 == 2) {
                main();
            } else if (op4 == 3) {
                exit(0);
            } else {
                cout << "\tInvalid action. Try again.\n\n";
                updateStudents();
            }
        break;
        case 4:
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
            int op5;
            cin >> op5;
            if (op5 == 1) {
                updateStudents();
            } else if (op5 == 2) {
                main();
            } else if (op5 == 3) {
                exit(0);
            } else {
                cout << "\tInvalid action. Try again.\n\n";
                updateStudents();
            }
        break;
        case 5:
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
            int op6;
            cin >> op6;
            if (op6 == 1) {
                updateStudents();
            } else if (op6 == 2) {
                main();
            } else if (op6 == 3) {
                exit(0);
            } else {
                cout << "\tInvalid action. Try again.\n\n";
                updateStudents();
            }
        break;
        case 6:
            isValidEmaillAddressUpdate(snum);
        break;
    }
}

int main() {
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\t   \033[1;31mLearning Module System (LMS)\033[0m";
   cout << "\n\tA simple program in managing students LMS accounts.";
   cout << "\n\n\t---------------------------------------------";
   cout << "\n\t| \e[1m[1]\e[0m Add New Students\t\e[1m[2]\e[0m List Students   |\n\t| \e[1m[3]\e[0m Update Students\t\e[1m[4]\e[0m Delete Students |\n\t| \e[1m[5]\e[0m Exit                                  |";
   cout << "\n\t---------------------------------------------";
   cout << "\n\n\tAction: ";
   int num;
   cin >> num;
   cls = 0;
   if (num == 1) {
       addStudents();
   } else if (num == 2) {
       readStudents();
   } else if (num == 3) {
       updateStudents();
   } else if (num == 4) {
       deleteStudents();
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}