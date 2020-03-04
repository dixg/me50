#include <cs50.h>
#include <stdio.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    char arr[6];
    int i;
    int j;
    int k;
    
    // for(j=65; j<=90; j++)
    // {
    //     arr[0]=j;
    //     printf("arr[0]= %c\n", arr[0]);
    // }
    // arr[1]='\0';

    // for(j=65; j<=90; j++)
    // {
    //     for(i=65; i<=90; i++)
    //     {
    //         arr[0]=j;
    //         arr[1]=i;
            
    //         printf("arr[0]= %c  arr[1]= %c\n", arr[0], arr[1]);
    //     }
    // }
    // arr[2]='\0';

    for(j=65; j<=90; j++)
    {
        for(i=65; i<=90; i++)
        {
            for(k=65; k<=90; k++)
            {
                arr[0]=j;
                arr[1]=i;
                arr[2]=k;
                
                printf("arr[0]= %c  arr[1]= %c  arr[2]= %c\n", arr[0], arr[1], arr[2]);
             }
        }
    }
   arr[3]='\0';

    


    char key1[6]={'l','o','l','\0'};
    char salt1[2]={'5','0'};
    crypt(key1, salt1);
    printf("%s\n",crypt(key1, salt1));

}
