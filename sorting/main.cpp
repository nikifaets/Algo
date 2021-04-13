#include "sort.cpp"
#include <vector>
#include <iostream>

using namespace insertion_sort;

int main(){


    std::vector<int> v = {1,3,5,2,8, 1, 4, 7, 2, 4};
    insertion_sort::sort(v);


    insertion_sort::insert(v, -3);
    insertion_sort::insert(v, -5);
    insertion_sort::insert(v, 20);
    
    for(int i=0; i<v.size(); i++){

        std::cout << v[i] << std::endl;
    }
}