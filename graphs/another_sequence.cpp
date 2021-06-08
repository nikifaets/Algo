#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000007;
pair<int, int> get_adj(int n){

    int digits = 0;
    int multiplicator = 1;
    
    pair<int, int> res;
    res.first = n+1;
    res.second = 0;
    
    int remainder;

    while(n){

        remainder = n%10;
        res.second = res.second*10 + remainder;
        n/= 10;
    }
    
    res.first %= MOD;
    res.second %= MOD;

    return res;
}

void test_get_adj(){

    int a = 5587;
    pair<int, int> rev_a = get_adj(a);
    cout << rev_a.first << " " << rev_a.second << endl;
    int b = 12;
    pair<int, int> rev_b = get_adj(b);
    cout << rev_b.first << " " << rev_b.second << endl;

    int c = 765432;
    pair<int, int> rev_c = get_adj(c);
    cout << rev_c.first << " " << rev_c.second << endl;

    int d = 0;
    pair<int, int> rev_d = get_adj(d);
    cout << rev_d.first << " " << rev_d.second << endl;
}
bool used[MOD+1];
int path[MOD+1];

int main(){


    //test_get_adj();

    int a, b;
    cin >> a >> b;

    queue<int> q;

    //unordered_map<int, int> path;

    q.push(a);
    used[a] = true;
    path[a] = 1;

    while(!q.empty()){

        int curr = q.front();
        q.pop();

        pair<int, int> adj = get_adj(curr);

        if(adj.first == b || adj.second == b){

            cout << path[curr] + 1 << endl;
            return 0;
        }

        if(!used[adj.first]){

            path[adj.first] = path[curr] + 1;
            used[adj.first] = true;
            q.push(adj.first);

        }
        if(!used[adj.second]){

            path[adj.second] = path[curr] + 1;
            used[adj.second] = true;
            q.push(adj.second);

        }
    }

}