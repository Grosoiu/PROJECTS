#include "functii.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

Graph* create(C_Node *complex_head, Node *head, int numar_varfuri)
{
    int i,j,orientat,k,l;
    Graph *g=(Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("Alocare dinamica esuata!");
        return NULL;
    }
    g->V=numar_varfuri;
    g->a=(int**)malloc(g->V*sizeof(int*));
    for(i=0;i<g->V;i++) g->a[i]=(int*)calloc(g->V,sizeof(int));
    if(g->a==NULL)
    {
        printf("Alocare dinamica esuata!");
        return NULL;
    }
    g->c=(int**)malloc(g->V*sizeof(int*));
    for(i=0;i<g->V;i++) g->c[i]=(int*)calloc(g->V,sizeof(int));
    g->E=0;
    printf("Ce tip de graf avem>? 0-orientat, altceva-neorientat  ");
    scanf("%d",&orientat);
    //C_Node *aux=complex_head;
    if(orientat == 0)
    {
        
            while(complex_head->next != NULL)
                {   
                    if(strcmp(complex_head->train_number,complex_head->next->train_number)==0)
                    {
                        k=return_position_in_list(head,complex_head->city_name);
                        l=return_position_in_list(head,complex_head->next->city_name);
                        if(g->a[k][l]==0)
                        g->E++;
                        g->a[k][l]=1;
                        g->c[k][l]=complex_head->next->distance-complex_head->distance;
                    }
                    complex_head=complex_head->next;
                }
    }
    else
    {
           while(complex_head->next != NULL)
                {   
                    if(strcmp(complex_head->train_number,complex_head->next->train_number)==0)
                    {
                        k=return_position_in_list(head,complex_head->city_name);
                        l=return_position_in_list(head,complex_head->next->city_name);
                        if(g->a[k][l]==0)
                        g->E++;
                        g->a[k][l]=1;
                        g->a[l][k]=1;
                        g->c[k][l]=complex_head->next->distance-complex_head->distance;
                        g->c[l][k]=complex_head->next->distance-complex_head->distance;
                    }
                    complex_head=complex_head->next;
                } 
        
    }
    return g;
}

int return_position_in_list(Node *head, char city_name[])
{
    int i=0;
    while(head)
    {   if(strcmp(head->city_name,city_name) == 0)
            return i;
        i++;
        head = head->next;
    }
    return -1;
}

void print_file(int n, char nume_fisier[])
{   FILE *fp;
    fp=fopen(nume_fisier,"at");
    fprintf(fp," %d ",n);
}

char* return_city_from_pos(int i, Node *head)
{
    for(int j=0;j<i;j++) head=head->next;
    return head->city_name;
}

void min_consecutiv(Graph *aux,int *poz1, int *poz2, int *distanta)
{
    int i,j,min=9999;
    {   
        for(i=0;i<aux->V;i++)
            for(j=0;j<aux->V;j++)
                {
                    if(min>aux->c[i][j] && aux->c[i][j] != 0)
                        {   
                            min=aux->c[i][j];
                            *poz1=i;
                            *poz2=j;
                            *distanta=min;
                        }
                }

    }
}

void max_consecutiv(Graph *aux,int *poz1, int *poz2, int *distanta)
{
    int i,j,max=0;
    {   
        for(i=0;i<aux->V;i++)
            for(j=0;j<aux->V;j++)
                {
                    if(max<aux->c[i][j] && aux->c[i][j] != 0)
                        {   
                            max=aux->c[i][j];
                            *poz1=i;
                            *poz2=j;
                            *distanta=max;
                        }
                }

    }
}

int return_total(Graph *aux)
{
    int sum=0,i,j;
    for(i=0;i<aux->V;i++)
            for(j=i+1;j<aux->V;j++)
            {
                sum=sum+aux->c[i][j];
            }
    return sum;

}

int printSolution(int dist[],int id_oras)
{
    printf("Distanta de la Bucuresti la Slatina \n");
    printf("%d\n",dist[id_oras]);
}

int minDistance(int dist[],int sps[],int V){
    int v, min=INT_MAX,min_index;
    for(v=0;v<V;v++)
    if(sps[v]==0 && dist[v]<=min){
            min=dist[v];
            min_index=v;
    }
    return min_index;
}

void dijkstra(Graph *g, int s,int id_oras){
    int i,j,u;
    int dist[g->V];
    int sps[g->V];
    for(i=0; i<g->V; i++){
        dist[i]=INT_MAX;
        sps[i]=0;
    }
    dist[s]=0;
    for(j=0;j<g->V-1;j++){
        u=minDistance(dist,sps,g->V);
        //printf("%d\n",u);
        sps[u]=1;
        for(i=0;i<g->V;i++){
            if(sps[i]==0 && g->c[u][i]!=0 && dist[u]!=INT_MAX && dist[u]+g->c[u][i]<dist[i])
                    dist[i]=dist[u]+g->c[u][i];
        }
    }
    printSolution(dist,id_oras);
}