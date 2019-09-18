//
//  main.c
//  SpellChecker
//
//  Created by Preston Kemp on 9/18/19.
//  Copyright © 2019 Preston Kemp. All rights reserved.
//

#include <stdio.h>
#include "dictionary.h"

int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]);
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]);
bool check_word(const char* word, hashmap_t hashtable[]);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

check_word(string word, hashmap hashtable[])
{
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
}

load_dictionary(string dictionary, hashmap hashtable[])
{
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

check_words(file fp, hashmap hashtable[], string misspelled[])
{
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
}
