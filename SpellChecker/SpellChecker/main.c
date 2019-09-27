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
    load_dictionary("wordlist.txt", hashmap);
}
