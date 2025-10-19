#include<stdio.h> // for declaration of printf
#include<stdlib.h> // for declaration of malloc(), free(), exit()
#include<string.h> //for declaration of memset()

struct Date
{
    int day;
    int month;
    int year;
};

struct array
{
    int* a;
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

    // Step 2: Allocate dynamic memory using malloc() and
    //         do the validation check
    ptr = (int*)malloc(sizeof(int));
    if(NULL == ptr)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    // step 3: Initialize allocated instance to 0
    memset(ptr, 0, sizeof(int));

    // step 4-5: Read/Write on dynamically allocted instance
    *ptr = 100;                  // Write Operation
    int n = *ptr;                // Read operation
    printf("*ptr = %d\n", *ptr); // Read operation

    // step 6: When dynamic instance is no longer wanted 
    //         Release it and make pointer NULL again
    free(ptr);
    ptr = NULL; 
}

void dynamic_user_defined_date(void)
{
    // Step 1:
    struct Date* newDate = NULL;

    // Step 2:
    newDate = (struct Date*)malloc(sizeof(struct Date));
    if(NULL == newDate)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    // Step 3:
    memset(newDate, 0, sizeof(struct Date));

    // step 4/5:
    newDate->day = 27;
    newDate->month = 9;
    newDate->year = 2025;

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year);

    // Step 6:
    free(newDate);
    newDate = NULL;
}

void dynamic_user_defined_array(void)
{
    // Step 1:
    struct array* p_array = NULL;
    
    // Step 2:
    p_array = (struct array*)malloc(sizeof(struct array));
    if(NULL == p_array)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    p_array->N = 8;
    p_array->a = (int *)malloc(sizeof(int));
    if(NULL == p_array->a)
    {
        puts("out of memmory");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i < p_array->N ; ++i)
        p_array->a[i] = (i+1) * 10;
    
    puts("showing array: ");
    for(i = 0; i < p_array->N ; ++i)
        printf("p_array->a[%d] = %d\n", i,p_array->a[i]);
    
    free(p_array->a);
    p_array->a = NULL;

    free(p_array);
    p_array = NULL;
}