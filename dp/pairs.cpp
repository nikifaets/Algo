#include <bits/stdc++.h>
using namespace std;

bool dp [6][2005][2005];
int target[6][2];

int main(){

    int t;
    cin >> t;

    for(int i=0; i<t; i++){

        int a,b,c,d;
        cin >> a >> b >> c >> d;
        dp[i][a][b] = true;
        target[i][0] = c;
        target[i][1] = d;

    }

    for(int i=0; i<t; i++){
        for(int j=0; j<1001; j++){
            for(int k=0; k<1001; k++){
                if(dp[i][j][k]){
                    dp[i][j+k][k] = true;
                    dp[i][j][j+k] = true;
                }
            }
        }

        if(dp[i][target[i][0]][target[i][1]]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

}