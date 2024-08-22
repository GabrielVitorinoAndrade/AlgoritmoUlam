#include<stdio.h>
#include <time.h>


int tamanhoDaMaiorSequencia = 0;
int valorQueGerouAMaiorSequencia = 1;
double somandoParaMedia = 0;
double tempoGastoSomado = 0;


void algoritmoUlam(int a){

    clock_t inicio,fim;
    double tempoGasto;

    inicio = clock();

    int x = a;

    int contador = 0;

    while(!(x == 4 && (x/2) == 2 && (x/4) == 1)){
        
        contador++;

        if(x % 2 == 0){
            x = x/2;
        }else{
            x = 3*x + 1;
        }
    }

    fim = clock();

    tempoGasto = (double)(fim - inicio) / (double) CLOCKS_PER_SEC;
    tempoGastoSomado += tempoGasto;

    contador = contador + 3;
    somandoParaMedia += contador;

    if(contador > tamanhoDaMaiorSequencia){
        tamanhoDaMaiorSequencia = contador;
        valorQueGerouAMaiorSequencia = a;
    }

}


void gerandoSequencia(int a){

    int x = a;

    printf("%d, ", a);

    while(!(x == 4 && (x/2) == 2 && (x/4) == 1)){
        
        if(x % 2 == 0){
            x = x/2;
        }else{
            x = 3*x + 1;
        }

        printf("%d, ", x);

    }

}


int main() {
    
    printf("COMECOU");
    for(int i = 1; i < 65536; i++){
    
       algoritmoUlam(i);
       printf("%d\n", i);
    }

    printf("\n\nMAIOR SEQUÊNCIA:\n");
    gerandoSequencia(valorQueGerouAMaiorSequencia);
    printf("TAMANHO DA MAIOR SEQUÊNCIA: %d\n", tamanhoDaMaiorSequencia);
    printf("\nVALOR QUE GEROU A MAIOR SEQUÊNCIA: %d\n", valorQueGerouAMaiorSequencia);
    printf("MEDIA DOS TAMANHOS DAS SEQUENCIAS: %lf\n", somandoParaMedia/(65536 - 1));
    printf("MEDIA DOS TEMPOS DE EXECUCAO (EM SEGUNDOS): %lf\n", tempoGastoSomado/(65536 - 1));

}