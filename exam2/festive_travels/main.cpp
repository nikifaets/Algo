#include <bits/stdc++.h>
using namespace std;

struct vertex{

    int idx;
    int path_to;
    

    bool operator < (const vertex& o) const{

        return path_to > o.path_to;
    }
};

const int MOD = 1000000021;
const int MAX_NODES = 556;
int dist[MAX_NODES];
long long paths[MAX_NODES*MAX_NODES];

vector<pair<int, int>> adj[MAX_NODES];

long long find_shortest_paths(int from, int to){

    memset(paths, 0, sizeof(long long) * MAX_NODES * MAX_NODES);
    memset(dist, -1, sizeof(int) * MAX_NODES);

    priority_queue<vertex> q;
    q.push({from, 0});
    paths[from] = 1;
    dist[from] = 0;

    while(!q.empty()){

        vertex curr = q.top();
        q.pop();

        //cout << "dist curr " << dist[curr.idx] << " path to curr " << curr.path_to << endl; 
        for(auto& neigh : adj[curr.idx]){

            int neigh_idx = neigh.first;
            int weight = neigh.second;

            if(dist[neigh_idx] == -1 || dist[neigh_idx] > dist[curr.idx] + weight){

                q.push({neigh_idx, dist[curr.idx] + weight});
                dist[neigh_idx] = dist[curr.idx] + weight;
                paths[neigh_idx] = paths[curr.idx];
            }

            else if(dist[neigh_idx] == dist[curr.idx] + weight){

                paths[neigh_idx] = (paths[neigh_idx] % MOD + paths[curr.idx] % MOD) % MOD;
            }
        }
    }

    return paths[to] % MOD;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num_nodes, num_vertices;

    cin >> num_nodes >> num_vertices;

    
    for(int i=0; i<num_vertices; i++){
        int from, to, w;

        cin >> from >> to >> w;
        adj[from].push_back({to, w});
        adj[to].push_back({from, w});
    }

    //cout << "input adj" << endl;
    int q;
    cin >> q;

    vector<pair<int, int>> queries;
    for(int i=0; i<q; i++){

        int from, to;
        cin >> from >> to;

        queries.push_back({from, to});
    }

    for(auto& q : queries){

        cout << find_shortest_paths(q.first, q.second) << " ";
    }

    return 0;
}