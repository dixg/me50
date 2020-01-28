#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    //int k = atoi(argv[1]);
    if (isdigit(atoi(argv[1]))) 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    int key = shift(argv[1][0]);
    printf("%i\n", key);
    
    //string s = get_string("plaintext:  ");
    //int n = strlen(s);
    //printf("ciphertext: "); 

}
    
int shift(char c)
{ 
    int char_asci = c; 
    
    if (char_asci >= 97 && char_asci <= 122)
    {
        int key = char_asci - 97;
        return key;
    }
    else 
    {
        return -1;
    }
}
     
  

