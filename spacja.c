#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char* select_a_word(char* line) {
    int index_enumerator = 0;
    while(line[index_enumerator] == ' ') {
        ++index_enumerator;
    }
    int beginningOfAWord = index_enumerator;
    index_enumerator = 0;
    while(line[beginningOfAWord + index_enumerator] != ' ') {
        ++index_enumerator;
    }
    int endOfAWord = beginningOfAWord + index_enumerator;
    int sizeOfAToken = endOfAWord - beginningOfAWord;
    char* token = malloc(sizeOfAToken*sizeof(char));
    for(int i = 0 ; i<sizeOfAToken ; ++i) {
        token[i] = line[beginningOfAWord+i];
    }
    return token;

}

char** tokenize_a_line(char* line) {
    char** tokens;
    int space_enumerator = 0;
    int index_enumerator = 0;
    while(line[index_enumerator] != '\n') {
        ++index_enumerator;
        if(line[index_enumerator] == ' ') {
            ++space_enumerator;
        }
    }
    tokens = malloc((space_enumerator+1)*sizeof(char*));

    for(int i = 0 ; i < space_enumerator +1; ++i) {
        tokens[i] = select_a_word(line);
        for(int j = 0 ; tokens[i][j] != '\0' ; ++j) {
            line = ++line;
            
        }
        ++line;
        printf("%s \n",line);
    }
    return tokens;
}



int main(int argc, char* argv[]) {
    char* word = malloc(1000*sizeof(char));
    read(STDIN_FILENO,word,1000);
    printf("Przeczytakem %s \n",word);

    char** tokenized_line = tokenize_a_line(word);

    return 0;
}