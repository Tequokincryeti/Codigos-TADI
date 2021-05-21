#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcular(int tipo){
    int n;
    double total, somando, media, totalvariancia;
    total = 0.0;
    totalvariancia = 0.0;
    printf("\nQuantos numeros vai inserir?\n\n");
    scanf("%d", &n);
    char VALORES[n];
    for(int i= 0; i < n  ; i++){
        printf("\ninsira o %d valor ", i+1);
        scanf("%lf", &somando);
        total += somando;
        VALORES[i]= somando;
    }
    double nb = (double)n;
    media = total/nb;
    if(tipo == 1){
    return media;
    }else if(tipo == 2 || 3){
        for(int j =0; j < n ; j++){
            double valor = VALORES[j];
            double var = valor - media;
            if ( var < 0){
                var -= (2*var);
            }
           //printf("\nvariancia e%lf", var);
            totalvariancia += pow(var,2);
	    //printf("\nA var e %lf",var);
	    // printf("\n%lf",totalvariancia);
            
        }
        if(tipo == 2){
        return totalvariancia;
        } else if(tipo == 3){
            double Desvio = sqrt(totalvariancia);
            printf("\nO desvio padrao e de: %lf",Desvio);
            return Desvio;
        }
    } else {
        printf("Voce errou alguma digito");
    }   

    return 0;
}
int main(void){
    int tipo;
    double media, variancia, Desvio;
    printf("Qual Medida quer obter? \n 1-media \n 2-variancia \n 3-Desvio padrao\n\n");
    scanf ("%d", &tipo);
    if(tipo == 1){
       media = calcular(1);
       printf("\nA media e: %lf", media);
    } else if( tipo == 2){
        variancia = calcular(2);
        printf("\nA variancia total e: %lf", variancia);
    } else if (tipo == 3){
        Desvio == calcular(3);
    }
	system("pause");
}   
