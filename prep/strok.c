#include <stdio.h>                                                                                       
#include <stdlib.h>                                                                                      
#include <readline/readline.h>                                                                           
#define DELIM " \t"                                                                                      
#define PROMPT "> "
char *result(const char *str) {
	if (str==NULL) {
		return NULL;
	}                                                                                                                                                   
    char *s = strdup(str);                                                                               
    int s_len = strlen(s);                                                                               
    char *r = calloc((s_len * 3) + 1, sizeof(char));                                                           
    int len = 0;                                                                                         
    char *word = strtok(s, " \t");
    char first = word[0];                                                                       
    while (word != NULL) {
    	int w_len = strlen(word);
    	if(word[0] == first || word[0]+32 == first){
    		memcpy(r+len, word, w_len);
    		len+=w_len;
    		r[len] = ' ';
    		++len;
    	}                                                                                                             
        if(w_len > 0) {                                                                                  
            memcpy(r+len, word, w_len * sizeof(char));                                                   
            len += w_len;                                                                                
            r[len] = ' ';                                                                                
            ++len;
        }                                                                                                                                                                         
        word  = strtok(NULL, " \t");                                                                     
    }                                                                                                    
    free(s);                                                                                             
    if (len > 0) {                                                                                       
        --len;                                                                                           
    }
    else {
    	return r;
    }
    /*len++;
    r = (char *) realloc(r, len+1);
    if (r[0] >= 97){
    	r[0]-=32;
    }
    for (int i = 1; i < len; i++){
    	if(r[i] < 97 && r[i]!= ' ') {
    		r[i]+=32;
    	}
    }
    r[len-1] = '.';*/
    r = (char *) realloc(r, len+1 *sizeof(char));
	r[len] = '\0';
	return r;
}
int main() {
	char *str = readline(PROMPT);                                                                                                 
    while(str != NULL) {                                                                                                                                                                                                                                                                                                                                                                                                                 
        char *res = result(str);                                                                     
        printf("\"%s\"\n",str);                                                                      
        printf("\"%s\"\n",res);
        free(str);                                                                                   
       	free(res);                                                                                   
    	str = readline(PROMPT);                                                                                                   
    }                                                                                                    
    return 0;                                                                                            
}
