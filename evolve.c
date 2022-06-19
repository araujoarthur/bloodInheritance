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
    int current_gen = 999;
    gen_list[0].generation_id = 0;
    gen_list[0].member_count = 2;


    while (gen_left--)
    {   
        printf("GEN LEFT: %i\n", gen_left);
        current_gen = MAX_GEN - gen_left - 1;
        if (gen_left+1 == MAX_GEN)
        {
            childcount = get_random(MAX_CHILD);
            generations[current_gen] = malloc(childcount*sizeof(individual)); //FREE!
            printf("CHILDCOUNT: %i | GEN: gen_left: %i\n", childcount, gen_left);

            while (childcount--)
            {   
                generations[current_gen][childcount] = evolve(origin1, origin2);
                printf("Bloodtype: %c%c\n", generations[current_gen][childcount]->bloodType[0],generations[current_gen][childcount]->bloodType[1]);
            }
        }
        else if (current_gen < SIBLINGS_PARAM)
        {
            //INFINITE LOOP;
            int couple_count = get_random((int) gen_list[current_gen].member_count/2);
            while (--couple_count)
            {
                int parent1_id = get_random(gen_list[current_gen - 1].member_count);
                int parent2_id = get_random(gen_list[current_gen - 1].member_count);

                while (parent2_id == parent1_id)
                {
                    parent2_id = get_random(gen_list[current_gen - 1].member_count);
                }

                individual* parent1 = generations[current_gen - 1][parent1_id];
                individual* parent2 = generations[current_gen - 1][parent2_id];

                childcount = get_random(MAX_CHILD);

                gen_list[current_gen].member_count += childcount;

                while(childcount--)
                {
                    generations[current_gen][childcount] = evolve(parent1, parent2);
                    printf("Bloodtype: %c%c\n", generations[current_gen][childcount]->bloodType[0],generations[current_gen][childcount]->bloodType[1]); 
                }                
            }
            
        }
        else
        {
            //Choose randomly not siblings who belong to the same generation.
        }
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