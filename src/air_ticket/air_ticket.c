//
// Created by User on 16.03.2022.
//
#include<stdio.h>
#include<stdlib.h>
#include "air_ticket.h"
air_ticket * air_ticket_constructor(char *key_dep, char * departure,char *key_des, char* destination, int duration,int price){
    air_ticket * buf = (air_ticket*)malloc(sizeof(air_ticket));
    buf->key_dep = key_dep;
    buf->departure = departure;
    buf->key_des = key_des;
    buf->destination = destination;
    buf->duration = duration;
    buf->price = price;
    return buf;
}

void air_ticket_print(air_ticket * ticket){
    if(ticket == NULL){
        return;
    }

    printf("%s%s", ticket->departure, "(");
    printf("%s%s", ticket->key_dep, ") to ");
    printf("%s%s", ticket->destination, "(");
    printf("%s%s", ticket->key_des, ")\n");
    printf("%d%s", ticket->duration, " hours\n");
    printf("%d%s", ticket->price, " dollars\n\n");
}
void air_ticket_input(air_ticket * ticket, char * key_dep, char * departure,char * key_des, char* destination, int duration,int price){
    ticket->key_dep = key_dep;
    ticket->departure = departure;
    ticket->key_des = key_des;
    ticket->destination = destination;
    ticket->duration = duration;
    ticket->price = price;
}
air_ticket_array * air_ticket_array_constructor(size_t length){
    air_ticket_array * temp = (air_ticket_array*)malloc(sizeof(air_ticket_array));
    temp->tickets = (air_ticket*)malloc(length * sizeof(air_ticket));
    temp->size = length;
    return temp;
}
void print_array(air_ticket_array *array){
    if(array==NULL)
        return;
    for(int i=0; i<array->size; ++i){
        air_ticket_print(&array->tickets[i]);
    }
}
void freearray(air_ticket_array *array){
    free(array->tickets);
    array->tickets = NULL;
    free(array);
    array = NULL;

}