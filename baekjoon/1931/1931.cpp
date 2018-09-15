

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

struct Time{
    int start;
    int end;
};

vector<struct Time> data;
int N;
int result = 0;

bool cmp_end (const Time &a, const Time &b){
    if(a.end == b.end) {
        return a.start < b.start;
    } else {
        return a.end < b.end;
    }
}

int main()
{
    int i;
    int cur;

#ifdef DEBUG
    freopen("data.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    cin >> N;

    data.resize(N);

    for(i=0; i<N; i++){
        cin >> data[i].start;
        cin >> data[i].end;
    }

    sort(data.begin(), data.end(), cmp_end);

#ifdef DEBUG
    for(i=0; i<N; i++)
        cout << data[i].start << " " <<  data[i].end << "\n";
#endif

    for(i=0; i<N; i++){
        if (i == 0 ){
            result++;
            cur = data[i].end;
        }else{
            if (cur <= data[i].start){
                result++;
                cur = data[i].end;
            }
        }
    }

    cout << result << "\n";
    return 0;
}


