#include <bits/stdc++.h>
using namespace std;

/*struct vertex{

    int idx;
    int path_to;
    

    bool operator < (const vertex& o) const{

        return path_to > o.path_to;
    }
};


int dist[MAX_NODES];

vector<pair<int, int>> adj[MAX_NODES];
long long find_shortest_paths(int from, int to){

    memset(dist, -1, sizeof(int) * MAX_NODES);

    priority_queue<vertex> q;
    q.push({from, 0});
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
            }

        }
    }

    return dist[to];
}*/

const int MAX_NODES = 100002;
int component[MAX_NODES];
int quali[MAX_NODES];
bool used[MAX_NODES];

struct edge{


    int from;
    int to;
    int cost;

    bool operator < (const edge& o) const{

        return cost > o.cost;
    }
};

vector<edge> edges;

int find(int n){

    if(component[n] == -1){

        return n;
        
    }

    return find(component[n]);
}

void make_union(int u, int v){

    component[u] = v;
}   

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(component, -1, sizeof(int) * MAX_NODES);
    edges.reserve(4*MAX_NODES + 10);

    int num_nodes;
    cin >> num_nodes;

    int max_quali = 0;
    
    for(int i=0; i<num_nodes; i++){
        int q;
        cin >> q;
        quali[i] = q;
        if(q > max_quali) max_quali = q;
    }

    int num_apps;
    cin >> num_apps;

    
    for(int i=0; i<num_apps; i++){
        
        int from, to, cost;
        cin >> from >> to >> cost;

        if(quali[from-1] <= quali[to-1]) continue;

        edges.push_back({from-1, to-1, cost});
        //cout << "pushed edge " << from << " " << to << endl;
    }

    vector<edge> tree;
    sort(edges.begin(), edges.end());

    int res = 0;

    for(auto& e : edges){

        int root_u = find(e.from);
        int root_v = find(e.to);

        //cout << "roots " << root_u << " " << root_v << endl;

        if(root_u != root_v){

            make_union(root_u, root_v);
            tree.push_back({e});
            res += e.cost;
            used[e.to] = true;
            used[e.from] = true;

        }

    }



    cout << res << endl;


}