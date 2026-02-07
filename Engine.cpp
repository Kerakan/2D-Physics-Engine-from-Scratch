#include <iostream>
#include "raylib.h"
#include "Vector2.h"
#include <vector>
#include <string>
struct Ball{//Define Ball which will be useful for later
        Vec2 pos;
        Vec2 vel;
    };
int main(){    
    InitWindow(1280,720,"2D Physics Engine");
    SetTargetFPS(120);//Set a target FPS so the engine doesn't crash trying to get 1000 FPS
    std::vector <Ball> Balls;
    int n;
    Vec2 ballVel(200,100);
    bool gamestarted=false;
    std::string Number="";
    while (not WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        if (not gamestarted){//We track the number of balls the user wants to use
            if(IsKeyPressed(KEY_ZERO)){
                Number+="0";
            }
            if(IsKeyPressed(KEY_ONE)){
                Number+="1";
            }
            if(IsKeyPressed(KEY_TWO)){
                Number+="2";
            }
            if(IsKeyPressed(KEY_THREE)){
                Number+="3";
            }
            if(IsKeyPressed(KEY_FOUR)){
                Number+="4";
            }
            if(IsKeyPressed(KEY_FIVE)){
                Number+="5";
            }
            if(IsKeyPressed(KEY_SIX)){
                Number+="6";
            }
            if(IsKeyPressed(KEY_SEVEN)){
                Number+="7";
            }
            if(IsKeyPressed(KEY_EIGHT)){
                Number+="8";
            }
            if(IsKeyPressed(KEY_NINE)){
                Number+="9";
            }
            if(IsKeyPressed(KEY_BACKSPACE)){
                if (Number.size()>=1){
                Number=Number.substr(0,Number.size()-1);
                }
            }
            if (IsKeyPressed(KEY_ENTER)){//If the user presses enter we start teh simulation with n balls
                    gamestarted=true;
                    if (Number.size()>0){
                        n=std::stoi(Number);
                    }
                    else{
                        n=0;
                    }
                    Balls.reserve(n);
                    for (int i=0;i<n;i++){//get random x and y positions and initialize the n balls used on the simulation
                        int x= GetRandomValue(20, 1260);
                        int y= GetRandomValue(20, 700);
                        Vec2 B(x,y);//With a large number of balls we get some balls initializing on each which leads to some unwanted bugs, will have to look for a workaround while I add Quadtree
                        Ball b; b.pos=B;b.vel=ballVel;//We give the same initial velocity to each ball in order to simplify
                        Balls.push_back(b);
                    }
            }
        }
        else{
        float dt=GetFrameTime();//Use frame time so the engine doesnt depend solely on the user's FPS
        for (int i=0;i<n;i++){
            Balls[i].pos=Balls[i].pos+(Balls[i].vel*dt);//update the balls position each loop
            if(Balls[i].pos.x+10>1280 or Balls[i].pos.x-10<0){
                Balls[i].vel.x*=-1;
            }
            if(Balls[i].pos.y+10>720 or Balls[i].pos.y-10<0){
                Balls[i].vel.y*=-1;
            }
            DrawCircle(Balls[i].pos.x,Balls[i].pos.y,10,WHITE);
        }
        for (int i=0;i<n;i++){//We check if any of the balls have collided, this is O(n²) and I will be updating it shortly to a Quadtree for optimization
            for (int j=i+1;j<n;j++){
                if (sqrt(pow(Balls[i].pos.x-Balls[j].pos.x,2)+pow(Balls[i].pos.y-Balls[j].pos.y,2))<20){
                    Vec2 a=Balls[i].vel;//Since the mass of each ball is the same we just have to exchange their velocities
                    Vec2 b=Balls[j].vel;
                    Balls[i].vel=b;
                    Balls[j].vel=a;
                }
            }
        }
        if (IsKeyDown(KEY_A)){//If A is pressed accelerate
            for (int i=0;i<n;i++){
                Balls[i].vel = Balls[i].vel * (1.0f + 2.0f * dt);
        }
    }
        if (IsKeyDown(KEY_B)){//If B is pressed decelerate
                for (int i=0;i<n;i++){
                    Balls[i].vel = Balls[i].vel * (1.0f - 2.0f * dt);
            }
        }      
    }
        if (not gamestarted){//Easy user interface for the user to choose the number of balls
                DrawText("Enter number of balls:(Recommended<250)", 300, 300, 30, WHITE);
                DrawText(Number.c_str(), 600, 350, 40, YELLOW);
                DrawText("(Press ENTER to start)", 1000, 680, 20, GRAY);
                if (IsKeyPressed(KEY_ENTER)){
                    gamestarted=true;
            }
        }
        else{
        DrawText("Hold D for Debug Mode",10,10,20,WHITE);//We add a Debug mode for the Grid and coordinates of the balls(will be more important later for the Quadtree)
        DrawText("Press A to Accelerate/B to Decelerate",10,680,20,WHITE);
        if(IsKeyDown(KEY_D)){
            int COLS=16;
            int ROWS=9;
            for (int i=0;i<COLS;i++){//Create a 9x16 Grid
                for(int j=0;j<ROWS;j++){
                    DrawRectangleLines(i*80,j*80,80,80,WHITE);
                }
            }
            DrawFPS(1190,10);
            for(int i=0;i<n;i++){//Show Coordinates
                const char* coordText = TextFormat("(%d, %d)", (int)Balls[i].pos.x, (int)Balls[i].pos.y);
                DrawText(coordText,(int)Balls[i].pos.x-50,(int)Balls[i].pos.y+15,20,WHITE);
            }
        }
        }
        EndDrawing();
    }
    CloseWindow();
}