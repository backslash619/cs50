/**
 * Implements a dictionary's functionality.
 * i have used the hastable data structure to store the word from the dictionary
 */

#include <stdbool.h>

#include "dictionary.h"

//keeping track of dictionary size
unsigned int word_count=0;
bool loaded = false;
///structure of node which contains a word (array of characters) and next ptr to node 
typedef struct node {
    char word[LENGTH+1];
    struct node *next;
}
node;

//array of ptrs 
node *hashtable[HASHTABLESIZE];

/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLESIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char word_copy[len+1];
    for (int i =0; i<len;i++){
        word_copy[i]=word[i];
    }
    //making last index equal to null
    word_copy[len] = '\0';
    
    // get hash value (a.k.a. bucket)
    int h = hash_it(word_copy);
    
    // assign cursor node to the first node of the bucket
    node* cursor = hashtable[h];
    
    // check until the end of the linked list
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word_copy) == 0)
        {
            // word is in dictionary
            return true;
        }
        else
        {
            // check next node
            cursor = cursor->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // make all hash table elements NULL
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        hashtable[i] = NULL;
    }
    
    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            unload();
            return false;
        }
        
        // read a word from the dictionary and store it in new_node->word
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;
        
        if (feof(fp))//foef return true of fp is null 
        {
            // hit end of file
            free(new_node);
            break;
        }

        word_count++;
        
        // hashtable[h] is a pointer to a key-value pair
        int h = hash_it(new_node->word);
        node* head = hashtable[h];
        
        // if bucket is empty, insert the first node
        if (head == NULL)
        {
            hashtable[h] = new_node;
        }
        // if bucket is not empty, attach node to front of list
        // design choice: unsorted linked list to minimize load time rather
        // than sorted linked list to minimize check time
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    // close dictionary
    fclose(fp);
    loaded = true;
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
     for (int i = 0; i < HASHTABLESIZE; i++){
    
        node *cursor =hashtable[i];
        while (cursor != NULL)
        {
            // maintain connection to linked list using temp
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
        loaded = false;
        return true;
}
