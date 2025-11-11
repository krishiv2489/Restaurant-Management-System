#include<stdio.h>
#include<string.h>
int main() {
    char arr[100], str[50];
    int present1=0, present2=0, present3=0;
    FILE *file1 = fopen("1.txt", "r");
    FILE *file2 = fopen("2.txt", "r");
    FILE *file3 = fopen("3.txt", "r");
    FILE *output = fopen("output.txt", "a");
    if(!file1||!file2||!file3||!output){
        printf("ERROR!! One or more file cant be accessed or opened!\n");
        return 1;
    }
    printf("Enter the searched string:-");
    scanf("%s", arr);
    while(fgets(str, sizeof(str), file1)){
        if(strstr(str,arr)){
            present1 =1;
            break;
        }
    }
    while(fgets(str, sizeof(str), file2)){
        if(strstr(str,arr)){
            present2 =1;
            break;
        }
    }
    while(fgets(str, sizeof(str), file3)){
        if(strstr(str,arr)){
            present3 =1;
            break;
        }
    }
    fprintf(output,"%s %d %d %d \n",arr,present1,present2,present3);
    fflush(output);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(output);
    printf("results have been printed");
    return 0;
}