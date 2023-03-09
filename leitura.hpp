#ifndef LEITURA_HPP
#define LEITURA_HPP

int Ler_Arquivo(long double matriz[MAXTAM][MAXTAM], FILE *file, char questao[2]){
	//Variáveis Locais
	char linha[100];
	char *aux;
	long double conv;
	int i = 0, control=0;
	int j = 0, k=0;

	while(!feof(file)){//Responsavel por Ler o arquivo
		fgets(linha, 100, file);
		if(linha[0]=='*' && linha[1]==questao[0] && (linha[2]==questao[1] || atoi(questao)<10)){//Contrala a Busca selecionada pelo usuario
			control=1;
			continue;
		}

		if(control==1){
			if(linha[0] == ';'){
				fclose(file);
				return i;
			}
			aux = strtok(linha, " ");
			conv = atof(aux);
			matriz[i][j] = conv;
			j++;
			while(aux != NULL){
				aux = strtok(NULL, " ");
				conv = atof(aux);
				matriz[i][j] = conv;
				j++;
			}
			i++;
			j=0;
		}
	}
	return i;
}

#endif //Finaliza a biblioteca
