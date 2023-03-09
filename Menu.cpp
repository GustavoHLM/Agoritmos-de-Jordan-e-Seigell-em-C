#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXTAM 16 

int erro(long double matriz[MAXTAM][MAXTAM], int tam){
	int i, j, k,l;
	long double m;
	int pivo = 0;
	long double soma = 0;
	long double solucoes[MAXTAM];
	int cont;

	for(i=0;i<tam;i++){
		for(k=0;k<tam;k++){
			soma = 0;
			cont = 0;
			for(l=0;l<tam;l++){
				soma += matriz[k][l];
				if(matriz[k][l] != 0){
					cont ++;
				}
			}
			if(soma == 0 && matriz[k][l] != 0 && cont == 0){
				printf("\n--->Sistema Impossivel<---\n\n");
				return 1;
			}else if(soma == 0 && matriz[k][l] == 0 && cont == 0){
				printf("\n--->Sistema Possivel Indeterminado<---\n\n");
				return 1;
			}
		}
	}
	return 0;
}	

void Exibe(long double matriz[MAXTAM][MAXTAM], int tam){
	int i, j;
	for(i=0;i<tam;i++){
		for(j=0;j<=tam;j++){
			__mingw_printf(" %Lf ", matriz[i][j]);
		}
		printf("\n");
	}
}

void Pivotar(long double matriz[MAXTAM][MAXTAM], int tam, int pivo){
	int i,j;
	long double aux, maior;

	maior = matriz[pivo][pivo];

	// Realiza a Busca do Pivô
	for(i = pivo+1; i < tam; i++){
		if(fabs(maior) < fabs(matriz[i][pivo])){ // Fabs corrige erros de numeros muito grandes, comumente chamado de sobrecarga
			maior = matriz[i][pivo];
		}
	}

	//Caso Nescessite Trocar a linha pivo
	if(fabs(maior) != fabs(matriz[pivo][pivo])){ // Fabs corrige erros de numeros muito grandes, comumente chamado de sobrecarga
		for(i = pivo+1; i < tam; i++){
			if(fabs(maior) == fabs(matriz[i][pivo])){
				for(j=0; j<tam+1; j++){
					aux = matriz[pivo][j];
					matriz[pivo][j] = matriz[i][j];
					matriz[i][j] = aux;
				}
				
			}
		}
	}
}

#include"leitura.hpp"//Biblioteca para leitura do arquivo
#include "pivotamentoCompleto.hpp"
#include"seigell.hpp"//Biblioteca do metodo de Seigell
#include"jordan.hpp"//Biblioteca do metodo de Jordan

main(){
	int metodo=111;

	do{
		system("cls");
		printf("||Metodo Jordan--> Aperte J");
		printf("\n||Metodo Seidel--> Aperte S");
		printf("\nComando:");
		fflush(stdin);
		scanf("%c", &metodo);
		if(metodo=='J' || metodo=='j'){
			menu_jordan();
		}
		else if(metodo=='S' || metodo=='s'){
			menu_seigell();
		}else{
			printf("\n\n-->Digite apenas os comando acima\n\n\n");
			system("pause");
			continue;
		}
		
	}while(1);
}
