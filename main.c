#include <stdio.h>
#include <stdlib.h>
#include "evolve.h"

void main()
{ 
    individual* o1 = malloc(sizeof(individual));
    individual* o2 = malloc(sizeof(individual));
    o1->parents[0] = NULL;
    o1->parents[1] = NULL;
    o2->parents[0] = NULL;
    o2->parents[1] = NULL;

    o2->bloodType[0] = 'A';
    o2->bloodType[1] = 'i';
    o1->bloodType[0] = 'B';
    o1->bloodType[1] = 'i';
    initSim(100,20, o1, o2);

   /* individual* child = evolve(o1,o2);
    printf("Child Parent 1 Blood Type: %c%c\n", child->parents[0]->bloodType[0],child->parents[0]->bloodType[1]);
    printf("Child Parent 2 Blood Type: %c%c\n", child->parents[1]->bloodType[0],child->parents[1]->bloodType[1]);
    printf("Child possitibilities: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c%c, ",child->possibilities[i][0],child->possibilities[i][1]);
    }
    printf("\nChild Bloodtype: %c%c\n", child->bloodType[0],child->bloodType[1]);
    */
}
