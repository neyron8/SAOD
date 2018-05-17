#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int size;
	int apex;

} heapnode;

typedef struct {

	int nnodes;
	int maxsize;
	heapnode *nodes;


} heap;

heap *heap_create(int maxsize)
{
	heap *h;

	h = malloc(sizeof(heap));
	if (h != NULL) {
		h->maxsize = maxsize;
		h->nnodes = 0;
		h->nodes = malloc(sizeof(heapnode) * (maxsize + 1));
		if (h->nodes == NULL) {
			free(h);
			return NULL;
		}
	}

	return h;
}

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

void heap_heapify(heap *h, int index)
{
	for (;;) {
		int left = 2 * index;
		int right = 2 * index + 1;
		int smallest = index;
		if (left <= h->nnodes && h->nodes[left].size < h->nodes[index].size ) {
			smallest = left;
		}
		if (right <= h->nnodes && h->nodes[right].size < h->nodes[smallest].size) {
			smallest = right;
		}
		if (smallest == index) {
			break;
		}
		heap_swap(&h->nodes[index], &h->nodes[smallest]);
		index = smallest;
	}
}

heapnode heap_extract_min(heap *h)
{
	if (h->nnodes == 0) {
		return;
	}
	heapnode minnode = h->nodes[1];
	h->nodes[1] = h->nodes[h->nnodes];
	h->nnodes--;
	heap_heapify(h, 1);
	return minnode;
}

int get_num (heap *h, int index)
{
	int i = 1;
	for (i; i < 21; i++){
		if (h->nodes[i].apex == index){
			break;
		}	
	}
	return i;
}

int heap_decrease_key(heap *h, int index, int size)
{
	if (h->nodes[index].size < size) {
		return -1;
	}
	h->nodes[index].size = size;

	for (; index > 1 && h->nodes[index].size < h->nodes[index / 2].size; index = index / 2) {
		heap_swap(&h->nodes[index], &h->nodes[index / 2]);
  	}

	return index;
}

void deikstra()
{
    FILE *in;
	int j,k,temp,i,minindex,min,n,count;
    in = fopen ( "matrix.txt", "rt");
	int matrix[21][21];
	for (i = 1; i < 21; i++) {
		for (j = 1; j < 21; j++) {
			fscanf(in, "%d", &matrix[i][j]);
		}
	}
	int metka[21]; 
	int path[21];
	for (i = 1; i < 21; i++) {
		path[i] = 0;
	}
	heap *structure;
	structure = heap_create(20);
	for (k = 1; k < 21; k++){
		heap_insert(structure, 90000, k);
		metka[k] = 1;
	}
	for (k = 1; k < 21; k++){
		if (structure -> nodes[k].apex == 1){
			structure -> nodes[k].size = 0;
			break;   
		}
	}  

    while (1) {
     
		heap_heapify(structure, 1);
        minindex = 90000;
        min = 90000;
		if ((metka[structure -> nodes[1].apex] == 1) ) {
			printf(" SIZE %d to %d\n",structure -> nodes[1].size,structure -> nodes[1].apex);
			min = structure -> nodes[1].size;
			minindex = structure -> nodes[1].apex;
			heap_extract_min(structure);
		}
        
        if (minindex != 90000) {
            for (i = 1; i < 21; i++) {
                if (matrix[minindex][i] > 0 && metka[i] != 0) {
                    temp = min + matrix[minindex][i];
					n = get_num(structure, i);
                    if (temp < structure -> nodes[n].size){
                    	heap_decrease_key(structure,n, temp);
						path[structure -> nodes[n].apex] = structure -> nodes[minindex].apex;
					}
                }
            }
            metka[minindex] = 0;
        }

		count = 0;
		for (n = 1; n < 21; n++){
			if (metka[n] == 0){
				count++;
			}
		}

		if (count == 20) {
			for (k = 1; k < 21; k++){
				printf("%d ", path[k]);
			}
			break;
		}

    }

}

int main()
{		
	deikstra();
	
	return 0;
}
