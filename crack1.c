#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>

int iscapital(int x);    // Function declaration to check parameter is capital char 
int issmall(int x);     // Function declaration to check parameter is small char
int salt(int argv[1]);

int main(int argc, char *argv[]) 
{
    int x;
    int i;
    int j;
    int k;
    int l; 
    int m;
    int n; 
    int count=0;
    char a[6];

    char salt1[2]={'5','0'};

    if (argc != 2)
    {
         printf("Usage: ./vigenere keyword\n");
         return 1;
    }

    // for(count=1; count<argc; count++)
    // {
    //     printf("%s!\n", argv[count]);
    // }

    for(j=65; j<=122; j++)
    {
        if(iscapital(j)== 1 || islower(j)== 1)
        {
            for(i=65; i<=122; i++)
            {
                if(iscapital(i)== 1 || islower(i)== 1)
                {
                    for(k=65; k<=122; k++)
                    {
                        if(iscapital(k)== 1 || islower(k)== 1)
                        {
                            for(l=65; l<=122; l++)
                            {
                                if(iscapital(l)== 1 || islower(l)== 1)
                                {
                                    for(m=65; m<=122; m++)
                                    {
                                        if(iscapital(m)== 1 || islower(m)== 1)

                                            a[0]=j;
                                            a[1]=i;
                                            a[2]=k;
                                            a[3]=l;
                                            a[4]=m;

                                            a[5]='\0';

                                            //a[5]={j,i,k,l,m};

                                                // for(count=0; count<5; count++)
                                                // {
                                                //     printf("%c\n", a[count]);
                                                // }      
                                            printf("a[0]: %c ", a[0]);
                                            printf("a[1]: %c ", a[1]);
                                            printf("a[2]: %c ", a[2]);
                                            printf("a[3]: %c ", a[3]);
                                            printf("a[4]: %c ", a[4]);

                                            crypt(a, salt1);
                                            printf("%s\n",crypt(a, salt1));

                                           if (argv[1] == (crypt(a, salt1)))
                                           {
                                                printf("Found it!");
                                                break;
                                            }

                                            
                                }
                            }
                        }
                    }
                }
            }
        }
    }                                               
}
printf("Hello");
}

int iscapital(int x)
{
    if(x>=65 && x<=90)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int issmall(int x)
{
    if(x>=97 && x<=122)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// int salt(int argv[1])
// {
//     int i;
//     int s_arr[3];
     
//     for (i = 0; i < 2; i++)
//     {
//         s_arr[i] = argv[1][i];
//         printf("S_arr[%d]= %d", i, s_arr[i] );
        
//         }
//     }

ispunct(i) == 0 && 

