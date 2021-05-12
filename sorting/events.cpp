#include <bits/stdc++.h>

using namespace std;
/*
unordered_map<int, int> months_days = {

    {1 , 31},
    {2 , 28},
    {3, 31},
    {4, 30},
    {5,31},
    {6, 30},
    {7,31},
    {8,30},
    {9, 31},
    {10, 30},
    {11, 31},
    {12, 30}

};*/


namespace merge_sort{


    namespace {
    template <typename T>
        void merge(int l, int mid, int h,  vector<T>& v){


            int it1 = l;
            int it2 = mid+1;

            std::vector<T> temp(h-l+1);
            int temp_it = 0;

            while(it1 <= mid && it2 <= h){

                temp[temp_it] = std::min(v[it1], v[it2]);

                if(v[it1] <= v[it2]) it1 ++;

                else{

                    it2++;
                }

                temp_it ++;

            }

            while(it1 <= mid){

                temp[temp_it++] = v[it1++];

            }

            while(it2 <= h){

                temp[temp_it++] = v[it2++];

            }

            for(int i=0; i<temp.size(); i++){

                v[l+i] = temp[i];
            }

        }
    }

    template <typename T>
    void sort(int l, int h, vector<T>& v){


        if(l < h){

            int mid = (h+l)/2;
            sort(l, mid, v);
            sort(mid+1, h, v);
            merge(l, mid, h, v);

        }

        
    }
}

const int DAYS_IN_MONTH = 45;
const int DAYS_IN_YEAR = 1000;

struct event_time{

    int id;
    int seconds_since_midnight;
    int days_since_christ;

    bool operator < (const event_time& o) const{

        return 
        days_since_christ < o.days_since_christ ||
        (days_since_christ == o.days_since_christ && seconds_since_midnight < o.seconds_since_midnight);

    }

    bool operator == (const event_time& o) const{

        return seconds_since_midnight == o.seconds_since_midnight &&
                days_since_christ == o.days_since_christ;
    }

    bool operator <= (const event_time& o) const{

        return !(o < *this);
    }



};

int main(){

    //std::ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    vector<event_time> events(n);

    int days_since_christ_dummy;
    int seconds_since_midnight_dummy;

    for(int i=0; i<n; i++){

        int h, mins, s;
        int d, months, y;

        scanf("%2d:%2d:%2d %2d.%2d.%4d", &h, &mins, &s, &d, &months, &y);
        //cout << h << " " << mins << " " << s << " " << d << " " << months << " " <<y << endl;
        seconds_since_midnight_dummy = h*3600 + mins*60 + s;
        days_since_christ_dummy = d + DAYS_IN_MONTH * months + y*DAYS_IN_YEAR;

        events[i] = {i, seconds_since_midnight_dummy, days_since_christ_dummy};

    }

    merge_sort::sort(0, events.size()-1, events);

    for(const event_time& event : events){

        printf("%d\n", event.id+1);
    }
    
}