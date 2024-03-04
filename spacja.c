#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    //printf("rozmiar %d \n",sizeOfAToken);
    for(int i = 0 ; i<sizeOfAToken ; ++i) {
        //printf("%d \n",i);
        if(line[beginningOfAWord+i] != ' ') {
        token[i] = line[beginningOfAWord+i];
        printf("na indeksie %d mamy %c \n ",i,token[i]);
        }
    }
    //printf(" tokenxx %s \n ",token);
   return token;
   //return "siema";

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
    //char* tokens[space_enumerator+1];
    //char** tokens = malloc((space_enumerator+1)*sizeof(*tokens));
    //for(int i = 0 ; i< space_enumerator +1 ; ++i) {
    //    tokens[i] = malloc(sizeof(char*));
    //}
    tokens = malloc((space_enumerator+1)*sizeof(char*));
    for(int j = 0 ; j < space_enumerator +1 ; ++j) {
        tokens[j] = malloc(sizeof(char*));
    }
    for(int i = 0 ; i < space_enumerator +1; ++i) {
        tokens[i] = select_a_word(line);
        //printf(" %s \n",tokens[i]);
        for(int j = 0 ; tokens[i][j] != '\0' ; ++j) {
            line = ++line;
            
        }
        ++line;
       // printf("%s \n",line);
    }
    //for(int i = 0 ; i <space_enumerator+1; ++i) {
    //    printf("%s ",tokens[i]);
   // }
    return tokens;
}

int get_string_length(char* string) {
    /* char* char_pointer = malloc(sizeof(char*));
    int length = -1;
    do {
        ++length;
        *char_pointer = string[length];
    } while(*char_pointer!= '\0' && *char_pointer!= ' ');
    return length;*/
    int i;
    for(i = -1 ; string[i+1]!='\0' && string[i+1] != ' ';++i);
    return i;
}

void test2(char* word,...) {
    char **tokens;
    int array_size = 0;
    char* stck_ptr = ((char*)(&word)) +sizeof(word);
    char* line =  malloc(1000*sizeof(char));
    read(STDIN_FILENO,line,1000);
    printf(" \n");
    char** test;
    //char** tokenized_line = tokenize_a_line(line,&array_size);
    char* wrd = select_a_word(line);
    char** wrd_ptr = *((char***)stck_ptr);
    int size_of_a_word = get_string_length(wrd);
    int size2 = strlen(wrd);
    printf("size %d i dwa %d \n",size_of_a_word,size2);
    //char* tmp_char = "siema";
    *wrd_ptr= wrd;
    return;
}


//TUTAJ NIE
void test(char* word,...) {
    char* stck_ptr = ((char*)(&word)) +sizeof(word);

    //char* tmp_ptr = *((char**)stck_ptr);
    //stck_ptr = stck_ptr+sizeof(char*);
    char** wrd_ptr = *((char***)stck_ptr);
    *wrd_ptr= "ppp";
    //printf("tutaj test %s \n",tmp_ptr);
    return;
}

void myscanf(char* word,...) {
    char* stck_ptr = ((char*)(&word)) + sizeof(word);
    int array_size;
    int current_position_on_stack = 0;
    char* line =  malloc(1000*sizeof(char));
    read(STDIN_FILENO,line,1000);
    //setvbuf(stdout,NULL,_IONBF,0);
    printf(" \n");
    //char** tokenized_line = tokenize_a_line(line,&array_size);
    //printf("tutaj %s",tokenized_line[0]);
    
    char *single_letter = malloc(sizeof(char*));
    int letter_enumerator = 0;
    //char** pointer_to_a_word ;
    do {
       *single_letter = word[letter_enumerator];
       if(*single_letter == '%') {
           ++letter_enumerator;
           *single_letter = word[letter_enumerator];
           if(*single_letter == 'd') {
               
           }
           else if(*single_letter == 's') {
            printf("skok \n");
                char** pointer_to_a_word = *((char***)stck_ptr);
                stck_ptr = stck_ptr +sizeof(char*);
                //pointer_to_a_word = "tutaj";
                //printf("tutaj %s \n",tokenized_line[current_position_on_stack]);
                //*pointer_to_a_word = tokenized_line[current_position_on_stack];
                *pointer_to_a_word = "co";
                //printf("tokenized line %s \n",tokenized_line[current_position_on_stack]);
                ++current_position_on_stack;

           }
       }
      letter_enumerator++;
    } while(*single_letter!='\0');
    return;
}


int main(int argc, char* argv[]) {
    //char *word = (char*) malloc(10*sizeof(char));
    char* word;
    test2("%s", &word);
    printf("tutaj %s \n",word);
    //char *word =  malloc(10*sizeof(char));
    //myscanf("%s",&word);
    //printf("po funkcji myscanf %s \n",word);
    /*int array_size;
    char* word = malloc(1000*sizeof(char));
    read(STDIN_FILENO,word,1000);
    printf(" \n");
    char** tokenized_line = tokenize_a_line(word,&array_size);
    printf("%d \n",array_size);
    for(int i = 0 ; i <array_size ; ++i) {
        printf("%s ",tokenized_line[i]);
    }*/
    return 0;
}