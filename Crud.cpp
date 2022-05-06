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
#include <iterator>

using namespace std;

int cls = 1;
bool isDebug = true;
int dataLoc = 0;
int main();

class Students {

    int studentNumber;
    string name;
    int yearLevel;
    string campus;
    string program;
    string city;
    string emailAddress;

    public:
    int create(Students *student, int loc) {
        student[loc].studentNumber = loc;
        if (isDebug) {
            cout << ">> Student number is " << student[loc].studentNumber;
        }
        cout << "\n\t\t   \033[1;31mNew Students\033[0m\n\tPlease Fill up the following required information.";
        cout << "\n\nName (Last Name, First Name, MI.): ";
        cin >> student[loc].name;
        if (isDebug) {
            cout << ">> Entered name is " << student[loc].name;
        }
        cout << "\nYear Level: ";
        cin >> student[loc].yearLevel;
        if (isDebug) {
            cout << ">> Entered year level is " << student[loc].yearLevel;
        }
        cout << "\nCampus: ";
        cin >> student[loc].campus;
        if (isDebug) {
            cout << ">> Entered campus is " << student[loc].campus;
        }
        cout << "\nProgram/Course: ";
        cin >> student[loc].program;
        if (isDebug) {
            cout << ">> Entered program/course is " << student[loc].program;
        }
        cout << "\nCity: ";
        cin >> student[loc].city;
        if (isDebug) {
            cout << ">> Entered city is " << student[loc].city;
        }
        cout << "\nEmail Address: ";
        cin >> student[loc].emailAddress;
        if (isDebug) {
            cout << ">> Entered email address is " << student[loc].emailAddress;
        }
        cout << "\nStudent successfully added.";
        cout << "\nDo you want to add new student or continue to the menu? [Y/n] ";
        char op;
        cin >> op;
        dataLoc++;
        if (op == 'Y' || op == 'y') {
            return 1;
        }
        return 0;
    }
    void read() {
         cout << "\n" << studentNumber << ": " << name << " " << yearLevel << " " << campus << " " << program << " " << city << " " << emailAddress;
    }
    void update(Students *student, int loc);
    void deleteA(Students *student, int loc);
    int getStudentNumber() {
        return studentNumber;
    }
};

Students student[230];

void display() {
    cout << "\n\t\t   \033[1;31mDisplay Students\033[0m";
    cout << "\n\n\t----------------------------------------------------";
    cout << "\n\t| [1] Display All Students \t[2] Find a Student |\n\t| [3] Main Menu\t                [4] Exit           |";
    cout << "\n\t----------------------------------------------------";
    cout << "\n\n\tAction: ";
    int num2;
    cin >> num2;
    if (num2 == 1) {
       cout << "\n\nName\tYear Level\tCampus\tProgram\t  City\t  Email Address";
       for (int i = 0; i < dataLoc; i++) {
            student[i].read();
       }
       cout << "\n\tDo you want to [1] Main Menu [2] Exit: ";
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
       if (stun > dataLoc || stun < 0) {
           cout << "\n\tStudent doesn't exists. Try again.";
       } else {
           cout << "\n\nName\tYear Level\tCampus\tProgram\t  City\t  Email Address";
           student[stun].read();
       }
       display();
    } else if (num2 == 3) {
        main();
    } else if (num2 == 4) {
        exit(0);
    } else {
        cout << "\n\tInvalid action. Try again.";
        display();
    }
}

void add() {
    int con = 1;
    while (con) {
        if (student[dataLoc].create(student, dataLoc) != 1) {
            main();
            con = 0;
        }
    }
}

void deleteA() {
    cout << "\tEnter student number: ";
    int stun;
    cin >> stun;
    if (stun > dataLoc || stun < 0) {
        cout << "\n\tStudent doesn't exists. Try again.";
        deleteA();
    } else {
        cout << "\n\nName\tYear Level\tCampus\tProgram\t  City\t  Email Address";
        student[stun].read();
        cout << "\tConfirmation for data deletion [Y/n]: ";
        char op;
        cin >> op;
        if (op == 'Y' || op == 'y') {
            for (int i = 0; i < dataLoc; i++) {
                if (student[i].getStudentNumber() == stun) {
                    if (i < dataLoc) {
                        dataLoc--;
                        for (int j = i; j < dataLoc; j++) {
                            student[j] = student[j+1];
                        }
                    }
                } 
            }
            main();
        } else {
            cout << "\tdeletion aborted...\n\tDo you want to [1] Delete another data or [2] Main Menu [3] Exit: ";
            int op2;
            cin >> op2;
            if (op2 == 1) {
                deleteA();
            } else if (op2 == 2) {
                main();
            } else {
                exit(0);
            }
        }
    }
}

int main() {
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\t   \033[1;31mLearning Module System (LMS)\033[0m\n\tA simple program in managing students LMS accounts.";
   cout << "\n\n\t--------------------------------------------------";
   cout << "\n\t| [1] Add New Students\t[2] List Students        |\n\t| [3] Update Students\t[4] Delete Students      |\n\t| [5] Exit                                       |";
   cout << "\n\t--------------------------------------------------";
   cout << "\n\n\tAction: ";
   int num;
   cin >> num;
   cls = 0;
   if (num == 1) {
       add();
   } else if (num == 2) {
       display();
   } else if (num == 3) {
       
   } else if (num == 4) {
       deleteA();
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}