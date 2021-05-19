// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Represents a node in a hash table
#define HASHTABLE_SIZE 1000

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *hashtable[HASHTABLE_SIZE];
node *table[N];

unsigned int num_words = 0;
bool is_loaded_dict = false;


// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if(hashtable[index] != NULL)
    {
        for(node *nodeptr = hashtable[index]; nodeptr != NULL; nodeptr = nodeptr->next)
            if(strcmp(nodeptr->word, check_word) == 0)
                return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hash = 0;
    int n;
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(isalpha(word[i]))
           n = word[i] - 'a' + 1;
        else
           hash = 27;
        // let the size remain in the HASHTABLE_SIZE -1;
        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* infile = fopen(dictionary, "r");
    if(infile == NULL)
        return false;
    for(int i = 0; i < HASHTABLE_SIZE; i++)
        hashtable[i] = NULL;

    char word[LENGTH + 1];
    node* new_nodeptr;
    while(fscanf(infile, "%s", word) != EOF)
    {
        num_words++;
        // do, while
        new_nodeptr = malloc(sizeof(node));
            // if(new_nodeptr == NULL)
            //     free(new_nodeptr);
        strcpy(new_nodeptr->word, word);
        int index = hash(word);
        new_nodeptr->next = hashtable[index];
        hashtable[index] = new_nodeptr;
    }
    fclose(infile);
    is_loaded_dict = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(!is_loaded_dict)
        return 0;
    return num_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    if(!is_loaded_dict)
        return false;
    for(int i = 0; i < HASHTABLE_SIZE; i++)
    {
        if(hashtable[i] != NULL)
        {
            node* ptr = hashtable[i];
            while(ptr != NULL)
            {
                node* predptr = ptr;
                ptr = ptr->next;
                free(predptr);
            }
        }
    }
    return true;
}
