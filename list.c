#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
  char *field; // поле данных
  struct list *ptr; // указатель на следующий элемент
}list;

list * init(char* a) // а- значение первого узла
{
  list *head;
  // выделение памяти под корень списка
  head = (list*)malloc(sizeof(list));
  head->field = (char*)malloc(sizeof(char) * strlen(a));
  head->field = strcpy(head -> field , a);
  head->ptr = NULL; // это последний узел списка
  return(head);
}

void printLinkedList(const list *head) {
    while(head) {
        printf("%s", head ->field);
        head = head -> ptr;
        printf("\n");
    }
}

void push(list **head, char* data) {
    list *tmp = (list*) malloc(sizeof(list)); // БЕРЕТСЯ ** ПОТОМУ ЧТО НАМ НУЖЕН АДРЕС ГОЛОВЫ СПИСКА Присваиваем указателю tmp адрес предыдущего узла, Присваиваем указателю head адрес нового узла
    tmp->field = (char*)malloc(sizeof(char) * strlen(data));
    tmp->field = data;
    tmp->ptr = (*head);
    (*head) = tmp;
}

int main()
{
    list *y;
    y = init("kol");
    push(&y,"ioi");// PUSH PEREDELAI
    push(&y,"132");
    printLinkedList(y);


    return 0;
}
