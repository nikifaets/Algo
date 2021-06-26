#include <bits/stdc++.h>
using namespace std;

const int X = 20, Y = 20, H = 20;
const long MOD = 1000000007;

int xm, ym, h;

long mem[X+2][Y*2+4][H+2];

int to_pos(int y){

    return y + Y;
}

long paths_from(int x, int y, int z){

    //cout << x << " " << y << " " << z << endl;
    if(x < 0 || to_pos(y) < 0 || z < 0) return 0;
    if(x > X || y > Y || z > H) return 0;

    if(x == xm-1 && y == ym && z == 1) return 1;

    if(mem[x][to_pos(y)][z] != -1) return mem[x][to_pos(y)][z];

    long paths = 0;
    paths += (paths_from(x+1, y, z) % MOD + 
              paths_from(x+1, y+1, z) % MOD +
              paths_from(x+1, y-1, z) % MOD) % MOD;

    if(z < h){

        paths += (paths_from(x+1, y, z+1) % MOD +
                  paths_from(x+1, y+1, z+1) % MOD +
                  paths_from(x+1, y-1, z+1) % MOD) % MOD;
    }

    if(z > 1){
        paths += (paths_from(x+1, y, z-1) % MOD +
                  paths_from(x+1, y+1, z-1) % MOD +
                  paths_from(x+1, y-1, z-1) % MOD) % MOD;

    }

    mem[x][to_pos(y)][z] = paths % MOD;
    //cout << "paths from " << x << " " << y << " " << z << " " << mem[x][to_pos(y)][z] << endl;
    return paths % MOD;

    
    
}
int main(){

    for(int i=0; i<X+2; i++){
        for(int j=0; j<(Y+2)*2; j++){
            for(int k=0; k<H+2; k++){
                mem[i][j][k] = -1;
            }
        }
    }
    cin >> xm >> ym >> h;

    long res = paths_from(1, 0, 1) % MOD;
    cout << res << endl;
    return 0;
}