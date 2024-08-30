/*
Can a variable be both const and volatile? 
------------------------------------------
yes, the const means that the variable cannot be assigned a new value.
The value can be changed by other code or pointer.
*/

#include <stdio.h>

int main(void)
{
    const  int local = 10;
    // const volatile int local = 10;

    int* ptr = (int*)&local;
    printf("Initial value of local : %d \n", local);
    
    *ptr = 100;
    printf("Modified value of local: %d \n", local);
    
    socket.write(local+22);
    // socket.write(10+22);
    // socket.write(32);

    return 0;
}


// void fn() {

//    volatile int counter=0;

//     while(counter < 10) {
//     while(TRUE) {

//         //read sensor
//     }
// }
