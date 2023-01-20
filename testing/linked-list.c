// Implementing a linked list in c

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node *next;
	node *prev;
};

typedef struct list list;

struct list {
	node *head;
	node *tail;
};

list *create_list();
node *create_node(int data);
void add_node(list *l, node *n);
void print_list(list *l);
void print_reverse(list *l);
void delete_n(list *l, int n);
int length(list *l);

int main() {
	list *l = create_list();
	node *n = create_node(1);
	add_node(l, n);
	n = create_node(2);
	add_node(l, n);
	n = create_node(3);
	add_node(l, n);
	print_list(l);
	print_reverse(l);
	printf("%i\n", length(l));
	printf("\n");
	delete_n(l, 1);
	print_list(l);
	delete_n(l, 1);
	print_list(l);
	return 0;
}

list *create_list() {
	list *l = (list *)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;
	return l;
}

node *create_node(int data) {
	node *n = (node *)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void add_node(list *l, node *n) {
	if (l->head == NULL) {
		l->head = n;
		l->tail = n;
	} else {
		l->tail->next = n;
		n->prev = l->tail;
		l->tail = n;
	}
}

void print_list(list *l) {
	node *n = l->head;
	while (n) {
		printf("%i\n", n->data);
		n = n->next;
	}
}

void print_reverse(list *l) {
	node *n = l->tail;
	while (n) {
		printf("%i\n", n->data);
		n = n->prev;
	}
}

// delete the last node
void delete_n(list *l, int n) {
	node *temp = l->head;
	int i = 0;
	while (i < n) {
		temp = temp->next;
		i++;
	}
	if (temp->prev) {
		temp->prev->next = temp->next;
	}
	if (temp->next) {
		temp->next->prev = temp->prev;
	}
	free(temp);
}

int length(list *l) {
	int counter = 0;
	node *n = l->head;
	while (n) {
		n = n->next;
		counter++;
	}

	return counter;
}
