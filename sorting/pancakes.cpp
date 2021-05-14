#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){

        int n, k;
        cin >> n >> k;

        //cout << "laps " << k << endl;
        vector<int> v(n);

        for(int i=0; i<n; i++){

            int s;
            cin >> s;
            v[i] = s;
        }

        sort(v.begin(), v.end());
        cout << v[k-1] << "\n";
    }
}