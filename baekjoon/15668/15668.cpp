//https://www.acmicpc.net/problem/15668

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, ans, Use[10];

//#define DEBUG

#ifdef DEBUG
#define D printf
#else
#define D 
#endif

int main() 
{
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d", &N);

    D("D = %d \n", N); 

    for (int i = 1; i < min(N, 98765); i++) 
    {
        memset(Use, 0, sizeof(Use));

        int a = i, b = N - i, flag = 1;

        while (a){
            Use[a % 10]++;
            a /= 10;
        }
        while (b) {
            Use[b % 10]++; 
            b /= 10;
        }

        for (int j = 0; j <= 9; j++) 
            if (Use[j] > 1) 
                flag = 0;

        if (flag) {
            printf("%d + %d", i, N - i);
            return 0;
        }else{
            D("Fail: %d + %d \n", i, N - i);
        }


    }
    puts("-1");
    return 0;
}

