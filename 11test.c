#include <stdio.h>
#include<stdlib.h>

typedef struct person
    {
        int age;
    } person;

void howOld(person *p) {
    printf("I'm %d years old!\n", p->age);
    p->age = 12;
    // p = NULL;
}

int main() {
    person *jim = (person *)malloc(sizeof(person));
    jim->age = 10;
    printf("before %d\n", jim->age);
    howOld(jim);
    // jim = NULL;
    printf("after %d\n", jim->age);
    return 0;
}