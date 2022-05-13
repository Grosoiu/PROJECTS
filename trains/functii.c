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
            aux2[strlen(aux2)-2]=0;
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

void add_oras_complex(C_Node **head, char oras[],char numar_tren[])
{
    C_Node *newNode = (C_Node *)malloc(sizeof(C_Node));
    int a,b;
    a = strlen(oras);
    b = strlen(numar_tren);
    newNode->city_name = malloc(sizeof(char) * (a + 1));
    strcpy(newNode->city_name, oras);
    newNode->train_number = malloc(sizeof(char) * (b + 1));
    strcpy(newNode->train_number, numar_tren);
    newNode->next = *head;
    *head = newNode;
}

C_Node *Create_Complex_List_of_Cities()
{
    C_Node *head=NULL;
    FILE *fp, *fp2;
    char *aux1, *aux2,*aux3;
    aux1=(char*)calloc(100,sizeof(char));
    aux2=(char*)calloc(100,sizeof(char));
    aux3=(char*)calloc(100,sizeof(char));
    fp=fopen("_all_files.txt","r");
    test(fp);
    while(fscanf(fp,"%s",aux1)==1)
    {   
        //fscanf(fp,"%s",aux3);
        fp2=fopen(aux1,"r");
        test(fp2);
        while(fgets(aux2,50,fp2))
        {
            aux2[strlen(aux2)-2]=0;
            //printf("%s\n",aux2);
            add_oras_complex(&head,aux2,aux1);   
        }
        fclose(fp2);
    }
    fclose(fp);
    return head;
}

void Print_Complex_Cities(C_Node *head,int *i)
{
    while (head != NULL)
    {   printf("Oras : %s  cu  numarul %s \n",head->city_name,head->train_number);
    (*i)++;
        head = head->next;
    }
}