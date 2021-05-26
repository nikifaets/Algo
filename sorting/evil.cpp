#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;

    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for(int i=0; i<m; i++){

        int l, r;
        cin >> l >> r;
        q.push({l, r});
    }

    if(q.empty()){

        cout << 0 << endl;
        return 0;
    }

    pair<int, int> last = q.top();
    q.pop();

    int leftmost = last.first;
    int rightmost = last.second;

    int covered = rightmost - leftmost + 1;

    while(!q.empty()){

        pair<int, int> next = q.top();

        if(rightmost >= next.first && next.second > rightmost){
            
            covered += next.second - rightmost;
            rightmost = next.second;

        }


        else if(next.first > rightmost){

            
            leftmost = next.first;
            rightmost = next.second;
            covered += rightmost - leftmost + 1;
            
        }


        last = move(next);
        q.pop();


    }

    cout << covered << endl;
}