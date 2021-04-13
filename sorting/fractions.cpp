#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
#include <iostream>

namespace insertion_sort{

    template<typename T>
    void sort(std::vector<T>& v){

        if(v.size() < 2) return;

        int key = 1;

        for(int i=key; i<v.size(); i++){
                        
            int pos = i;

            while(v[pos] < v[pos-1] && pos > 0){
                
                std::swap(v[pos], v[pos-1]);
                pos --;
            }            
        }
    }

    template<typename T>
    void insert(std::vector<T>& v, T& val){

        v.push_back(val);

        int insert_pos = v.size()-1;

        while(v[insert_pos] < v[insert_pos-1] && insert_pos > 0){

            std::swap(v[insert_pos], v[insert_pos-1]);
            insert_pos --;
        }
    }
}

namespace merge_sort{

}

namespace quicksort{


}

struct frac{

    int numerator;
    int denominator;

    const bool operator <(const frac& o) const{

        return numerator * o.denominator < denominator * o.numerator;
    }

    const bool operator == (const frac& o) const{

        frac cancelled = o;

        return numerator * o.denominator == denominator * o.numerator;
    }

    
};

int lcd (int& a, int& b){

    for(int i=2; i <= std::min(a,b); i++){

        if(a % i == 0 && b % i == 0){

            return i;
        }
    }

    return 1;
}

void cancel_frac(frac& f){

    int divisor = lcd(f.numerator, f.denominator);
    while(divisor != 1){

        cout << f.numerator << " " << f.denominator << endl;
        
        f.numerator /= divisor;
        f.denominator /= divisor;

        divisor = lcd(f.numerator, f.denominator);
    }
}

int main(){

    int n;
    cin >> n;
    
    std::vector<frac> v;

    for(int denom=1; denom<=n; denom++){

        for(int num=1; num<denom; num++){

            frac fr = {num, denom};

            if(std::find(v.begin(), v.end(), fr) != v.end()) continue;
            insertion_sort::insert(v, fr);
        }
    }

    cout << 0 << " ";
    for(int i=0; i<v.size(); i++){

        cout << v[i].numerator << "/" << v[i].denominator << " ";
    }

    cout << endl;
    return 0;
}
