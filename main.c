#include <stdio.h>
#include <stdlib.h>

typedef struct individual
{
    char bloodType[2];
    char possibilities[4][2];
    struct individual* parents[2];
}individual;

void crossover(individual* p);

void main()
{   
    individual* p = malloc(sizeof(individual));
    individual* k = malloc(sizeof(individual));
    individual* l = malloc(sizeof(individual));

    k->parents[0] = NULL;
    k->parents[1] = NULL;
    l->parents[0] = NULL;
    l->parents[1] = NULL;
    
    k->bloodType[0] = 'A';
    k->bloodType[1] = 'i';
    l->bloodType[0] = 'B';
    l->bloodType[1] = 'i';

    p->parents[0] = k;
    p->parents[1] = l;

    printf("Ran!");
    crossover(p);
    
    for(int jk = 0; jk < 4; jk++)
    {
        printf("\n%c,%c\n", p->possibilities[jk][0],p->possibilities[jk][1]);
    }
    free(p);
    free(k);
    free(l);
    return;
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