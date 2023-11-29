#include <stdio.h>
#include <stdlib.h>

#define MONTH_DAYS 30

typedef struct Cell {
    int element;
    struct Cell* next;
}Cell;

Cell* createCell(int x){
    Cell* new = malloc(sizeof(Cell));
    new->element = x;
    new->next = NULL;
    return new;
}

void show(Cell* head){
    Cell* i = head->next;
    while (i != NULL)
    {
        printf("%d ", i->element);
        i = i->next;
    }
    printf("\n");
}

void add(Cell** tail, int num){
    (*tail)->next = createCell(num);
    *(tail) = (*tail)->next;
}

int withdraw(Cell** head){
    Cell* tmp = (*head)->next;
    int res = tmp->element;
    (*head)->next = (*head)->next->next;
    tmp->next = NULL;
    free(tmp);
    return res;
}
// -----------------------------------------------------------------------------------------
int average(Cell* day){
    int sum = 0, avg;
    for(int i = 0; i < MONTH_DAYS; i++, day = day->next){
        sum += day->element;
    }
    avg = sum / MONTH_DAYS;

    return avg;
}

int daysRequied(int current_followers, int goal_followers, Cell** head, Cell** tail) {

    int past_days = 0;

    while(current_followers < goal_followers) {

        int curr_avg = average((*head)->next);

        current_followers += curr_avg;
        add(tail, curr_avg);
        withdraw(head);

        past_days++;
    }
    return past_days;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    Cell* head = malloc(sizeof(Cell));
    head->next = NULL;
    Cell* currDay = head;

    for(int i = 0; i < MONTH_DAYS; i++)
    {
        int subs;
        scanf("%d", &subs);

        add(&currDay, subs);
    }
    
    printf("%d\n", daysRequied(N, M, &head, &currDay));

    return 0;
}