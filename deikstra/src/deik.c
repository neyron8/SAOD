#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

	int value;
	int apex;

} D;

D *init (D *array, int size){
	int i = 0;
	for (i; i < size; i++){
		array[i].value = i;
		array[i].apex = i;
	}
	return array;	
}

void swap(D * array, int i, int j)
{
	D tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
 
void heap_it(D *array, int length, int root)
{

    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int biggest = root;
    
    if ( left < length && array[root].value < array[left].value )
        biggest = left;
    if ( right < length && array[biggest].value < array[right].value )
        biggest = right;
    if ( biggest != root ) {
        swap(array, biggest, root);
        heap_it(array, length, biggest);
    }
}
 
void make_heap(D * array, int length)
{

    int i = length / 2 - 1;
 
    for ( ; i >= 0; --i )
        heap_it(array, length, i);
}

void heap_sort(D * array, int elements)
{

    int end;
    
    make_heap(array, elements);
    for ( end = elements - 1; end > 0; --end ) {
        swap(array, 0, end);
        heap_it(array, end, 0);
    }
}

void add_to_array(D *array, int versh, int size, int path)
{
	int i = 0;
	for (i = 0; i < size ; i ++){
		if (array[i].apex == versh) {
			printf("DSDSD");
			array[i].value = path;
		}
	}
}
	
int main()
{
	int i = 0;
	D *test = malloc (sizeof(D)*5);
	test = init (test,5);
	for (i = 0; i < 5; i++){
		printf("%d\n", test[i].value);
	}
	//heap_sort(test, 5);
	printf("razdel");
	swap(test, 0,1);
	for (i = 0; i < 5; i++){
		printf("%d\n", test[i].value);
	}
	return 0;
}
