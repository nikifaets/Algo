#include <bits/stdc++.h>
using namespace std;

struct edge{

    int neighbor;
    long long weight;
    int equipment;

    const bool operator < (const edge& o) const{

        if(weight == o.weight) return equipment > o.equipment;
        return weight > o.weight;
    }
};

struct vertex{

    long long path_to = -1;
    int idx;

    vertex(long long path_to, int idx) : path_to(path_to), idx(idx){}
    bool operator < (const vertex& o) const{

        return path_to > o.path_to;
    }
};

int find_shortest(int start, int end, vector<vector<edge>>& adj, int equipment){

    priority_queue<vertex> q;
    vector<long long> shortest(adj.size(), -1);

    fill_n(shortest.begin(), shortest.size(), -1);

    for(const edge& e : adj[start]){

        //cout << "initial " << e.neighbor << " " << e.weight << endl;;
        if(e.equipment > equipment) continue;
        q.push({e.weight, e.neighbor});
        shortest[e.neighbor] = e.weight;
    }

    
    shortest[start] = 0;

    while(!q.empty()){

        int curr = q.top().idx;
        q.pop();

        for(const edge& e : adj[curr]){

            int neigh = e.neighbor;
            //cout << "cost " << e.equipment << endl;
            if( (shortest[neigh] == -1 || shortest[neigh] > shortest[curr] + e.weight) && e.equipment <= equipment){
                
               // cout << "in " << endl;
                shortest[neigh] = shortest[curr] + e.weight;
                q.push({shortest[neigh], neigh});
            } 
        }
    }

    for(int i=1; i<adj.size(); i++){

        //cout << "node " << i << " shortest " << shortest[i] << endl;
    }

    return shortest[end];

}

int bs_equipment(vector<vector<edge>>& adj, int world_record, int min_cost, int max_cost){

    int shortest = -1;

    /*if(min_cost == max_cost){

        shortest = find_shortest(1, adj.size(), adj, min_cost);

    }*/

    while(min_cost < max_cost){

        //cout << "min cost " << min_cost << " max cost " << max_cost << endl;
        int mid = (max_cost + min_cost) / 2;
        //cout << "mid " << mid << endl;

        shortest = find_shortest(1, adj.size()-1, adj, mid);
        //cout << "shortest " << shortest << " WR " << world_record << endl;
        if(shortest > world_record || shortest == -1){

            min_cost = mid + 1;
        }

        else{

            max_cost = mid;
        }
    }

    return (shortest == -1 || shortest > world_record) ? -1 : min_cost;
}
void test_dijkstra(){

    int n, m, x, y;

    cin >> n >> m >> x >> y;
    n++;
    vector<vector<edge>> adj(n);



    for(int i=0; i<m; i++){

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w, 0});
        adj[v].push_back({u, w, 0});
    }

    int shortest = find_shortest(x, y, adj, 7);
    if(shortest == -1) shortest = -1;

    cout << shortest << "\n";
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*

        n - num of rocks
        m - num of bridges
        k - world record
    */

    int n, m, k;
    
    cin >> n >> m >> k; 

    vector<vector<edge>> adj(n+1);

    int mincost = 1000002;
    int maxcost = 0;
    for(int i=0; i<m; i++){

        int u, v, c, w;
        cin >> u >> v >> c >> w;

        if(c < mincost) mincost = c;
        if( c > maxcost) maxcost = c;

        adj[u].push_back({v, w, c});
    }


    int res = bs_equipment(adj, k, mincost, maxcost);
    cout << res << endl;

    return 0;
}