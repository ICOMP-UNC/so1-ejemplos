/* C program to illustrate isprint() and iscntrl() functions.
If a character passed to isprint() is a printable character, it returns non-zero integer, if not it returns 0.
If a character passed to iscntrl() is a control character, it returns non-zero integer, if not it returns 0. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch = 'a';
    // char ch = 0x53;
    // char ch = 2;

    if (isprint(ch)) {
        printf("%c is printable character\n", ch);
    }
    else {
        printf("%c is not printable character\n", ch);
    }
  
    if (iscntrl(ch)) {
        printf("%c is control character\n", ch);
    }
    else {
        printf("%c is not control character\n", ch);
    }

    printf("The ASCII printable characters are:\n");
    for (int i=0; i<128; ++i)
    {
        if (isprint(i)!=0)
            printf("%c ", i);
    }
    // Output: ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @
    //         A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _ `
    //         a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~

    printf("\nThe ASCII value of all control characters are:\n");
    for (int i=0; i<128; ++i)
    {
        if (iscntrl(i)!=0)
            printf("%d ", i);
    }
    // Output: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
    //         23 24 25 26 27 28 29 30 31 127

    return (0);
}
