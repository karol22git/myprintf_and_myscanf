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
    while(line[beginningOfAWord + index_enumerator] != ' ' && line[beginningOfAWord + index_enumerator] != '\0') {
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

int ten_to_n(int n) {
    if(n == 0) {
        return 1;
    }
    else if(n==1) {
        return 10;
    }
    else {
        return 10*ten_to_n(n-1);
    }
}

char** tokenize_a_line(char* line,int *number_of_tokens) {
    char** tokens;
    int space_enumerator = 0;
    int index_enumerator = 0;
    while(line[index_enumerator] != '\n') {
        ++index_enumerator;
        if(line[index_enumerator] == ' ') {
            ++space_enumerator;
        }
    }
    *number_of_tokens = space_enumerator +1;
    tokens = malloc((space_enumerator+1)*sizeof(char*));
    for(int i = 0 ; i < space_enumerator +1; ++i) {
        tokens[i] = select_a_word(line);
        for(int j = 0 ; tokens[i][j] != '\0' ; ++j) {
            line = ++line;
            
        }
        ++line;
    }
    return tokens;
}

int get_string_length(char* string) {
    int i;
    for(i = 0 ; string[i]!='\0' && string[i] != ' ' && string[i]!='\n';++i);
    return i;
}

int string_to_int(char* word) {
    int number_length = get_string_length(word);
    int result = 0;
    int negative = 0;
    if(word[0]=='-') {
        negative = 1;
    }
    for(int i = 0 +negative ; i  <number_length ; ++i) {
        result = result + ten_to_n(number_length-i-1)*(word[i]- '0');
    }
    if(negative == 1) {
        result = - result;
    }
    return result;

}


void myscanf(char* word,...) {
    char* stck_ptr = ((char*)(&word)) + sizeof(word);
    int array_size;
    int current_position_on_stack = 0;
    char* line =  malloc(1000*sizeof(char));
    read(STDIN_FILENO,line,1000);
    printf(" \n");
    char *single_letter = malloc(sizeof(char*));
    int letter_enumerator = 0;
    do {
       *single_letter = word[letter_enumerator];
       if(*single_letter == '%') {
           ++letter_enumerator;
           *single_letter = word[letter_enumerator];
           if(*single_letter == 'd') {
               int *integer_ptr = *((int**)stck_ptr);
               stck_ptr = stck_ptr + sizeof(int*);
               char* string_integer = select_a_word(line);
               *integer_ptr = string_to_int(string_integer);
               line = line+sizeof(string_integer);
           }
           else if(*single_letter == 's') {
                char** pointer_to_a_word = *((char***)stck_ptr);
                stck_ptr = stck_ptr +sizeof(char*);
                *pointer_to_a_word= select_a_word(line);
                line = line + get_string_length(*pointer_to_a_word) +1;

           }
       }
      letter_enumerator++;
    } while(*single_letter!='\0');
    return;
}


int main(int argc, char* argv[]) {
    char* word1;
    char* word2;
    int n,m;
    myscanf("%d %s %d %s",&n,&word1,&m,&word2);
    printf("after myscanf %d %s %d %s \n",n,word1,m,word2);
    return 0;
}