#include <iostream>
#include <string>
#include "AbstractCollection.h"

#define ABOUT "Created By:\n-----------\nAnirudh Ramnath \
(aramna2)\nSuriya Sundar Sampath (ssampa7)\n\n"

#define HELP "HELP:\n-----\nq – Quit the program\n\
h – Help\n\
a – About\n\
s <listNum> <type> - Set list number <listNum> to be of type <type>\n\
i <listNum> <val> - Insert value <val> into list numbered <listNum>\n\
r <listNum> - Remove a value from list numbered <listNum>\n\
g <listNum> - Get a value from list numbered <listNum>\n\
l <listNum> - List information about list numbered <listNum>\n\
f <filename> - Read commands from the file in <filename>\n\
# comment - Ignore the information contained on this line\n\
\n\
Any other input line will generate an error message\n\n"

using namespace std;

int main() {

    AbstractCollection* lists[8];

    cout<< "Enter operation or enter 'h' to view various commands being used for this program\n\n";
    string operation;

    getline(cin, operation);

    while(operation.compare("q") !=0) {
        if (operation.compare("h") == 0) {
            cout << HELP;
        }
        else if (operation.compare("a") == 0) {
            cout << ABOUT;
        }
        else {
            cout << "Invalid input";
        }

        cout << "Enter operation or enter 'h' to view various commands being used for this program\n\n";
        getline(cin, operation);
    }

    cout << "Quitting program";

    return 1;
}