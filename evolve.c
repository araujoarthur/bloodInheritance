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
    int SIBLINGS_PARAM = 5;
    individual** generations[MAX_GEN];

    generation gen_list[MAX_GEN];
     
    int childcount = 0;
    int current_gen = 1;
    gen_list[0].generation_id = 0;
    gen_list[0].member_count = 2;


    while (current_gen != MAX_GEN)
    {   
        if (current_gen != 0)
        {
            gen_list[current_gen].generation_id = current_gen;
            gen_list[current_gen].member_count = 0;
            if(gen_list[current_gen - 1].member_count < 1)
            {
                printf("Population didn't evolve");
                return;
            }
        }

        if (current_gen < SIBLINGS_PARAM)
        {
            int couple_count = get_random((int) (gen_list[current_gen-1].member_count / 2) + 1);
            printf("couple_count: %i\n",couple_count);
            int childcount_list[couple_count];
            int counter = 0;
            while(counter != couple_count)
            {
                childcount_list[counter] = get_random(MAX_CHILD);
                gen_list[current_gen].member_count += childcount_list[counter];
                printf("CHILDS %i\n", childcount_list[counter]);
                counter++;
            }
            //Populate members for n couples
            

        }
        
        current_gen++;
    }

    //WORK ON FREEING MEMORY!!!!!!!!!!!
}

void crossover(individual* p)
{   
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
    int i = get_random(4);
    p->bloodType[0] = p->possibilities[i][0];
    p->bloodType[1] = p->possibilities[i][1];
}

int get_random(int max)
{
   return rand() % (max);
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