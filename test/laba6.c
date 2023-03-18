#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PROMPT "> "

int is_delim(char ch) {
        return ch == ' ' || ch == '\t';
}

List *read_list() {
        printf(PROMPT);
        List *list = list_new();
        if(!list) {
                return NULL;
        }
        int check_delim = 0;
        while (1) {
                char ch = getchar();
                if(feof(stdin)) {
                        list_delete(list);
                        return NULL;
                }
                if (ch == '\n') {
                        return list;
                }
                if(is_delim(ch)) {
                        if(list->head && !is_delim(list->head->ch)) {
                                check_delim = 1;
                        }
                        continue;
            }
            if(check_delim) {
                if(list_push_back(list, ' ')) {
                        list_delete(list);
                        return NULL;
                }
                check_delim = 0;
            }
            if(list_push_back(list, ch)) {
                list_delete(list);
                return NULL;
            }
        }
}

/*void process(List *list) {
        Item *ptr = list->head;
        int words = 0;
        while (ptr) {
                if(ptr->ch==' '){
                        words++;
                }

                //next = ptr->next;
                //ptr->next = prev;
                //prev = ptr;
                ptr = ptr->next;
        }
        words++;
        List **arr = (List **) calloc(words, sizeof(List));
        for (int i = 0; i < words; i++) {
                arr[i] = (List *) calloc(1, sizeof(List));
                arr[i]->head = NULL;
                arr[i]->tail = NULL;
        }
        ptr = list->head;
        int count = 0;
        while (ptr) {
                if(ptr->ch == ' ') {
                        count++;
                }
                else {
                        list_push_back(arr[count], ptr->ch);
                }
                ptr = ptr->next;
        }
        printf("\"");
        for (int j = words-1; j > -1; j--){
                list_print(arr[j]);
                if(j != 0) {
                        printf(" ");
                }
                list_delete(arr[j]);

        }
        printf("\"");

}*/

int move_words(List *list) {
    if (!list || !list->head) {
        return 1;
    }

    Item *ptr = list->head;
    while (ptr->next && ptr->next->ch != ' ') { // ищем конец первого слова
        ptr = ptr->next;
    }
    if (!ptr->next) {
        return 0; // строка из одного слова
    }
    
    list->tail = ptr; // новым концом списка будет конец первого слова
    ptr = ptr->next;
    list->tail->next = NULL;
    Item *end_space = ptr;
    ptr = ptr->next;
    
    while (1) {    
        Item *word_start = ptr;
        Item *word_end;
        
        while (ptr && ptr->ch != ' ') {
            word_end = ptr;
            ptr = ptr->next;
        }
        
        if (ptr) { // если есть пробел после слова (не последнее слово)
            word_end = ptr; // считаем пробел после слова его частью
            ptr = ptr->next;
            
            word_end->next = list->head;
            list->head = word_start;
        } 
        else {
            word_end->next = end_space;
            end_space->next = list->head;
            list->head = word_start;
            return 0;
        }
    }
}

int foo(List *list) {
	Item *ptr = list->head;
	while (ptr && ptr->ch!= ' ') {
		ptr = ptr->next;
	}
	if (!ptr->next) {
		return 0;
	} 
	ptr = ptr->next;
	while (ptr && ptr->ch!= ' ') {
		list_push_begin(list,ptr->ch);
		list_remove(list,ptr->ch);
		ptr = ptr->next;
	}
	return 0;
}

int main() {
    List *list = read_list();
    while(list != NULL) {
        printf("\"");
        list_print(list);
        printf("\"");
        printf("\n");
       // move_words(list);
        foo(list);
        printf("\""); 
        list_print(list);
        printf("\""); 
        printf("\n");
        list_delete(list);
        list = read_list();
    }
    printf("\n");
    return 0;
}
