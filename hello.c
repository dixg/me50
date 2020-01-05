#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("type your name/n");
    
    printf("hello, %s/n", name);
}
