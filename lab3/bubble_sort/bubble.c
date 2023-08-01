#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int bubbleSort(int* arr, int n){
    int count=0, flag=0;
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-i-1; j++){
            count++;
            if(arr[j]>arr[j+1]) {
                flag=1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag==0) return count;
        
    }
    return count;
}

void main(){
 FILE* fp;
 int count=0,*arr=NULL;
 int values[]={10,100,1000,2000,5000,10000,20000,40000};
 int n=sizeof(values)/sizeof(values[0]);
 fp=fopen("bubble.dat", "a");
 for(int i=0; i<n; i++){
    int* arr=(int*)malloc(values[i]*sizeof(int));

    //Best Case I/P
    for(int j=0; j<values[i]; j++) arr[j]=j;
    count=bubbleSort(arr,values[i]);
    fprintf(fp,"%d\t%d\t",values[i],count);

    //  Worst Case I/P
    for(int j=0; j<values[i]; j++) arr[j]=values[i]-j;
    count=bubbleSort(arr,values[i]);
    fprintf(fp,"%d\n",count);
 
    free(arr);
 }
 fclose(fp);
}
