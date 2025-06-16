
#include "MyContainer.hpp"
#include <ostream>
int main(){
Mycontainer<double>cont;// make cont and add value
cont.add(5);
cont.add(12);
cont.add (5.5);
cont.add(7.7);
std::cout<< std::endl<<"AscendingOrder: "<< std::endl;
for (auto it = cont.AscendingOrder_begin(); it != cont.AscendingOrder_end(); ++it) {
        std::cout << *it << ' ';   // 5, 5.5, 7.7 12
    }
std::cout<< std::endl<<"DescendingOrder: "<< std::endl;
for (auto it = cont.DescendingOrder_begin(); it != cont.DescendingOrder_end(); ++it) {
        std::cout << *it << ' ';   // 12 7.7 5.5 5
    }
std::cout<< std::endl<<"order: "<< std::endl;
for (auto it = cont.Order_begin(); it != cont.Order_end(); ++it) {
        std::cout << *it << ' ';   // 5 12 5.5 7.7
    }
    return 0;
}