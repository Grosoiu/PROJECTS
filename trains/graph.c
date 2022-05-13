#include "functii.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    g->E=0;
    printf("Ce tip de graf avem>? 0-orientat, altceva-neorientat");
    scanf("%d",&orientat);
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
                    }
                    complex_head=complex_head->next;
                } 
        
    }
    return g;
}

int return_position_in_list(Node *head, char city_name[])
{
    int i=0;
    //while (strcmp(head->city_name,city_name) != 0 && head!=NULL)
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

//Functie care returneaza statia cea mai vizitata

int most_frequented_station(Graph *a, Node *head)
{
    int i=0,max=0,aux=0,poz=0,j,max2,poz2=0;

    for(i=0;i<a->V;i++)
    {
        for(j=0;j<a->V;j++)
            {
                if(a->a[i][j]==1) aux++;
            }
            if(aux>max)
                {   max2=max;
                    poz2=poz;
                    max=aux;
                    poz=i;
                }
                else
            if(aux>max2)
                {
                    max2=aux;
                    poz2=i;
                }
            aux=0;
                
    }

printf("Orasul cel mai vizitat este: %s, cu %d legaturi\n", return_city_from_pos(poz,head),max);
printf("Al doilea oras cel mai vizitat este: %s, cu %d legaturi\n", return_city_from_pos(poz2,head),max2);
            
}

char* return_city_from_pos(int i, Node *head)
{
    for(int j=0;j<i;j++) head=head->next;
    return head->city_name;
}

int return_grad_Slatina(Graph *gr, Node *head)
{   
    int grad=0;
    int i=return_position_in_list(head, "Slatina");
    for(int j=0;j<gr->V;j++)
    {
        if(gr->a[i][j]==1) grad++;
    }
    return grad;
}