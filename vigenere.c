#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h> 

int shift(char c);    // Shift value function declaration

int main(int argc, char *argv[]) 
{
    int i;
    int j = 0; 

    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    int n = strlen(argv[1]);  //initalized length of keyworb
    char key[n];  //declared an array of char datatype
     
    for (i = 0; i < n; i++)
    {
        key[i] = argv[1][i];
        if (isdigit(key[i])) 
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
  
    string plaintext = get_string("plaintext: ");
    int plaintext_len = strlen(plaintext); 
    //printf("plaintext_len = %d\n ", plaintext_len); 
    char ciphertext[plaintext_len + 1];
    printf("ciphertext: "); 
   
    for (i = 0; i < plaintext_len; i++)
    {

        if (isalpha(plaintext[i]))
        {
            if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
            ciphertext[i] = (((shift(plaintext[i]) + shift(key[j])) % 26) + 97);
            }
            else if (plaintext[i] >= 65 && plaintext[i] <= 90)
            {
                ciphertext[i] = (((shift(plaintext[i]) + shift(key[j])) % 26) + 65);
            } 
            else if (plaintext[i] >= 33 && plaintext[i] <= 64)
            {
                ciphertext[i] = plaintext[i]
            }
            j++;
            printf("%c", ciphertext[i]);

            if (j == n)
            {
                j = 0;                                                                    
            }
            //j++;

        }
        else if (plaintext[i] == 32)
        {
            printf(" ");
            continue;
            
        }     
    }
    printf("\n");
    ciphertext[plaintext_len] = '\0';  
}   

int shift(char c)    //function defination
{ 
    int char_asci = c; 
    
    if (char_asci >= 97 && char_asci <= 122)   //for lowercase alphabetes
    {
        int test = char_asci - 97;
        //printf("%d\n", test);
        return test;
    }
    else if (char_asci >= 65 && char_asci <= 90)   //for uppercase alphabetes
    {
        int test = char_asci - 65;
        //printf("%d\n", test);
        return test;
    }
    else 
    {
        return -1;
    }
}
     
