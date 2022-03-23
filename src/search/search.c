//
// Created by User on 17.03.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "air_ticket.h"
#include "search.h"
void search_price(air_ticket_array *array, char* departure, char* destination) {
    if (!array || array->size == 0){
        printf("No suitable flights.\n");
        return;
}
    int min = 0;
    for(int i=0; i<array->size; ++i){
        if(strcmp(array->tickets[i].departure, departure)==0 && strcmp(array->tickets[i].destination, destination)==0){
            if(array->tickets[min].price > array->tickets[i].price){
                min = i;
            }
        }

    }
    if(strcmp(array->tickets[min].departure, departure) == 0 && strcmp(array->tickets[min].destination, destination) == 0) {
        printf("The cheapest flight:\n");
        air_ticket_print(&array->tickets[min]);
    } else
        printf("No suitable flights.\n");
}
void search_duration(air_ticket_array *array, char* departure, char* destination){
    if (!array || array->size == 0){
        printf("No suitable flights.\n");
        return;
    }
    int min = 0;
    for(int i=0; i<array->size; ++i){
        if(strcmp(array->tickets[i].departure, departure)==0 && strcmp(array->tickets[i].destination, destination)==0){
            if(array->tickets[min].duration > array->tickets[i].duration){
                min = i;
            }
        }

    }
    if(strcmp(array->tickets[min].departure, departure) == 0 && strcmp(array->tickets[min].destination, destination) == 0) {
        printf("The quickest flight:\n");
        air_ticket_print(&array->tickets[min]);
    } else
        printf("No suitable flights.\n");
}