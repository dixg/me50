#include<math.h>
#include<stdio.h>
#include<cs50.h>

int total_digit(long num);

int main(void)
{ 
    int num,prod_even,sum,i,j,sum_odd=0,prod_digit=0,prod_digit2=0;
    
    long cc_num = get_long("Number:");
    //printf("Number: %ld\n", cc_num);
    
    //total_digit(cc_num);
    long backup= cc_num;
    
    int store_count = total_digit(cc_num);
    printf("Total digits: %i\n", store_count);
    
    for ( i = 1; i<=store_count; i++)
    {
         num = cc_num % 10; 
        
        
         if(i%2==0) //even placeholder
         {
            prod_even= num*2;
             
             if(prod_even>10)
             {
                 for(j=1; j<=2; j++)
                {
                     prod_digit2 = prod_even %10;
                     prod_even/=10;
                     prod_digit+=prod_digit2;    
                 }           
             }
           else
           {
               prod_digit+=prod_even;
           }
         }
        
        // else if i is od
        else
        {
            sum_odd +=num;
            
        }
        
        cc_num= cc_num/10;
        
    }
   
    printf("prod_digit: %d\n",prod_digit);
    printf("sum_odd:%d\n", sum_odd);
    
    int Final_factor= prod_digit + sum_odd;
    printf("The deciding numberis %d\n", Final_factor);
    
    if((Final_factor%10 == 0)&& (store_count==13 || store_count==15 ||store_count==16))
    {
        if (store_count >= 13 && store_count <= 16)
    {
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && store_count <= 55 && store_count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || store_count == 37) && store_count == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
         
        
        
        
    }
    else
    {
     printf("This is not ligit\n");
    }
}

    

int total_digit(long num)
{     
    int count=0;
    while ( num >= ! 0 )
    {
        count ++;
        num = num/10;
    }
 return count;
}    

