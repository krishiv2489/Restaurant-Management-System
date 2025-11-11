#include<stdio.h>
int main() {
    int w;
    scanf("%d", &w);
    if(w%2==0 && w>=1 && w!=2){
        printf("YES");}
    else if(w%2!=0 && w<=100 && w>=1 || w==2){p
        printf("NO");}
    return 0;
}