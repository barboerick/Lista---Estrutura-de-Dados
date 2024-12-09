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

    int i,j, aux;
    float k = log(tamanho+1)/log(3);
    k = floor(k+0.5);

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
