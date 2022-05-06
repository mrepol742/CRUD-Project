#include <iostream>
#include <iterator>

using namespace std;

int cls = 1;
bool isDebug = true;
int dataLoc = 0;

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
};

Students student[230];

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
       int con = 1;
       while (con) {
          if (student[dataLoc].create(student, dataLoc) != 1) {
              main();
              con = 0;
          }
       }
   } else if (num == 2) {
       cout << "\n\t\t   \033[1;31mDisplay Students\033[0m";
       cout << "\n\nName\tYear Level\tCampus\tProgram\t  City\t  Email Address";
       for (int i = 0; i < dataLoc; i++) {
            student[i].read();
       }
       cout << "\nDo you want to continue? [Y/n] ";
       char op;
       cin >> op;
       if (op == 'Y' || op == 'y') {
           main();
       } 
       return 0;
   } else if (num == 3) {
       
   } else if (num == 4) {
      
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      main();
   }
   return 0;
}