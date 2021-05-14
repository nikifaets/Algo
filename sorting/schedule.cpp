#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;



    

    int start, len;

    while(cin >> start >> len){

        q.push(make_pair(start+len, start));

    }

 
    if(q.empty()){

        cout << 0 << endl;
        return 0;

    } 


    int visited = 1;

    pair<int, int> last_visited = q.top();
    q.pop();

    while(!q.empty()){

        pair<int, int> next_event = q.top();
        if(last_visited.first <= next_event.second){

            last_visited = move(next_event);
            visited ++;

        }

        q.pop();
    }

    cout << visited << endl;
    return 0;
}