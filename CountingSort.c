#include <stdio.h>
#include <stdlib.h>

void CountingSort(int * v , int n);

int main()
{
    int i;
    int n;
    int * v;
    printf("Digite N:");
    scanf("%d",&n);

    v=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        v[i]=rand();


    for(i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");


    CountingSort(v,n);


    for(i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");

    free(v);

    return 0;

}


void CountingSort(int * v , int n)
{
    int i,j;
    int * aux;  //vetor auxilar
    int maior;  //maior valor do vetor v
    int menor;  //menor valor do vetor v
    int k;      //tamanho do vetor aux


    //acha maior e menor valor
    maior=menor=v[0];
    for(i=1;i<n;i++)
    {
        if(v[i]>maior)maior=v[i];
        if(v[i]<menor)menor=v[i];

    }

    //tamanho de aux igual a maior - menor
    k=maior-menor + 1;

    //aloca memoria pra aux e inicia com 0

    aux=(int *)calloc(k,sizeof(int)) ;

    //verrifica se consegiu alocar memoria
    if(aux==NULL)
    {
        printf("Erro ao alocar memoria");
        return;
    }

    //conta e armazena em aux
    for(i=0;i<n;i++)
        aux[ v[i] - menor]++;

    //ordena v utilizando os valores de aux
    for(i=0,j=0;i<k;i++)
        for(aux[i];aux[i]>0;aux[i]-- , j++)
            v[j]=i+menor;

    //libera memoria aux
    free(aux);

}
