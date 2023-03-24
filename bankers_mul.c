#include <stdio.h>
#define N 5 
#define V 3

int main(){

    int allocation[V][N] = {
        {0,2,3,2,0},
        {1,0,0,1,0},
        {0,0,2,1,2}
    };
    int max[V][N] = {
        {7,3,9,2,4},
        {5,2,0,2,3},
        {3,2,2,2,3}
    };

    int total[] = {10,5,7};
    int available[V];
    int need[V][N], check[V][N];

    int counter = 0, sum = 0;

    for(int i = 0; i < V; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            sum += allocation[i][j];
        }
        available[i] = total[i] - sum;
    }


    for(int i = 0; i < V; i++){
        for(int j = 0; j < N; j++){
            need[i][j] = max[i][j] - allocation[i][j];
            check[i][j] = 0;
        }
    }


    while(1){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < N; j++){
                if(need[i][j] <= available[i] && check[i][j] == 0){
                    available[i] += allocation[i][j];
                    check[i][j] = 1;
                }
                else{
                    continue;
                }
            }
        }

        int final = 1;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < N; j++){
                if(check[i][j] == 0){
                    final = 0;
                    break;
                }
            }
        }

        if(final == 1)
            break;   
    }

    for(int i = 0; i < V; i++){
        printf("%d ", available[i]);
    }

    return 0;
}