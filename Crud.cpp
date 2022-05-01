#include <iostream>
#include <iterator>

using namespace std;

int cls = 1;
bool isDebug = true;

class Students {

    int studentNumber;
    string name;
    int yearLevel;
    string campus;
    string program;
    string city;
    string emailAddress;

    public:
    void create();
    void read();
    void update();
    void deleteA();
};

Students student[230];
int main();

    void Students::create() {
        cout << "\n\t\t   \033[1;31mNew Students\033[0m\n\tPlease Fill up the following required information.";
        cout << "\n\nName (Last Name, First Name, MI.): ";
        cin >> name;
        if (isDebug) {
            cout << ">> Entered name is " << name;
        }
        cout << "\nYear Level: ";
        cin >> yearLevel;
        if (isDebug) {
            cout << ">> Entered year level is " << yearLevel;
        }
        cout << "\nCampus: ";
        cin >> campus;
        if (isDebug) {
            cout << ">> Entered campus is " << campus;
        }
        cout << "\nProgram/Course: ";
        cin >> program;
        if (isDebug) {
            cout << ">> Entered program/course is " << program;
        }
        cout << "\nCity: ";
        cin >> city;
        if (isDebug) {
            cout << ">> Entered city is " << city;
        }
        cout << "\nEmail Address: ";
        cin >> emailAddress;
        if (isDebug) {
            cout << ">> Entered email address is " << emailAddress;
        }
        cout << "\nStudent successfully added.";
        cout << "\nDo you want to add new student or continue to the menu? [Y/n] ";
        char op;
        cin >> op;
        if (op == 'Y' || op == 'y') {
            student[sizeof(student)/sizeof(student[0])/230].create();
        } else {
            main();
        }
    }

    void Students::read() {
        cout << "\n" + name + "\t" << yearLevel << "\t\t" + campus + "\t" + program + "\t" + city + "\t" + emailAddress;
    }

    void Students::update() {

    }

    void Students::deleteA() {

    }


int main() {
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
   cls = 0;
   if (num == 1) {
       student[size()].create();
   } else if (num == 2) {
       cout << "\n\t\t   \033[1;31mDisplay Students\033[0m";
       cout << "\n\nName\tYear Level\tCampus\tProgram\t  City\t  Email Address";
       for (int i = 0; i < sizeof(student)/sizeof(student[0])/230; i++) {
           student[i].read();
       }
       cout << "\nDo you want to continue or exit? [Y/n] ";
        char op;
        cin >> op;
        if (op == 'Y' || op == 'y') {
            main();
        } 
        return 0;
   } else if (num == 3) {
       student[size()].update();
   } else if (num == 4) {
       student[size()].deleteA();
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}