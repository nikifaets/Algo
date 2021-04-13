#include <vector>
#include <iostream>

namespace insertion_sort{

    template<typename T>
    void sort(std::vector<T>& v){

        if(v.size() < 2) return;

        int key = 1;

        for(int i=key; i<v.size(); i++){
                        
            int pos = i;

            while(v[pos] < v[pos-1] && pos > 0){
                
                std::swap(v[pos], v[pos-1]);
                pos --;
            }            
        }
    }

    template<typename T>
    void insert(std::vector<T>& v, T& val){

        v.push_back(val);

        int insert_pos = v.size()-1;

        while(v[insert_pos] < v[insert_pos-1] && insert_pos > 0){

            std::swap(v[insert_pos], v[insert_pos-1]);
            insert_pos --;
        }
    }
}

namespace merge_sort{

}

namespace quicksort{


}