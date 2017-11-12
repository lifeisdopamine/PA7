#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
        char name[20];
        int age;
        int arrivalTime;
        struct patient *left;
        struct patient *right;
};

void newArrival (char name[], int age);
struct patient getNextPatient();