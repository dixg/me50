#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    
    while (key<0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string plaintext = get_string("plaintext:  ");
    int n =strlen(plaintext);
    printf("ciphertext: "); 
    
    for(int i=0; i<n; i++)
    {
        int c = plaintext[i];
        int result = c+key;
        char char_result=result;
        printf("%c", char_result); 
    }
    
    printf("\n"); 
}

