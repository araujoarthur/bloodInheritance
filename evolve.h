#ifndef EVOLVEH
#define EVOLVEH

struct individual;

typedef struct individual
{
    char bloodType[2];
    char possibilities[4][2];
    int childcount;
    int generation;
    struct individual* parents[2];
}individual;

void initSim();
void crossover(individual* p);
void set_btype(individual* p);
int get_random(int max);
individual*  evolve(individual* origin1, individual *origin2);

#endif