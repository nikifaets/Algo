#include <bits/stdc++.h>
using namespace std;

int find_start(int p, vector<int>& nums){

    int from_end = lower_bound(nums.rbegin(), nums.rend(), p, greater<int>()) - nums.rbegin();
    int from_start = nums.size()-1 - from_end;

    return from_start;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> nums;

    for(int i=0; i<n; i++){

        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    vector<int> prefsum;
    prefsum.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++){

        prefsum.push_back(prefsum[i-1] + nums[i]);
    }
    


    for(int i=0; i<q; i++){

        int s, p;

        cin >> s >> p;

        int rstart = find_start(p, nums);
        int rstart_sum = prefsum[rstart];
        int end_sum = rstart_sum - s;

        if(end_sum <=0 ){

            cout << rstart + 1<<endl;
            continue;
        }
        int start_idx = lower_bound(prefsum.begin(), prefsum.end(), end_sum) - prefsum.begin();
        //cout << "rstart " << nums[rstart] << " lstart " << nums[start_idx] << endl;

        cout << rstart - start_idx  << endl;

    }
}