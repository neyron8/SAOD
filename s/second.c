int hashtab_coll(hash_table *hashtab)
{
	int index;
	node *hashnode;
	int count = 0, col = 0;
	for (count;count < SIZE;){
		for (hashnode = hashtab -> list[count]; hashnode != NULL;hashnode = hashnode -> next) {	
					col++;
		}
		count++;
 		col--;
	}
			
	return col;
}

int hashtab_coll(hash_table *hashtab);

