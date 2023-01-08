#ifndef LINE
# define LINE 256
# define WORD 30
# define NUM_LINE 250
#endif

void print_similar_words(char *str);
int get_line(char s[]);
int getWord(char w[]);
int similar (char *s, char *t, int n);
char * longer(char * s, char * t); // helping function
char * delete_char(char * word, int index); // helping function
int substring( char * str1, char * str2);
int main();
