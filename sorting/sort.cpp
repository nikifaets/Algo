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


    namespace {
    template <typename T>
        void merge(int l, int mid, int h,  std::vector<T>& v){


            int it1 = l;
            int it2 = mid+1;

            std::vector<T> temp(h-l+1);
            int temp_it = 0;

            while(it1 <= mid && it2 <= h){

                temp[temp_it] = min(v[it1], v[it2]);

                if(v[it1] <= v[it2]) it1 ++;

                else{

                    it2++;
                }

                temp_it ++;

            }

            while(it1 <= mid){

                temp[temp_it++] = v[it1++];

            }

            while(it2 <= h){

                temp[temp_it++] = v[it2++];

            }

            for(int i=0; i<temp.size(); i++){

                v[l+i] = temp[i];
            }

        }
    }

    template <typename T>
    void sort(int l, int h, std::vector<T>& v){


        if(l < h){

            int mid = (h+l)/2;
            mergesort(l, mid, v);
            mergesort(mid+1, h, v);
            merge(l, mid, h, v);

        }

        
    }
}

namespace quicksort{


}