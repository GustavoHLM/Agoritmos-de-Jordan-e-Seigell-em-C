#ifndef SEIGELL_HPP
#define SEIGELL_HPP

void formula(long double matriz[MAXTAM][MAXTAM], int tam, int k, long double resp[]){
	long double chute[tam]={-1};
	int aux;
	long double re;
	printf("\n\n-----> Formulas para as operacoes <-----\n\n");
	for(int i=0; i<tam; i++){
		re = resp[i];
		for(int j=0, v=0; j<tam; j++){
			if(j!=i){
				re -= matriz[i][j]*chute[j];
				if(v==0){
					__mingw_printf("\nX[%d]: %Lf-= %d * %d/",i, re, matriz[i][j], chute[j]);
					__mingw_printf("%d", matriz[i][i]);
					v=1;
				}
			}
			aux=i;		
		}
		re /= matriz[aux][aux];
		chute[i]=re;
	}
	printf("\n\n");
}

void conv(long double matriz[MAXTAM][MAXTAM], int tam){
	int i,j;
	long double vetor[MAXTAM]={0};
	
	printf("\n\n Betas encontrados\n\n");
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(i!=j){
				if(vetor[j]!=0){
	 			vetor[i]+= fabs(matriz[i][j])* fabs(vetor[j]);
				}else{
					vetor[i]+= fabs(matriz[i][j]);
				}
			}
		}
	
		if(matriz[i][i]!=0){
			vetor[i]=(vetor[i]/matriz[i][i]);
		}
		__mingw_printf(" X: %Lf",vetor[i]);
	}	
	for(i=0;i<tam;i++){
		if(vetor[i]>1){
		printf("\n --->Nao converge\n");
		return;
		}
	}
	printf("\n --->Converge\n");
}

void seidel(long double matriz[MAXTAM][MAXTAM], int tam, int k, double dist){
	long double resp[tam], chute[tam]={-1};
	int aux, cont, control=0, form=0;
	long double re;
	
	for(int i=0; i<tam; i++){//Distribuir as respostas em um vetor
		resp[i]=matriz[i][tam];
	}
	
	formula(matriz, tam, k, resp);
	
	printf("----> Solucoes do K\n\n");
	for(int l=0; l<k; l++){
		for(int i=0; i<tam; i++){
			re = resp[i];
			for(int j=0; j<tam; j++){
				if(j!=i){
					re -= matriz[i][j]*chute[j];
				}
				aux=i;		
			}
	
			re /= matriz[aux][aux];
			
			if(re>-0.01 && re<0.1){////Trato numeros muito pequenos
				re=0;
			}	
			
			if((re-chute[i])<dist){
				cont++;
			}else{
				cont=0;
			}
		
			__mingw_printf("\nx%d, %d interacao: %Lf ",i,l, re);
			chute[i]=re;
			
			if(cont==tam){///Quando atinge o valor nescessario cria a flag 1
				control=1;
			}
			if(control==1 && i==tam){///Faz o programa finalizar apenas na ultima inserção do I
				return;
			}
		}
		printf("\n\n");
	}
}

void menu_seigell(){
	long double matriz[MAXTAM][MAXTAM];
	FILE *file;
	int tam, i, k;
	double dist;
	char questao[2]={','};

	do{
		file = fopen("inputs.txt", "r");
		system("cls");
		if(file==NULL){
			printf("\n Problemas na abertura do arquivo");
			break;
		}else{
			printf("\n||Qual a questao que voce deseja resolver(3 ao 15), aperte 0 para sair: ");
			fflush(stdin);
			scanf("%s", &questao);
			if(questao[0]=='0'){
				break;
			}

			if(atoi(questao)>15 || atoi(questao)<3){
				printf("\n\n||So eh aceito as questoes do 3 ao 15...\n\n\n");
				system("pause");
				continue;
			}
			
			printf("\n||Qual a quantidade de iteracoes sera utilizada(k): ");
			scanf("%d", &k);
			printf(" \n\n||Qual a distancia minima a ser empregada: ");
			scanf("%lf", &dist);

			tam = Ler_Arquivo(matriz, file, questao);
			
			conv(matriz, tam);
			
			printf("\n---> Matriz:\n\n");
			Exibe(matriz,tam);
			printf("\n");
			
			PivotarCompleto(matriz, tam);
			
			printf("\nMatriz Apos o pivotamento:\n");
			Exibe(matriz,tam);
			printf("\n");
			
			if(erro(matriz, tam)==0){
				seidel(matriz, tam, k, dist);
			}
				
			printf("\n\n");
			system("pause");
		}
	}while(1);
}

#endif //Finaliza a biblioteca
