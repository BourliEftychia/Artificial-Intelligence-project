//eftycho
#include <stdio.h>
#include <stdlib.h>

#define SIZE 2000 // TODO

int extensions = 0;

struct node {
	int *numbers;
	struct node* parent;
	int cost;
};

struct queue {
  struct node* items[2000];
  int start;
  int end;
};

// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->start = -1;
  q->end = -1;
  return q;
}

// Create a node
struct node* createNode(int N) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->numbers = (int *) malloc(N*sizeof(int));
	return new_node;
}

// Check if the queue is empty
int isEmpty(struct queue* q){
  if (q->end == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void add_queue(struct queue* q, struct node* value){
  if (q->end == SIZE - 1)
    printf("\nQueue is Full!!\n");
  else {
    if (q->start == -1)
      q->start = 0;
    q->end++;
    q->items[q->end] = value;
  }
}

// Removing elements from queue
struct node* delete_queue(struct queue* q){
  struct node* item;
  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    item = q->items[q->start];
    q->start++;
    if (q->start > q->end) {
      q->start = q->end = -1;
    }
  }
  return item;
}

// Swap elements
struct node* swaper(int N,int T, struct node* n){ 
	int *start, *end, temp, i;
	struct node* child = createNode(N);
    for(i=0; i<N; i++){
		child->numbers[i] = *(n->numbers+i);
	}
	start = &child->numbers[0];
	end = &child->numbers[T-1];
	while(start<end){
		temp = *start;  
		*start = *end;
		*end = temp; 
		start++;
		end--;
	}
	child->parent = n;
	child->cost = child->parent->cost + 1;
	extensions += 1;
	return child;
}

// Create children
void create_children(int N,struct node* n, struct node** children){
	int position = 0;
	
	for (int t=2; t<=N; t++){
		children[position] = swaper(N,t,n);
		position++;
	}
}

// Check
int checker(int N,int *TK,struct node* n){
	int i;
	for(i=0; i<N; i++){
		if(TK[i] != n->numbers[i]){
			return 0;
		}
	}
	return 1;
}

// Create path
struct node** create_path(int N, struct node* last, struct node** path, int position){
	if (last->parent == NULL){
		path[position] = last;
		return path;
	}
	else{
		path = create_path(N, last->parent, path, position+1);
		path[position] = last;
		return path;
	}
}

// Informations: Path, cost, extentions
void information(int N, struct node* n){
	struct node* path[n->cost+1];
	create_path(N, n, path, 0);
	printf("Cost: %d\n", n->cost);
	printf("Path: ");
	for(int i=n->cost; i>=0; i--){
		for(int j=0; j<N; j++){
			printf("%d", path[i]->numbers[j]);
		}
		if(i!= 0)
			printf(" -> ");
	}
	printf("\n");
	printf("Extensions: %d\n", extensions);
}

// BFS (All costs = 1)  
int ucs(int N,struct node* AK,int *TK){
	struct queue* q = createQueue();
	struct node* n;
	add_queue(q,AK);
	while (!isEmpty(q)) {
		n =delete_queue(q);
		if(checker(N,TK,n)==1){
			printf("Found it!\n");
			information(N, n);
			return 1;
		}else{
			struct node* children[N-1];
			create_children(N,n,children);
			for(int i=0; i<N-1; i++){
				add_queue(q,children[i]);
			}
		}
	}
	printf("Didn't found it!\n");
	return 0;
}

int main(int argc,char *argv[]){
	int *TK,N,i,j,x;
	int *AK; // AK
	
	// Check
	if (argc != 2){	
		printf("Wrong!\n");
		return 1;
	}
	
	// Size of array
	N = atoi(argv[1]);  
	printf("The number of elements is: %d\n",N);
	//Input
	AK = (int*) malloc(N*sizeof(int ));          
	for(i=0; i<N; i++){
		printf("Give number:  ");
		scanf(" %d",&AK[i]);
		if (AK[i]<1 || AK[i]>N){// Check
			printf("Wrong!\n");
			return 1;
		}
	}
	// Create final situation
	TK = (int *) malloc(N*sizeof(int )); 
	for(j=0; j<N; j++){
		TK[j] = j+1;
	}
	// Create root
	struct node* AK_node = createNode(N);
	for(i=0; i<N; i++){
		AK_node->numbers[i] = AK[i];
	}
	AK_node->parent = NULL;
	AK_node->cost = 0;
	
	// Call ucs algorithm
	ucs(N,AK_node,TK);

	free(AK);
	return 0;
}
