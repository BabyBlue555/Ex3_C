
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdin.h>
#include "txt_find.h"

void print_lines(char * );
void print_similar_words(char *str);
int get_line(char s[]);
int getWord(char w[]);
int similar (char *s, char *t, int n);
char * longer(char * s, char * t); // helping function
char * delete_char(char * word, int index); // helping function
int substring( char * str1, char * str2);
int main();

int main(){
char wanted_word[WORD];
char option,blank;
scanf("%s %c%c",wanted_word,&option,&blank);
if(option=='a'){
    print_lines(wanted_word);
}
else if(option=='b'){
    print_similar_words(wanted_word);
}
return 0;


}


void print_lines(char * str){
   // str= scanf("%s",&str);

   // int num_lines=0;
    char line[LINE]; 
    while(get_line(line) > 0){ // keeps reading the lines until end of file
        if(substring(str,line)){
            printf("%s", line); 
        }
    }
}
  
    
void print_similar_words(char *str){
    char word[WORD]; 
    while(getWord(word) > 0 ){ // keeps reading each word until end of file
           if(word[0]!='\n'){
            if(similar(str,word,0)|| similar(str,word,1)){
                printf("%s\n", word); 
            }
           }
        }

}


/* the function gets an empty array of charaters , puts the current line 
* in the array , and returns the number of chars in the line. 
*/
int get_line(char s[]){
    int i=0, c=0;
    for(i=0; i< LINE-1 && c!='\n' && c!='\r';++i){
        if((c=getchar())!= EOF){
            if(c != '\r')
                s[i]=c;
            else
                s[i]='\n';
        }
        else{
            return 0;
        }

    }
    if(i==0) return 1; // edge case -only one char
    s[i]='\0';
    return i;
}
    // s= scanf("%s",&s );
    // int count_char=0;
    // if(s ==EOF){
    //     return 0;
    // }
    // else{
    //     for(int c=0;c<LINE;c++){
    //         while(s[c] != '\n'){
    //             count_char++;
    //         }
    //     }
    // }
    // return count_char;

int getWord(char w[]){
    int c , counter; 
    c=getchar();
    for(counter=0; counter<WORD-1 && (c!= EOF)&& c!=' ' && c!='\t'&& c!='\n'&& c!='\r';++counter){
        w[counter]=c;
        c=getchar();
    }
    if(c== '\n' && counter==0 ){
        w[counter++]=c;
    }    
    w[counter]= '\0';
    return counter;
}

int similar (char *s, char *t, int n){
    int length=0;
    char * longer_word=(char*)malloc(WORD*sizeof(char));
    char * shorter_word;
    //char * dest;
    int is_similar;
    if(n==0){
        if(strlen(s)!=strlen(t)){
            return 0;
        }
        if(strcmp(s,t)!=0){
            return 0;
        }
        return 1;
    }
    strcpy(longer_word,longer(s,t));
    length= strlen(longer_word);
    if(longer_word==s){
        shorter_word=t;
    }
    else{
        shorter_word=s;
    }
    // if( strcmp(longer_word,s)==0){
    //     length=strlen(s); 
    // }
    // else{
    //     length= strlen(t);
    // }
    for(int i=0; i<length; i++){
        if(s[i]==t[i]){
            continue;
        }
        else{
//strcpy(dest,longer[i])
            if(n==1){
                longer_word=delete_char(longer_word,i);
                if(strcmp(longer_word,shorter_word)==0){
                    return 1;
                }
                return 0;
                //longer_word=longer(s,t);
            }
            else{
                longer_word=delete_char(longer_word,i);
                for(int k=0;k<n-1;k++){
                    for(int j=i; j< length; j++){
                        is_similar=strcmp(delete_char(longer_word,j),shorter_word);
                        if(is_similar==0)
                        {
                            return 1;
                        }
                        if(substring(shorter_word,delete_char(longer_word,j))){
                             longer_word=delete_char(longer_word,j);
                        }
                        // longer_word=delete_char(longer_word,j);
                        //j++;
                    }
                    
                }
                strcpy(longer_word,longer(s,t));
                }
}
    }
    free(longer_word);
    }

char * longer(char * s, char * t){
    char * longer;
    if( strlen(s)> strlen(t)){
        longer=s;
    }
    else{
        longer=t;
    }
    return longer;
}
char * delete_char(char * word, int index){
    int length = strlen(word);
    if(index>=length){
        printf("invalid index");
        return NULL;
    }
    for(int i=index; i<length;i++){
        word[i]=word[i+1];
    }
    return word;
}

   // char new_word[WORD+WORD];
    //new_word= (char*)malloc(WORD*sizeof(char));

    // for(int i=0; i<strlen(word) && word[i]!='\0';i++){
    //     if(i!=index){
    //         strcat(new_word,word[i]);
    //         //strcat(new_word,'\0');
    //     }
    //     else{
    //         continue;
    //     }
    // }
    // return new_word;



/* this function checks if str2 contains str1
* if so, returns 1 , otherwise returns 0
*/
int substring( char * str1, char * str2)
{
    int count=0;
    for(int i=0; i<strlen(str2);i++){
        for(int j=0;j<strlen(str1);j++)
        {
         if(str2[i]!=str1[j]){
            count=0;
            continue;
         }
         else{
            count++;
            if(i<strlen(str2)){
            i++;
         }
         }
        }
    if(count==strlen(str1)){
        return 1;
    } 
    
 }
       
        return 0;

}





// // reading first line 
//  char s[] getWantedWord(char s[]){
//  char wanted_word [WORD];
//  char option;
//  int end_of_word=0;

//  for(int i=0; i<LINE; i++){
//     if(s[i]!= '\n'){
//     if((s[i]!=' ' || s[i]!='\t' )&& !end_of_word ){
//     strncat(wanted_word,s[i],1);
//     }
//     else if(s[i]==' ' || s[i]=='\t'){
//         end_of_word=1;
//         continue;
//     }
//     else{ // end_of_word==1
//        option=s[i]; 
//     }
//  }
//  }
//  return wanted_word;
// }

// char get_option(char s[]){
    
// }



