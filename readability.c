#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(char letter);
int count_words(char letter);
int count_sentences(char letter);

int main(void)
{
    string text = get_string("Text:");
    //printf("text[0]: %c\n", text[0]);
    int len = strlen(text);
    //printf ( "string length  = %d\n", len );

    char letter;
    int count=0;
    float total_letter=0;
    float t_letter=0;
    float t_word=0;
    float total_words=0;
    float t_sentence=0;
    float total_sentences=0;
    for(int i=0; i<=len; i++)
    {
        letter = text[i];
        //printf("text[%d]: %c", i, letter);
        t_letter = count_letters(letter);
        //printf("t_letter = %i", t_letter);
        total_letter = total_letter+t_letter;

        t_word = count_words(letter);
        total_words=total_words+t_word;

       if ((letter == 33) || (letter == 46) || (letter == 63))
       {
           if((text[i-1] > 64 && text[i-1] < 91) || (text[i-1] > 64 && text[i-1] < 91) || (text[i-1] > 64 && text[i-1] < 91))
           {
               break;
           }
           else
           {
                t_sentence = count_sentences(letter);
                total_sentences = total_sentences + t_sentence;
           }
       }
    }

    total_words+=1;
    // printf("\n");
    // printf("total_letter: %f\n", total_letter);
    // printf("total_words: %f\n", total_words);
    // printf("total_sentences: %f\n", total_sentences);


   float pre_L = total_letter/total_words;
   //printf("pre_L = %f\n", pre_L);
   float L = pre_L*100;

   float pre_S = (total_sentences/total_words);
   //printf("pre_S = %f\n", pre_S);
   float S = pre_S*100;

   //printf("L = %f\n", L);
  // printf("S = %f\n", S);

   float Index = round((0.0588 * L) - (0.296 * S) - 15.8);
    int grade = Index;

    if(Index<1)
    {
        printf("Before Grade 1\n");
    }

    else if(Index>=16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);

    }
}

int count_letters(char letter)
{
    int count = 0;
    if ((letter > 64 && letter < 91 ) || (letter > 96 && letter < 123 ))
    {
        count = count + 1;
        //printf(" count: %i\n", count);
    }
    return count;
}

int count_words(char letter)
{
    int count = 0;
    if (letter == 32)
    {
        count = count + 1;
        //printf(" count: %i\n", count);
    }
    return count;
}

int count_sentences(char letter)
{
    int count = 0;
    if ((letter == 33) || (letter == 46) || (letter == 63))
    {
        count = count + 1;
        //printf(" count: %i\n", count);
    }
    return count;
}