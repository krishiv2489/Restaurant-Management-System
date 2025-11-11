#include<stdio.h>
struct complex{
    float real;
    float imag;
};
struct complex addComplex(struct complex a, struct complex b){
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
};

int main() {
    struct complex c1,c2,c3;
    printf("Enter the real and imaginary part of first complex number:- ");
    scanf("%f %f",&c1.real,&c1.imag);
    printf("Enter the real and imaginary part of first complex number:- ");
    scanf("%f %f",&c2.real,&c2.imag);
    c3 = addComplex(c1, c2);
    printf("The sum of the two entered complex number is:- %.2f + i%.2f", c3.real, c3.imag);
    return 0;
}