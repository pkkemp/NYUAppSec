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
//      if (s[c] >= 33 && s[c] <= 46) {
//          s[c] = " ";
//       }
      c++;
   }
}

bool check_word(const char* word, hashmap_t hashtable[])
{
    if(word != NULL) {
    //printf("%s ", word);
    char wtmp[LENGTH];
    strcpy(wtmp, word);
    lower_string(wtmp);
    int bucket = hash_function(wtmp);
    hashmap_t cursor = hashtable[bucket];
        while(cursor->next) {
            int match = strcmp(cursor->word, wtmp);
            if(match == 0)
                return true;
            cursor = cursor->next;
        }
        bucket = hash_function(word);
        cursor = hashtable[bucket];
        while(cursor->next) {
            char ctmp[LENGTH];
            char wtmp[LENGTH];
            strcpy(ctmp, cursor->word);
            strcpy(wtmp, word);
            lower_string(ctmp);
            lower_string(wtmp);
            int match = strcmp(ctmp, wtmp);
            if(match == 0)
                return true;
            cursor = cursor->next;
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
    }
    return false;
}


bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    //File pointer for our dictionary
    FILE *word_list  = fopen(dictionary_file, "r"); // read only
    char delim[] = {"\n", " "};
    
    for(int i = 0; i < HASH_SIZE; i++) {
        hashtable[i] = NULL;
    }
    
    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    FILE *fp = fopen(dictionary_file, "r");
    if (!fp)
    {
      fprintf(stderr, "Error opening file '%s'\n", dictionary_file);
      return false;
    }
    
    /* Get the first line of the file. */
     line_size = getline(&line_buf, &line_buf_size, fp);
     line_buf = strtok(line_buf, delim);
     

     /* Loop through until we are done with the file. */
     while (line_size >= 0)
     {
       /* Increment our line count */
       line_count++;
       struct node* new_node = (struct node*) malloc(sizeof(struct node));
       strcpy(new_node->word, line_buf);
       lower_string(new_node->word);
       new_node->next = NULL;
       //struct node temp_node;
         
         
         int bucket = hash_function(line_buf);
         if(hashtable[bucket] == NULL) {
             hashtable[bucket] = new_node;
         }
         else {
             new_node->next = hashtable[bucket];
             hashtable[bucket] = new_node;
         }

       /* Show the line details */
//       printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count,
//           line_size, line_buf_size, line_buf);

       /* Get the next line */
         
       //printf(line_buf);
       //printf(hashtable[bucket]);
       line_size = getline(&line_buf, &line_buf_size, fp);
       line_buf = strtok(line_buf, delim);

         
     }
    fclose(word_list);
    return true;

}

    
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

//void remove_punctuation(char *word) {
//    char delim[] = {"."};
//    word = strtok(word, delim);
//}

char *remove_punctuation(const char *string)
{
  char delim[] = {".", ","};
  char * newstr = malloc(strlen(string) + 1);
  int counter = 0;
 
  for ( ; *string; string++) {
    if (!strchr(delim, *string)) {
      newstr[ counter ] = *string;
      ++ counter;
    }
  }
 
  newstr[counter] = 0;
  return newstr;
}
 


int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[])
{
    int num_misspelled = 0;
    char delim[] = " ";

    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    if (!fp)
    {
      return num_misspelled;
    }

    /* Get the first line of the file. */
    line_size = getline(&line_buf, &line_buf_size, fp);

    /* Loop through until we are done with the file. */
    while (line_size >= 0)
    {
      // Returns first token
      char* token = strtok(line_buf, delim);
      token = remove_punctuation(token);
    
      // Keep printing tokens while one of the
      // delimiters present in str[].
      while (token != NULL) {
          token = remove_punctuation(token);
          bool correct = check_word(token, hashtable);

          if (!correct) {
              char *stringa1 = (char*) malloc((LENGTH)*sizeof(char));
              strcpy(stringa1, token);
              misspelled[num_misspelled] = stringa1;
              num_misspelled++;
          }
          token = strtok(NULL, delim);
      }
      line_count++;
      /* Get the next line */
      line_size = getline(&line_buf, &line_buf_size, fp);
    }

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
    return num_misspelled;
}
