#include <cs50.h>
#include <stdio.h>
int for_Key(char letter);

int main(void)
{ 
    char alpha;
    printf("Enter the aplhabet to convert: ");
    scanf("%c", &alpha);
    for_Key(alpha);
}
    
int for_Key(char letter)
{     
    int char_asci=c;       
    if(char_asci>=97 && char_asci<=122)
    {
        int key=char_asci-97;
        return key;
    }
     else 
        {
           return -1;
        }
     }  
