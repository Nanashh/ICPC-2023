#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct 
{
    int weight;
    int value;
} Treasure;

typedef struct 
{
    Treasure heap[MAX_SIZE];
    int size;
} PriorityQueue;

void push(PriorityQueue *pq, Treasure value) 
{
    int i = pq->size++;
    while (i > 0) {
        int j = (i - 1) / 2;
        if (pq->heap[j].value >= value.value) break;
        pq->heap[i] = pq->heap[j];
        i = j;
    }
    pq->heap[i] = value;
}

Treasure top(PriorityQueue *pq) 
{
    return pq->heap[0];
}

void pop(PriorityQueue *pq) 
{
    Treasure value = pq->heap[--pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) 
	{
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int j = left;
        if (right < pq->size && pq->heap[right].value > pq->heap[left].value)
            j = right;
        if (pq->heap[j].value <= value.value)
            break;
        pq->heap[i] = pq->heap[j];
        i = j;
    }
    pq->heap[i] = value;
}

int empty(PriorityQueue *pq) 
{
    return pq->size == 0;
}

int compare(const void *first_value, const void *second_value) 
{
    return *(int *)first_value - *(int *)second_value;
}

int main() {
    int trea, cart;
    scanf("%d %d", &trea, &cart);

    Treasure treasures[trea];
    for (int s = 0; s < trea; s++) {
        scanf("%d %d", &treasures[s].weight, &treasures[s].value);
    }

    int hcart[cart];
    for (int s = 0; s < cart; s++) 
	{
        scanf("%d", &hcart[s]);
    }

    qsort(treasures, trea, sizeof(Treasure), compare);
    qsort(hcart, cart, sizeof(int), compare);

    PriorityQueue pq;
    pq.size = 0;

    int s = 0;
    long long int maxValue = 0;
    for (int t = 0; t < cart; t++)
	 {
        while (s < trea && treasures[s].weight <= hcart[t]) 
		{
            push(&pq, treasures[s++]);
        }
        if (!empty(&pq))
		 {
            maxValue += top(&pq).value;
            pop(&pq);
        }
    }

    printf("%lld\n", maxValue);

    return 0;
}
