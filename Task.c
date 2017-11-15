#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int arr[100];
int main()
{
  
  for(int k=0;k<100;k++)
  {
   arr[k]=k+1;
  }
  int sumofchild=0;
  int sumofparent=0;
  int sumtotal=0;
  pid_t pid=-1;
  for(int i=0;i<2;i++)
  { 
    if(i==1)
    { sumofparent=0;sumofchild=0;}
    pid =fork();
    if( pid == 0 )
    {
     printf("i am child number %d and my pid is %d \n",i+1,getpid());    
     if(i==0)
     {
      for(int b=0;b<25;b++)
      {
       sumofchild+=arr[b];
      }
      printf("sum of first child is %d\n",sumofchild);
     }
     if(i==1)
     {
      for(int b=50;b<75;b++)
      {
       sumofchild+=arr[b];
      }
      printf("sum of second child is %d\n",sumofchild);
     }
     printf("child %d task sumofchild result is %d \n",i+1,sumofchild);  
     sumtotal+=(sumofchild);
     printf("child %d task sumchildtotal result is :%d \n",i+1,sumtotal); 
    }
    else if( pid == -1)
    { 
     printf("fail to forking \n");
     exit(0);
    }
    else
    {
     printf("i am parent of child %d my pid is %d my child will be  %d\n",i+1,getpid(),pid);
     if(i==0)
     { 
      for(int a=25;a<50;a++)
      {
       sumofparent+=arr[a];
      }
      printf("sum of first parent is %d\n",sumofparent);
     }
     if(i==1)
      {
       for(int a=75;a<100;a++)
       {
        sumofparent+=arr[a];
       }
       printf("sum of second parent is %d\n",sumofparent);
      }
     printf("parent %d  sumofparent result is %d \n",i+1,sumofparent);     
     sumtotal+=sumofparent;
     printf("parent %d  sumparenttotal result is :%d \n",i+1,sumtotal);     
    }
 if(i==1){sumtotal+=sumtotal;}
  }
  sleep(1);
  printf("task total result is %d\n",sumtotal);     
  return 0;
}
