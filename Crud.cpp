#include <iostream>

using namespace std;


class students {

  protected:
      char name[20];
      int yearLevel;
      char campus[20];
      char program[20];
      char city[20];
      char emailAddress[20];

  public:
      void setStudents() {
         cout << "\n\t*** NEW STUDENTS **";

      }

      void getStudents() {
         
      }
};

void create() {

}

void read() {

}

void update() {

}

void deleteA() {

}

int cls = 1;

int main() {
   if (cls) {
       cout << "\033[2J\033[1;1H";
   }
   cout << "\n\n\t\033[1;31mLearning Module System (LMS)\033[0m\n\tA simple program in managing\n\tstudents LMS accounts.";
   cout << "\n\n\t--------------------------------------------------";
   cout << "\n\t| [1] Add New Students\t[2] Display All Students |\n\t| [3] Update Students\t[4] Delete Students      |\n\t| [5] Exit                                       |";
   cout << "\n\t--------------------------------------------------";
   cout << "\n\n\tAction: ";
   int num;
   cin >> num;
   if (num == 1) {
       create();
   } else if (num == 2) {
       read();cout<<"\n\nEnter name :- ";
    cin>>name;
    cout<<"\nEnter code :- ";
    cin>>code;
   } else if (num == 3) {
       update();
   } else if (num == 4) {
       deleteA();
   } else if (num == 5) {
       return 0;
   } else {
      cout << "\n\tInvalid action. Try again.";
      cls = 0;
      main();
   }
   return 0;
}