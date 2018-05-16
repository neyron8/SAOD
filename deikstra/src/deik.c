
void heap_swap(heapnode *a, heapnode *b)
{

	heapnode temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int heap_insert(heap *h, int size, int apex)
{
	if (h->nnodes >= h->maxsize) {
		return -1;
	}
	h->nnodes++;
	h->nodes[h->nnodes].size = size;
	h->nodes[h->nnodes].apex = apex;

	for (int i = h->nnodes; i > 1 && h->nodes[i].size < h->nodes[i / 2].size; i = i / 2) {
		heap_swap(&h->nodes[i], &h->nodes[i / 2]);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  int size;
  int apex;

} D;

typedef struct {

  int nnodes;
  int maxsize;
  struct D **nodes;
  int metka;

} heap;

heap *heap_create(int maxsize) {
  heap *h;
  h = malloc(sizeof(heap));
  if (h != NULL) {
    h->maxsize = maxsize;
    h->nnodes = 0;
    h->nodes = malloc(sizeof(int) * (maxsize + 1));
    if (h->nodes == NULL) {
      free(h);
      return NULL;
    }
  }
  return h;
}

void heap_swap(D *a, D *b) {
  D temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int heap_insert(heap *h, int size, int apex) {
  if (h->nnodes >= h->maxsize) {
    return -1;
  }
  h->nnodes++;
  h->nodes[h->nnodes].size = size;
  h->nodes[h->nnodes].apex = apex;

  for (int i = h->nnodes; i > 1 && h->nodes[i].size < h->nodes[i / 2].size;
       i = i / 2) {

    heap_swap(&h->nodes[i], &h->nodes[i / 2]);
  }
  return 0;
}

D heap_extract_min(heap *h) {
  if (h->nnodes == 0) {
    return NULL;
  }
  D minnode = h->nodes[1];
  h->nodes[1] = h->nodes[h->nnodes];
  h->nnodes--;
  heap_heapify(h, 1);
  return minnode;
}

int heap_decrease_key(heap *h, int index, int size) {
  if (h->nodes[index].size < size)
    return -1;
  h->nodes[index].size = size;
  for (; index > 1 && h->nodes[index].size > h->nodes[index / 2].size;
       index = index / 2) {
    heap_swap(&h->nodes[index], &h->nodes[index / 2]);
  }
  return index;
}

void heap_heapify(heap *h, int index) {
  for (;;) {
    int left = 2 * index;
    int right = 2 * index + 1;
    // Find largest key: A[index], A[left] and A[right]
    int smallest = index;
    if (left <= h->nnodes && h->nodes[left].size < h->nodes[index].size) {
      smallest = left;
    }
    if (right <= h->nnodes && h->nodes[right].size < h->nodes[smallest].size) {
      smallest = right;
    }
    if (smallest == index) {
      break;
    }

    heap_swap(&h->nodes[index], &h->nodes[largest]);
    index = largest;
  }
}

int main() {
  heap *test;
  test = heap_create(5);
  test->nnodes = 1;
  printf("%d", test->nnodes);
  test->nodes = malloc(sizeof(int) * 5);
  test->nodes[test->nnodes] = 123;
  printf("%d\n", test->nodes[test->nnodes]);

  return 0;
}
