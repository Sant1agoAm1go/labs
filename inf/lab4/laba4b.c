#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#define DELIM " \t"
#define PROMPT "> "

size_t mystrlen(const char *s) {
    int res = 0;
    while (*s) {
        ++s, ++res;
    }
    return res;
}

void mcp(char *dest, const char *source, size_t len){
	for (size_t i = 0; i < len; i++) {
		dest[i]=source[i];
	}
}

char *dup(const char *source) {
	size_t len = mystrlen(source);
	char *dest = (char*) calloc(len + 1, sizeof(char));
	for (size_t i = 0; i < len; i++) {
		dest[i]=source[i];
	}
	dest[len] ='\0';
	return dest;
}

/*char * mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    return ( *s ) ? (char*) s : NULL;
}
 
char *my_strtok(char *str, const char * delim) {
    static char *next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
        
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}*/

int isEnd(char ch)
{
        return ch == '\0' || ch == -1;
}

int isHave(char ch, const char* str)
{
        for (size_t i = 0; !isEnd(str[i]); i++)
                if (str[i] == ch)
                        return 1;
        return 0;
}

void fill(char* str, const char* delim) {
        size_t len = mystrlen(str);
        // printf("Hello2!\n");
        // printf("%d\n", len);
        for (size_t i = 0; i < len; i++) {
                // printf("Hello2!\n");
                if (isHave(str[i], delim)) {
                        // printf("%d\n", len);
                        str[i] = '\0';
                }
        }
}

char* my_strtok(char* str, const char* delim) {
        static size_t len;
        static char* res;
        static size_t position;
        if (str) {
                len = mystrlen(str);
                position = 0;
                fill(str, delim);
                res = str;
                return res;
        }
        while(res[0] != '\0' && position < len) {
                position++;
                res++;
        }
        while (res[0] == '\0' && position < len) {
                position++;
                res++;
        }
        if (position == len)
                return NULL;
        else 
                return res;
}

int math(char *str){
    int len = mystrlen(str), num = 0, res = 0, k = 1;
    for (int i = 0; i < len; i++){
        if (str[i] >= '0' && str[i] <='9') {
            num = num*10 + str[i] - '0';
        }
        else {
            if (num!=0) {
                res = res + num * k;
                num = 0; 
                
            }
            if (str[i] == '+') {
                k = 1;
            }
            else if (str[i] == '-') {
                k = -1;
            }
         
        }
    }
    return res+num*k;
}

char *result(const char *str) {
    char *s = dup(str);
    int s_len = mystrlen(s);
    char *r = calloc(s_len + 1, sizeof(char));
    int len = 0;
    char *word = my_strtok(s, DELIM);
    while (word != NULL) {
        int w_len = mystrlen(word);
        if(w_len > 0) {
            mcp(r+len, word, w_len * sizeof(char));
            len += w_len;
            r[len] = ' ';
            ++len;
        }
        word  = my_strtok(NULL, DELIM);
    } 
    free(s);
    
    if (len > 0) {
        --len;
    }  
    else {
    	return r;
    }
    len+=3;
    r = realloc(r, (len+1)*sizeof(char));
    
    r[len-3] = ' ';
    r[len-2] = '=';
    r[len-1] = ' ';
    r[len] = '\0';
    int res = math(r);
    int count = 0;
    if (res == 0){
        count = 1;
    }

    if (res < 0) {
        res*=-1;
    }
    while(res > 0){
        count++;
        res/=10;
        
    } 
    res = math(r);
    int add = 0;
    if (res < 0) {
         res *=-1; 
         len+=count+1;
         r = (char *) realloc(r, (len+1)*sizeof(char));
         r[len-count-1] = '-';
         for(int i = 0; i < count; i++) {
             add = res%10;
             r[len-(i+1)] = add + '0';
             res/=10;
         }  
         r[len] = '\0';
    }
    else {
        len+=count; 
        r = (char *) realloc(r, (len+1)*sizeof(char));
        for(int i = 0; i < count; i++) {
            add = res%10; 
            r[len-(i+1)] = add + '0';
            res/=10;
        }
        r[len] = '\0'; 
    }
    return r;
}
char *my_str() {
	printf(PROMPT);
	char buf[81] = {0}; 
	//char *buf = (char*) calloc(81, sizeof(char)); 
	char *res = NULL;
	size_t len = 0;
	int  n = 0;
	do {
		n = scanf("%80[^\n]", buf);
		if (n < 0) {
			printf("\n");
			return NULL;
		}
		else if (n > 0) {
			size_t chunk_len = mystrlen(buf);
			size_t str_len = len + chunk_len;
			res = realloc(res, str_len + 1);
			mcp(res+len, buf, chunk_len);
			len = str_len;
		}
		else {
		scanf("%*c");
		}
	} while (n > 0);
	if (len > 0) {
		res[len] = '\0';
	}
	else {
		res = calloc(1,sizeof(char));
	} 
	return res;
}
int main () {
	clock_t start = clock();
	char *input = my_str(PROMPT);
	while (input != NULL) {
		char *res = result(input);
		printf("\"%s\"\n",input);
		printf("\"%s\"\n",res);
		free(input);
		free(res);
		input = my_str(PROMPT);
	}
	//double end = (double) (clock() - start) / CLOCKS_PER_SEC;
	//printf("На считывание и обработку строки ушло %lf секунд\n", end);
	return 0;
}
