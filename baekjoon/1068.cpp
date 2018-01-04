//https://www.acmicpc.net/problem/1068

#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include <string.h>

#define DEBUG
#ifdef DEBUG
#define D printf
#else
#define D
#endif

// 1<= N <= 50
#define N_MAX 51

int data[N_MAX][2];

int check_leaf(int val, int N)
{
    int i;
    int ret = 0;

    D("start val = %d \n", val);
    if(data[val][1] > 0)
        goto end;

    ret = 1;
    for(i=0; i<N;i++){

        if (data[val][0] == -1)
            break;
        if (data[val][0] == -2){
            ret = 0;
            break;
        }

        val = data[val][0];
        D("    val = %d \n", val);
    }

end:
    D("end return = %d \n\n", ret);
    return ret;
}

int main() {
    int N, K; 
    int i, j;
    int result;

#ifdef DEBUG
    freopen("1068.txt", "rt", stdin);
    setbuf(stdout, NULL);
#endif

    scanf("%d", &N);
    D("N:%d \n", N);

    memset(data, 0, sizeof(data));

    for(i=0;i<N;i++){
        data[i][0] = -2;
        data[i][1] = 0;
    }
    for(i=0;i<N;i++){
        D("(%d, %d) ", data[i][0], data[i][1]);
    }
    D("\n");

    for(i=0;i<N;i++){
        scanf("%d", &data[i][0]);
        data[data[i][0]][1] = data[data[i][0]][1] + 1;
    }

    for(i=0;i<N;i++){
        D("(%d, %d) ", data[i][0], data[i][1]);
    }
    D("\n");

    scanf("%d", &K);
    D("Delete node K:%d \n", K);

    result = 0;
    if ( data[K][0] != -1 ){

        data[K][0] = -2;
        data[data[K][0]][1] = data[data[K][0]][1] - 1;

        result = 0;
        for(i=0;i<N;i++){
            if (check_leaf(i, N) == 1)
                ++result;
        }

        for(i=0;i<N;i++){
            D("(%d, %d) ", data[i][0], data[i][1]);
        }
        D("\n");
    }

    printf("%d\n", result);

}

