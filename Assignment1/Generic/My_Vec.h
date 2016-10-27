/*My_vec.h
 Your name
 Header file for a vector data structure.
 */

#include <ostream>

using namespace std;

template <typename T>class My_vec {
    
    //member variables
    int size, capacity;
    T *ptr;
    
public:
    //member functions
    My_vec():size(0), capacity(10), ptr(new T[capacity]){}
    
    ~My_vec(){delete ptr;};
    
    My_vec(const My_vec<T>& vec) {
        ptr = new T[vec.get_size()];
        size = vec.get_size();
        capacity = vec.get_capacity();
        for (int i = 0; i<size; i++) {
            ptr[i] = vec[i];
        }
    }

    My_vec& operator=(const My_vec<T>& vec) {
        size = vec.size;
        capacity = vec.capacity;
        ptr = new T[capacity];
        for (int i = 0; i<size; i++) {
            ptr[i] = *vec.ptr;
        }
        return *this;
    }
    
    int get_size() const {
        return size;
    }
    
    int get_capacity() const {
        return size;
    }
    
    T& operator[](int i) const{
         return ptr[i];
    }
    
    T& operator[](int i) {
         return ptr[i];
    }
    
    bool is_empty() const {
        return size == 0;
    }
    
    T& elem_at_rank(int r) const {
        if (r >= 0 && r<size) {
            return ptr[r];
        }
        throw "index out of bounds";
    }
    
    void insert_at_rank(int r, const T& elem) {
        if (r < 0 || r>size) {
            throw "index out of bounds";
        }
        if (size == capacity) {
            capacity*=2;
            T* temp = new T[capacity];
            for(int i =0; i<size; i++){
                temp[i] = ptr[i];
            }
            delete ptr;
            ptr = temp;
        }
        int j = size;
        while (j>r) {
            ptr[j] = ptr[j-1];
            j--;
        }
        ptr[r] = elem;
        size++;
    }
    
    void replace_at_rank(int r, const T& elem) {
        if (r <0 && r<size) {
            throw "index out of bounds";
        }
        ptr[r] = elem;
    }
    void remove_at_rank(int r) {
        if (r <0 && r>size) {
            throw "index out of bounds";
        }
        while(r+1<size){
            ptr[r]=ptr[r+1];
            r++;
        }
        size--;
    }
    
};
template <typename T>
ostream& operator<<(ostream& out, const My_vec<T>& vec) {
    out<<"[ ";
    for (int i = 0; i<vec.get_size(); i++) {
        out << vec[i]<< " ";
    }
    out << "]"<<endl;
    return out;
}
template <typename T>
int find_max_index(const My_vec<T>& v,int size) {
    int before = 0;
    int after = 1;
    for (int i = after; i<size; i++) {
        if (v[before] < v[i]) {
            before = i;
        }
        
    }
    return before;
}
template <typename T>
void sort_max(My_vec<T>& vec) {
    My_vec<T> temp;
    for (int i = vec.get_size(); i>0; i--) {
        int max = find_max_index(vec, i);
        temp.insert_at_rank(0, vec[max]);
        vec.remove_at_rank(max);
    }
    vec = temp;
}








