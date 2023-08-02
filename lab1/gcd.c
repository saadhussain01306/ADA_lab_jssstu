#include<stdio.h>
#include<stdlib.h>

int gcd_modulo(int,int); // Modified Euclid's Algorithm
int gcd_rept_sub(int,int); // Euclid's Algorithm
int gcd_cons_intg(int,int);

int main()
{
   FILE*fp = NULL;
   fp = fopen("gcd.dat","w");
   
   if(fp == NULL)
   {
      printf("Error!!");
      exit(1);
   }
   int n = 1;
   
   while(n!=11)
   {
      int a,b,r1,r2,r3;
      a = rand()%100;
      b = rand()%100;
     
      r1 = gcd_modulo(a,b);
      r2 = gcd_rept_sub(a,b);
      r3 = gcd_cons_intg(a,b);
     
      fprintf(fp,"%d\t%d\t%d\t%d\n",n,r1,r2,r3);
      n++;
   }
   
   fclose(fp);
   
   return 0;
}

int gcd_modulo(int a, int b)
{
   int rem,count = 0;
   while(b!=0)
   {
      count++;
      rem = a%b;
      a = b;
      b = rem;
   }
   return count;
}

int gcd_rept_sub(int a, int b)
{
    if(a == 0 || b==0)
    return 0;
   
    int count = 0;
   
    while(a!=b)
    {
       count++;
       if(a>b)
           a = a-b;
       
       else
           b = b-a;
    }
   
    return count;
}

int gcd_cons_intg(int a, int b)
{
   if(a == 0 || b==0)
   return 0;
   
   int t,t1,t2,count = 0;
   
   if(a>b)
       t = b;
     
   else
       t = a;
       
   while(t != 1)
   {
      count++;
      t1 = a%t;
      if(t1 == 0)
      {
         t2 = b%t;
         if(t2 == 0)
            return count;
      }
      t = t-1;
   }
   return count;        
}
