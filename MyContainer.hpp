#pragma once

template<typename T= int>
class Mycontainer {
private:
    T* data; // Pointer to the data
    size_t size; // Size of the number of elements in the container
    size_t capacity; // Capacity of the container

public:

// Constructor to initialize the container with a given capacity
    Mycontainer(size_t user_capacity=20){
        this->size=0;
        this->capacity=user_capacity; 
        this->data= new T[capacity]; // Allocate memory for the data
    }
    // Destructor to free the allocated memory
    ~MyContainer(){
        delete[] data; // Free the allocated memory
    }
    // func that add item  T for our container
    add(&T item ){
        if (size>= capacity){
           T* new_data = new T[capacity*2]; // Allocate new memory with double the capacity
           for (size_t i=0; i <size; i++){
            new_data[i] = data [i]; // Copy the old data to the new memory
           } 
           delte[] data ; // Free the old memory
           data = new_data; // change tyhe pointer to the newst memory
           capacity *=2;// capcaity increse
           size++; // size need to grow by one
        }
        else{
            data[size] = item; // add the item for out container 
            size++; // increase the size by one
        }
    }
    // func that give us the size of our container 
    // *please note that size isnt the same as capacity, size is only the num of elemts that we add to our container*
    size_t getsize() const {
        return size; 
    }
    



}