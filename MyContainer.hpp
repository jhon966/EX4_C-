#pragma once
#include <ostream>
#include <stdexcept>
#include <iostream>

template<typename T= int>
class Mycontainer {
private:
    T* data; // Pointer to the data
    size_t size; // Size of the number of elements in the container
    size_t capacity; // Capacity of the container
    Mycontainer<T>* cont_sorthHtoL=nullptr; // container that already sort hige to low for the iterator
    Mycontainer<T>* cont_sortLtoH=nullptr; // container that already sort low to hige for the iterator
public:

    // Constructor to initialize the container with a given capacity
    Mycontainer(size_t user_capacity = 20) {
        this->size = 0;
        this->capacity = user_capacity;
        this->data = new T[capacity]; // Allocate memory for the data
    }
// Destructor to free the allocated memory
    ~Mycontainer() {
        delete[] data; // Free the allocated memory
        delete  cont_sorthHtoL;
        delete  cont_sortLtoH;
    }
    // copy constuctor 
Mycontainer(const Mycontainer<T>& other) {
        this->size = other.size; // copy the fields from other...
        this->capacity = other.capacity;
        this->data = new T[capacity]; // Allocate memory for the data
        for(size_t i =0; i<size ; i++ ){
            data[i]=other.data[i];
        }
    }

    //assignment operator 
    Mycontainer<T>& operator=(const Mycontainer<T>& other){
        if(this== &other){ // if this is the object
            return *this;
        }
        delete [] data;
        this->size = other.size; // copy the fields from other...
        this->capacity = other.capacity;
        this->data = new T[capacity]; // Allocate memory for the data
        for(size_t i =0; i<size ; i++ ){
            data[i]=other.data[i];
        }
        return *this;
    }

Mycontainer<T> sortHtoL(){
    Mycontainer<T> sorted(*this);// use deep copy
    T higest;
    for(size_t i=0; i<size; i++){
        higest=sorted.data[i];
        size_t r=i;// for moves value 
    for(size_t j=i+1; j<size; j++){// To find the higest value
        if(sorted.data[j]> higest){ 
        higest=sorted.data[j];
        r=j;
    }
}
sorted.data[r]= sorted.data[i];
    sorted.data[i]=higest;
}
return  sorted;
}

Mycontainer<T> sortLtoH(){
    Mycontainer<T> sorted(*this);// use deep copy
    T higest;
    for(size_t i=0; i<size; i++){
        higest=sorted.data[i];
        size_t r=i;// for moves value 
    for(size_t j=i+1; j<size; j++){// To find the higest value
        if(sorted.data[j]< higest){ 
        higest=sorted.data[j];
        r=j;
    }
}
sorted.data[r]= sorted.data[i];
    sorted.data[i]=higest;
}
return  sorted;
}
    
    // func that add item  T for our container
    void add(const T& item) {
        if (size >= capacity) {
            T* new_data = new T[capacity * 2]; // Allocate new memory with double the capacity
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i]; // Copy the old data to the new memory
            }
            delete[] data; // Free the old memory
            data = new_data; // change tyhe pointer to the newts memory
            data[size] = item;
            capacity *= 2;// capacity increase
            size++; // size need to grow by one
        }
        else {
            data[size] = item; // add the item for out container 
            size++; // increase the size by one
        }
    }

    // func that give us the size of our container 
    // *please note that size isnt the same as capacity, size is only the num of elemts that we add to our container*
    size_t getsize() const {
        return size;
    }
    // remove all t elemnts from the container 
    void remove(T item) {
        bool b = false;
        for (size_t i = 0; i < size; i++) { // run for all the arr to find if some elments need to be remove
            if (data[i] == item) {
                b = true;
                removeAndMove(i);// use the func for rempve and move all the elemnts to left 
                i--; // to cancel the i++ effect because we move all the elemnts to the left
            }
        }
        if (b == false) {
            throw std::runtime_error("this element is not found ");
        }
    }
    // use by remove, for evrey element we delete we need to move all the arr left.
    void removeAndMove(size_t j) {
        for (size_t i = j; i < this->size - 1; i++) // run the arr for move all the values to the left
        {
            data[i] = data[i + 1];
        }
        this->size--;// we need to reduce the size by one for every delete  
    }
    void print(std::ostream& os) const{ // print the container
        os<<"[ ";
        for(size_t i=0; i<this->size; i++){
            os<<data[i]<<" ";
    }
    os<< "]"<<std::endl; // Going down a row for more readability
    }
// return the begin of the iterator
T* AscendingOrder_begin(){ 
    if(cont_sorthHtoL==nullptr){
        //delete cont_sort;
     cont_sorthHtoL=new Mycontainer<T> (sortLtoH());// cont_sort is a pointer!
     }
    return cont_sorthHtoL->data; // return the beg
}

 // return the end of the iterator
T* AscendingOrder_end(){
    if(cont_sorthHtoL==nullptr){// need to free before
        //delete cont_sort;
     cont_sorthHtoL=new Mycontainer<T> (sortLtoH());// cont_sort is a pointer!
     }
    return cont_sorthHtoL->data + cont_sorthHtoL->size; // we add the size to reach the end
}
// return the begin of the iterator
T* DescendingOrder_begin(){ 
    if(cont_sortLtoH==nullptr){// need to free before
        //delete cont_sortLtoH;
     cont_sortLtoH=new Mycontainer<T> (sortHtoL());// cont_sort is a pointer!
     }
    return cont_sortLtoH->data; // return the beg
}

 // return the end of the iterator
T* DescendingOrder_end(){
    if(cont_sortLtoH==nullptr){// need to free before
        //delete cont_sortLtoH;
    
     cont_sortLtoH=new Mycontainer<T> (sortHtoL());// cont_sort is a pointer!
     }
    return cont_sortLtoH->data + cont_sortLtoH->size; // we add the size to reach the end
}
// return the begin of the iterator
T* Order_begin(){
    return data;
}

// return the end of the iterator
T* Order_end(){
    return (data+size);
}

T* reverse_begin(){
    return data+size-1;
}

// return the end of the iterator
T* reverse_end(){
    return (data-1);
}
};
 //   operator that print the container
    template<typename T>
    std::ostream& operator<<(std::ostream& os,const Mycontainer<T>& cont){
        cont.print(os); // the operator call to print 
        return os;
    }
