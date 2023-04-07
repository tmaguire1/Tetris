#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// 10 x 20 Block

int shapesOrigin[7][4][4][2] = {

    { 
        {{ 2 , 0 }, { 3 , 0 }, { 0 , 0 }, {1 , 0}},
        {{2 , 0}, {2 , -1}, {2 , -2}, {2 , 1}},
        {{ 2 , 0 }, { 3 , 0 }, { 0 , 0 }, {1 , 0}},
        {{2 , 0}, {2 , -1}, {2 , -2}, {2 , 1}}
         }, 
        // Ishape

    {
        {{ 0 , 0 }, { 1 , 0 }, { 0 , 1 }, {1 , 1}},
        {{ 0 , 0 }, { 1 , 0 }, { 0 , 1 }, {1 , 1}}, 
        {{ 0 , 0 }, { 1 , 0 }, { 0 , 1 }, {1 , 1}}, 
        {{ 0 , 0 }, { 1 , 0 }, { 0 , 1 }, {1 , 1}} 
    
    }, 
    // Blockshape

    {
         {{ 1 , 0 }, { 0 , 0 }, { 2 , 0 }, {2 , 1}},
         {{ 1 , 0 }, { 1 , -1 }, { 1 , 1 }, {0 , 1}},
         {{ 1 , 0 }, { 2 , 0 }, { 0 , 0 }, {0 , -1}},
         {{ 1 , 0 }, { 1 , 1 }, { 1 , -1 }, {2 , -1}}
        
      }, 
     // Lshape

    { 
        {{ 1 , 0 }, { 0 , 0 }, { 2 , 0 }, {0 , 1}},
        {{ 1 , 0 }, { 1 , -1 }, { 0 , -1 }, {1 , 1}},
        {{ 1 , 0 }, { 0 , 0 }, { 2 , 0 }, {2 , -1}},
        {{ 1 , 0 }, { 1 , -1 }, { 1 , 1 }, {2 , 1}}
        
    }, 
    // Jshape

    { 
        {{ 1 , 0 }, { 2 , 0 }, { 1 , 1 }, {0 , 1}},
        {{ 1 , 0 }, { 1 , -1 }, {2 , 0 }, {2 , 1}},
        {{ 1 , 0 }, { 2 , 0 }, { 1 , 1 }, {0 , 1}},
        {{ 1 , 0 }, { 1 , -1 }, {2 , 0 }, {2 , 1}}
        
    }, 
    // Sshape

    { 
        {{ 1 , 0 }, { 0 , 0 }, { 2 , 0 }, {1 , 1}},
        {{ 1 , 0 }, { 1 , -1 }, {1 , 1 }, {0 , 0}},
        {{ 1 , 0 }, { 0 , 0 }, { 2 , 0 }, {1 , -1}},
        {{ 1 , 0 }, { 1 , -1 }, {1 , 1 }, {2 , 0}}
        
    }, 
    // Tshape

    {
        
        {{ 1 , 0 }, { 0 , 0 }, { 1 , 1 }, {2 , 1}},
        {{ 1 , 0 }, { 2 , 0 }, { 2 , -1 }, {1 , 1}},
        {{ 1 , 0 }, { 0 , 0 }, { 1 , 1 }, {2 , 1}},
        {{ 1 , 0 }, { 2 , 0 }, {2 , -1 }, {1 , 1}}


}    // Zshape
};




int activeShape[4];

int savedShape[4];

int savedShapeBoard[5][20] = {};

void clearSavedShapeBoard(){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            savedShapeBoard[i][j] = ' ';
        }
        
    }
    

}







bool gameOver = false;

int getRandomNumber(int lower, int upper,
                            int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
        (upper - lower + 1)) + lower;
        return num;
    }
}
void getRandomShape(){

    srand(time(0));

    int shapeIndex = getRandomNumber(0, 6, 1);
    int rotIndex = getRandomNumber(0, 3, 1);



    int shapeInfo[4] = {shapeIndex, rotIndex , 3, 3};

    addActiveShape(shapeInfo);

    
}

void addActiveShape(int info[4]){
    for (int i = 0; i < 4; i++)
    {
        activeShape[i] = info[i];
    }
    
}


char board[20][20] = {};

void blankBoard(){

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            board[i][j] = '_';
        }

        
    }
    
}



int score = 0;




void clearLine(int row){
    for (int i = row; i > 0; i--)
    {
    for (int j = 0; j < 20; j++)
    {
        board[i][j] = board[i - 1][j];
    }
    
        
    }
    
}

void checkForClearedLine(){


    int count = 0;


    for (int i = 0; i < 20; i++)
    {
        bool clear = true;
        for (int j = 0; j < 20; j++)
        {
            if(board[i][j] == '_'){
                clear= false;
            }
        }


        if(clear){
            clearLine(i);
            count += 1;
        }

        
    }

    score += (count * 100) * count;

}


void drawCube(int x, int y){

    board[y][x] = '[';
    board[y][x+1] = ']';
}

void drawSpace(int x, int y){

    board[y][x] = '_';
    board[y][x+1] = '_';
}

void printBoard(){


    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");


    printf("     Score : %d\n", score);

    // printf("     Saved Shape     \n");

    // printSavedShape();

    printf("\n");

    

    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 20; j++)
        {
            printf("%c", board[i][j]);
            
        }
        
        if (i == 0){
            printf("          Saved Shape");
        }
        else{
            printf("     ");
            if (i < 6){
                for (int j = 0; j < 20; j++)
                {
                    printf("%c",savedShapeBoard[i - 1][j]);
                    
                    
                }
            }

            if (i == 8){
                printf("     Move Left : A");
            }
            if (i == 9){
                printf("     Move Right : D");
            }

            if (i == 10){
                printf("     Move Down : S");
            }

            if (i == 11){
                printf("     Rotate Shape : W");
            }

            if (i == 12){
                printf("     Save / Swap Shape : Q");
            }

            if (i == 13){
                printf("     Stop Game : X");
            }
        }
        

        printf("\n");
        
    }


}


int functionShape[4][2];

void getShape(int info[4]){

    for (int i = 0; i < 4; i++)
    {
        functionShape[i][0] = shapesOrigin[info[0]][info[1]][i][0];
        functionShape[i][1] = shapesOrigin[info[0]][info[1]][i][1];
    }

}



int getX(int x, int xV){

    return (x + xV) * 2;
}

int getY(int y, int yV){

    return y + yV;
}


void drawShape(int info[4]){
    getShape(info);

    for (int i = 0; i < 4; i++)
    {

        int x = getX(functionShape[i][0], info[2]);
        int y = getY(functionShape[i][1], info[3]);

        drawCube(x, y);
    }
    

}


void drawSavedShape(int info[4]){
    getShape(info);

    for (int i = 0; i < 4; i++)
    {

        int x = getX(functionShape[i][0], 3);
        int y = getY(functionShape[i][1], 2);

        savedShapeBoard[y][x] = '[';
        savedShapeBoard[y][x+1] = ']';
    }
    

}




void removeShape(int info[4]){
    getShape(info);

    for (int i = 0; i < 4; i++)
    {

        int x = getX(functionShape[i][0], info[2]);
        int y = getY(functionShape[i][1], info[3]);

        drawSpace(x, y);
    }
    

}






bool checkForSameShape(int info[4], int newX, int newY){
    for (int i = 0; i < 4; i++)
    {
        int x = getX(functionShape[i][0], info[2]);
        int y = getY(functionShape[i][1], info[3]);

        if(x == newX && y == newY){
            return true;
        }
    }

    return false;
    
}


bool checkForCollision(int info[4], int xV, int yV){

    getShape(info);

    for (int i = 0; i < 4; i++)
    {
        int newX = getX(functionShape[i][0], xV);
        int newY = getY(functionShape[i][1], yV);

        if (newY >= 20){
            return true;
        }

        if (board[newY][newX] != '_'){
            
            if (!checkForSameShape(info, newX, newY)){
                return true;
            }
            
        }
    }


    return false;
    


}

checkXInBounds(int info[4], int xV){

    getShape(info);

    for (int i = 0; i < 4; i++)
    {
        int x = getX(functionShape[i][0], xV);

        if(x < 0 || x > 18){
            return true;
        }

    }

    return false;


}

int getXHighLow(int info[4], int xV){

    getShape(info);

    for (int i = 0; i < 4; i++)
    {
        int x = getX(functionShape[i][0], xV);
        

        if(x < 0 || x > 18){
            return x;
        }

    }

}

void moveShape(int xV, int yV){

    removeShape(activeShape);



    int originalX = activeShape[2];
    int originalY = activeShape[3];


    int newX = originalX + xV;
    int newY = originalY + yV;



    if (yV == 0){

    if(!checkXInBounds(activeShape, newX) && !checkForCollision(activeShape, newX, newY)){
        activeShape[2] = newX;
    }}

    else{

    if(!checkForCollision(activeShape, newX, newY)){

            activeShape[3] = newY;

    }else{
        drawShape(activeShape);
        getRandomShape();
        checkForClearedLine();
        if (checkForCollision(activeShape, 3, 4)){

            

            gameOver = true;
        }
        
    }
    }


    drawShape(activeShape);
    printBoard();


}


void rotateShape(){

    removeShape(activeShape);



    int originalRot = activeShape[1];

    int newRot;

    if(originalRot == 3){

        newRot = 0;

    }else{
        newRot = originalRot + 1;
    }

    int newInfo[4];

    newInfo[0] = activeShape[0];
    newInfo[1] = newRot;
    newInfo[2] = activeShape[2];
    newInfo[3] = activeShape[3];



    int xV = activeShape[2];

    if (checkXInBounds(newInfo, xV)){

        if(getXHighLow(newInfo, xV) < 0){
            while(checkXInBounds(newInfo, xV)){
                xV += 1;
            }
        }else{
            while(checkXInBounds(newInfo, xV)){
                xV -= 1;
            }
        }

    }

    newInfo[2] = xV;

    if(!checkForCollision(newInfo, xV, activeShape[3])){
        activeShape[1] = newRot;
        activeShape[2] = xV;
    }else{
        drawShape(activeShape);
        getRandomShape();
        checkForClearedLine();

        
        
    }


    drawShape(activeShape);
    printBoard();



}





int timeDelay = 1000;

int level = 1;

void setLevel(){
    if( timeDelay > 200 && score > level * 100){
        timeDelay -= 50;
        level += 1;
    }
}

bool hasSavedShape = false;

void saveShape(){

    removeShape(activeShape);

    int shapeToSave[4];

    shapeToSave[0] = activeShape[0];
    shapeToSave[1] = activeShape[1];
    shapeToSave[2] = 3;
    shapeToSave[3] = 3;

    

    if (hasSavedShape){
        addActiveShape(savedShape);

    }else{

        getRandomShape();


    }

    hasSavedShape = true;


    for (int i = 0; i < 4; i++)
    {
        savedShape[i] = shapeToSave[i];
    }

    


    
    
}


int main(){


    printf("\n\nWelcome To Tom's Tetris\n\n" );

    printf("Scoring :\n\n" );

    printf("1 Line  : 100pts\n");

    printf("2 Lines : 400pts\n");

    printf("3 Lines : 900pts\n");

    printf("4 Lines : 1600pts\n\n");

    printf("Speed will increase as you build a higher score.\n\n");

    printf("Shapes can be saved by press Q.\nThis will swap the current shape with the existing shape or for a random shape if you have not stored one already.\n\n");

    printf("See the controls below:\n");

    printf("Move Left : A \n");

    
    printf("Move Right : D \n");

    printf("Move Down : S \n");

    printf("Rotate Shape : W \n");

    printf("Save / Swap Shape : Q \n");

    printf("Stop Game : X \n");


    printf("\n\nPress the Enter Key to play \n");
    
    int cha;

    cha = getchar();


    bool playing = true;

    

    blankBoard();

    clearSavedShapeBoard();


    getRandomShape();

    drawShape(activeShape);

    
    


    printBoard();

    clock_t startTime = clock();

    float delay = 1000;

    while (playing)
    {

        if(gameOver){
            playing = false;
        }
        

        setLevel();

        if(kbhit()){

        char c = getch();

        

        if(c == 's'){

           moveShape(0, 1);
           

        }

        if(c == 'a'){

           moveShape(-1, 0);
           

        }

        if(c == 'd'){

           moveShape(1, 0);

           startTime = clock();
           


        }

        if(c == 'w'){

           rotateShape();
           


        }

        if(c == 'q'){

            
            saveShape();
            clearSavedShapeBoard();
            drawSavedShape(savedShape);
           


        }

        if(c == 'x'){

            
            playing = false;
           


        }




        



    }


    if(clock() > startTime + timeDelay){


        moveShape(0, 1);





        startTime = clock();

        


    }






    }
    

    


    printf("Game Over!\n");
    printf("\nYour Score Was : %d\n", score);
    printf("\nThank You For Playing\n");

   

    return 0;

}