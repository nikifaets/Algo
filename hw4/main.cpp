
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long> nums;
    //nums.reserve
    priority_queue<long> sums;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    long max_sum = nums[0];
    long curr_sum = max_sum;
    long curr_zeros = nums[0] == 0 ? 1 : 0;
    long start = 0;

    for(int i=1; i<nums.size(); i++){

        if(nums[i] == 0) curr_zeros ++;
        if(curr_zeros > k){

            sums.push(max_sum);
            //cout << "push max sum " << max_sum << endl;
            //cout << " zero at " << i << " start excluding from " << start << endl;
            do{
                curr_sum -= nums[start];
                start++;
            }
            while(nums[start] != 0 && start < i);

            do{

                if(nums[start] == 0) curr_zeros --;
                curr_sum -= nums[start];
                start++;
            }
            while(nums[start] <= 0 && start < i);
            max_sum = curr_sum;

            //cout << "new start at " << start << endl;
        }

        if(nums[i] >= nums[i] + curr_sum){

            start = i;
        } 
        curr_sum = max(nums[i], nums[i] + curr_sum);
        max_sum = max(curr_sum, max_sum);
        //cout << "amx " << max_sum << endl;
    }

    sums.push(max_sum);
    //cout << "start " << start << endl;
    cout << sums.top() << endl;
    return 0;
}