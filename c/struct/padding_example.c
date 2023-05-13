#include <stdio.h>
#include <stdint.h>

struct Student
{
    int id1;
    char name;
    int id2;
    char c;
    float percentage;
};

int main(void)
{   
    struct Student student = {
        .id1 = 1,
        .name = 'A',
        .id2 = 2,
        .c = 'B',
        .percentage = 80.5
    };
    printf("Size of members of the struct:\n- id1: %zu bytes\n- name: %zu byte\n- id2: %zu bytes\n- c: %zu byte\n- percentage: %zu bytes\n", sizeof(student.id1),  sizeof(student.name),  sizeof(student.id2),  sizeof(student.c), sizeof(student.percentage));
    printf("Expected size of the struct: %zu bytes\n", sizeof(student.id1)+ sizeof(student.name)+ sizeof(student.id2)+  sizeof(student.c) + sizeof(student.percentage));
    printf("Actual size of the struct: %zu bytes\n", sizeof(student));
}
