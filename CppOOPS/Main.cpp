#include <iostream>
#include <string>
#include <regex>
#include <fstream>
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

AbstractCollection* lists[8] = {NULL}; // Stores all lists

void process_input( std::istream  * stream){
    // Strings used for regex
    regex INIT_LIST ("[ ]*s[ ]+([1-8])[ ]+(u|o|q|s)[ ]*");
    regex INSERT_LIST ("[ ]*i[ ]+([1-8])[ ]+(\\d+)[ ]*");
    regex REMOVE_VAL ("[ ]*r[ ]+([1-8])[ ]*");
    regex LIST_INFO ("[ ]*l[ ]+([1-8])[ ]*");
    regex GET_VAL ("[ ]*g[ ]+([1-8])[ ]*");
    regex COMMENT ("[ ]*#.*");
    regex FILE_NAME ("[ ]*f[ ]+(\.+)[ ]*");
    Stack * temp_stack;
    Queue * temp_queue;
    OrderedList * temp_ol;
    UnorderedList * temp_ul;

    string operation;

    do {
        getline(*stream, operation);
        smatch match;  // Regex matcher object
        if(operation.compare("q") == 0){
            exit(0);
        }else if (operation.compare("h") == 0) {
            cout << HELP;
        }
        else if (operation.compare("a") == 0) {
            cout << ABOUT;
        }
        // Match COMMENT
        else if (regex_match(operation , match , COMMENT)) {
            // ignore comments
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
                cout << "List number "<<listNum+1<<" is empty!"<<endl;
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
                    try{
                        cout<<"Enter the index of the element to be removed: ";
                        getline(*stream, remove_index_str);
                        remove_index = stoi(remove_index_str);
                        stream->clear();
                        lists[list_index]->remove(remove_index -1);
                    }
                    catch(invalid_argument){
                        cout<<"Invalid arguments"<<endl;
                    }
                }
                else if(temp_ol = dynamic_cast<OrderedList*>(lists[list_index])){
                    try{
                        cout<<"Enter the index of the element to be removed: ";
                        getline(*stream, remove_index_str);
                        remove_index = stoi(remove_index_str);
                        stream->clear();
                        lists[list_index]->remove(remove_index -1);
                    }
                    catch(invalid_argument){
                            cout<<"Invalid arguments"<<endl;
                    }
                }
                }
                catch(IndexOutOfBound)
                {
                    cout<<"Index out of range"<<endl;
                }
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
                    try{
                        cout<<"Enter the index of the element to be returned: ";
                        getline(*stream, remove_index_str);
                        remove_index = stoi(remove_index_str);
                        stream->clear();
                        cout<<(lists[list_index]->get(remove_index - 1))<<endl;
                    }
                    catch(invalid_argument){
                        cout<<"Invalid arguments"<<endl;
                    }
                }
                else if(temp_ol = dynamic_cast<OrderedList*>(lists[list_index])){
                    try{
                        cout<<"Enter the index of the element to be returned: ";
                        getline(*stream, remove_index_str);
                        remove_index = stoi(remove_index_str);
                        stream->clear();
                        cout<<(lists[list_index]->get(remove_index - 1))<<endl;
                    }
                    catch(invalid_argument){
                        cout<<"Invalid arguments"<<endl;
                    }
                }
                }
                catch(IndexOutOfBound)
                {
                    cout<<"Index out of range";
                }
            }
        }
        else if (regex_match(operation , match , FILE_NAME)) {
            ifstream fs(match[1]);
            if(fs){
                process_input(&fs);
            }else{
                cout<<"Invalid file"<<endl;
            }
        }
        else {
            cout << "Invalid input"<<endl;
        }

    }while(!stream->eof());

}

int main() {
    while (1 == 1)
        process_input(&cin);

    return 1;
}

