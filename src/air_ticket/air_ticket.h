//
// Created by User on 16.03.2022.
//

#ifndef UNTITLED1_AIR_TICKET_H
#define UNTITLED1_AIR_TICKET_H

#endif //UNTITLED1_AIR_TICKET_H

typedef struct {
    char *key_dep;
    char *departure;
    char *key_des;
    char *destination;
    int duration;
    int price;
}air_ticket;
typedef struct {
    air_ticket *tickets;
    size_t size;
}air_ticket_array;

air_ticket * air_ticket_constructor(char *key_dep, char * departure,char *key_des, char* destination, int duration,int price);
void air_ticket_print(air_ticket * ticket);
void air_ticket_input(air_ticket * ticket, char *key_dep, char * departure,char *key_des, char* destination, int duration,int price);
air_ticket_array * air_ticket_array_constructor(size_t size);
void print_array(air_ticket_array *array);
void freearray(air_ticket_array *array);