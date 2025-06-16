#pragma once
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <iostream>

template<typename T= int>
class Mycontainer {
private:
    T* data; // Pointer to the data
    size_t size; // Size of the number of elements in the container
    size_t capacity; // Capacity of the container

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
};

 //   operator that print the container
    template<typename T>
    std::ostream& operator<<(std::ostream& os,const Mycontainer<T>& cont){
        cont.print(os); // the operator call to print 
        return os;
    }