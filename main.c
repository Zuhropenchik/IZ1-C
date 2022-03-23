#include <stdio.h>
#include <stdlib.h>
#include "air_ticket.h"
#include "search.h"
#include "input.h"
int main() {
    int n;
    printf("Input number of air_ticket\n");
    scanf("%d", &n);
    air_ticket_array * ticketArray = air_ticket_array_constructor(n);
    input_array(ticketArray);
    interface(ticketArray);
    freearray(ticketArray);
    return 0;
}
