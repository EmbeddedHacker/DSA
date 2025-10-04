#include<stdio.h>   // for declaration of printf()
#include<stdlib.h>  // for declaration of malloc(), free(), exit()
#include<string.h>  // for declaration of memset()

struct Date
{
    int day;
    int month;
    int year;
};

struct array
{
    int *a;
    int N;
};

void dynamic_builtin(void);
void dynamic_user_defined_date(void);
void dynamic_user_defined_array(void);

int main(void)
{
    dynamic_builtin();
    dynamic_user_defined_date();
    dynamic_user_defined_array();

    return (0);
}

void dynamic_builtin(void)
{
    // step 1: Declare a pointer and initialize it to NULL
    int* ptr = NULL;

    // step 2: Allocate dynamic memory using malloc and do the vallidation
    ptr = (int *) malloc(sizeof(int));
    if(NULL == ptr)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    // step 3: Initialize allocated instance to 0
    memset(ptr, 0, sizeof(int));

    // step 4-5 Read/Write on dynamically allocated instance
    *ptr = 100;                 // Write operation
    int n = *ptr;               // Read operation
    printf("*ptr = %d\n",*ptr); // Read operation

    // step 6: When dynamic instance is no longer wanted 
    //         Release it and make pointer NULL again
    free(ptr);
    ptr = NULL;
}

void dynamic_user_defined_date(void)
{

}
void dynamic_user_defined_array(void)
{

}