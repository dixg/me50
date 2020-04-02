#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
        FILE* fptr;
        FILE* outptr=NULL;
        int count=0;

        fptr = fopen("card.raw", "r");
        if(fptr == NULL)
        {
            printf("Error in file: card.raw is NULL!!");
            return 1;
        }

        BYTE buffer[512];

        while((fread(buffer,1,512,fptr)) == 512 )
        {
            if( (int) buffer[0] == 0xff  &&
                (int)buffer[1] == 0xd8  &&
                (int)buffer[2] == 0xff  &&
                (int)(buffer[3] & 0xf0) == 0xe0)
            {
                char filename[8];

                sprintf(filename, "%03i.jpg", count);
                outptr = fopen(filename, "w");
                fwrite(buffer, 512, 1, outptr);
                count++;
            }
            else if (count>0)
            {
                fwrite(buffer, 512, 1, outptr);
            }

        }
            fclose(outptr);
            fclose(fptr);
            return 0;
}  
                

