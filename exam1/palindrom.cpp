#include <bits/stdc++.h>
using namespace std;

void add(vector<char>& v, char c, int num){

    for(uint i=0; i<num; i++){

        v.push_back(c);
    }
}

int chars_num[30];

void count_chars(string& inp){

   // cout << "inp size " << inp.size() << endl;
    for(int i=0; i<inp.size(); i++){

       // cout << "index" << int(inp[i] - 'a') << endl;
        chars_num[int(inp[i]) - 'a'] ++;
    }

   

    //cout << "end loop" << endl;
}


int count_odd(){

    int res=0;
    
    for(int i=0; i<30; i++){

        if(chars_num[i] % 2 == 1) res++;
    }

    return res;
}

bool is_possible(){

    return count_odd() < 2;
}

char find_odd(){

    for(int i=0; i<30; i++){

        if(chars_num[i] % 2 == 1) return i + 'a';
    }

    return ' ';
}

void add_half(vector<char>& v){

    for(uint i=0; i<30; i++){

        if(chars_num[i] % 2 ==0) add(v, i+'a', chars_num[i]/2);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    //cout << "dsfdsfdsfds" << endl;
    count_chars(s);

    if(! is_possible()){

        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<char> v;
    char odd_c = ' ';

    if(count_odd() > 0){

        odd_c = find_odd();
        int num_app = chars_num[odd_c-'a'];
        add(v, odd_c, num_app/2);
    }

    add_half(v);

   // cout << "added half" << endl;
    sort(v.begin(), v.end());
    //cout << "sorted" << endl;


    //cout << "v size " << v.size() << endl;


    for(int i=0; i<v.size(); i++){

        cout << v[i];
    }


    if(count_odd() > 0){

        cout << odd_c;
    }
    for(int i=v.size()-1; i>=0; i--){

        cout << v[i];
    }

    cout << endl;
    return 0;


}