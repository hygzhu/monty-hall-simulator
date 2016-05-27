#include <stdio.h>
#include <stdlib.h>

//note: does not consider leap years
int main(void){

 int running = 1;

 while(running){

  int room_capacity = 0;
  int num_rooms = 0;
  int pair_found = 0;


  printf("How many people are in each room?\n");
  scanf("%d", &room_capacity);

  printf("How many rooms are there?\n");
  scanf("%d", &num_rooms);

  for(int i = 0; i < num_rooms; ++i){

   int same_birthday = 0;

   int *person = malloc(sizeof(int)* room_capacity); 

   for(int i = 0; i < room_capacity; ++i){



    person[i] = rand()%364 + 1;
    //printf("Person %d is born on day %d\n", i + 1, person[i]);

    //check if theres another same birthday
    int n = 0;
    while(n < i){
     if(person[n] == person[i]){
      ++same_birthday;
     }
     ++n;
    }
   }
   //printf("In a room with %d people, there are %d same\
   //birthday pairs\n", room_capacity, same_birthday);

    if(same_birthday){
    ++pair_found;
   }

   free(person);
  }
  printf("In %d rooms of %d people, %d rooms had at \
 least one pair of people with the same birthday.\n",
         num_rooms, room_capacity, pair_found);
  
  float percent = (float) pair_found * 100 / (float) num_rooms;
  
  printf("Therefore the percent of having a pair in \
 a room of %d people was %f%%\n", room_capacity, percent);
  
  printf("Try again? (Yes = 1, No = 0)\n");
  scanf("%d", &running);
  
 }
 
}