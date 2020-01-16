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
    if (store_count != 13 || store_count != 15 ||store_count != 16)
    {
        printf("INVALID\n");
        return 1;
    }
    
//     printf("Total digits: %i\n", store_count);
    else{
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
   
//     printf("prod_digit: %d\n",prod_digit);
//     printf("sum_odd:%d\n", sum_odd);
    
    int Final_factor= prod_digit + sum_odd;
//     printf("The deciding numberis %d\n", Final_factor);
    
    if(Final_factor%10 == 0)//&& (store_count==13 || store_count==15 ||store_count==16))
    {
        int check=backup/(long) pow(10,13);
        int check2=backup/(long) pow(10,14);
        if ((backup/(long) pow(10,15) ==4) || backup/(long) pow(10,13) ==4)
        {
            printf("VISA\n");
            return 1;
        }
        else if (check==34 || check==37)
        {
            printf("AMEX\n");
            return 1;
        }
        else if(check2==51 || check2==52 ||check2==53 || check2==54 ||check2==55)
        {
            printf("MASTERCARD\n");
            return 1;
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else 
    {
        printf("INVALID\n");
    }      
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

