#include<stdio.h>
struct Elem
{
    char *city_name;
    struct Elem *next;
};
typedef struct Elem Node;

struct Element
{
    char *city_name;
    char *train_number;
    int distance;
    struct Element *next;
};
typedef struct Element C_Node;

void test(FILE *fp);
void add_oras(Node **head, char oras[]);
int IsInList(Node *head, char oras[]);
Node *Create_List_of_Cities();
void PrintCities(Node *head,int *i);
void add_oras_complex_beginning(C_Node **head, char oras[],char numar_tren[],int distanta);
void add_oras_complex_end(C_Node **head, char oras[],char numar_tren[],int distanta);
C_Node *Create_Complex_List_of_Cities();
void Print_Complex_Cities(C_Node *head,int *i);

//PTR GRAPH

typedef struct {
    int V;
    int E;
    int **a;
    int **c;
} Graph;

Graph* create(C_Node *complex_head, Node *head, int numar_varfuri);
int return_position_in_list(Node *head, char city_name[]);
void print_file(int n, char nume_fisier[]);
char* return_city_from_pos(int i, Node *head);
void min_consecutiv(Graph *aux,int *poz1, int *poz2, int *distanta);
void max_consecutiv(Graph *aux,int *poz1, int *poz2, int *distanta);
int return_total(Graph *aux);
int minDistance(int dist[],int sps[],int V);
void dijkstra(Graph *g, int s,int id_oras);
int printSolution(int dist[],int id_oras);
