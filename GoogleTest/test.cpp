#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include "air_ticket.h"
}
bool is_air_ticket_equal(air_ticket * air_ticket1, air_ticket * air_ticket2){
    if(air_ticket1->price != air_ticket2->price || air_ticket1->duration != air_ticket2->duration)
        return false;
    if(strcmp(air_ticket1->key_dep, air_ticket2->key_dep)!=0 || strcmp(air_ticket1->key_des, air_ticket2->key_des)!=0)
        return false;
    if(strcmp(air_ticket1->departure, air_ticket2->departure)!=0 ||
    strcmp(air_ticket1->destination, air_ticket2->destination)!=0)
        return false;
    return true;
}
bool is_array_equal(air_ticket_array * array1, air_ticket_array * array2){
    size_t i;
    for(size_t i=0; i<array1->size && i<array2->size; ++i){
        if(!is_air_ticket_equal(&array1->tickets[i], &array2->tickets[i]))
            return false;
    }
    if(i == array1->size && i == array2->size)
        return true;
}
TEST(air_ticket_test, air_ticket_constructor_test){
    air_ticket * ticket_test1 = (air_ticket*)malloc(sizeof(air_ticket));
    air_ticket * ticket_test2 = (air_ticket*)malloc(sizeof(air_ticket));
    ticket_test1->key_dep = "DME";
    ticket_test1->departure = "Moscow";
    ticket_test1->key_des = "NRT";
    ticket_test1->destination = "Tokyo";
    ticket_test1->duration = 10;
    ticket_test1->price = 200;
    ticket_test2->key_dep = "AER";
    ticket_test2->departure = "Sochi";
    ticket_test2->key_des = "VOZ";
    ticket_test2->destination = "Voronezh";
    ticket_test2->duration = 3;
    ticket_test2->price = 50;
    air_ticket * ticket = air_ticket_constructor("DME", "Moscow", "NRT", "Tokyo", 10, 200);
    EXPECT_EQ(true,is_air_ticket_equal(ticket_test1,ticket));
    EXPECT_EQ(false,is_air_ticket_equal(ticket_test2,ticket));
    free(ticket_test1);
    free(ticket_test2);
    free(ticket);
}
TEST(array_test, air_ticket_array_constructor_test){
    air_ticket_array * test_array= (air_ticket_array*)malloc(sizeof(air_ticket_array));
    test_array->size = 0;
    air_ticket_array * array = air_ticket_array_constructor(0);
    EXPECT_EQ(true,is_array_equal(test_array,array));
    free(test_array);
    free(array);
}
TEST(input_test, air_ticket_input_test){
    air_ticket * ticket_test = (air_ticket*)malloc(sizeof(air_ticket));
    ticket_test->key_dep = "DME";
    ticket_test->departure = "Moscow";
    ticket_test->key_des = "NRT";
    ticket_test->destination = "Tokyo";
    ticket_test->duration = 10;
    ticket_test->price = 200;
    air_ticket * ticket = (air_ticket*)malloc(sizeof(air_ticket));
    air_ticket_input(ticket, "DME", "Moscow", "NRT", "Tokyo", 10, 200);
    EXPECT_EQ(true, is_air_ticket_equal(ticket_test,ticket));
}