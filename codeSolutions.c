/*
 * File:   codeSolutions.h
 * Author: KitaDinis
 */

#include "index.h"

/* Learn the Basics */

void helloWorld() {
    printf("Hello, World!");
}

void variablesAndTypes() {
    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum;

    sum = a + b + c;
    printf("The sum of a, b, and c is %f.", sum);
}

void arrays() {
    int grades[3];
    int average;

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d", average);
}

void multidimensionalArrays() {
    int grades[2][5];
    float average;
    int i;
    int j;

    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    for (i = 0; i < 2; i++) {
        average = 0;
        for (j = 0; j < 5; j++) {
            average += grades[i][j];
        }

        average = average / 5;
        printf("The average marks obtained in subject %d is: %.2f\n", i, average);
    }
}

void guessNumber(int guess) {
    if (guess < 555) {
        printf("Your guess is too low.\n");
    } else if (guess > 555) {
        printf("Your guess is too high.\n");
    } else {
        printf("Correct. You guessed it!\n");
    }
}

void conditions() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}

void strings() {
    char *first_name = "John";
    char last_name[] = "Doe";
    char name[100];

    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    if (strncmp(name, "John Boe", 100) == 0) {
        printf("Done!\n");
    }
    name[0] = '\0';
    strncat(name, first_name, 4);
    strncat(name, last_name, 20);
    printf("%s\n", name);
}

void forLoops() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int factorial = 1;
    int i;

    for (i = 0; i < 10; i++) {
        factorial *= array[i];
    }
    printf("10! is %d.\n", factorial);
}

void whileLoops() {
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i < 10) {
        if (array[i] < 5) {
            i++;
            continue;
        }

        if (array[i] > 10) {
            break;
        }

        printf("%d\n", array[i]);
        i++;
    }
}

void functions() {
    int array[] = {1, 11, 2, 22, 3, 33};
    int i;
    for (i = 0; i < 6; i++) {
        print_big(array[i]);
    }
}

void print_big(int number) {
    if (number > 10) {
        printf("%d is big\n", number);
    }
}

int sum(int num) {
    static int total = 0;
    total += num;
    return total;
}

void Static() {
    printf("%d ", sum(55));
    printf("%d ", sum(45));
    printf("%d ", sum(50));
}

/* Advanced */

int pointers() {
    int n = 10;

    int *pointer_to_n = &n;

    *pointer_to_n += 1;

    if (pointer_to_n != &n) return 1;
    if (*pointer_to_n != 11) return 1;

    printf("Done!\n");
}

void structures() {
    person john;

    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);
}

void birthday(person *p) {
    (*p).age += 1;
}

void functionArgumentsByReference() {
    person john;
    john.name = "John";
    john.age = 27;

    printf("%s is %d years old.\n", john.name, john.age);
    birthday(&john);
    printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);
}

void dynamicAllocation() {
    point *mypoint;

    mypoint = (point *) malloc(sizeof(point));

    mypoint->x = 10;
    mypoint->y = 5;
    printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

    free(mypoint);
}

void arraysAndPointers() {
    int i, j;
    int **pnumbers;

    pnumbers = (int **) malloc(3 * sizeof(int *));

    pnumbers[0] = (int *) malloc(1 * sizeof(int));
    pnumbers[1] = (int *) malloc(2 * sizeof(int));
    pnumbers[2] = (int *) malloc(3 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        free(pnumbers[i]);
    }

    free(pnumbers);
}

int factorial(int number) {
    int f = number;
    if (number > 1) {
        f *= factorial(number - 1);
    }
    return f;
}

void recursion() {

    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t **head) {
    int retval = -1;
    node_t *next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t **head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current = current->next;
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t *current = head,
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void linkedLists() {
    node_t *test_list = (node_t *) malloc(sizeof(node_t));

    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    delete_list(test_list);
}

void insert(node_t *tree, int val) {
    if (tree->val == 0) {
        /* insert on current (empty) position */
        tree->val = val;
    } else {
        if (val < tree->val) {
            /* insert left */
            if (tree->left != NULL) {
                insert(tree->left, val);
            } else {
                tree->left = (node_t *) malloc(sizeof(node_t));
                tree->left->val = val;
                tree->left->left = NULL;
                tree->left->right = NULL;
            }
        } else {
            if (val >= tree->val) {
                /* insert right */
                if (tree->right != NULL) {
                    insert(tree->right, val);
                } else {
                    tree->right = (node_t *) malloc(sizeof(node_t));
                    /* set values explicitly, alternative would be calloc() */
                    tree->right->val = val;
                    tree->right->left = NULL;
                    tree->right->right = NULL;
                }
            }
        }
    }
}

void printDFS(node_t *current) {
    if (current == NULL) return;   /* security measure */
    if (current != NULL) printf("%d ", current->val);
    if (current->left != NULL) printDFS(current->left);
    if (current->right != NULL) printDFS(current->right);
}

void binaryTrees() {
    node_t *test_list = (node_t *) malloc(sizeof(node_t));

    test_list->val = 0;
    test_list->left = NULL;
    test_list->right = NULL;

    insert(test_list, 5);
    insert(test_list, 8);
    insert(test_list, 4);
    insert(test_list, 3);

    printDFS(test_list);
    printf("\n");
}

void unions() {
    union hiddenMessage intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    printf("[");
    for (int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);
    printf("%s\n", intCharacters.chars);
}

void pointerArithmetics() {
    int intarray[5] = {10, 20, 30, 40, 50};
    int *pointer = &intarray[2];
    int *parray[3];

    int i;
    for (i = 0; i < 3; i++) {
        parray[i] = pointer + i;
    }

    for (i = 0; i < 3; i++) {
        if (parray[i] == &pointer[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }
}

void f1(int var) {
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var) {
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var) {
    printf("this is f3 and var is: %d\n", var);
}

void functionPointers() {
    void (*pf[])(int) = {f1, f2, f3};

    int c = 0;
    while (c < 3) {
        pf[c](c);
        ++c;
    }
}