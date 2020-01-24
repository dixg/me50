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
    
    int k = atoi(argv[1]);
    while (k<0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string s = get_string("plaintext:  ");
    int n = strlen(s);
    printf("ciphertext: "); 
    
    for(int i=0; i<n; i++)
    {
       if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a');
            } 
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); 
            }

            else

            {
                printf("%c", s[i]);
            }
    }
    
    printf("\n"); 
}
