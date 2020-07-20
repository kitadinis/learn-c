#ifndef LEARN_C_INDEX_H
#define LEARN_C_INDEX_H

/*
 * File:   index.h
 * Author: KitaDinis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} person;

typedef struct {
    int x;
    int y;
} point;

typedef struct node {
    int val;
    struct node *next;
    struct node *left;
    struct node *right;
} node_t;

union hiddenMessage {
    int ints[6];
    char chars[21];
};

void helloWorld();

void variablesAndTypes();

void arrays();

void multidimensionalArrays();

void conditions();

void strings();

void forLoops();

void whileLoops();

void functions();

void Static();

void print_big(int number);

int pointers();

void structures();

void birthday(person *p);

void functionArgumentsByReference();

void dynamicAllocation();

void arraysAndPointers();

int factorial(int number);

void recursion();

void linkedLists();

void binaryTrees();

void insert(node_t *tree, int val);

void print_tree(node_t *current);

void printDFS(node_t *current);

void unions();

void pointerArithmetics();

void functionPointers();

#endif //LEARN_C_INDEX_H