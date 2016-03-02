#include <iostream>
#include <string>
#include <regex>
#include <typeinfo>
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
    regex INIT_LIST ("s ([1-8]) (u|o|q|s)");
    regex INSERT_LIST ("i ([1-8]) (\\d+)");
    regex REMOVE_VAL ("r ([1-8])");
    regex LIST_INFO ("l ([1-8])");
    regex GET_VAL ("g ([1-8])");

    AbstractCollection* lists[8] = {NULL}; // Stores all lists

    Stack * temp_stack;
    Queue * temp_queue;
    OrderedList * temp_ol;
    UnorderedList * temp_ul;

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
            string datatype = match[2];
            int listNum = stoi(match[1]) - 1;
            if (datatype.compare("s") == 0)
                lists[listNum] = new Stack();
            else if (datatype.compare("q") == 0)
                lists[listNum] = new Queue();
            else if (datatype.compare("o") == 0)
                lists[listNum] = new OrderedList();
            else if (datatype.compare("u") == 0)
                lists[listNum] = new UnorderedList();
        }
        // Match INSERT_LIST
        else if (regex_match(operation , match , INSERT_LIST)) {
            int valueToInsert = stoi(match[2]);
            int listNum = stoi(match[1]) - 1;

            if (NULL == lists[listNum]) {
                cout << "List number "<<listNum<<" is empty!"<<endl;
            }
            else {
                lists[listNum]->insert(valueToInsert);
            }
        }
        // Match REMOVE_VAL
        else if (regex_match(operation , match , REMOVE_VAL)) {
            int list_index = stoi(match[1]) - 1;
            int remove_index;
            if (NULL == lists[list_index]) {
                cout << "List number "<<list_index+1<<" is empty!"<<endl;
            }else {
                string remove_index_str;
                try{
                    Stack * temp_stack;
                    Queue * temp_queue;
                    OrderedList * temp_ol;
                    UnorderedList * temp_ul;
                if(temp_queue = dynamic_cast<Queue*>(lists[list_index])){
                    lists[list_index]->remove();
                }
                else if(temp_stack = dynamic_cast<Stack*>(lists[list_index])){
                    lists[list_index]->remove();
                }
                else if(temp_ul = dynamic_cast<UnorderedList*>(lists[list_index])){
                    cout<<"Enter the index of the element to be removed:";
                    getline(cin, remove_index_str);
                    remove_index = stoi(remove_index_str);
                    cin.clear();
                    lists[list_index]->remove(remove_index -1);
                }
                else if(temp_ol = dynamic_cast<OrderedList*>(lists[list_index])){
                    cout<<"Enter the index of the element to be removed:";
                    getline(cin, remove_index_str);
                    remove_index = stoi(remove_index_str);
                    cin.clear();
                    lists[list_index]->remove(remove_index -1);
                }
                }
                catch(IndexOutOfBound)
                {
                    cout<<"Index out of range";
                }
                cout << "Matched REMOVE_VAL"<<endl;
            }
        }
        // Match LIST_INFO
        else if (regex_match(operation , match , LIST_INFO)) {
            int listNum = stoi(match[1]) - 1;

            if (NULL == lists[listNum]) {
                cout << "List number "<<listNum+1<<" is empty!"<<endl;
            }
            else {
                cout << lists[listNum]->toString()<<endl;
            }
        }
        // Match GET_VAL
        else if (regex_match(operation , match , GET_VAL)) {
            cout << "Matched GET_VAL"<<endl;
            int list_index = stoi(match[1]) - 1;
            int remove_index;

            if (NULL == lists[list_index]) {
                cout << "List number "<<list_index+1<<" is empty!"<<endl;
            }
            else {
                string remove_index_str;
                try{
                    Stack * temp_stack;
                    Queue * temp_queue;
                    OrderedList * temp_ol;
                    UnorderedList * temp_ul;
                if(temp_queue = dynamic_cast<Queue*>(lists[list_index])){
                    cout<<lists[list_index]->get()<<endl;
                }
                else if(temp_stack = dynamic_cast<Stack*>(lists[list_index])){
                    cout<<lists[list_index]->get()<<endl;
                }
                else if(temp_ul = dynamic_cast<UnorderedList*>(lists[list_index])){
                    cout<<"Enter the index of the element to be returned:";
                    getline(cin, remove_index_str);
                    remove_index = stoi(remove_index_str);
                    cin.clear();
                    cout<<(lists[list_index]->get(remove_index - 1))<<endl;
                }
                else if(temp_ol = dynamic_cast<OrderedList*>(lists[list_index])){
                    cout<<"Enter the index of the element to be returned:";
                    getline(cin, remove_index_str);
                    remove_index = stoi(remove_index_str);
                    cin.clear();
                    cout<< "Remove index is "<<remove_index-1 << endl;
                    cout<<(lists[list_index]->get(remove_index - 1))<<endl;
                }
                }
                catch(IndexOutOfBound)
                {
                    cout<<"Index out of range";
                }
            }
        }
        else {
            cout << "Invalid input"<<endl;
            cout << "input was : "<<operation<<endl;
        }

        cout << "Enter operation or enter 'h' to view various commands being used for this program\n\n";
        
        getline(cin, operation);
    }

    cout << "Quitting program"<<endl;

    return 1;
}