#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

typedef struct {
    char actions[MAX][LEN];
    int top;
} Stack;

typedef struct {
    char names[MAX][LEN];
    int front;
    int rear;
} Queue;

typedef struct {
    char names[MAX][LEN];
    int front;
    int rear;
} Deque;

/*  STACK  */
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, const char *action) {
    if (isStackFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    strncpy(s->actions[s->top], action, LEN - 1);
    s->actions[s->top][LEN - 1] = '\0';
}

void pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Nothing to undo.\n");
        return;
    }
    printf("Undo action: %s\n", s->actions[s->top]);
    s->top--;
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("No stored actions.\n");
        return;
    }

    printf("Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("- %s\n", s->actions[i]);
    }
}

/*  QUEUE  */
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->rear < q->front;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, const char *name) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->rear++;
    strcpy(q->names[q->rear], name);
}

void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed from queue: %s\n", q->names[q->front]);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->names[i]);
    }
}

/*  DEQUE  */
void initDeque(Deque *d) {
    d->front = -1;
    d->rear = -1;
}

int isDequeEmpty(Deque *d) {
    return d->front == -1;
}

int isDequeFull(Deque *d) {
    return d->rear == MAX - 1;
}

void insertFront(Deque *d, const char *name) {
    if (isDequeFull(d)) {
        printf("Deque is full.\n");
        return;
    }

    if (isDequeEmpty(d)) {
        d->front = 0;
        d->rear = 0;
        strcpy(d->names[d->front], name);
    } else if (d->front > 0) {
        d->front--;
        strcpy(d->names[d->front], name);
    } else {
        printf("No space at front.\n");
    }
}

void insertRear(Deque *d, const char *name) {
    if (isDequeFull(d)) {
        printf("Deque is full.\n");
        return;
    }

    if (isDequeEmpty(d)) {
        d->front = 0;
        d->rear = 0;
    } else {
        d->rear++;
    }

    strcpy(d->names[d->rear], name);
}

void deleteFront(Deque *d) {
    if (isDequeEmpty(d)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Removed from front: %s\n", d->names[d->front]);

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else {
        d->front++;
    }
}

void deleteRear(Deque *d) {
    if (isDequeEmpty(d)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Removed from rear: %s\n", d->names[d->rear]);

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else {
        d->rear--;
    }
}

void displayDeque(Deque *d) {
    if (isDequeEmpty(d)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque:\n");
    for (int i = d->front; i <= d->rear; i++) {
        printf("- %s\n", d->names[i]);
    }
}

int main() {
    Stack s;
    Queue q;
    Deque d;

    initStack(&s);
    initQueue(&q);
    initDeque(&d);

    printf("===== STACK TEST =====\n");
    push(&s, "Add customer Budi");
    push(&s, "Remove customer Siti");
    push(&s, "Add priority customer Andi");
    displayStack(&s);
    pop(&s);
    displayStack(&s);

    printf("\n===== QUEUE TEST =====\n");
    enqueue(&q, "Budi");
    enqueue(&q, "Siti");
    enqueue(&q, "Andi");
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);

    printf("\n===== DEQUE TEST =====\n");
    insertRear(&d, "Customer A");
    insertRear(&d, "Customer B");
    insertFront(&d, "VIP Customer");
    displayDeque(&d);
    deleteFront(&d);
    deleteRear(&d);
    displayDeque(&d);

    return 0;
}