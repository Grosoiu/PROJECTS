#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functii.h"

void test(FILE *fp)
{
    if(fp==NULL){
    printf("Fisierul nu a fost deschis! \n");
    exit(1);
    }

}

void add_oras(Node **head, char oras[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    int a;
    a = strlen(oras);
    newNode->city_name = malloc(sizeof(char) * (a + 1));
    strcpy(newNode->city_name, oras);
    newNode->next = *head;
    *head = newNode;
}

int IsInList(Node *head, char oras[])
{
    int i=0;
    while (head != NULL)
    {
        if(strcmp(head->city_name,oras)==0)   i++; 
        head = head->next;
    }
    if(i==0)return i;
    else return 1;
}
Node *Create_List_of_Cities()
{   
    int i;
    Node *head=NULL;
    FILE *fp, *fp2;
    char *aux1, *aux2;
    aux1=(char*)calloc(100,sizeof(char));
    aux2=(char*)calloc(100,sizeof(char));
    fp=fopen("_all_files.txt","r");
    test(fp);
    while(fscanf(fp,"%s",aux1)==1)
    {
        fp2=fopen(aux1,"r");
        test(fp2);
        while(fgets(aux2,50,fp2))
        {
            for(i=0;i<strlen(aux2);i++)
            if(aux2[i]==',')
            aux2[i]=0;
            if(IsInList(head,aux2)==1) continue;
            else add_oras(&head,aux2);   
        }
        fclose(fp2);
    }
    fclose(fp);
    return head;
}

void PrintCities(Node *head,int *i)
{
    while (head != NULL)
    {   //printf("Oras : %s \n",head->city_name);
    (*i)++;
        head = head->next;
    }
}


//Pentru lista cu orasele care se pot repeta + numarul trenului

void add_oras_complex_beginning(C_Node **head, char oras[],char numar_tren[],int distanta)
{
    C_Node *newNode = (C_Node *)malloc(sizeof(C_Node));
    int a,b;
    a = strlen(oras);
    b = strlen(numar_tren);
    newNode->city_name = malloc(sizeof(char) * (a + 1));
    strcpy(newNode->city_name, oras);
    newNode->train_number = malloc(sizeof(char) * (b + 1));
    strcpy(newNode->train_number, numar_tren);
    newNode->distance=distanta;
    newNode->next = *head;
    *head = newNode;
}

void add_oras_complex_end(C_Node **head, char oras[],char numar_tren[],int distanta)
{   
    C_Node *aux=*head, *headcopy=*head;
    C_Node *newNode=(C_Node*)malloc(sizeof(C_Node));
    int a,b;
    a = strlen(oras);
    b = strlen(numar_tren);
    newNode->city_name = malloc(sizeof(char) * (a + 1));
    strcpy(newNode->city_name, oras);
    newNode->train_number = malloc(sizeof(char) * (b + 1));
    strcpy(newNode->train_number, numar_tren);
    newNode->distance=distanta;
    while(headcopy != NULL){
            aux=headcopy;
            headcopy=headcopy->next;
    }
    if(aux==NULL) 
        add_oras_complex_beginning(&*head,oras,numar_tren,distanta);
    else{
        aux->next=newNode;
        newNode->next=NULL;


    }

}

C_Node *Create_Complex_List_of_Cities()
{
    C_Node *head=NULL;
    FILE *fp, *fp2;
    char *aux1, *aux2,*aux3,*aux4;
    aux1=(char*)calloc(100,sizeof(char));
    aux2=(char*)calloc(100,sizeof(char));
    fp=fopen("_all_files.txt","r");
    test(fp);
    while(fscanf(fp,"%s",aux1)==1)
    {   
        fp2=fopen(aux1,"r");
        test(fp2);
        while(fgets(aux2,50,fp2))
        {   
            char *aux3;
            aux3=strtok(aux2,",");
            aux4=strtok(NULL,",");
            add_oras_complex_end(&head,aux3,aux1,atoi(aux4+1));   
        }
        fclose(fp2);
    }
    fclose(fp);
    return head;
}

void Print_Complex_Cities(C_Node *head,int *i)
{
    while (head != NULL)
    {   printf("Oras : %s  cu  numarul %s , kilometrii %d\n",head->city_name,head->train_number,head->distance);
    (*i)++;
        head = head->next;
    }
}