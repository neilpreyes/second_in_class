#include <stdio.h> //input/output library
#include <stdlib.h> //random number generator
#include <time.h> //time/date utilities
#include <stdbool.h>//boolean variable

void getRandNum();
void addNumToArray(int);
bool isLoShu();
void squareGrid();
void winningTest();
const int size = 3;
int square[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};


int main(){
    printf("size is ");
    printf("%d", size);

    int count = 0;
    printf("Number of Tries: ");
    printf("\n");

    do{
        count++;
        printf("%d", count);
        printf("\n");
        getRandNum();

        if(count == 1000){//prevent from calculating too much
            break;
        }

        //test case
        /*
        if(count == 50){
            winningNum();
        }*/

    }while(!isLoShu());

    squareGrid();
    printf("It took ");
    printf("%d", count);
    printf(" number of tries to get a magic square.");

    return 0;
}

void squareGrid(){
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){
            printf("%d", square[i][j]);
        }
        printf("\n");

    }
}

void getRandNum(){
    int num = 0;
    int usedNum[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //keep track of numbers that i have used

    srand(time(NULL));
    bool isNumUsed = true;
    
    for (int i = 0; i < 9; i++){
        //finds new number not used
        do{
            isNumUsed = true; //reset true for every loop

            num = (rand() % 9) + 1;

            //uses arr to input numbers used
            if(usedNum[num - 1] == 0){

                usedNum[num - 1] == num;
                isNumUsed = false;
            }

        }while(isNumUsed); //stops when new number is inputted

        addNumToArray(num);
    }

}

void addNumToArray(int num){
    //loops through array looking for an empty slot
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){
            //adds number to array if empty slot
            if(square[i][j] == 0){
                square[i][j] = num;
                return;
            }

        }

    }
}

bool isLoShu(){

    int sum = square[0][0] + square[0][1] + square[0][2];
    int checkSum;
    
    //check rows
    for(int i = 1; i < size; i++){
        checkSum = (square[i][0] + square[i][1] + square[i][2]);
        if(checkSum != sum){
            return false;
        }
    }

    //check columns
    for(int i = 0; i < size; i++){
        checkSum = (square[0][i] + square[1][i] + square[2][i]);
        if(checkSum != sum){
            return false;
        }
    }
    
    checkSum = (square[0][0] + square[1][1] + square[2][2]);
    if(checkSum != sum){
        return false;
    }

    checkSum = (square[0][2] + square[1][1] + square[2][0]);
    if(checkSum != sum){
        return false;
    }

    return true;
}

/*
void winningNum(){
    square[0][0] = 4;
    square[0][1] = 9;
    square[0][2] = 2;
    square[1][0] = 3;
    square[1][1] = 5;
    square[1][2] = 7;
    square[2][0] = 8;
    square[2][1] = 1;
    square[2][2] = 6;
}*/