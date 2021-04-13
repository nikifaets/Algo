#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;

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

        while(insert_pos > 0 && v[insert_pos] < v[insert_pos-1]){

            std::swap(v[insert_pos], v[insert_pos-1]);
            insert_pos --;
        }
    }

    template<typename T>
    void insert_desc(std::vector<T>& v, T& val){

        v.push_back(val);

        int insert_pos = v.size()-1;
        //cout << "start pushing " << val << endl;
        while(insert_pos > 0 && v[insert_pos] > v[insert_pos-1]){

            std::swap(v[insert_pos], v[insert_pos-1]);
            insert_pos --;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<string> v_pos;
    std::vector<string> v_neg;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){

        string inp;
        inp.reserve(12);
        cin >> inp;
        //cout << "input is " << inp << endl;

        insertion_sort::insert(v_pos, inp);
    }

    //cout << "sorted " << endl;
    for(int i=0; i<v_neg.size(); i++){

        cout << v_neg[i] << endl;
    }

    for(int i=0; i<v_pos.size(); i++){

        cout << v_pos[i] << endl;
    }

    
    return 0;
}