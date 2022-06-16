/*
 *
 * Copyright (c) 2022 Melvin Jones Repol (mrepol742.github.io). All Rights Reserved.
 *
 * License under the GNU General Public License, version 3.0 (the "License");
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
#include <fstream>

using namespace std;

int cls = 1;
bool isDebug = false;
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
        cout << "\tEmail Address: ";
        cin >> email;
        if (email.find("@") != string::npos && email.find(".") != string::npos) {
            student[loc].emailAddress += email;
        } else {
            cout << "\tInvalid Email Address. Try Again.\n";
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
        cout << "\n\t\t       \033[1;31mNew Students\033[0m\n\tPlease Fill up the following required information.\n";
        cout << "\n\tName (Last Name, First Name, MI.): ";
        cin.ignore();
        getline(cin, student[loc].name);
        if (isDebug) {
            cout << ">> Entered name is " << student[loc].name;
        }
        cout << "\tYear Level: ";
        cin >> student[loc].yearLevel;
        if (isDebug) {
            cout << ">> Entered year level is " << student[loc].yearLevel;
        }
        cout << "\tCampus Location: ";
        cin.ignore();
        getline(cin, student[loc].campus);
        if (isDebug) {
            cout << ">> Entered campus is " << student[loc].campus;
        }
        cout << "\tProgram (BSIT, BEED, BSHM, BSP): ";
        getline(cin, student[loc].program);
        if (isDebug) {
            cout << ">> Entered program/course is " << student[loc].program;
        }
        cout << "\tCity: ";
        getline(cin, student[loc].city);
        if (isDebug) {
            cout << ">> Entered city is " << student[loc].city;
        }
        getEmailAddress(student, loc);
        cout << "\n\tStudent Name: " << student[loc].name;
        cout << "\n\tStudent ID: " << loc;
        cout << "\n\tSuccessfully enrolled to the program " << student[loc].program << "!";
        cout << "\n\tDo you want to \e[1m[1]\e[0m Add another student, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
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
         cout << "\n\t" << name << "\t" << yearLevel << "\t\t" << campus << "\t" << program << "\t" << city << "\t" << emailAddress;
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

    string getName() {
        return name;
    }

    string getProgram() {
        return program;
    }

    int getYearLevel() {
        return yearLevel;
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
        cout << "\n\n\t\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
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
            cout << "\n\n\t\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\e[1mCampus\e[0m\t\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
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
        cout << "\n\n\t\e[1mName\e[0m\t\t\t\e[1mYear Level\e[0m\t\t\e[1mCampus\e[0m\t\e[1mProgram\e[0m\t  \e[1mCity\e[0m\t\t\e[1mEmail Address\e[0m";
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

void showModules() {
    cout << "\n\n\t\t      \033[1;31mModules\033[0m";
    cout << "\n\n\t---------------------------------------------";
    int num;
    cout << "\n\n\tEnter Student Number: ";
    cin >> num;

    cout << "\n\n\t\033[1;31m" + student[num].getName() + "\033[0m - " << student[num].getProgram() << " Year " << student[num].getYearLevel();
    cout << "\n\n\tSubjects:\n";
    string program = student[num].getProgram();
    int yearLevel = student[num].getYearLevel();
    if (program == "BSIT" || program == "IT") {
        switch (yearLevel) {
            case 1:
            cout << "\n\t\tFirst Sem\n\t⊛ Computer Programming 1\n\t⊛ Introduction to Computing\n\t⊛ Social and Professional Issues in Computing\n\t⊛ Literacy/Civic Welfare/Military Science 1\n\t⊛ Physical Education 1\n\t⊛ The Contemporary World\n\t⊛ Understanding the Self\n\n\t\tSecond Sem\n\t⊛ Computer Programmign 2\n\t⊛ Data Structures and Algorithms\n\t⊛ Fundamentals of Database Systems\n\t⊛ Literacy/Civic Welfare/Military Science 2\n\t⊛ Physical Education 2\n\t⊛ Mathematics in the Modern World\n\t⊛ Purposive Communication\n\t⊛ Readings in Philippine History";
            break;
            case 2:
            cout << "\n\t\tFirst Sem\n\t⊛ Business Process Management\n\t⊛ Computer Programmign 3\n\t⊛ Applications Development and Emerging Technologies\n\t⊛ Discrete Mathematics for ITE\n\t⊛ Information Management\n\t⊛ Application of Statistics in IT\n\t⊛ Hardware, Software, and Peripherals\n\t⊛ Physical Education 3\n\n\t\tSecond Sem\n\t⊛ Data Analytics\n\t⊛ Human Computer Interaction\n\t⊛ Information Assurance and Security 1\n\t⊛ Integrative Programming and Technologies 1\n\t⊛ Networking 1\n\t⊛ Systems Analysis, Design and Prototyping\n\t⊛ Physical Education 4\n\t⊛ GE Eletive 1";
            break;
            case 3:
            cout << "\n\t\tFirst Sem\n\t⊛ Information Assurance and Security 2\n\t⊛ Networking 2\n\t⊛ Systems Integration and Architecture\n\t⊛ Professional Elective 1\n\t⊛ Methods of Research for IT/IS\n\t⊛ Multimedia Systems\n\t⊛ Ethics\n\t⊛ Life and Works of Rizal\n\n\t\tSecond Sem\n\t⊛ Networking 3\n\t⊛ Professional Eletive 2\n\t⊛ Numerical Analysis for ITE\n\t⊛ Capstone Project and Research 1\n\t⊛ Art Appreciation\n\t⊛ Science, Technology, and Society\n\t⊛ GE Elective 2\n\t⊛ Effective Communication with Personality Development";
            break;
            case 4:
            cout << "\n\t\tFist Sem\n\t⊛ Certification Course\n\t⊛ Systems Administration and Maintenance\n\t⊛ Professional Elective 3\n\t⊛ Professional Elective 4\n\t⊛ Capstone Project and Research 2\n\t⊛ Quantitative Methods (including Modeling and Simulation)\n\t⊛ GE Elective 3\n\n\t\tSecond Sem\n\t⊛ Practicum for IT/IS";
            break;

        }
    } else if (program == "BSHM" || program == "HM") {
        switch (yearLevel) {
            case 1:
            cout << "\n\t\tFirst Sem\n\t⊛ Kontekstwalisadong Komunikasyon sa Filipino\n\t⊛ The Contemporary World\n\t⊛ Purposive Communication\n\t⊛ Understanding the Self\n\t⊛ Kitchen Essentials & Basic Food Preparation\n\t⊛ CWTS/ROTC 1\n\t⊛ Self-Testing Activities\n\t⊛ Macro Perspective of Tourism and Hospitality\n\t⊛ Risk Management as Applied to Safety, Security and Sanitation\n\n\t\tSecond Sem\n\t⊛ Filipino sa ibat ibang Disiplina\n\t⊛ Ethics\n\t⊛ Mathematics in the Modern World\n\t⊛ Readings in Philippine History\n\t⊛ Fundamentals in Lodging Operations\n\t⊛ Business Communication\n\t⊛ CWTS/ROTC\n\t⊛ Rhythmic Activities\n\t⊛ Quality Service Management in Tourism and Hospitality";
            break;
            case 2:
            cout << "\n\t\tFist Sem\n\t⊛ Living in the IT Era\n\t⊛ Science Technology and Society\n\t⊛ Catering Management\n\t⊛ Applied Business Tools and Technologies\n\t⊛ Supply Chain Management in Hospitality Industry\n\t⊛ Foreign Language 1(Spanish 1)\n\t⊛ Games and Sports\n\t⊛ Rizals Life and Works\n\t⊛ Philippine Culture and Tourism Geography\n\n\t\tSecond Sem\n\t⊛ Art Appreciation\n\t⊛ Housekeeping Operations\n\t⊛ Fundamentals in Food Service Operators\n\t⊛ Introduction to MICE\n\t⊛ Foreign Language 2(Spanish 2)\n\t⊛ Recreational Activities\n\t⊛ Micro Perspective of Tourism and Hospitality";
            break;
            case 3:
            cout << "\n\t\tFirst Sem\n\t⊛ Operations Management in Tourism and Hospitality Industry Gender and Society\n\t⊛ Asian Cuisine\n\t⊛ Front Office Operation\n\t⊛ Professional Development and Applied Ethics\n\t⊛ Tourism and Hospitality Marketing\n\n\t\tSecond Sem\n\t⊛ Strategic Management in Tourism and Hospitality\n\t⊛ Total Quality Management\n\t⊛ Bar and Beverage Managament\n\t⊛ Ergonomics and Facilities Planning for the Hospitality Industry\n\t⊛ Entrepreneurship in Tourism and Hospitality\n\t⊛ Legal Aspects in Tourisn and Hospitality\n\t⊛ Multicultural Diversity in Workplace for the Tourism Professional";
            break;
            case 4:
            cout << "\n\t\tFirst Sem\n\t⊛ Recreation and Leisure Management\n\t⊛ Research in Hospitality\n\t⊛ Literatures in the Contemporary World\n\n\t\tSecond Sem\n\t⊛ Practicum - Hotel & Restaurant Practicum (600 Hours)";
            break;
        }
    } else if (program == "BEED" || program == "ED") {
        switch (yearLevel) {
            case 1:
            cout << "\n\t\tFirst Sem\n\t⊛ Understanding the Self\n\t⊛ Readings in Philippine History\n\t⊛ Purposive Communication\n\t⊛ The Contemporary World\n\t⊛ The Child and Adolescent Learners and Learning Principles\n\t⊛ The Teaching Profession\n\t⊛ Wika at Kultura sa Mapayapang Lipunan\n\t⊛ Exercise Prescription and Management\n\t⊛ National Service Training Program 1\n\n\t\tSecond Sem\n\t⊛ History of MINSUPALA\n\t⊛ The Teacher and Community, School Culture and Organizational Leadership\n\t⊛ Facilitating Learner-Centered Teaching\n\t⊛ Art Appreciation\n\t⊛ School-Community Linkages\n\t⊛ Life and Works of Rizal\n\t⊛ Good Manners and Right Conduct\n\t⊛ Dance/Martial Arts\n\t⊛ National Service Training Program 2";
            break;
            case 2:
            cout << "\n\t\tFirst Sem\n\t⊛ Ethics\n\t⊛ Mathematics in the Modern World\n\t⊛ Assessment in Learning 1\n\t⊛ The Teacher and School Curriculum\n\t⊛ Teaching Social Studies in the Elementary\n\t⊛ Ekokristisismo at Pagpapahalaga sa Kalikasan\n\t⊛ Individual/Dual Sports/Traditional/Recreational Games\n\n\t\tSecond Sem\n\t⊛ Teaching Science in the Elementary\n\t⊛ Inobasyon sa Wikang Filipino\n\t⊛ Assessment in Learning 2\n\t⊛ Teaching Beginning Reading\n\t⊛ Building and Enhancing New Literacies Across the Curriculum\n\t⊛ Teaching Math in Primary Grades\n\t⊛ Edukasyong Pantahanan at Pangkabuhayan\n\t⊛ Team Sports";
            break;
            case 3:
            cout << "\n\t\tFirst Sem\n\t⊛ Technology for Teaching and Elementary Grades\n\t⊛ Teaching Social Studies in the Elementary\n\t⊛ Pagtuturo and Filipino sa Elementarya\n\t⊛ Teaching PE and Health in the Elementary\n\t⊛ Teaching Math in the Intermediate\n\t⊛ Teaching English in the Elementary\n\t⊛ Content and pedagogy for the Mother-Tongue\n\t⊛ Teaching Multi-Grade\n\n\t\tSecond Sem\n\t⊛ Foundation of Inclusive and Special Education\n\t⊛ Teaching English in the Elementary Grades\n\t⊛ Edukasyon Pantahanan at Pangkabuhayan with Entrpreneurship\n\t⊛ Teaching Music in the Elementary\n\t⊛ Teaching Science in the Elementary\n\t⊛ Teaching Arts in the Elementary\n\t⊛ Research Methods";
            break;
            case 4:
            cout << "\n\t\tFirst Sem\n\t⊛ Observation of Teaching-Learning in Actual School Environment\n\t⊛ Participating and Teaching Assistantship\n\t⊛ Undergradute Thesis\n\n\t\tSecond Sem\n\t⊛ Teaching Internship";
            break;
        }
    } else if (program == "BSP" || program == "P") {
        switch (yearLevel) {
            case 1:
            cout << "\n\t\tFirst Sem\n\t⊛ Readings in Philippine History\n\t⊛ Art Appreciation\n\t⊛ Understanding the Self\n\t⊛ Introduction to Psychology\n\t⊛ Physical Fitness, Gymnastics and Aerobics\n\t⊛ Kontekswalisadong Komunikasyon sa Filipino\n\t⊛ Sosyedad at Literatura/Panitikang Panlipunan\n\t⊛ National Service Training Program 1\n\n\t\tSecond Sem\n\t⊛ Mathematics in the Modern World\n\t⊛ Purposive Communication\n\t⊛ Science, Technology and Society\n\t⊛ Development Psychology\n\t⊛ Filipino sa ibat ibang Disiplina\n\t⊛ National Service Training Program 2\n\t⊛ Rhythmic Activities";
            break;
            case 2:
            cout << "\n\t\tFirst Sem\n\t⊛ Ethics\n\t⊛ The Contemporary World\n\t⊛ Physiological/Biological Psyhology\n\t⊛ Cognitive Psychology\n\t⊛ Thoeries of Personality\n\t⊛ Fundamentals of Biology\n\t⊛ Retorika Masining na Pagpapahayag\n\t⊛ Individual and Dual Sports\n\n\t\tSecond Sem\n\t⊛ The Life and Works of Rizal\n\t⊛ Psychological Assessment\n\t⊛ Culture and Psychology\n\t⊛ Experimental Psychology\n\t⊛ Disaster and Mental Health\n\t⊛ ASEAN Literature\n\t⊛ Team Sports";
            break;
            case 3:
            cout << "\n\t\tFirst Sem\n\t⊛ Human Resource Management with Labor Relations\n\t⊛ Abnormal Psychology\n\t⊛ Social Psychology\n\t⊛ Industrial/Organizational Psychology\n\t⊛ Fundamentals of Chemistry\n\n\t\tSecond Sem\n\t⊛ Field Methods in Pyschology\n\t⊛ Clinical Psychology\n\t⊛ Research in Pyschology 1\n\t⊛ Biochemistry";
            break;
            case 4:
            cout << "\n\t\tFirst Sem\n\t⊛ Praticum in Psychology 200 hours\n\tI. Clinical Setting - 200 hours\n\tII. Industrial Setting - 200 hours\n\tIII. Educational Setting - 200 hours\n\n\t\tSecond Sem\n\t⊛ Research in Psychology 2\n\t⊛ General Zoology\n\t⊛ Group Dynamics\n\t⊛ Psychology Board Review Program";
            break;
        }
    }
    cout << "\n\n\t---------------------------------------------";
    cout << "\n\tDo you want to \e[1m[1]\e[0m View another student, \e[1m[2]\e[0m Main Menu or \e[1m[3]\e[0m Exit: ";
    string actions;
        cin >> actions;
        if (actions == "1" || actions == "u") {
            showModules();
        } else if (actions == "2" || actions == "m") {
             main();
        } else if (actions == "3" || actions == "e") {
            exit(0);
        } else {
            cout << "\tInvalid action. Try again.\n\n";
            showModules();
        }
}

int main() {
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\t   \033[1;31mLearning Module System (LMS)\033[0m";
   cout << "\n\tA simple program in managing students LMS accounts.";
   cout << "\n\n\t---------------------------------------------";
   cout << "\n\t| \e[1m[1]\e[0m Add New Students\t\e[1m[2]\e[0m List Students   |\n\t| \e[1m[3]\e[0m Update Students\t\e[1m[4]\e[0m Delete Students |\n\t| \e[1m[5]\e[0m Export Database   \e[1m[6]\e[0m Read Database   |\n\t| \e[1m[7]\e[0m Modules           \e[1m[8]\e[0m Exit            |";
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
   } else if (action == "7" || action == "m") {
       showModules();
   } else if (action == "8" || action == "x") {
       cout << "\033[2J\033[1;1H";
       exit(0);
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}