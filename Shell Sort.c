#include <stdio.h>
#include <math.h>
#define N 8

int h = (pow(3,k)-1)/2;

printf("digite o tamanho da varredura");
scanf("%d",&tamanho);
printf("%d",h);*/
void shell(int *lista, int tamanho);
int lista[N]={1,8,6,7,2,9,99,35};
void main() {
   for(int w =0; w<N;w++){
    printf("%d ",lista[w]);
   }
   printf("\n");
   shell(lista,N);
   for(int w = 0; w<N; w++){
    printf("%d ",lista[w]);
   }
   printf("\n");
}

void shell(int *lista, int tamanho){
    /*i = laço principal, j = laço interno, aux = compara os itens*/
    int i,j, aux;
    /*formula se torna diferente por conta da 
    linguagem C não ter como fazer o calculo de
    log3, assim usando o Logaritmo neperiano. Calculo de varredura*/
    float k = log(tamanho+1)/log(3);
    /*arredondando para baixo o valor recebido por K, 
assim convertendo em numero inteiro*/
    k = floor(k+0.5);
    /*uma função que recebe dois argumentos 
sendo o primeiro a base e o segundo a potencia*/
    int h = (pow(3,(int)k)-1)/2;
    while(h>0){
        for(i = h;i<tamanho;i++){
                aux = lista[i];
                j = i;

                while(j >= h && lista[j-h] > aux){
                    lista[j] = lista[j-h];
                    j-=h;
                }
                lista[j] = aux;  
        }
         h=(h-1)/3;
    }
}
