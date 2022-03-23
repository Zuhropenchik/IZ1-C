//
// Created by User on 17.03.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "air_ticket.h"
#include "search.h"
#include "input.h"

char * get_str(){
    size_t size = 4;
    char *tempo = (char*)malloc(size * sizeof(char));
    char sym = getchar();
    int i= 0;
    for(;sym!=' ' && sym!= '\n' && sym!= '\0' && sym!= '\t'; i++){
        if(i == size){
            size = size * 2;
            tempo = (char*)realloc(tempo, size);

        }
        tempo[i] = sym;
        sym = getchar();
    }
    if(i == size){
        tempo = (char*)realloc(tempo, size+1);
        size = size * 2;
    }
    tempo[i] = '\0';
    return tempo;
}
int testing_key(char * key){
    if(strlen(key)!=3){
        return 0;
    }
    for(int i=0; key[i]!='\0'; ++i){
        if(key[i]<'A' || key[i]>'Z'){
            return 0;
        }
    }

    return 1;
}
void input_ticket(air_ticket * ticket){
    if(!ticket){
        return;
    }
    char *key_dep;
    char *departure;
    char * key_des;
    char *destination;
    int duration;
    int price;
    key_dep = get_str();
    while(testing_key(key_dep)!=1) {
        printf("Incorrect input of key of departure. Try again:\n");
        key_dep = get_str();
    }
    departure = get_str();
    key_des = get_str();
    while(testing_key(key_des)!=1) {
        printf("Incorrect input of key of destination. Try again:\n");
        key_des = get_str();
    }
    destination = get_str();
    duration = atoi(get_str());
    while(duration<0){
        printf("Incorrect input of duration. Try again:\n");
        duration = atoi(get_str());
    }
    price = atoi(get_str());
    while(price<0){
        printf("Incorrect input of price. Try again:\n");
        price = atoi(get_str());
    }
    air_ticket_input(ticket, key_dep, departure, key_des, destination, duration, price);
}
void input_array(air_ticket_array * array){
    if(!array) {
        return;
    }
    for(int i=0; i<array->size; i++){
        input_ticket(&array->tickets[i]);
    }
}
void interface(air_ticket_array * array){
    printf("Input \"exit\" to complete the program\n");
    printf("Input \"price\" + two cities to find the cheapest flight\n");
    printf("Input \"duration\" + two cities to find the quickest flight\n");
    printf("Input \"print\" to print all flights\n");
    fflush(stdin);
    char * temp = get_str();
    while(strcmp(temp, "exit") != 0){
        if(strcmp(temp, "price") == 0){
            char * departure = get_str();
            char * destination = get_str();
            search_price(array, departure, destination);
        }
        else if(strcmp(temp, "duration") == 0){
            char * departure = get_str();
            char * destination = get_str();
            search_duration(array, departure, destination);
        }
        else if(strcmp(temp, "exit") == 0) {
            free(temp);
            return;
        }
        else if(strcmp(temp, "print") == 0) {
            print_array(array);
        }
        else {
            printf("Unknown command. Please try again\n");
        }
        temp = get_str();
    }
}