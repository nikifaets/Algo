#include <bits/stdc++.h>
using namespace std;

//int palind[4001][4001];
const int MOD = 100003;
int palind[4001];

bool is_palind(int start, int end, string& s){

    if(s[start] != s[end]) return false;
    if(start == end) return true;
    if(start == end-1){
        return s[start] == s[end];
    }

    return is_palind(start+1, end-1, s);
}

int count_palind(int start, string& s){

    if(palind[start] != -1) return palind[start];

    if(start == s.size()-1) return 1;

   // cout << "count palind " << endl;
    int count = 0;
    for(int i=start; i<s.size(); i++){
        if(is_palind(start, i, s)){
            
            if(i == s.size()-1) count++;
            //cout << "palindrom with start " << start << " until " << i << endl;
            //cout << s.substr(start, i-start+1) << endl;
            count += count_palind(i+1, s) % MOD;
            count %= MOD;
            //cout << "palindromes in substring " << s.substr(i, s.size()-i) <<" "<< count << endl;
        }
    }

    palind[start] = count;
    return count;
}
int main(){

    for(int i=0; i<4001; i++){
        palind[i] = -1;
    }

    string s;
    cin >> s;

    cout << count_palind(0, s) << endl;

}