/********************************************************************************
Memory game: during each turn the players will gain points. You will have
to remember each players score and calculate the players total. After all rounds
are completed you will have to guess the final score.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME 1 // time in seconds
#define MAX 20 // number of players limit

int userPrompt(int value, char *valName);
void scoreCounter(int players, int rounds);
void printRoundNumber(int i, int rounds);
void playerCounter(int players, int i, int rounds, int temp, int *playerScore);
int generateRandomNumber();
void delay(int millis);


int main()
{
    int numPlayers=0, numRounds=0;
    char players[10] = "players";
    char rounds[10] = "rounds";

    printf("Memory game: during each turn the players will gain points. \nYou will have to remember each players score and calculate the players total. \nAfter all rounds are completed you will have to guess the final score.\n\n");

    numPlayers = userPrompt(numPlayers, players);
    numRounds = userPrompt(numRounds, rounds);

    scoreCounter(numPlayers, numRounds);

    return 0;
}


int userPrompt(int value, char *valName)
{
    printf("Please enter the number of %s from 1-20: ", valName);
    scanf("%d", &value);

    if (value <= 0|| value > MAX) {
        printf("Invalid input - try again with an integer value");
        exit(0);
    }

    return (value);
}


void scoreCounter(int players, int rounds)
{
    int temp = 0;
    int playerScore[MAX] = {0};

    srand(time(0)); // generates random seed based on time

    for (int i = 0; i <= rounds; i++)
    {
        // delay and clear screen
        if (i != 0) {
            delay(TIME);
            system("cls");    //->Windows
            //system("clear");    //->UNIX


        }

        printRoundNumber(i, rounds);
        playerCounter(players, i, rounds, temp, playerScore);
    }

    return;
}


void printRoundNumber(int i, int rounds)
{
    if (i != rounds)
        printf("Round %d: \n", i + 1);
    else
        printf("Score of %d total rounds:\n", i);

    return;
}


void playerCounter(int players, int i, int rounds, int temp, int *playerScore)
{
    for (int j = 0; j < players; j++) {

        if (i != rounds) {
            temp = generateRandomNumber();
            printf("Player %d: %d\n", j + 1, temp);

            playerScore[j] += temp;
        }
        else
            printf("Player %d total: %d\n", j + 1, playerScore[j]);
    }

    return;
}


int generateRandomNumber()
{
    return (rand() % 10 + 3.0);		// returns a random number between 3-12
}


void delay(int millis)
{
    clock_t start = clock();
    while (clock() < start + (millis * 1000));

    return;
}
