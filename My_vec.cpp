#include "My_vec.h"

using namespace std;

My_vec::My_vec() : size(0), capacity(10) { //default constructor
	ptr=(new char[capacity]);
}



My_vec::My_vec(const My_vec& vec) { //copy constructor
    ptr = new char[vec.get_size()];
    size = vec.get_size();
    capacity = vec.get_capacity();
    for (int i = 0; i<size; i++) {
        ptr[i] = vec[i];
    }
}

My_vec& My_vec::operator=(const My_vec& vec) {
    size = vec.size;
    capacity = vec.capacity;
    ptr = new char[capacity];
    for (int i = 0; i<size; i++) {
        ptr[i] = *vec.ptr;
    }
    return *this;
}

int My_vec::get_size() const { 
    return size;
}

int My_vec::get_capacity() const {
    return capacity;
}

char& My_vec::operator[] (int i) const {
    return ptr[i];
}

char& My_vec::operator[] (int i) {
    return ptr[i];
}

bool My_vec::is_empty() const {
    return size == 0;
}

char& My_vec::elem_at_rank(int r) const {
    if (r >= 0 && r<size) {
        return ptr[r];
    }
    throw "index out of bounds";
}

void My_vec::insert_at_rank(int r, const char& elem) {
    if (r < 0 && r>size) {
        throw "index out of bounds";
    }
    if (size == capacity) {
        capacity*=2;
        char* temp = new char[capacity];
        for(int i =0; i<size; i++){
            temp[i] = ptr[i];
        }
        delete ptr;
        ptr = temp;
    }
    int i = size;
    while (i>r) {
        ptr[i] = ptr[i-1];
        i--;
    }
    ptr[r] = elem;
    size++;
}

void My_vec::replace_at_rank(int r, const char& elem) {
    if (r <0 && r<size) {
        throw "index out of bounds";
    }
    ptr[r] = elem;
}

void My_vec::remove_at_rank(int r) {
    if (r <0 && r>size) {
        throw "index out of bounds";
    }
    while(r+1<size){
        ptr[r]=ptr[r+1];
        r++;
    }
    size--;
}

ostream& operator<<(ostream& out, const My_vec& vec) {
    out<<"[ ";
    for (int i = 0; i<vec.get_size(); i++) {
        out << vec[i]<< " ";
    }
    out << "]"<<endl;
    return out;
}

int find_max_index(const My_vec& v, int size) {
    int before = 0;
    int after = 1;
    for (int i = after; i<size; i++) {
        if (v[before] < v[i]) {
            before = i;
        }
            
    }
    return before;
}

void sort_max(My_vec& vec) {
    My_vec temp;
    for (int i = vec.get_size(); i>0; i--) {
        int max = find_max_index(vec, i);
        temp.insert_at_rank(0, vec[max]);
        vec.remove_at_rank(max);
    }
    vec = temp;
}















