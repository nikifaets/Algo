#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <memory>
#include <iostream>
using namespace std;


struct pos{

    int x;
    int y;

    bool operator == (const pos& o) const{

        return x == o.x && y == o.y;
    }

    pos operator + (const pos& o) const{

        return pos{x + o.x, y + o.y};
    }

};

struct pos_hash{

    size_t operator() (const pos& p) const{

        return std::hash<int>{} (p.y*2000 + p.x);
    }

};

int hash_p(const pos& p){

    return p.y*2000 + p.x;
}
vector<pos> neigh_dists = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

bool is_in_square(int width, int x, int y){

    return x >= 0 && x < width && y >= 0 && y < width;
}

void fill_adj(int width, unordered_set<pos, pos_hash>& obstacles,
            unordered_map<pos, vector<pos>, pos_hash>& out){
    
    vector<pos> neigh_dists = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    for(int i=0; i<width; i++){
        for(int j=0; j<width; j++){

            pos tile = {i, j};
            for(auto& neigh : neigh_dists){

                pos neigh_coords = {tile.x + neigh.x, tile.y + neigh.y};

                
                if(is_in_square(width, neigh_coords.x, neigh_coords.y) && obstacles.count(neigh_coords) < 1){

                    out[tile].push_back(neigh_coords);
                }
            }
        }
    }
}

bool used[2000*2000];
int path[2000*2000];
bool knights[2000*2000];
bool obstacles[2000*2000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int width, num_obstacles, num_knights;

    cin >> width >> num_obstacles >> num_knights;

    //unordered_set<pos, pos_hash> obstacles;

    for(int i=0; i<num_obstacles; i++){

        int x,y;
        cin >> x >> y;
        obstacles[hash_p(pos{x,y})] = true;
    }

    //unordered_set<pos, pos_hash> knights;

    for(int i=0; i<num_knights; i++){

        int x, y;
        cin >> x >> y;
        knights[hash_p({x, y})] = true;
    }
    pos princess;
    cin >> princess.x >> princess.y;

    //unordered_map<pos, vector<pos>, pos_hash> adj;

    //fill_adj(width, obstacles, adj);



    int available_knights = 0;
    int max_path = 0;

    //unordered_set<pos, pos_hash> used;
    //unordered_map<pos, int, pos_hash> path;

    used[hash_p(princess)] = true;
    path[hash_p(princess)] = 0;

    queue<pos> q;
    q.push(princess);

    while(!q.empty()){

        auto& curr = q.front();
        q.pop();


        for(int i=0; i<neigh_dists.size(); i++){
            
            pos neigh = curr + neigh_dists[i];
            int neigh_hash = hash_p(neigh);

            if( ! is_in_square(width, neigh.x, neigh.y) || obstacles[neigh_hash]) continue;
            if(!used[neigh_hash]){
                
                int new_path = path[hash_p(curr)] + 1;
                path[neigh_hash] = new_path;
                q.push(neigh);
                used[neigh_hash] = true;

                if(knights[neigh_hash]){

                    if(new_path > max_path) max_path = new_path;
                    available_knights ++;
                }

            }
        }

        if(available_knights >= num_knights) break;
    }



    cout << available_knights << " " << max_path << endl;
    return 0;
        
}