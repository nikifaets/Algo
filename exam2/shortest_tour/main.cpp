#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
const int MAX_VERTICES = 10001;

vector<int> adj[MAX_NODES];
int forbidden[MAX_NODES];
bool used[MAX_NODES];
int dist[MAX_NODES];

int bfs_to_target(int start, int target, vector<int>adj[], int forbidden[]){

    memset(used, false, sizeof(bool) * 1001);
    memset(dist, -1, sizeof(int)*1001);
    queue<int> q;
    q.push(start);
    used[start] = true;
    dist[start] = 0;

    while(!q.empty()){

        int curr = q.front();
        q.pop();
        //cout << "visit " << curr << endl;
        for(int neigh : adj[curr]){


            if(neigh == target){

                if(dist[neigh] == -1) return dist[curr] + 1;
                else return min(dist[neigh], dist[curr] + 1);
            }

            if(forbidden[neigh] > 0 || used[neigh]) continue;
            used[neigh] = true;

            if(dist[neigh] == -1) dist[neigh] = dist[curr] + 1;
            else dist[neigh] = min(dist[neigh], dist[curr] + 1);

            q.push(neigh);
            
        }
    }

    return dist[target];
}
int main(){

    int num_nodes, num_vertices;
    cin >> num_nodes >> num_vertices;

    for(int i=0; i<num_vertices; i++){

        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int num_forbidden;
    cin >> num_forbidden;

    queue<int> next_goal;

    for(int i=0; i<num_forbidden; i++){

        int x;
        cin >> x;
        forbidden[x] ++;
        next_goal.push(x);
    }

    if(next_goal.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    if(next_goal.size() == 1){
        cout << 0 << endl;
        return 0;
    }

    int start = next_goal.front();
    next_goal.pop();
    
    int res = 0;
    while(!next_goal.empty()){

        
        if(forbidden[start] > 0) forbidden[start] --;
        int target = next_goal.front();
        next_goal.pop();
        //cout << "start from " << start << "target " << target << endl;

        int shortest = bfs_to_target(start, target, adj, forbidden);

        if(shortest == -1){

            cout << -1 << endl;
            return 0;
        }

        res += shortest;

        start = target;
    }

    cout << res << endl;
    return 0;  

}