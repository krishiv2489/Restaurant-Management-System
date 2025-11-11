#include<stdio.h>
struct employee{
    char name[50];
    int id;
    float basic_salary;
    float total_salary;
};

int main() {
    struct employee e[3];
    int n;
    for(int i=0;i<3;i++){
        printf("Enter the name of the employee no. %d: ", i+1);
        scanf("%s", e[i].name);
        printf("Enter the id of the employee %d: ", i+1);
        scanf("%d", &e[i].id);
        printf("Enter the Basic Salary of the employee %d: ", i+1);
        scanf("%f", &e[i].basic_salary);
        e[i].total_salary=(1.6*e[i].basic_salary);
    }
    printf("Enter the id of the employee that you want the total salary of:- ");
    scanf("%d", &n);
    printf("The total salary of employee no. %d is %f",n,e[n].total_salary);
    float max = e[0].total_salary;
    int a=0;
    for(int i=1;i<3;i++){
        if(max< e[i].total_salary){
            max = e[i].total_salary;
            a=i;
        }
    }
    printf("\n");
    printf("The maximum salary is of employee no. %d and that is %f",n,max);
    return 0;
}