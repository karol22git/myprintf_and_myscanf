#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



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

int get_int_rank(int number) {
    int rank = 0 ;
    for (int i = 0 ;ten_to_n(i)<= number ; ++i ) {
        rank = i;
    }
    return rank;
}

const char* int_to_string(int number) {
    int rank = get_int_rank(number);
    char *int_string = malloc((rank+1)*sizeof(char));
    int tmp;
    for(int i = 0 ; i < rank +1 ; ++i) {
        tmp = (int) number/ten_to_n(rank-i);
        number = number - tmp*ten_to_n(rank - i);
        int_string[i] = tmp + '0';
    }
    int_string[rank+1] = '\0';
    return int_string;
}

void myprintf(char* word,...) {
    char* stck_ptr = ((char*)(&word)) + sizeof(word);
    char *single_letter = malloc(sizeof(char*));
    int letter_enumerator = 0;
    do {
        *single_letter = word[letter_enumerator];
        if(*single_letter == '%') {
            ++letter_enumerator;
            *single_letter = word[letter_enumerator];
            if(*single_letter == 'd') {
                int number = *((int*)stck_ptr);
                stck_ptr = stck_ptr +sizeof(int);
                const char* number_in_string_format = int_to_string(number);
                char* letter = malloc(sizeof(char));
                for(int i = 0 ; number_in_string_format[i]!='\0'; ++i) {
                    *letter = number_in_string_format[i];
                    write(1,letter,sizeof(char));
                }

            }
            else if(*single_letter == 's') {
                char* pointer_to_a_word = *((char**)stck_ptr);
                stck_ptr = stck_ptr +sizeof(char*);
                char* letter = malloc(sizeof(char*));;
                for(int i = 0 ; pointer_to_a_word[i]!='\0'; ++i) {
                    *letter = pointer_to_a_word[i];
                    write(1,letter,sizeof(char));
                }
            }
            ++letter_enumerator;
            continue;
        }
        ++letter_enumerator;
        write(1,single_letter,sizeof(char));
    } while(*single_letter!='\0') ;
}

int main(int argc, char* argv) {
    int number = 1234;
    char* word = "greetings";
    myprintf("%s %d %s %d \n",word,number,word,number);
    return 0;
}