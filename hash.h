#ifndef __HASH__
#define __HASH__

typedef struct _hash_entry{
	void *key;
	void *item;
	struct _hash_entry *next;
} hash_entry;

typedef struct _hash_table{
	unsigned int size;
	unsigned int items;
	hash_entry **store;

	hash_entry *cur;
	unsigned int where;
	
	long int (*hash_fun)(void *);
	int (*key_cmp)(void *, void *);
	void (*free_fun)(void *);
} hash_table;


hash_table *create_hash_table(int size, 
			     long int (*hashfn)(void *), 
			     int (*keyfn)(void *, void*),
			     void (*freefn)(void *)
);

int destroy_hash_table(hash_table *table);

hash_entry *hash_get(hash_table *table, void* key);
int hash_add(hash_table *table, void* key, void *item);
int hash_delete(hash_table *table, void *key);
void hash_start_iterator(hash_table *table);
hash_entry *hash_get_next(hash_table *table);


//HASH & KEY_CMP
long int __inline__ hash_fn_int(void *key);
int __inline__ cmp_fn_int(void *key1, void *key2);

long int __inline__ hash_fn_str(void *key);
int __inline__ cmp_fn_str(void *key1, void *key2);
#endif