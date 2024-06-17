//MinMax Game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct player{
	int M;
	int N;
};

int isnotXorA(char c){
	if(!((c == 'X') || (c == 'A') || (c == 'B'))){
		return 1;
	}
	return 0;
}

int can_move(int m,int n,int M,int N,char *Array,struct player* playerB){

	if(isnotXorA(*(Array + playerB->M*n + playerB->N+1))
	|| isnotXorA(*(Array + playerB->M*n + playerB->N-1))
	|| isnotXorA(*(Array + (playerB->M+1)*n + playerB->N+1))
	|| isnotXorA(*(Array + (playerB->M+1)*n + playerB->N))
	|| isnotXorA(*(Array + (playerB->M+1)*n + playerB->N-1))
	|| isnotXorA(*(Array + (playerB->M-1)*n + playerB->N+1))
	|| isnotXorA(*(Array + (playerB->M-1)*n + playerB->N))
	|| isnotXorA(*(Array + (playerB->M-1)*n + playerB->N-1))) {
		return 1;
	}
	return 0;
}

int check_input(int m,int n,int new_M,int new_N,char *Array,struct player* playerB){
	if((playerB->M == new_M) && ((playerB->N == new_N+1) || (playerB->N == new_N-1))
	|| (((playerB->M == new_M+1) || (playerB->M == new_M-1)) && ((playerB->N == new_N) || (playerB->N == new_N+1) || (playerB->N == new_N-1)))){
		return isnotXorA(*(Array + new_M*n + new_N));
	}
	return 0;
}

void update_Array(int m,int n,int M,int N,int new_M,int new_N,char *Array,struct player* playerB){
	int i,j;
	
	playerB->M = new_M;
	playerB->N = new_N;
	
	*(Array +N + M*m)='X';
	*(Array +new_N + new_M*m)='B';
	
	printf("\n");	
	for (i = 0; i <  m; i++){
		for (j = 0; j < n; j++){
			printf("%c ", *(Array + i*n + j));
		}
		printf("\n");
	}
	printf("\n");	
}


/*

struct node** children(){
	int position = 0;
	if(isnotXorA(*(Array + (playerA->M)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M+1)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N+1)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N)==1){
		children[position] = make_child;
		position++;
	}else if(isnotXorA(*(Array + (playerA->M-1)*(playerA->N) + playerA->N-1)==1){
		children[position] = make_child;
		position++;
	}
}


void start_tree(int m,int n,struct player* playerA,struct player* playerB,char *Array){
	struct node* root =  malloc(sizeof(struct node));
}
	


void tree

	
void Max(int m,int n,struct player* playerA,char *Array){
	
}	
*/
void Min(int m,int n,struct player* playerB,char *Array){
	int M,N,new_M,new_N;
	
	M = playerB->M;
	N = playerB->N;
	
	if(can_move(m,n,M,N,Array,playerB)==1){
		printf("Your turn. Give directions.\n");
		
		printf("Give M :");
		scanf("%d",&new_M);
		printf("Give N :");
		scanf("%d",&new_N);
		printf("\n");
		
		while(check_input(m,n,new_M,new_N,Array,playerB)==0){
			printf("Wrong directions.\n");
			printf("Try again.\n");
			printf("Give M :");
			scanf("%d",&new_M);
			printf("Give N :");
			scanf("%d",&new_N);
			printf("\n");
		}
		update_Array(m,n,M,N,new_M,new_N,Array,playerB);
	}else{
		printf("Player 1 Lost!");
		printf("PLAYER 2 WIN THE GAME!!!\n");
		exit(1);
	}
}

int main(int argc,char *argv[]){
	int m,n,M,N,i,j;
	
	m = atoi(argv[1]);  
	n = atoi(argv[2]); 
	
	char *Array = malloc(m*n*sizeof(char));
	
	for (i = 0; i <  m; i++){
		for (j = 0; j < n; j++){
			strcpy((Array + i*n + j),"0");
		}
	}	
	
	printf("\n");

	struct player* playerA =  malloc(sizeof(struct player));
	playerA-> M = 0;
	playerA-> N = (int)(n/2);
	
	struct player* playerB =  malloc(sizeof(struct player));
	playerB-> M = m-1;
	playerB-> N = (int)(n/2);
	
	*(Array + 0*n + (int)(n/2))='A';
	*(Array +(m-1)*n + (int)(n/2))='B';
	

	for (i = 0; i <  m; i++){
		for (j = 0; j < n; j++){
			printf("%c ", *(Array + i*n + j));
		}
		printf("\n");
	}
	
	printf("\n");
	
	while(1){
		Min(m,n,playerB,Array);
		//Max();
	}
	
}
