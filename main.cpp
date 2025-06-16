
#include "MyContainer.hpp"
#include <ostream>
int main(){
Mycontainer<double>cont;// make cont and add value
cont.add(5);
cont.add(12);
cont.add (5.5);
cont.add(7.7);
    std::cout<< std::endl<<"AscendingOrder: "<< std::endl;// run AscendingOrder:
    for (auto it = cont.AscendingOrder_begin(); it != cont.AscendingOrder_end(); ++it) {
        std::cout << *it << ' ';   // 5, 5.5, 7.7 12
    }
    
    std::cout<< std::endl<<"DescendingOrder: "<< std::endl;// run DescendingOrder
    for (auto it = cont.DescendingOrder_begin(); it != cont.DescendingOrder_end(); ++it) {
        std::cout << *it << ' ';   // 12 7.7 5.5 5
    }
    std::cout<< std::endl<<"order: "<< std::endl;// run order
    for (auto it = cont.Order_begin(); it != cont.Order_end(); ++it) {
        std::cout << *it << ' ';   // 5 12 5.5 7.7
    }
    std::cout<< std::endl<<"reverse: "<< std::endl;// run reverse 
    for (auto it = cont.reverse_begin(); it != cont.reverse_end(); --it) {
        std::cout << *it << ' ';   // 7.7 5.5 12 5
    }
    std::cout<< std::endl<<"SideCrossOrder: "<< std::endl;// run SideCrossOrder
    for (auto it = cont.SideCrossOrder_begin(); it != cont.SideCrossOrder_end(); ++it) {
        std::cout << *it << ' ';  
    }

    return 0;
}