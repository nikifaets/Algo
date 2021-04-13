#include <iostream>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::tuple;
using std::pair;

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

typedef pair<tuple<int, int, int>, int> date_with_id;

int main(){

    int n;
    cin >> n;

    std::vector<date_with_id> dates;

    for(int i=0; i<n; i++){

        int day, month, year;
        scanf("%d.%d.%4d", &day, &month, &year);
        //printf("%i/%i/%i %i \n", day, month, year, i+1);
        date_with_id date {{year, month, day}, i+1};
        insertion_sort::insert(dates, date);
    }


    //cout << "-----------------" << endl;
    for(int i=0; i<dates.size(); i++){

        //printf("%i/%i/%i ", std::get<2>(dates[i].first), std::get<1>(dates[i].first), std::get<0>(dates[i].first));
        cout << dates[i].second << endl;

    }

    return 0;

}