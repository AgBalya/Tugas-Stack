#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    return stack->data[stack->top];
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int processTwoStacks(int maxSum, int stackA[], int stackB[], int n, int m) {
    Stack sA, sB;
    initializeStack(&sA);
    initializeStack(&sB);
    
    for (int i = n - 1; i >= 0; i--) {
        push(&sA, stackA[i]);
    }
    for (int i = m - 1; i >= 0; i--) {
        push(&sB, stackB[i]);
    }

    int total = 0, count = 0;
    while (!isStackEmpty(&sA) || !isStackEmpty(&sB)) {
        if (!isStackEmpty(&sA) && total + peek(&sA) <= maxSum) {
            total += pop(&sA);
            count++;
        }
        else if (!isStackEmpty(&sB) && total + peek(&sB) <= maxSum) {
            total += pop(&sB);
            count++;
        }
        else
            break;
    }
    return count;
}

int main() {
    int numGames;
    printf("Enter the number of games: ");
    scanf("%d", &numGames);

    while (numGames--) {
        int n, m, maxSum;
        printf("Enter the sizes of stacks A and B, and the maximum sum: ");
        scanf("%d %d %d", &n, &m, &maxSum);

        int stackA[n], stackB[m];
        printf("Enter the elements of stack A: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &stackA[i]);
        }
        printf("Enter the elements of stack B: ");
        for (int i = 0; i < m; i++) {
            scanf("%d", &stackB[i]);
        }

        int result = processTwoStacks(maxSum, stackA, stackB, n, m);
        printf("Result: %d\n", result);
    }

    return 0;
}
