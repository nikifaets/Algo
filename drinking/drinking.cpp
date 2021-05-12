#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char command = ' ';

    priority_queue<int> q;

    while(command != 'Q'){

        cin >> command;

        switch(command){

            case 'A':

                int b;
                cin >> b;
                q.push(b);
                break;

            case 'R':

                if(q.empty()){

                    cout << "Not available\n";
                    break;
                }

                cout << q.top() << '\n';
                q.pop();
                break;

            case 'L':

                if(q.empty()){

                    cout << "Not available\n";
                    break;
                }
                cout << q.top() << '\n';
                break;

        }
    }
    return 0;
}