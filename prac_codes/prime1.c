#include <stdio.h>

int main()
{
    int i;
    int j;
    int size = 0;
    int arr[size];
    int arr_int;
    int val;
    int count = 1;
    int rem;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Input in the array\n");
    for(i=0; i<size; i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d", &arr[i]);
       printf("arr[%d] = %d", i, arr[i]);
    }

    for(i=0; i<size; i++)
    {
        val=arr[i];

        if (val == 0 || val == 1)
        {
                printf("%d - Not Prime\n", val);
        }

      else
      {
        for(j=2; j<val; j++)
        {

            rem = val % j;

            if(rem != 0)
            {
                count = 1;
            }
            else if (rem == 0 )
            {
                printf("%d - Not Prime\n", val);
                count += 1;
                break;
            }
        }
         if (count == 1)
         {
             printf("%d - It is a prime!\n", val);
         }
      }
    }
}



