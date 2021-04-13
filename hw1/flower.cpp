#include <bits/stdc++.h>

using namespace std;

void get_closest(int& left, int& right, const set<int, greater<int>>& line_asc, const set<int>& line_desc, const int& num){

    left = *line_asc.lower_bound(num);
    right = *line_desc.lower_bound(num);

    //cout << "insert " << num << " left " << left << " right " << right << endl;
}

void process_intervals(const int& left, const int& right, const int& num, int& intervals, const int& d){

    if(right - left - 1 < d) return;

    if(num - left - 1 < d && right - num - 1 < d){

        intervals -= 1;
        return;
    }

    if(num - left - 1 >= d && right - num - 1 >= d){

        intervals += 1;
        return;
    }

    
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, l, d;
    cin >> n >> l >> d;

    
    long long x_last, a, b;
    cin >> x_last >> a >> b;

    set<int> line_desc;
    set<int, greater<int>> line_asc;
    line_desc.insert(0);
    line_desc.insert(l-1);

    line_asc.insert(-1);
    line_asc.insert(l);

    int intervals = 1;

    process_intervals(0, l, x_last, intervals, d);

    line_asc.insert(x_last);
    line_desc.insert(x_last);
    if(intervals < 1 ){

        cout << 1 << endl;
        return 0;
    }

    for(int i=1; i<n; i++){

        long long xi = (x_last * a + b) % (l+1);
        int left, right;

        get_closest(left, right, line_asc, line_desc, xi);
        process_intervals(left, right, xi, intervals, d);

        //cout << "intervals " << intervals << endl;
        if(intervals < 1){

            cout << i+1 << endl;
            return 0;
        }

        line_asc.insert(xi);
        line_desc.insert(xi);
        x_last = xi;

        
    }

    cout << -1 << endl;
    return 0;


}