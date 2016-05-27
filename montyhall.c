#include <stdio.h>
#include <stdlib.h>

int running = 1;

int main(void){

 while(running){

  int switch_door = 0;
  int games = 0;
  int wins = 0;
  int loss = 0;

  printf("Welcome to the Monty Hall Simulator\n\
Please input how many times you want to play the game:\n");

  scanf("%d", &games);

  printf("Manual or Automatic Switching? (Manual = 1,\
 Automatic = 0)\n");

  scanf("%d", &switch_door);

  if(switch_door){
   //Manual switching
   for(int i = games; i > 0; --i){

    printf("Game %d start!\n", games + 1 - i);

    int winning_door = rand()%3 + 1;
    int choice = rand()%3 + 1;
    int opened_door;

    printf("You chose door #%d\n", choice);

    if(choice != 1 && winning_door != 1 ){

     opened_door = 1;

     printf("The host opens door #1, revealing a goat!\n\
Do you switch doors? (Yes = 1, No = 0)\n");

     scanf("%d", &switch_door);

    }else if(choice != 2 && winning_door != 2 ){

     opened_door = 2;

     printf("The host opens door #2, revealing a goat!\n\
Do you switch doors? (Yes = 1, No = 0)\n");

     scanf("%d", &switch_door);

    }else if(choice != 3 && winning_door != 3 ){

     opened_door = 3;

     printf("The host opens door #3, revealing a goat!\n\
Do you switch doors? (Yes = 1, No = 0)\n");

     scanf("%d", &switch_door);

    }

    if(switch_door){
     if(opened_door != 1 && choice != 1){
      choice = 1;
      printf("You have switched to door #1!\n");
     }else if(opened_door != 2 && choice != 2){
      choice = 2;
      printf("You have switched to door #2!\n");
     }else if(opened_door != 3 && choice != 3){
      choice = 3;
      printf("You have switched to door #3!\n");
     }
    }

    printf("The door opens...\n");
    if(choice == winning_door){
     printf("You have won! Door #%d was the winning door!\n", winning_door);
     ++wins;
    }else{
     printf("Sorry you lost! Door #%d was the winning door!\n", winning_door);
     ++loss;
    }
   }
  }else{
   //automatic switching
   int switched_games = 0;

   printf("How many games in your %d games do you want\
 to switch?\n", games);
   scanf("%d", &switched_games);

   for(int i = games; i > 0; --i){

    //printf("Game %d start!\n", games + 1 - i);

    int winning_door = rand()%3 + 1;
    int choice = rand()%3 + 1;
    int opened_door;

    //printf("You chose door #%d\n", choice);

    if(choice != 1 && winning_door != 1 ){

     opened_door = 1;

     //printf("The host opens door #1, revealing a goat!\n");

    }else if(choice != 2 && winning_door != 2 ){

     opened_door = 2;

     //printf("The host opens door #2, revealing a goat!\n");

    }else if(choice != 3 && winning_door != 3 ){

     opened_door = 3;

     //printf("The host opens door #3, revealing a goat!\n");
    }

    if(i < switched_games){
     if(opened_door != 1 && choice != 1){
      choice = 1;
      //printf("You have switched to door #1!\n");
     }else if(opened_door != 2 && choice != 2){
      choice = 2;
      //printf("You have switched to door #2!\n");
     }else if(opened_door != 3 && choice != 3){
      choice = 3;
      //printf("You have switched to door #3!\n");
     }
    }

    //printf("The door opens...\n");
    if(choice == winning_door){
     //printf("You have won! Door #%d was the winning door!\n", winning_door);
     ++wins;
    }else{
     //printf("Sorry you lost! Door #%d was the winning door!\n", winning_door);
     ++loss;
    }
   }
  }


  printf("Games: %d, Won: %d, Lost: %d\n", games, wins, loss);
  float win_rate = wins * 100 / games; 
  
  printf("Win percentage: %f%%\n", win_rate);

  printf("Play again? (Yes = 1, No = 0)\n");

  scanf("%d", &running);
 }
}
