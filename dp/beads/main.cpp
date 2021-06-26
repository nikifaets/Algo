#include <bits/stdc++.h>
using namespace std;

int mem[101][2];
const int MOD = 1000000007;
int n, k;

int dp(int i, bool prev_blue){  

    if(mem[i][prev_blue] != -1) return mem[i][prev_blue];

    //cout << i << " " << prev_blue << " last multiplier " << (prev_blue ? k-1 : k) << endl;
    if(i >= n){

        mem[i][prev_blue] = (prev_blue ? k-1 : k) % MOD;
        return mem[i][prev_blue];
    } 

    if(prev_blue){

        mem[i][prev_blue] = ((long long)(dp(i+1, false) % MOD)* (k-1)) % MOD; 
        return mem[i][prev_blue];
    } 

    int no_blue = ((long long)(dp(i+1, false) % MOD) * (k-1)) % MOD;
    int blue = (dp(i+1, true) % MOD) ;

    mem[i][prev_blue] = (blue + no_blue) % MOD;
    return mem[i][prev_blue];
}

int main(){

    for(int i=0; i<101; i++){
        mem[i][0] = -1;
        mem[i][1] = -1;
    }
    cin >> n >> k;

    cout << ((long long)dp(2, false)*(k-1) % MOD + dp(2, true) % MOD) % MOD;

}