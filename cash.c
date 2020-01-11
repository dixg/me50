#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float value;
    printf("Change owed: ");
    scanf("%f", &value);
    
    int cents = round(value * 100); //to convert dollers into cents
    printf("%d cents\n", cents);
    
    int num_coins = 0; // declaring for counting total number coins
    
    while (cents >= 25)
    {
        cents = cents - 25;
        num_coins = num_coins + 1;
    }    
    
    printf("No. of coins of 25 cents: %d\n", num_coins);
    printf("Remaning cents= %d\n", cents);
    
    while (cents >= 10 )
    {
        cents = cents - 10;
        num_coins = num_coins + 1;
    }
    
  printf("No. of coins of 25 & 10 cents: %d\n", num_coins);
    printf("Remaning cents= %d\n", cents);
    
    while(cents >= 5)
    {
        cents = cents - 5;
        num_coins = num_coins + 1;
    }
    
    printf("No. of coins of 25, 10 & 5 cents: %d\n", num_coins);
    printf("Remaning cents= %d\n", cents);
    
    while(cents >= 1)
    {
        cents = cents - 1;
        num_coins = num_coins + 1;
    }
    
    printf("No. of coins of total cents: %d\n", num_coins);
    printf("Remaning cents= %d\n", cents);
    
    printf("%d\n", num_coins);
    

}
