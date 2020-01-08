#include<stdio.h>
#include<cs50.h>
int main ()
{
    int height;
    do
    {
    printf("Height: ");
    scanf("%d",&height);
    }
    while (height<0 || height>8);  
    for(int i=1; i<=height; i++)
      {
            for( int j=1; j<=height-i; j++)
            {
                printf(" ");
            }
            for(int k=1; k<=i; k++)
            {
              printf("*");
            }
            printf("\n");
        
     
    }
}

