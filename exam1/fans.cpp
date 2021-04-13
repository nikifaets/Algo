#include <bits/stdc++.h>
using namespace std;


int closest(int a, int b, int to){

    if(abs(a-to) < abs(b-to)) return a;
    return b;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coords;

    for(int i=0; i<n; i++){

        int coord;
        cin >> coord;

        coords.push_back(coord);

    }

    sort(coords.begin(), coords.end());

    int max = coords[coords.size()-1];
    int min = coords[0];

    int ideal_dist = (max-min+1)/(k-1);

    vector<int> positions;

    for(int i=0; i<k; i++){

        int ideal_pos = min + i * ideal_dist;
        int lb = *lower_bound(coords.begin(), coords.end(), ideal_pos);
        int ub = *lower_bound(coords.rbegin(), coords.rend(), ideal_pos, greater<int>());

        int closer = closest(lb, ub, ideal_pos);

        positions.push_back(closer);

        coords.erase(find(coords.begin(), coords.end(), closer));

    }

    int prev = positions[0];
    int max_dist = 0;

    for(int i=1; i<positions.size(); i++){

        int dist = positions[i] - prev;
        if(dist > max_dist) max_dist = dist;
        prev = positions[i];

    }

    cout << max_dist << endl;

}