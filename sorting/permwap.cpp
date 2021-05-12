#include <bits/stdc++.h>
using namespace std;

long long merge(int l, int mid, int h,  vector<int>& v){

    long long inversions = 0;

    int it1 = l;
    int it2 = mid+1;

    vector<int> temp(h-l+1);
    int temp_it = 0;

    while(it1 <= mid && it2 <= h){

        temp[temp_it] = min(v[it1], v[it2]);

        if(v[it1] <= v[it2]) it1 ++;

        else{

            //cout << "else it1 " << it1 << " mid " << mid << endl;
            inversions += mid - it1 + 1;
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

    return inversions;
}

long long mergesort(int l, int h, vector<int>& v){

    long long inversions = 0;

    if(l < h){

        int mid = (h+l)/2;
        inversions += mergesort(l, mid, v);
        inversions += mergesort(mid+1, h, v);
        inversions += merge(l, mid, h, v);

    }

    return inversions;
    
}

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
        mergesort(0, v.size()-1, v);
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

    long long inversions = mergesort(0, n-1, v);


    cout << inversions << endl;
    return 0;
}