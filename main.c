#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct individual
{
    char bloodType[2];
    char possibilities[4][2];
    int childcount;
    struct individual* parents[2];
}individual;

void crossover(individual* p);
void set_btype(individual* p);
int get_random(int max);
individual*  evolve(individual* origin1, individual *origin2);


void main()
{   
    srand(time(NULL));

    individual* o1 = malloc(sizeof(individual));
    individual* o2 = malloc(sizeof(individual));
    o1->parents[0] = NULL;
    o1->parents[1] = NULL;
    o2->parents[0] = NULL;
    o2->parents[1] = NULL;

    o2->bloodType[0] = 'A';
    o2->bloodType[1] = 'i';
    o1->bloodType[0] = 'B';
    o1->bloodType[1] = 'B';


    individual* child = evolve(o1,o2);
    printf("Child Parent 1 Blood Type: %c%c\n", child->parents[0]->bloodType[0],child->parents[0]->bloodType[1]);
    printf("Child Parent 2 Blood Type: %c%c\n", child->parents[1]->bloodType[0],child->parents[1]->bloodType[1]);
    printf("Child possitibilities: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c%c, ",child->possibilities[i][0],child->possibilities[i][1]);
    }
    printf("\nChild Bloodtype: %c%c\n", child->bloodType[0],child->bloodType[1]);
}

void crossover(individual* p)
{   
    //p->possibilities[i][l] = p->parents[k]->bloodType[l];
    for (int a = 0; a < 2; a++) // parent 1
    {
        for (int b = 0; b < 2; b++) // parent 2
        {   
            p->possibilities[2 * a + b][0] = p->parents[0]->bloodType[a];
            p->possibilities[2 * a + b][1] = p->parents[1]->bloodType[b];
        }
    }
}

void set_btype(individual* p)
{
    int i = get_random(3);
    p->bloodType[0] = p->possibilities[i][0];
    p->bloodType[1] = p->possibilities[i][1];
}

int get_random(int max)
{
   return rand() % (max + 1);
}

individual*  evolve(individual* origin1, individual *origin2)
{
    individual* new_ind = malloc(sizeof(individual));
    new_ind->parents[0] = origin1;
    new_ind->parents[1] = origin2;
    crossover(new_ind);
    set_btype(new_ind);
    return new_ind;
}
