#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
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

