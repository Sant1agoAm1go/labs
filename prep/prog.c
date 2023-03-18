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
			if(list->tail && !is_delim(list->tail->ch)) {
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

void process(List *list) {
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
	//list->head  = prev;
   
}
int main() {
    List *list = read_list();
    while(list != NULL) {
    	printf("\"");
    	list_print(list);
    	printf("\"");
    	printf("\n");
    	process(list);
    	printf("\n");
    	//printf("\"");
    	//list_print(list);
    	list_delete(list);
    	list = read_list();
    }
    /*list_insert(l, 10);
    list_print(l);
    list_insert(l, 20);
    list_print(l);
    list_insert(l, 30);
    list_print(l);
    list_push_back(l, 40);
    list_print(l);
    list_insert(l, 35);
    list_print(l);
    list_insert(l, 5);
    list_print(l);
    list_remove(l, 20);
    list_print(l);
    list_push_back(l, 45);
    list_print(l);
    list_delete(l);*/
    return 0;
}
