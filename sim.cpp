#include "raylib.h"
#include "math.h"
#include "stdlib.h"
#include "iomanip"


int main(void) {


// initialization ----------------------------------------------------------

int xValue = GetRandomValue(-10,10);

//bool assignVariables = false;

const int screenWidth = 600;
const int screenHeight = 600;

InitWindow(screenWidth, screenHeight, "Particle Fire Explosion");       // InitWindow(1000, 600, "beep bop");

SetTargetFPS(60);

const static int NPARTICLES = 10000;

float arrayParticlesX[NPARTICLES] = {};  
float arrayParticlesY[NPARTICLES] = {}; 

double xArray[NPARTICLES] = {};
double yArray[NPARTICLES] = {};

int randomX[NPARTICLES] = {};
int randomY[NPARTICLES] = {};

float xx;
float yy;

    int xCoord = 0;
    int yCoord = 0;
    
    int value2 = GetRandomValue(-1000, 1000);
    float value;
    
//----------------------------------------------

//create a particle at a random point that changes color, then do that 200 times


// array that creates particle variables int 1 to 200, then for each pixel sets coordinates, then change color for all pixels
    
//random number between -1 and 1
// const float xSpeed = roundf(((GetRandomValue(1, 2000)/2000) - 1) *100 ) / 100; 
// const float xSpeed = roundf(((GetRandomValue(1, 2000)/2000) - 1) *100 ) / 100; 


for (int i=0; i<NPARTICLES; i++) {
      
    xCoord = screenWidth / 2;          //GetRandomValue(1, (screenWidth -1));                                
    yCoord = screenHeight / 2;         //GetRandomValue(1, (screenHeight -1)); 


    value2 = GetRandomValue(-1000, 1000);
    value = value2;
    value /= 1000;
    
    xArray[i] = value;
    
    value2 = GetRandomValue(-1000, 1000);
    value = value2;
    value /= 1000;
    
    yArray[i] = value;
   
    
    arrayParticlesX[i] = xCoord; //xcoord for pixel i
    arrayParticlesY[i] = yCoord; // ycoord for pixel i
 
    //speed and direction of particle i
    //gets value between -1 & +1
    
    
    
  //  (GetRandomValue(1, 200)/100.0f) -1;
}
//----------------------------------------------

bool reverse1 = false;
bool reverse2 = false;
bool reverse3 = false;

double ticks1 = 0;
double ticks2 = 0;
double ticks3 = 0;

//int framesCounter = 0; 

//main game loop ----------------------------------------------------

while (!WindowShouldClose()) {
    //update - code constantly run -> update variables between here and before the beginDrawing();
//  --------------------------------------------------------------
// Every two seconds (120 frames) a new random value is generated

/*        framesCounter++;
        if (((framesCounter/120)%2) == 1)
        {
            randValue = GetRandomValue(-8, 5);
            framesCounter = 0;
        }


    if(!assignVariables) {
        xArray[20] = GetRandomValue(-10.0f, 10.0f);
        xArray[20] = xArray[20];
        assignVariables = true;
    }
    
*/
       
       
    if(!reverse1) {
     if(ticks1 > 254) {
         reverse1 = true;
     } else {
         ticks1++;
     }
    } 
        
    if(reverse1) {
     if(ticks1 < 1) {
         reverse1 = false;
     } else {
         ticks1--;
     }
    } 
    
    //--------------------------------------
    
        if(!reverse3) {
     if(ticks3 > 254) {
         reverse3 = true;
     } else {
         ticks3++;
     }
    } 
        
    if(reverse3) {
     if(ticks3 < 1) {
         reverse3 = false;
     } else {
         ticks3 -= 0.9;
     }
    } 
    
    //---------------------------------------
    
        if(!reverse2) {
     if(ticks2 > 254) {
         reverse2 = true;
     } else {
         ticks2 += 1.1;
     }
    } 
        
    if(reverse2) {
     if(ticks2 < 1) {
         reverse2 = false;
     } else {
         ticks2 -= 1.1;
     }
    } 
 
 
 unsigned char red = ticks3;
 unsigned char green = ticks1;
 unsigned char blue = ticks2;
 
 ClearBackground(BLACK);
 
    for (int i=0; i<NPARTICLES; i++) { 
    ClearBackground(BLACK);
   
    xx = xArray[i];
    yy = yArray[i];
   
    xArray[i] = sin(xx) * tan(arrayParticlesX[i]) * 4; 
    yArray[i] = cos(yy) * tan(arrayParticlesY[i]) * 4;

    arrayParticlesX[i] += xArray[i];
    arrayParticlesY[i] += yArray[i];
   
    double x = arrayParticlesX[i];
    double y = arrayParticlesY[i];
    
   
    if((x > 0) && (x < screenWidth) && (y > 0) && (y < screenHeight)){
    DrawPixel(x, y, (Color){ red, green, blue, 255 });
    } else { 
       
       if (x <= 0 || x >= screenWidth)  {
       xArray[i] = -xArray[i];      
       }

       if (y <= 0 || y >= screenHeight) {
       yArray[i] = -yArray[i]; 
       }
       
    arrayParticlesX[i] += xArray[i];
    arrayParticlesY[i] += yArray[i];
    
    DrawPixel(x, y, (Color){ red, green, blue, 255 });
       
    }
    }




//


//  --------------------------------------------------------------
    
    BeginDrawing();
    //make sure to set the background or else epilepsy
   // ClearBackground(WHITE);
    
    // for(int y=0; y < screenHeight; y++) {
     //     for(int x=0; x < screenWidth; x++) {
   
     // DrawText(FormatText("%f", value), 30, 50, 20, WHITE);
      
   /*   
      DrawText(FormatText("%.2f", xArray[20]), 360, 180, 20, LIGHTGRAY);
      DrawText(FormatText("%.2f", yArray[20]), 360, 500, 20, LIGHTGRAY);
       DrawText(FormatText("%.2f", xArray[19]), 30, 180, 20, LIGHTGRAY);
      DrawText(FormatText("%.2f", yArray[19]), 30, 500, 20, LIGHTGRAY);
      */
      
   
      

      
      
      //DrawText(FormatText("%i", xArray[20]), 100, 300, 80, LIGHTGRAY);
      
    EndDrawing();
    
     
}
     //de-initialization ----------------------------------------------------------------
     
     
     
     CloseWindow();
     return 0;

}
