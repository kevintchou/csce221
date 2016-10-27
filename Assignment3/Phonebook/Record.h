#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Record {
	public:
    string lastName;
    string firstName;
    int UIN;
    long phone;

    Record& operator =(const Record& r) {
        lastName = r.lastName;
        firstName = r.firstName;
        UIN = r.UIN;
        phone = r.phone;
	}

    bool operator <(const Record& r){
        if(lastName<r.lastName)
            return true;
        if(lastName == r.lastName && firstName<r.firstName)
            return true;
        if(lastName == r.lastName && firstName == r.firstName && UIN<r.UIN)
            return true;
        return false;
    }
};

ostream& operator <<(ostream& os, Record& r) {
    os<<r.lastName<<", "<<r.firstName<< endl << "UIN: "<<r.UIN<< endl <<"Phone: "<<r.phone<<endl;
    return os;
}

istream& operator >>(istream& is, Record& r) {
    string temp;
    getline(is,temp);
    r.lastName = temp;
    getline(is,temp);
    r.firstName = temp;
    getline(is,temp);
    r.UIN = atoi(temp.c_str());
    getline(is,temp);
    r.phone = atol(temp.c_str());
    is.ignore();
    return is;
}