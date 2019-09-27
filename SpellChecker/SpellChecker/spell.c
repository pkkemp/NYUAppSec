//
//  main.c
//  SpellChecker
//
//  Created by Preston Kemp on 9/18/19.
//  Copyright © 2019 Preston Kemp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include "dictionary.h"

const int MAX_HASH_TABLE_SIZE = 1000;

int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]);
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]);
bool check_word(const char* word, hashmap_t hashtable[]);

void lower_string(char s[]) {
   int c = 0;
   
   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z') {
         s[c] = s[c] + 32;
      }
      c++;
   }
}

bool check_word(const char* word, hashmap_t hashtable[])
{
    char* lower_word = word;
    lower_string(lower_word);
    int bucket = hash_function(lower_word);
    const char* hashmap_t_cursor = hashtable[bucket]->word;
    while(hashmap_t_cursor != NULL) {
        
    }
//    Set int bucket to the output of hash_function(word).
//    Set hashmap_t cursor equal to hashmap[bucket].
//    While cursor is not NULL:
//    If word equals cursor->word:
//    return True.
//    Set curosr to cursor->next.
//    Set int bucket to the output of hash_function(word).
//    Set hashmap_t cursor equal to hashmap[bucket].
//    While cursor is  not NULL:
//    If lower_case(word) equals curosr->word:
//    return True.
//    Set curosr to cursor->next.
//    return False.
    return false;
}

//edit
char * read_line (FILE *file)
{
    const int BUFFER_LENGTH = 1024;
    char      buffer[BUFFER_LENGTH];
    char     *result = 0;
    int       length = 0;
    int       len = 0;
    size_t    result_len = 0;

    while (!feof (file)) {
        if (!fgets (buffer, BUFFER_LENGTH, file)) {
            return result;
        }

        len = strlen (buffer);

        length += len;
        char *tmp = (char *) malloc ((length + 1) * sizeof (char));

        if (!tmp) {
            printf ("error while trying to allocate %ld bytes. \n",
                (length + 1) * sizeof (char));
            return result;
        }

        tmp[0] = '\0';

        if (result) {
            strcpy (tmp, result);
            free (result);
            result = tmp;
        } else {
            result = tmp;
        }

        strcat (result, buffer);

        if (strstr (buffer, "\n"))
            break;
    }

    if (result) {
        result_len = strlen(result);

        if (result_len > 1 && result[result_len - 2] == '\r') {
            result[result_len - 2] = '\0';
        } else if (result_len > 0) {
            if (result[result_len - 1] == '\n'
                || result[result_len - 1] == '\r') {
                result[result_len - 1] = '\0';
            }
        }
    }

    return result;
}


bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    //File pointer for our dictionary
    FILE *word_list  = fopen("/Users/prestonkemp/Documents/NYUAppSec/SpellChecker/SpellChecker/wordlist.txt", "r"); // read only
    if(word_list != NULL) {
        for(int i = 0; i < HASH_SIZE; i++) {
            hashtable[i] = NULL;
        }
        char buffer[LENGTH + 1];

        char   *word = NULL;

        while ((word = read_line(word_list)) != NULL) {
            node new_node;
            strcpy(new_node.word, word);
            new_node.next = NULL;
            //hashtable[wordcount] = &new_node;
            
            int bucket = hash_function(word);
            if(hashtable[bucket] == NULL) {
                hashtable[bucket] = &new_node;
            }
            else {
                new_node.next = hashtable[bucket];
                hashtable[bucket] = &new_node;
            }
        }
        fclose(word_list);
        return true;
    }
        
    
    return false;

    
//    Initialize all values in hash table to NULL.
//    Open dict_file from path stored in dictionary.
//    If dict_file is NULL:
//    return false.
//    While word in dict_file is not EOF (end of file):
//    Set hashmap_t new_node to a new node.
//    Set new_node->next to NULL.
//    Set new_node->word equal to word.
//    Set int bucket to hash_function(word).
//    if hashtable[bucket] is NULL:
//        Set hashtable[bucket] to new_node.
//        else:
//            Set new_node->next to hashtable[bucket].
//            Set hashtable[bucoket] t new_node.
//            Close dict_file.
}



int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[])
{
    int num_misspelled = 0;
    
//    Set int num_misspelled to 0.
//    While line in fp is not EOF (end of file):
//    Read the line.
//    Split the line on spaces.
//    For each word in line:
//    Remove punctuation from beginning and end of word.
//    If not check_word(word):
//    Append word to misspelled.
//    Increment num_misspelled.
//    Return num_misspelled.
    return false;
}
