#ifndef PIVOTAMENTO_HPP
#define PIVOTAMENTO_HPP

void PivotarCompleto(long double m[MAXTAM][MAXTAM], int N){
	
	int i, j, k, linha_pivo, coluna_pivo, saida=0;
    long double x[N], soma=0, fator, pivo, aux;
	
	for (k=0; k<N; k++) {
        pivo = m[k][k];
        linha_pivo = k;
        coluna_pivo = k;
        
        for (i=k; i<N; i++) {
            for (j=k; j<N; j++) {
                if (fabs(m[i][j])>fabs(pivo)) {
                    pivo = m[i][j];
                    linha_pivo = i;
                    coluna_pivo = j;
                }
            }
        }
        
        if (linha_pivo!=k) {
            for (j=0; j<=N; j++) {
                aux = m[k][j];
                m[k][j] = m[linha_pivo][j];
                m[linha_pivo][j] = aux;
            }
        }
        
        if (coluna_pivo!=k) {
            for (i=0; i<N; i++) {
                aux = m[i][k];
                m[i][k] = m[i][coluna_pivo];
                m[i][coluna_pivo] = aux;
            }
        }
        
        for (i=(k+1); i<N; i++) {
            fator = m[i][k]/m[k][k];
                 
            for (j=0; j<=N; j++) {
                m[i][j] = m[i][j]-fator*m[k][j];
            }
        }
    }
}

#endif //Finaliza a biblioteca
