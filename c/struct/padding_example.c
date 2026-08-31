#include <stdio.h>
#include <stdint.h>

struct Student1
{
    int a;
    char b;
    int c;
    char d;
    float e;
};

struct Student2
{
    int a;
    int b;
    char c;
    char d;
    float e;
};

struct __attribute__((packed)) Student3    // We cab force the compiler to not add padding
{
    int a;
    char b;
    int c;
    char d;
    float e;
};

int main(void)
{
    struct Student1 student1 = {
        .a = 1,                 // 4 bytes
        .b = 'A',               // 1 byte + 3 bytes padding
        .c = 2,                 // 4 bytes
        .d = 'B',               // 1 byte + 3 bytes padding
        .e = 80.5               // 4 bytes
    };
/*            |a|a|a|a|b|X|X|X|        X=padding
              |c|c|c|c|d|X|X|X|
              |e|e|e|e| | | | |
 */

    // The order of the members in the struct matters
    struct Student2 student2 = {
        .a = 1,                 // 4 bytes
        .b = 2,                 // 4 bytes
        .c = 'A',               // 1 byte
        .d = 'B',               // 1 byte + 2 bytes padding
        .e = 80.5               // 4 bytes
    };
/*            |a|a|a|a|b|b|b|b|        X=padding
              |c|d|X|X|e|e|e|e|
 */

    // Packed struct
    struct Student3 student3 = {
        .a = 1,                 // 4 bytes
        .b = 'A',               // 1 byte
        .c = 2,                 // 4 bytes
        .d = 'B',               // 1 byte
        .e = 80.5               // 4 bytes
    };
    /*            |a|a|a|a|b|c|c|c|        X=padding
                  |c|d|e|e|e|e| | |
     */


    printf("Size of members of the struct:\n- (int)   a: %zu bytes\n- (char)  b: %zu byte\n- (int)   c: %zu bytes\n- (char)  d: %zu byte\n- (float) e: %zu bytes\n", sizeof(student1.a),  sizeof(student1.b),  sizeof(student1.c),  sizeof(student1.d), sizeof(student1.e));
    printf("Expected size of the struct: %zu bytes\n", sizeof(student1.a)+ sizeof(student1.b)+ sizeof(student1.c)+  sizeof(student1.d) + sizeof(student1.e));
    printf("Actual size of the struct: %zu bytes\n\n", sizeof(student1));

    printf("Size of members of the struct:\n- (int)   a: %zu bytes\n- (int)   b: %zu byte\n- (char)  c: %zu bytes\n- (char)  d: %zu byte\n- (float) e: %zu bytes\n", sizeof(student2.a),  sizeof(student2.b),  sizeof(student2.c),  sizeof(student2.d), sizeof(student2.e));
    printf("Expected size of the struct: %zu bytes\n", sizeof(student2.a)+ sizeof(student2.b)+ sizeof(student2.c)+  sizeof(student2.d) + sizeof(student2.e));
    printf("Actual size of the struct: %zu bytes\n\n", sizeof(student2));

    printf("Size of members of the struct:\n- (int)   a: %zu bytes\n- (char)  b: %zu byte\n- (int)   c: %zu bytes\n- (char)  d: %zu byte\n- (float) e: %zu bytes\n", sizeof(student3.a),  sizeof(student3.b),  sizeof(student3.c),  sizeof(student3.d), sizeof(student3.e));
    printf("Expected size of the struct: %zu bytes\n", sizeof(student3.a)+ sizeof(student3.b)+ sizeof(student3.c)+  sizeof(student3.d) + sizeof(student3.e));
    printf("Actual size of the struct: %zu bytes\n", sizeof(student3));
}
