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
    struct Element *next;
};
typedef struct Element C_Node;

void test(FILE *fp);
void add_oras(Node **head, char oras[]);
int IsInList(Node *head, char oras[]);
Node *Create_List_of_Cities();
void PrintCities(Node *head,int *i);
void add_oras_complex(C_Node **head, char oras[],char numar_tren[]);
C_Node *Create_Complex_List_of_Cities();
void Print_Complex_Cities(C_Node *head,int *i);

//PTR GRAPH

typedef struct {
    int V;
    int E;
    int **a;
} Graph;

Graph* create(C_Node *complex_head, Node *head, int numar_varfuri);
int return_position_in_list(Node *head, char city_name[]);
void print_file(int n, char nume_fisier[]);
int most_frequented_station(Graph *a, Node *head);
char* return_city_from_pos(int i, Node *head);
int return_grad_Slatina(Graph *gr, Node *head);