#include <stdio.h>
#include <string.h>
#include <math.h>

int menu(){
	int op;
	printf("=------------------------=");
	printf("Selecione as opcoes abaixo");
	printf("=------------------------=");
	printf("1- Reservar lugar");
	printf("2- Ver bilhete");
	printf("3- Cancelar");
	printf("4- Sair");
	printf("=-========================");
	
	switch(op){
		case 1:
			reservarLugar;
			break;
		case 2:
			fun2
			break;
		case 3:
			fun3
			break;
		case 4:
			fun4
			break;
		default:
			printf("digite uma opcao valida");
			return 0;
	}
	
}

int reservarLugar(){
	int linhas, colunas;
	int lugares[25];
	printf("Lugares disponiveis sao representados com O e ocupados com X");
	
	
	
	for(int i=0;i<5;i++;){
		for(int j=0;j<5;j++;){
			if (ocp=1){
				printf("X");
			}
			else{
				printf("O");
			}
		}
	}
	
	printf("Escolha seu lugar: \n");
	
	printf("Colunas: ");
	scanf("%i", &colunas);
	
	printf("Linhas: ");
	scanf("%i", &linhas);
	
	
}


int main(){
	
	
	
}
