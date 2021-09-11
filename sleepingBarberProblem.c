#include <stdio.h>

int front = 0, rear = 0, count = 0;                                                     // properties of the queue with it's initial values

void waitingRoom (int chairs) {
    int i, j = 1;
    printf ("\n-----Current waiting room-----\n\n |");
    for (i = 0; i < chairs; i++) {
        if (j <= count) {                                                               // if there is a customer
            /* code */
            printf ("     Customer No.%d     |", j);
            j++;

        }else {                 // no customer
            printf ("      Empty chair       |");

        } 
    }
}

void enqueue (int chairs) {
    if (count == 0) {                                                                   // when the 1st customer arrives
        printf("\nThe barber is sleeping...zzz...zzz...zzz\n");
        rear = (rear + 1) % chairs;
        count++;
        printf ("The 1st customer is going to awake the barber and get the service\n");

    }else if (count == chairs) {                                                        // when waiting room is full
        /* code */
        printf ("\nThe waiting room is full\n");
        printf ("The new customer is leaving\n");

    }else {                                                                             // if there are customers and empty  chairs are available
        printf ("\nThe barber is working\n");
        rear = (rear + 1) % chairs;
        count++;
        printf ("The new customer can wait in the waiting room\n");

    }
}

void dequeue (int chairs) {
    if (count == 0) {                                                                   // when queue is empty
        printf ("\nThe shop is empty\n");
        printf ("The barber is sleeping...zzz...zzz...zzz\n");

    }else { 
        front = (front + 1) % chairs;
        count--;

        if (count > 0) {                                                                // when the queue is not empty
            printf ("\nOne is leaving\n");
            printf ("The waiting room is not full\n");

        }else {                                                                         // when the last items is dequeued
            printf ("\nThe last one is leaving\n");
            printf ("The shop is empty\n");
            printf("The barber is going to sleep\n");
    
        }
    }
    
}

int main () {
    int chairs = 0, action;
    printf ("Number of chairs = ");
    scanf ("%d", &chairs);

    do
    {
        /* code */
        printf ("\n\n-----Actions-----\n");
        printf ("1. Check waiting room\n");
        printf ("2. A new cutomer's arrival\n");
        printf ("3. The barber is working\n");
        printf ("4. Exit\n\n");
        printf ("   What is the action : ");
        scanf ("%d", &action);

        switch (action)
        {
        case 1:
            /* code */
            waitingRoom (chairs);
            break;

        case 2:
            enqueue (chairs);
            break;

        case 3:
            dequeue (chairs);
            break;
        
        default:
            break;

        }

    } while (action != 4);
    
}