#include<math.h>
#include<stdio.h>
#include<cs50.h>

int total_digit(long num);

int main(void)
{ 
    int num,prod_even,sum,i,j,sum_odd=0,prod_digit=0,prod_digit2=0;
    long cc_num = get_long("Number:");
    
    //total_digit(cc_num);
    long backup= cc_num;
    
    int store_count = total_digit(cc_num);
    
    if (store_count != 13 && store_count != 15 &&store_count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    
    else
    {
        for ( i = 1; i<=store_count; i++)
        {
             num = cc_num % 10; 
   
             if(i%2==0) //even placeholder
             {
                prod_even= num*2;
             
                if(prod_even>=10)
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
        
        else
        {
            sum_odd +=num;
            
        }
        
        cc_num= cc_num/10;
        
    }
  
    
    int Final_factor= prod_digit + sum_odd;
        
    //printf("The sum is %d\n", Final_factor);
    
    if(Final_factor%10 == 0)//&& (store_count==13 || store_count==15 ||store_count==16))
    {
        int Visa_check1=backup/(long) pow(10,15); // Visa number size could be 16 digit.
        int Visa_check2=backup/(long) pow(10,12); // Visa number size could be 13 digit. 
        int Amex_check=backup/(long) pow(10,13);
        int MasterCard_check=backup/(long) pow(10,14); 
        
        if (( Visa_check1==4) || Visa_check2 ==4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (Amex_check == 34 || Amex_check == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        else if(MasterCard_check==51 || MasterCard_check==52 ||MasterCard_check==53 || MasterCard_check==54 ||MasterCard_check==55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
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

