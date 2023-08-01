#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int cicf(int a , int b){
    int gcd=1,count=0;
    for(int i=2; i<=a && i<=b; i++) {
        count++;
        if (a%i==0 && b%i==0) gcd=i;
    }

    return count;
}

int modified_euclid(int m , int n){
    int r,count=0;
    while(n>0){
        count++;
        r=m%n;
        m=n;
        n=r;
    }

    return count;
}

int euclid(int m , int n){
    int count=0;
    while(m!=n){
        if(n>m) n=n-m; else  m=m-n;
        count++;
    }

    return count;
}


void main(){
    srand(time(NULL));
    FILE* fp;
int x;
    fp=fopen("gcd.dat","a");
    for(int i=0; i<=10; i++){
        fprintf(fp, "%d ", i);
        int x=rand()%100+1;
        int y=rand()%100+1;
        printf("(%d,%d)\n",x,y);
        //CICF
        fprintf(fp, "%d\t", cicf(x,y));
        //Euclids
        fprintf(fp, "%d\t", euclid(x,y));
        //Modified Euclids
        fprintf(fp, "%d\n", modified_euclid(x,y));
    }
    fclose(fp);


}
