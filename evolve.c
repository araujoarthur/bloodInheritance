#include <stdio.h>
#include <stdlib.h>
#include "evolve.h"
#include <time.h>

void initSim(int mg, int mc, individual* origin1, individual* origin2)
{
    srand(time(NULL));
    int MAX_GEN = mg;
    int MAX_CHILD = mc;
    int gen_left = mg;
    individual** generations[MAX_GEN];
    
    int childcount = 0;

    while (gen_left--)
    {
        //printf("GEN_LEFT = %i\n");
        if (gen_left+1 == MAX_GEN)
        {
            childcount = get_random(MAX_CHILD);
            generations[MAX_GEN-gen_left] = malloc(childcount*sizeof(individual));
            printf("CHILDCOUNT: %i | GEN: gen_left: %i\n", childcount, gen_left);

            while (childcount--)
            {   
                generations[MAX_GEN - gen_left][childcount] = evolve(origin1, origin2);
                printf("Bloodtype: %c%c\n", generations[MAX_GEN - gen_left][childcount]->bloodType[0],generations[MAX_GEN - gen_left][childcount]->bloodType[1]);
            }

        }
        else
        {
            //Choose randomly couples to cross.
        }
    }
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
    new_ind->generation = new_ind->parents[0]->generation + 1;
    crossover(new_ind);
    set_btype(new_ind);
    return new_ind;
}