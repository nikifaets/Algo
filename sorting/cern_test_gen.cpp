#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(){

    srand(time(NULL));

    const int NUMS = 10000;
    const int MAX = 10000000;

    cout << NUMS << endl;
    for(int i=0; i<NUMS; i++){

        int n = rand() % MAX + 1;
        bool odd = (rand() % 2 == 0);
        if(odd) n *= -1;
        cout << n << endl;
    }
}   