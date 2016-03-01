#include <iostream>
#include <string>
#include <regex>
#include "AbstractCollection.h"
#include "OrderedList.h"
#include "UnorderedList.h"
#include "Stack.h"
#include "Queue.h"

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

    // Strings used for regex
    regex INIT_LIST ("s (\\d) (u|o|q|s)");
    regex INSERT_LIST ("i ([1-8]) (\\d)");
    regex REMOVE_VAL ("r ([1-8])");
    regex LIST_INFO ("l ([1-8])");
    regex GET_VAL ("g ([1-8])");

    AbstractCollection* lists[8];

    cout<< "Enter operation or enter 'h' to view various commands being used for this program\n\n";
    string operation;

    getline(cin, operation);

    while(operation.compare("q") !=0) {
        smatch match;  // Regex matcher object

        if (operation.compare("h") == 0) {
            cout << HELP;
        }
        else if (operation.compare("a") == 0) {
            cout << ABOUT;
        }
        // Match INIT_LIST
        else if (regex_match(operation , match , INIT_LIST)) {
            cout << "Matched INIT_LIST"<<endl;
            /*
            This is how you access the matches.
            match[0], match[1] ... etc
            */
        }
        // Match INSERT_LIST
        else if (regex_match(operation , match , INSERT_LIST)) {
            cout << "Matched INSERT_LIST"<<endl;
        }
        // Match REMOVE_VAL
        else if (regex_match(operation , match , REMOVE_VAL)) {
            cout << "Matched REMOVE_VAL"<<endl;
        }
        // Match LIST_INFO
        else if (regex_match(operation , match , LIST_INFO)) {
            cout << "Matched LIST_INFO"<<endl;
        }
        // Match GET_VAL
        else if (regex_match(operation , match , GET_VAL)) {
            cout << "Matched GET_VAL"<<endl;
        }
        else {
            cout << "Invalid input"<<endl;
        }

        cout << "Enter operation or enter 'h' to view various commands being used for this program\n\n";
        getline(cin, operation);
    }

    cout << "Quitting program"<<endl;

    return 1;
}