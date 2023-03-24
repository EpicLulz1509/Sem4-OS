#include <stdio.h>
#define N 5



// void check(int i){
//     if()
// }

int main(){

    int allocation[] = {0, 2, 3, 2, 0};
    int max[] = {7, 3, 9, 2, 4};
    int total = 10, counter = 0, sum = 0;
    for(int i = 0; i < N; i++){
        sum += allocation[i];
    }
    int available = total - sum;
    int need[N];
    int check[N];

    for(int i = 0; i < N; i++){
        need[i] = max[i] = allocation[i];
        check[i] = 0;
    }
    
    while(1){
        for(int i = 0; i < N; i++){
            if(need[i] <= available && check[i] == 0){
                available += allocation[i];
                check[i] = 1;
            }
            else{
                continue;
            }
        }

        // printf("Here");

        int final = 1;
        for(int i = 0; i < N; i++){
            if(check[i] == 0){
                final = 0;
                break;
            }
        }

        if(final == 1)
            break;

    }

    printf("%d ", available);


    return 0;
}