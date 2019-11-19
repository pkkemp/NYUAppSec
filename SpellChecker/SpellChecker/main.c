//
//  main.c
//  SpellChecker
//
//  Created by Preston Kemp on 9/23/19.
//  Copyright © 2019 Preston Kemp. All rights reserved.
//

#include "main.h"
#include "dictionary.h"

int main(int argc, const char * argv[]) {
    hashmap_t hashmap[HASH_SIZE];
    char missed[1000];
    load_dictionary("/Users/prestonkemp/Documents/NYUAppSec/SpellChecker/SpellChecker/wordlist.txt", hashmap);
    FILE *fp = fopen("/Users/prestonkemp/Documents/NYUAppSec/SpellChecker/SpellChecker/test1.txt", "r");
    int num = check_words(fp, hashmap, missed);
    printf(num);
}
