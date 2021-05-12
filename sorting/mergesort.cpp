#include <bits/stdc++.h>
#include "sort.cpp"
using namespace std;



void generate_array(vector<int>& v){
    
    for(int i=0; i<v.size(); i++){

        v[i] = rand() % 1000000;
        
    }

}

bool is_array_sorted(vector<int>& v){

    for(int i=0; i<v.size()-1; i++){

        if(v[i] > v[i+1]) return false;
    }

    return true;
}

void test(){

    const int NUM_TESTS = 200;
    const int MAX_SIZE = 100000;

    for(int i=0; i<NUM_TESTS; i++){


        int vec_size = rand() % MAX_SIZE;
        vector<int> v(vec_size);

        generate_array(v);
        merge_sort::sort(0, v.size()-1, v);
        if(!is_array_sorted(v)){

            cout << "FAILED: \n";

            for(const int& i : v){

                cout << i << " ";
            }

            cout << endl;
        }

        else{

            //cout << "PASSSED \n";
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(nullptr));

    //test();
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){

        cin >> v[i];
    }

    merge_sort::sort(0, n-1, v);


    for(const int& i : v){

        cout << i << " ";
    }

    return 0;
}