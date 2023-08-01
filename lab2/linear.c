#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int* arr, int key, int len){
    int count=0;
    for(int i=0; i<len; i++){
        count++;
        if(arr[i]==key) return count;
    }
    return count;
}
void main(){
    srand(time(NULL));
    int x,size=1,key=0;
    FILE* fptr=fopen("linear.dat","a");
    while(size<=40000){
        if(size<10000) size*=10;
        else size*=2;
        fprintf(fptr, "%d\t", size);

        int * arr= (int *)malloc(sizeof(int)*size);
        for(int i=0; i<size; i++) arr[i]= rand();
        //best case 
        x=linearSearch(arr, arr[0], size);
        fprintf(fptr, "%d\t", x);
        
        //worst case
        x=linearSearch(arr, arr[size-1], size);
        fprintf(fptr, "%d\n", x);

        free(arr);
    }

    fclose(fptr);
    
}
