#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void myscanf(char* word,...) {
    char* whole_line = malloc(1000*sizeof(char));
    char* stack_pointer = ((char*) &word) + sizeof word;
    read(STDIN_FILENO,whole_line,1000);


    char *single_letter = malloc(sizeof(char));
    int letter_enumerator = 0;
    do {
        *single_letter = word[letter_enumerator];
        //printf("%c",*single_letter);
        if(*single_letter == '%') {
            ++letter_enumerator;
            *single_letter = word[letter_enumerator];
            if(*single_letter == 'd') {
                
            }
            else if(*single_letter == 's') {
                
            }
        }
        letter_enumerator++;
    } while(*single_letter!='\0');

    

}

int main(int argc, char* argv[]) {
    myscanf("siema");
}