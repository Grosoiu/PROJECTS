#include<stdio.h>
#include<stdlib.h>
#include"functii.h"


int main()
{
    C_Node *lista_complexa;
    Node *lista_simpla;
    Graph *graf_orientat, *graf_neorientat;

    int i=0;
    int poz1,poz2,distanta=0;
    lista_simpla=Create_List_of_Cities();
    lista_complexa=Create_Complex_List_of_Cities();
    PrintCities(lista_simpla,&i);
    graf_orientat=create(lista_complexa,lista_simpla,i);
    graf_neorientat=create(lista_complexa,lista_simpla,i);
    min_consecutiv(graf_neorientat,&poz1,&poz2,&distanta);
    printf("Orasele cu distanta minima sunt %s si %s cu distanta de %d \n",return_city_from_pos(poz1,lista_simpla),return_city_from_pos(poz2,lista_simpla),distanta);
    max_consecutiv(graf_neorientat,&poz1,&poz2,&distanta);
    printf("Orasele cu distanta maxima sunt %s si %s cu distanta de %d \n",return_city_from_pos(poz1,lista_simpla),return_city_from_pos(poz2,lista_simpla),distanta);
    printf("Numrul total de kilometrii este: %d \n",return_total(graf_neorientat));
    dijkstra(graf_neorientat,return_position_in_list(lista_simpla,"Bucuresti Nord"),return_position_in_list(lista_simpla,"Slatina"));

    return 0;
}