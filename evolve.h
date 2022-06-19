#ifndef EVOLVEH
#define EVOLVEH

struct individual;
struct generation;

typedef struct individual
{
    char bloodType[2];
    char possibilities[4][2];
    int childcount;
    int generation;
    struct individual* parents[2];
}individual;

typedef struct generation
{
    int generation_id;
    int member_count;
}generation;

void initSim();
void crossover(individual* p);
void set_btype(individual* p);
int get_random(int max);
individual*  evolve(individual* origin1, individual *origin2);

#endif