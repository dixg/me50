// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <strings.h>


#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

bool checkinList(const char *word, node *root);
int sizeofList(node* root);
void addtoLinkedList(node *root, node *n);

// Represents a hash table__ NODE POINTER ARRAY
node *hashtable[N];

int loadedWords = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    for(int i=0; i<N; i++)
    {
        node* root = malloc(sizeof(node));
        root->next = NULL;
        //root->word = NULL;

        hashtable[i] = root;
    }

    // Insert words into hash table
     while (fscanf(file, "%s", word) != EOF)
    {
        printf("%s\n",word);
        int hash_index = hash(word);

        node* n = malloc (sizeof(node));
        //printf("<<%p\n", n);
        if(n == NULL)
        {
            unload();
            return false;
        }
        strcpy(n->word,word);

        //printf("<    %s\n",(n->word));

        n->next = NULL;

        addtoLinkedList(hashtable[hash_index],n);

        loadedWords++;
        //printf("Loaded words:%d \n",loadedWords);
    }
        fclose(file);
    // Indicate success
    return true;
    //free(root);
   // free(n);
    // Close dictionary

}
void addtoLinkedList(node* root, node* n)
{
    node* temp = root;

    while(temp->next != NULL)
    {
        temp = temp -> next;
    }

    temp->next=n;
     //printf("%p\n",(temp->next));
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int total_size = 0;

    for(int i=0; i<N; i++)
    {
        node* root = hashtable[i];
        total_size += sizeofList(root);
    }
    // printf("<<< total Loaded words:%d \n",total_size);
    return total_size;

}

    int sizeofList(node* root )
    {
        int count = 0;
        node* temp = root;

        while(temp->next != NULL)
        {
            temp = temp -> next;
            count ++;
        }

        return count;
    }

    // Returns true if word is in dictionary else false
bool check(const char *word)
{
    int length = strlen(word);
    char *new_word = malloc(length*sizeof(char));

    for(int i=0; i<length; i++)
    {
        new_word[i] = tolower(word[i]);
    }

    int hash_index = hash(new_word);
    // printf("word - %s   hash_index = %d\n", new_word,hash_index);

    bool sign = checkinList(new_word, hashtable[hash_index]);

    //free(new_word);

     return sign;

}

bool checkinList(const char *word, node* root)
{
    int result=0;
    node* temp = root;
    int isfound = 0;

    while(temp->next != NULL)
    {
        temp= temp-> next;
        result = strcasecmp(temp->word, word);

        if(result == 0)
        {
            isfound = 1;
            return true;
            break;
        }
    }
    if(isfound == 0)
    {
    //   printf("<<%s>>       \n", word);
    }

    return false;
}

    // Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i=0; i<N; i++)
    {
        node* root = hashtable[i];
        node* current_temp = root;
        
        node* future_temp = current_temp->next; 

            while(future_temp != NULL)
            {
                // = current_temp->next;
                free(current_temp);
                current_temp = future_temp;
                future_temp = future_temp->next;
            }
           
            free(root);
        }
       
        return true;
}
