#include <bits/stdc++.h>
using namespace std;

const int MAX_CAVES = 1000003;
const int MAX_NODES = 100003;
const int MOD = 900007;
vector<pair<int, int>> adj[MAX_NODES];

bool used[MAX_NODES];
int low[MAX_NODES];
int disc[MAX_NODES];
int parent[MAX_NODES];
int t = 0;

struct hash_p{

    size_t operator () (const pair<int, int>& p) const{

        return hash<int>()( ( (p.first % MOD) * (p.second % MOD) ) % MOD);
    }
};

unordered_set<pair<int, int>, hash_p> bridges;

bool is_root(int node){

    return parent[node] == -1;
}

void dfs(int node){

    disc[node] = t;
    t++;
    low[node] = disc[node];
    int children = 0;

    for(pair<int, int>& edge : adj[node]){

        int neigh = edge.first;

        /*if(used[neigh]){
            low[node] = min(low[node], disc[neigh]);
        }*/

        if(!used[neigh]){

            children ++;
            used[neigh] = true;
            parent[neigh] = node;
            dfs(neigh);
            low[node] = min(low[node], low[neigh]);


            if(low[neigh] > disc[node]){

                bridges.insert({node, neigh});
                //bridges.insert({neigh, node});
            }
        }

        else if(neigh != parent[node]){
            low[node] = min(low[node], disc[neigh]);
        }
    }


}

void find_bridges(){
    t = 1;
    used[0] = true;
    dfs(0);
}

bool find_cycle_for_level(int level, int num_nodes){

    memset(used, false, sizeof(bool) * num_nodes);
    memset(parent, -1, sizeof(int) * num_nodes);
    for(int node=0; node<num_nodes; node++){

        stack<int> q;
        q.push(node);

        while(!q.empty()){

            int curr_node = q.top();
            q.pop();

            if(used[curr_node]) continue;
            used[curr_node] = true;

            //cout << "visit " << curr_node << endl;
            for(pair<int, int>& neigh : adj[curr_node]){

                if(bridges.count({neigh.first, curr_node}) > 0 || bridges.count({curr_node, neigh.first}) > 0 ) continue;
                
                if(used[neigh.first] && neigh.first != parent[curr_node] && neigh.second <= level){

                   // cout << "return from " << neigh.first << " coming from " << curr_node << endl; 
                    return true;
                } 

                if(!used[neigh.first] && neigh.second <= level){

                    q.push(neigh.first);
                    
                    parent[neigh.first] = curr_node;

                }
            }

        }
    }

    return false;

}

int bsearch_levels(int min_level, int max_level, int num_nodes){

    if(min_level == max_level) return max_level;

    int res = max_level;

    while(min_level < max_level){

        //cout << min_level << " mid max " << max_level << endl;
        int mid = (max_level + min_level) / 2;
        //cout << " mid " << mid << endl;
        bool cycle = find_cycle_for_level(mid, num_nodes);
        //cout << "found " << cycle << endl;
        //assert(mid < 5);
        if(cycle){

            max_level = mid;
            res = mid;
        } 
        else min_level = mid+1;
    }

    return res;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(parent, -1, sizeof(int) * MAX_NODES);

    int min_level = 100004;
    int max_level = 0;

    int num_camps, num_caves;
    cin >> num_camps >> num_caves;

    for(int i=0; i<num_caves; i++){

        int from, to, level;
        cin >> from >> to >> level;
        adj[from].push_back({to, level});
        adj[to].push_back({from, level});

        if(level > max_level) max_level = level;
        if(level < min_level) min_level = level;
    }

    find_bridges();

    //memset(parent, -1, sizeof(int) * MAX_NODES);
    //memset(used, false, sizeof(bool) * MAX_NODES);

    int res = bsearch_levels(min_level, max_level, num_camps);

    cout << res << endl;
}