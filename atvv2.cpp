#include <stdio.h>
#include <string.h>
#include <math.h>

int reservarLugar(){
	int linhas, colunas;
	int lugares[25];
	printf("Lugares disponiveis sao representados com O e ocupados com X\n");
	
	int ocp{};
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if (ocp=1){
				printf("X");
			}
			else{
				printf("O");
			}
		}printf("\n");
	}
	
	printf("Escolha seu lugar: \n");
	
	printf("Colunas: ");
	scanf("%i", &colunas);
	
	printf("Linhas: ");
	scanf("%i", &linhas);
	
    return 0;
}

int menu(){
	int op;
	printf("=------------------------=\n");
	printf("Selecione as opcoes abaixo\n");
	printf("=------------------------=\n");
	printf("1- Reservar lugar\n");
	printf("2- Ver bilhete\n");
	printf("3- Cancelar\n");
	printf("4- Sair\n");
	printf("=------------------------=\n");
	scanf("%i", &op);
	switch(op){
		case 1:
			reservarLugar();
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		
	}
	
}


int main(){

	menu();
	
}