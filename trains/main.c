#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functii.h"

int main()
{ int i=0,j=0,poz;
    Node *head;
    C_Node *complex_head;
    head=Create_List_of_Cities();
    complex_head=Create_Complex_List_of_Cities();
    PrintCities(head,&i);
    printf(" \n\n  %d \n",i);
    Print_Complex_Cities(complex_head,&j);
    printf(" \n\n  %d \n",j);
    Graph *orientat,*neorientat;
    orientat=create(complex_head,head,i);
    neorientat=create(complex_head,head,i);
    print_file(i,"noduri.txt");
    print_file(orientat->E,"muchii.txt");
    print_file(neorientat->E,"muchii.txt");
    most_frequented_station(neorientat,head);

    printf("Orasul meu, Slatina are gradul:  %d  \n",return_grad_Slatina(neorientat,head));
}
