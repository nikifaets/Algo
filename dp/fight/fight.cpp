#include <bits/stdc++.h>
using namespace std;

const int SUM = 150001;

bool mem[301][150001];
int arr[301];

int main(){

    int num_wires;
    cin >> num_wires;

    for(int i=0; i<num_wires; i++){

        int a;
        cin >> a;
        arr[i] = a;
    }

    int sum = 0;
    for(int i=0; i<num_wires; i++){
        mem[i][0] = true;
        mem[i][arr[i]] = true;
        sum += arr[i];
    }

    for(int i=1; i<=sum; i++){
        mem[0][i] = false;
    }

    for(int i=1; i<num_wires; i++){
        for(int j=1; j<=sum; j++){
            
            //dont take
            mem[i][j] = mem[i-1][j];

            //take
            if(j >= arr[i-1])
            mem[i][j] |= mem[i-1][j-arr[i-1]];

        }
    }

    //cout << sum << endl;
    int min_diff = sum;
    for(int i=sum/2; i>=0; i--){
        if(!mem[num_wires-1][i]) continue;
        //cout << "sum exists " << i << endl;
        min_diff = sum - i*2;
        break;
    }

    cout << min_diff << endl;
    
}