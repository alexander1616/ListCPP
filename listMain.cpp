#include <iostream>
#include <cstdlib>
#include "a_list.h"

int main(int ac, char*av[]){
    a_list_t x;
    x.add(10);
    x.add(10);
    x.add(10);
    x.add(50);
    x.add(100);
    x.add(30);
    x.add(2);

    std::cout <<"x = "<< x << '\n';
    x.sort_ascending();
    std::cout <<"x = "<< x << '\n';
    x.sort_descending();
    std::cout <<"x = "<< x << '\n';
    return 0;
}