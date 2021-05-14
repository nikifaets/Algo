#include <bits/stdc++.h>

using namespace std;



void fill_maps(unordered_map<int, char>& ic, unordered_map<char, int>& ci){

    for(int i=1; i<=10; i++){

        char c = '0' + i -1;
        ic[i] = c;
        ci[c] = i;
    }

    for(int i=11; i<= 36; i++){

        char c = 'a' + i -11;
        ic[i] = c;
        ci[c] = i;
    }

    for(int i=37; i<= 62; i++){

        char c = 'A' + i - 37;
        ic[i] = c;
        ci[c] = i;
    }
}


int count_arr[64];
char str[10000000];
char res[10000001];

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, char> i_to_c;
    unordered_map<char, int> c_to_i;

    fill_maps(i_to_c, c_to_i);

    int n;
    cin >> n;

    string inp;

    cin >> str;




     for(int i=0; i<n; i++){

         count_arr[c_to_i[str[i]]] ++;
     }


    int bytes_set = 0;
    for(int i=0; i<63; i++){

        if(count_arr[i] < 1) continue;

        memset(res + bytes_set, i_to_c[i], count_arr[i]);
        bytes_set += count_arr[i];
    }

    cout << res;

    cout << "\n";


    return 0;
}