#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;

int sequence_min(const int*& arr, const int& len, const int& start, const int& end){

    assert(start + end < len);
    int min = arr[start];

    for(int i=start+1; i<=end; i++){

        if(arr[i] < min){

            min = arr[i];
        }
        
    }

    return min;

}

void print_deque(deque<int>& q){

    for(int i=0; i<q.size(); i++){

        cout << q.at(i) << " ";
    }
}
void add(deque<int>& q, vector<int>& v, int idx){
        
        while(q.size() > 0 && v[idx] < v[q.back()]) q.pop_back();
        //cout << "push " << v[idx] << endl;
        q.push_back(idx);

        //print_deque(q);
        //cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;

    cin >> n >> k;

    vector<int> v;

    for(int i=0; i<n; i++){

        int num;
        cin >> num;

        v.push_back(num);
    }

    deque<int> q;


    int min = v[0];
    int min_idx = 0;

    
    for(int i=0; i<k; i++){

        add(q, v, i);

    }

    min_idx = q.front();
    min = v[min_idx];

    //cout << "start min " << min << endl;
    //cout << "start min idx" << min_idx << endl;

    for(int i=k; i<v.size(); i++){

        //cout << "i " << i << endl;
        //cout << "q front before pop " << q.front() << endl;

        if(q.front() < i-k+1) q.pop_front();

        //cout << "q front after pop " << q.front() << endl;
        add(q, v, i);

        int curr_min_idx = q.front();
        int curr_min = v[curr_min_idx];

        //cout << "curr min " << v[q.front()] << endl;

        if(curr_min > min){

            min = curr_min;
             
        }
        
    }

    cout << min << endl;
    return 0;
}