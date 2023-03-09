#ifndef JORDAN_HPP
#define JORDAN_HPP

void jordan(long double matriz[MAXTAM][MAXTAM], int tam){
	int i, j, k,l;
	long double m;
	int pivo = 0;
	long double soma = 0;
	long double solucoes[MAXTAM];
	int cont;

	printf("\n***Matriz Bruta***\n");
	Exibe(matriz,tam);
	printf("\n");
	for(i=0;i<tam;i++){
		Pivotar(matriz, tam, pivo);
		printf("\n***Matriz Pivotada %d vez***\n", i+1);
		Exibe(matriz,tam);
		printf("\n");
		pivo ++;
		for(j=0;j<tam;j++){
			if(i != j){
				m = matriz[j][i];
				m = m/matriz[i][i];
				for(k=0;k<=tam;k++){
					matriz[j][k] = matriz[j][k] - m*matriz[i][k];
				}
			}
		}
	}
		
	if(erro(matriz, tam)==1){
		return;
	}
		
	for(i=0;i<tam;i++){
		soma = 0;
		for(j=0;j<tam;j++){
			soma += matriz[i][j];
		}
		solucoes[i] = matriz[i][tam]/soma;
	}
	printf("\n***Matriz apos realizar o Metodo Jordan***\n");
	Exibe(matriz, tam);
	printf("\n");
	printf("\n ||Solucoes: {(");
	for(i=0;i<tam;i++){
		__mingw_printf(" %Lf; ", solucoes[i]);
	}
	printf(")}\n\n");
}

void menu_jordan(){
	long double matriz[MAXTAM][MAXTAM];
	FILE *file;
	int tam, i;
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

			tam = Ler_Arquivo(matriz, file, questao);
			jordan(matriz, tam);
			printf("\n\n");
			system("pause");
		}
	}while(1);
}

#endif //Finaliza a biblioteca
