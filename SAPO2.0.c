#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int i, j, count1, count2, count3;
int LimitarMovimento(int x, int y, char movimento){
	if((x==0 && (movimento=='W' || movimento=='E' || movimento=='Q' )) || (x==9 && (movimento=='S' || movimento=='C' || movimento=='Z' )) || (y == 0 && (movimento=='A' || movimento=='Q' || movimento=='Z' )) || (y == 9 && (movimento=='D' || movimento=='E' || movimento=='C'))){
		return 1;
	}
}
void PreencherMatriz(char matriz[10][10]){
	int x, y;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			matriz[i][j] = ' ';
			if(i==0 && (j % 2 == 0)){
				matriz[i][j] = 'A';
			}else if(i==9 && (j % 2 == 0)){
				matriz[i][j] = 'V';
			}
		}
	}
	srand(time(NULL));
	for (i=0; i < 10; i++)
	{
		x = 1+ (rand() % 8);
		y = 1+ (rand() % 8);
		matriz[x][y] = 'X';
	}
}
void ImprimirMatriz(char matriz[10][10]){
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<10;i++){
		printf("%d ", i);
		for(j=0;j<10;j++){
			if(matriz[i][j] == 'X'){
				printf(" |");
			}else if(matriz[i][j] == 'P'){
				printf("A|");	
			}else if(matriz[i][j] == 'p'){
				printf("V|");		
			}else if(matriz[i][j] == 'W' && i == 9){
				printf("A|");
			}else if(matriz[i][j] == 'W' && i == 0){
				printf("V|");
			}else{
				printf("%c|" ,matriz[i][j]);
			}	
		}
		printf("\n");
	}
}
void movimentar(int player, int x, int y, char movimento, char matriz[10][10]){
	if(movimento == 'W'){
		if(matriz[x-1][y] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x-1][y] != 'A' && matriz[x-1][y] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y] = 'A';
		}else if(player == 0 && matriz[x-1][y] != 'V' && matriz[x-1][y] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'S'){
		if(matriz[x+1][y] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x+1][y] != 'A' && matriz[x+1][y] != 'W'){
			matriz[x][y] = ' ';
			matriz[x+1][y] = 'A';
		}else if(player == 0 && matriz[x+1][y] != 'V' && matriz[x+1][y] != 'W'){
			matriz[x][y] = ' ';
			matriz[x+1][y] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'A'){
		if(matriz[x][y-1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x][y-1] != 'A' && matriz[x][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x][y-1] = 'A';
		}else if(player == 0 && matriz[x][y-1] != 'V' && matriz[x][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x][y-1]= 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'D'){
		if(matriz[x][y+1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x][y+1] != 'A' && matriz[x][y+1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x][y+1] = 'A';
		}else if(player == 0 && matriz[x][y+1] != 'V' && matriz[x][y+1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x][y+1] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'Q'){
		if(matriz[x-1][y-1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x-1][y-1] != 'A' && matriz[x-1][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y-1] = 'A';
		}else if(player == 0 && matriz[x-1][y-1] != 'V' && matriz[x-1][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y-1] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'E'){
		if(matriz[x-1][y+1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x-1][y+1] != 'A' && matriz[x-1][y+1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y+1] = 'A';
		}else if(player == 0 && matriz[x-1][y+1] != 'V' && matriz[x-1][y+1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x-1][y+1] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'Z'){
		if(matriz[x+1][y-1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && matriz[x+1][y-1] != 'A' && matriz[x+1][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x+1][y-1] = 'A';
		}else if(player == 0 && matriz[x+1][y-1] != 'V' && matriz[x+1][y-1] != 'W'){
			matriz[x][y] = ' ';
			matriz[x+1][y-1] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else if(movimento == 'C'){
		if(matriz[x+1][y+1] == 'X'){
			matriz[x][y] = ' ';
			printf("Sapo foi de base");
			sleep(1);
		}else if(player == 1 && (matriz[x+1][y+1] != 'A' && matriz[x+1][y+1] != 'W')){
			matriz[x][y] = ' ';
			matriz[x+1][y+1] = 'A';
		}else if(player == 0 && (matriz[x+1][y+1] != 'V' && matriz[x+1][y+1] != 'W')){
			matriz[x][y] = ' ';
			matriz[x+1][y+1] = 'V';
		}else{
			printf("Perdeu a vez");
			sleep(1);
		}
	}else{
		printf("Perdeu a vez");
	}
	system("cls");
	ImprimirMatriz(matriz);
}
int PrenderSapo(int player, int x, int y, char matriz[10][10]){
	if(player == 1 && (matriz[x][y] == 'A' || matriz[x][y] == 'P')){
		if((matriz[x-1][y] == 'V' || matriz[x-1][y] == 'p') || ((matriz[x-1][y-1] == 'V' && y-1>=0) || (matriz[x-1][y-1] == 'p' && y-1>=0)) || ((matriz[x-1][y+1] == 'V' && y+1<10) || (matriz[x-1][y+1] == 'p' && y+1<10)) || (matriz[x+1][y] == 'V' || matriz[x+1][y] == 'p') || ((matriz[x+1][y-1] == 'V' && y-1>=0)  || (matriz[x+1][y-1] == 'p' && y-1>=0)) || ((matriz[x+1][y+1] == 'V' && y+1<10) || (matriz[x+1][y+1] == 'p' && y+1<10)) || ((matriz[x][y-1] == 'V' && y-1>=0) || (matriz[x][y-1] == 'p' && y-1>=0)) || ((matriz[x][y+1] == 'V' && y+1<10) || (matriz[x][y+1] == 'p' && y+1<10))){
			matriz[x][y] = 'P';
			return 1;	
		}
	}else if(player == 0 && (matriz[x][y] == 'V' || matriz[x][y] == 'p')){
		if((matriz[x-1][y] == 'A' || matriz[x-1][y] == 'P') || ((matriz[x-1][y-1] == 'A' && y-1>=0) || (matriz[x-1][y-1] == 'P' && y-1>=0)) || ((matriz[x-1][y+1] == 'A' && y+1<10) || (matriz[x-1][y+1] == 'P' && y+1<10)) || (matriz[x+1][y] == 'A' || matriz[x+1][y] == 'P') || ((matriz[x+1][y-1] == 'A' && y-1>=0)  || (matriz[x+1][y-1] == 'P' && y-1>=0)) || ((matriz[x+1][y+1] == 'A' && y+1<10) || (matriz[x+1][y+1] == 'P' && y+1<10)) || ((matriz[x][y-1] == 'A' && y-1>=0) || (matriz[x][y-1] == 'P' && y-1>=0)) || ((matriz[x][y+1] == 'A' && y+1<10) || (matriz[x][y+1] == 'P' && y+1<10))){
				matriz[x][y] = 'p';
				return 1;
	}else{
		return 0;
		}
	}
}
void Vitoria(int *terminaJogo, char matriz[10][10]){
	count1=0;
	count2=0; 
	count3=0;
	for(i=0;i<10;i++){
		if(matriz[9][i] == 'A'){
			matriz[9][i] = 'W';
		}
		if(matriz[0][i] == 'V'){
			matriz[0][i] = 'W';
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(matriz[i][j] == 'V' || matriz[i][j] == 'A'){
				count1++;
			}	
		}
	}
	for(i=0;i<10;i++){
		if(matriz[9][i] == 'W'){
			count2++;
		}
		if(matriz[0][i] == 'W'){
			count3++;
		}
	}
	if(count1 == 0){
		*terminaJogo = 1;
		if(count2>count3){
			system("cls");
			printf("SAPO AZUL VENCEU!!!\n");
		}else if(count3>count2){
			system("cls");
			printf("SAPO VERMELHO VENCEU!!!\n");
		}else{
			system("cls");
			printf("EMPATE!!\n");
			}
	}
}

int main(){
	char matriz[10][10], movimento;
	int terminaJogo = 0 , player = 1, x, y;
	PreencherMatriz(matriz);
	ImprimirMatriz(matriz);
	while(terminaJogo == 0){
		if (player == 1){
			printf("\nEscolha o Sapo Azul que voce quer movimentar\n");
			printf("Linha: ");
			scanf("%d",&x);
			fflush(stdin);
			printf("Coluna: ");
			scanf("%d",&y);
			fflush(stdin);
			if(PrenderSapo(player, x, y, matriz) == 1){
				printf("Sapo Preso\n");
			}else if(matriz[x][y] == 'A' && x>=0 && x<10 && y>=0 && y<10){
				printf("Deseja mover para CIMA(W), BAIXO(S), ESQUERDA(A), DIREITA(D), DIAGONAIS SUPERIORES(Q ou E) ou INFERIORES(Z ou C)? ");
				scanf(" %c",&movimento);
				fflush(stdin);
				if(LimitarMovimento(x, y, movimento) == 1){
					printf("Perdeu a vez");
				}else{
					movimentar(player, x, y, movimento, matriz);
				}
			}else{		
				printf("Perdeu a vez!");
			}
			player = 0;
			Vitoria(&terminaJogo, matriz);
		}else{
			printf("\nEscolha o Sapo Vermelho que voce quer movimentar\n");
			printf("Linha: ");
			scanf("%d",&x);
			fflush(stdin);
			printf("Coluna: ");
			scanf("%d",&y);
			fflush(stdin);
			if(PrenderSapo(player, x, y, matriz) == 1){
				printf("Sapo Preso\n");
			}else if(matriz[x][y] == 'V' && x>=0 && x<10 && y>=0 && y<10){
				printf("Deseja mover para CIMA(W), BAIXO(S), ESQUERDA(A), DIREITA(D), DIAGONAIS SUPERIORES(Q ou E) ou INFERIORES(Z ou C)? ");
				scanf(" %c",&movimento);
				fflush(stdin);
				if(LimitarMovimento(x, y, movimento) == 1){
					printf("Perdeu a vez");
				}
				else{
					movimentar(player, x, y, movimento, matriz);
				}
			}else{
				printf("Perdeu a vez!");
			}
			Vitoria(&terminaJogo, matriz);
			player = 1;
		}
		
	}
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<10;i++){
		printf("%d ", i);
		for(j=0;j<10;j++){
			if(matriz[i][j] == 'P'){
				printf("A|");	
			}else if(matriz[i][j] == 'p'){
				printf("V|");		
			}else if(matriz[i][j] == 'W' && i == 9){
				printf("A|");
			}else if(matriz[i][j] == 'W' && i == 0){
				printf("V|");
			}else{
				printf("%c|" ,matriz[i][j]);
			}	
		}
		printf("\n");
	}
}
