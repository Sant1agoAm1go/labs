#include <stdlib.h> 
#include <stdio.h> 
typedef struct Item {
	int data;
	struct Item *next;
} Item;

typedef struct List {
    Item *head;
} List;

void process(List *list) {
	Item *ptr = list->head, *prev = NULL, *tail = NULL; 
	while(ptr) {
		tail = ptr;
		ptr = ptr->next;
	}
	ptr = list->head; 
	while (ptr) {
		if(ptr->data == tail->data) {
			if(prev) {
				prev->next = ptr->next;
				ptr = ptr->next;
			}
			else {
				list->head = ptr->next;
				ptr = ptr->next;
			}
		}
		else {
			prev = ptr;
			ptr = ptr->next;
		}
	}
}
/*List *list_new() { 
	return (List *) calloc(1, sizeof(List));
}
int list_push_back(List *list, int data) {
	Item *ptr = (Item *) malloc(sizeof(Item)), *prev = NULL;
	ptr->data = data;
	ptr->next = NULL;
	if(!list->head) {
		list->head = ptr;
	} 
	else {
		while(ptr)
	}
} 
void list_delete(List *list) { Item *ptr = list->head, *ptr_prev; while (ptr) { ptr_prev = ptr; ptr = ptr->next; free(ptr_prev);
    }
    free(list);
}
void list_print(const List *list) { Item *ptr = list->head; while (ptr) { printf("%d ", ptr->data); ptr = ptr->next;
    }
    printf("\n");
}
int list_push_back(List *list, int data) { Item *ptr = (Item *) malloc(sizeof(Item)); if (!ptr) { return 1;
    }
    ptr->data = data; ptr->next = NULL; if (!list->head) { list->head = ptr; list->tail = ptr;
    } else {
        list->tail->next = ptr; list->tail = ptr;
    }
    return 0;
}
int list_insert(List *list, int data) { Item *ptr = list->head, *ptr_prev = NULL; while (ptr && (ptr->data < data)) { ptr_prev = ptr; ptr = ptr->next;
    }
    
int list_remove(List *list, int data) { Item *ptr = list->head, *ptr_prev = NULL; while (ptr && ptr->data != data) { ptr_prev = ptr; ptr = ptr->next;
    }
    if (!ptr) { return 1;
    }
    if (ptr == list->head) { list->head = ptr->next;
    }
    if (ptr == list->tail) { list->tail = ptr_prev;
    }
    if (ptr_prev) { ptr_prev->next = ptr->next;
    }
    free(ptr); return 0;
}*/

int main () {
	List *list = (List *)  malloc(sizeof(List));
	Item *p1 = (Item *) malloc(sizeof(Item)); 
	Item *p2 = (Item *) malloc(sizeof(Item));
	Item *p3 = (Item *) malloc(sizeof(Item));
	Item *p4 = (Item *) malloc(sizeof(Item));
	list->head = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	p1->data = 2;
	p2->data = 2;
	p3->data = 1;
	p4->data = 3;
	Item *ptr = list->head;
	while(ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	process(list);
	ptr = list->head;
	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}	
	printf("\n");					
	return 0;
}
