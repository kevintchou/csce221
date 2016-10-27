#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include "Record.h"
#include "TemplateDoublyLinkedList.h"

using namespace std;

void display(vector<DoublyLinkedList<Record>> & v) {
    for (int i=0; i<v.size(); ++i) {
        cout<<"List: "<<i<<"\n"<<v[i];
        cout<<endl<<endl;
    }
}

void insertRecord(vector<DoublyLinkedList<Record>>& v, Record r) {
    char c = '0';
    int index;
    stringstream ss;
    ss<<r.lastName;
    ss>>c; 
    index = c-65;
    if(index<0) {
        throw "Error: first letter must be capitalized";
    }
    v[index].insert(r); 
}

Record* search(vector<DoublyLinkedList<Record>>& v, Record r) {
    Record* result = new Record;
    char c = '0';
    int index;
    stringstream ss;
    ss<<r.lastName;
    ss>>c; 
    index = c-65;
    if(index<0) {
        throw "Error: first letter must be capitalized";
    }
    DoublyLinkedList<Record> List,List2; 

    DListNode<Record>* it = v[index].getFirst();
    int count = 0;

    while(it!=v[index].getAfterLast()) {
        if (it->getElem().lastName == r.lastName) {
            *result = it->getElem();
            List.insert(*result);
            ++count;
        }
        it = it->getNext();
    }
    if(count == 0)
        return NULL;
    else if(count == 1)
        return result;
    else {
        cout<<"Please enter their first name: ";
        cin>>r.firstName;
        count = 0;
    }

    it = List.getFirst();
    while(it!=List.getAfterLast()) {
        if (it->getElem().firstName == r.firstName) {
            *result = it->getElem();
            List2.insert(*result);
            ++count;
        }
        it = it->getNext();
    }
    if(count == 0)
        return NULL;
    else if(count == 1)
        return result;
    else { 
        cout<<"Please enter their UIN: ";
        cin>>r.UIN;
    } 

    it = List2.getFirst();
    while(it!=List2.getAfterLast()) {
        if (it->getElem().UIN == r.UIN) {
            *result = it->getElem();
            ++count;
        }
        it = it->getNext();
    }
    if(count == 0)
        return NULL;
    if(count == 1)
        return result;

    return result;
}

int main()
try
{

    Record r;
    vector<DoublyLinkedList<Record>> PhoneBook(26);
    ifstream in("PhoneBook.txt");
    if(!in.is_open())
        throw 1;

    while(!in.eof()) {
        in>>r;
        insertRecord(PhoneBook, r);
    }
    display(PhoneBook);

    string name;
    cout<<"Please enter a last name: ";
    cin>>name;
    Record input;
    input.lastName = name;
    Record* result = search(PhoneBook,input);
    if(result == NULL)
        cout<<"No match found\n";
    else
        cout<<"Match found: "<<*result;
    in.close();

    if(cin.fail())
        throw 2;
    return 0;

}

catch(int& e)
{
    if(e == 1)
        cout<<"Error";
    if(e == 2)
        cout<<"Error: UIN is incorrect\n";
    if(e!=1 || e!=2)
        cout<<"Error";
}
catch(string& s)
{
    cout<<s;
}

catch(...)
{

    cout<<"Error: first letter must be capitalized\n";
}