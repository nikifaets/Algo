#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char* NA = "Not available";

void insert(vector<int>& v, int& num){

    if(v.size() == 0){

        v.push_back(num);
    }

    for(int i=v.size()-1; i>=0; i--){

        if(v[i] < num){

            v.insert(v.begin()+i+1, num);
            break;
        }
    }
}

void remove(vector<int>& v){

    v.pop_back();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    char inp = ' ';
    
    while(inp != 'Q'){

        cin >> inp;

        switch(inp){

            case 'Q':
                break;

            case 'A':
                
                int num;
                cin >> num;
                insert(v, num);
                break;

            case 'R':

                if(v.size() == 0){

                    cout <<  NA << endl;
                }

                else{
                    cout << *(v.end()-1) << endl;
                    remove(v);
                    
                }

                break;

            case 'L':

                if(v.size() ==  0){

                    cout << NA << endl;
                }
                else cout << *(v.end()-1) << endl;
                break;
            
        }
    }
}