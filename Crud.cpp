#include <iostream>

using namespace std;

int cls = 1;
bool isDebug = true;

class Students {

    int student number;
    string name;
    int yearLevel;
    string campus;
    string program;
    string city;
    string emailAddress;

    public:
    void putData();
    void getData();
};

class LMS {

  public:
    void create() {
        Students students[230];
        cout << "\n\t\t   \033[1;31mNew Students\033[0m\n\tPlease Fill up the following required information.";
        cout << "\n\nName (Last Name, First Name, MI.): ";
        cin >> Students::name;
        if (isDebug) {
            cout << ">> Entered name is " << Students::name;
        }
        cout << "\nYear Level: ";
        cin >> Students::yearLevel;
        if (isDebug) {
            cout << ">> Entered year level is " << Students::yearLevel;
        }
        cout << "\nCampus: ";
        cin >> Students::campus;
        if (isDebug) {
            cout << ">> Entered campus is " << Students::campus;
        }
        cout << "\nProgram/Course: ";
        cin >> Students::program;
        if (isDebug) {
            cout << ">> Entered program/course is " << Students::program;
        }
        cout << "\nCity: ";
        cin >> Students::city;
        if (isDebug) {
            cout << ">> Entered city is " << Students::city;
        }
        cout << "\nEmail Address: ";
        cin >> Students::emailAddress;
        if (isDebug) {
            cout << ">> Entered email address is " << Students::emailAddress;
        }
    }

    void read() {

    }

    void update() {

    }

    void deleteA() {

    }
};

int main() {
   LMS lms;
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\t   \033[1;31mLearning Module System (LMS)\033[0m\n\tA simple program in managing students LMS accounts.";
   cout << "\n\n\t--------------------------------------------------";
   cout << "\n\t| [1] Add New Students\t[2] Display All Students |\n\t| [3] Update Students\t[4] Delete Students      |\n\t| [5] Exit                                       |";
   cout << "\n\t--------------------------------------------------";
   cout << "\n\n\tAction: ";
   int num;
   cin >> num;
   if (num == 1) {
       lms.create();
   } else if (
       num == 2) {
       lms.read();
   } else if (num == 3) {
       lms.update();
   } else if (num == 4) {
       lms.deleteA();
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      cls = 0;
      main();
   }
   return 0;
}