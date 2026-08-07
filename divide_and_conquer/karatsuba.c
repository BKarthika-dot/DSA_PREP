#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int get_long_length(long num){
    if(num==0) return 1;
    int length=0;
    long temp=labs(num);
    while(temp>0){
        length++;
        temp/=10;
    }
    return length;
}
long karatsuba(long x,long y){
    if(x<10 || y<10) return x*y;

    int n=(get_long_length(x) > get_long_length(y))? get_long_length(x) : get_long_length(y);
    int half=n/2;
    long power= (long)pow(10,half);

    long a= x / power;
    long b= x% power;
    long c= y/power;
    long d=y%power;

    //x= a * (10^n/2)+b
    //y= c* (10^n/2)+d
    //xy = ac*10^(2*n/2) + bd + [(a+b)(c+d)-ac-bd]*(10^n/2)

    long ac=karatsuba(a,c);
    long bd=karatsuba(b,d);
    long abcd=karatsuba(a+b,c+d);

    return ac * power * power + (abcd - ac - bd) * power + bd;

}
int main(){
    long num1=1234;
    long num2=5678;

    printf("%ld",karatsuba(num1,num2));
}