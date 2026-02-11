#include <iostream>
#include <vector>
#include "Input.h"
#include "Physics.h"
#include "Spatial_Hash.h"
#include "Vector2.h"
#include "raylib.h"
#include "Ball.h"
int main () {    
    int width = 1280; int height = 720;//Give a width and height
    InitWindow (width, height, "2D Physics Engine");//Initialize the window
    SetTargetFPS (60);//Set a target FPS so the engine doesn't crash trying to get 1000 FPS
    std::vector <Ball> Balls;
    int n;
    Vec2 ballVel;
    bool gamestarted = false;
    SpatialHash map (width, height, 40);//We create the spatial hash of cell size 40 so no ball's diameter is bigger than the cell size
    while (not WindowShouldClose()) {
        if (not gamestarted) {
            Balls = GetInput();//We track the number of balls the user wants to use
            n=Balls.size();
            gamestarted=true;
        }
        else {
            float dt = GetFrameTime();//Use frame time so the engine doesnt depend solely on the user's FPS
            BeginDrawing();
            ClearBackground(BLACK);
            for (int i = 0; i < n; i++) {
                //Update the balls position each loop
                Ball& A=Balls[i];
                A.pos = A.pos + (A.vel * dt);
                //Check collision with walls using overlap so they dont get stuck in them
                Physics::BalltoWallCollision(A, width, height);
                //Draw the Balls and insert their position on the Spatial Hash
                DrawCircle(A.pos.x, A.pos.y, A.Radius, WHITE);
                map.Insert(A,i);
            }
            for (int i = 0; i < n; i++) {
                //We check collision by checking only the cells where the center of the ball is and the 8 neighbouring cells optimizing the naive approach that is O(n²) to ~O(n)
                std::vector <int> Collisionable=GetNeighbours(map, Balls[i].ind);
                for (int Neighbour_index: Collisionable){
                    if (i >= Neighbour_index) continue;
                    Ball& A = Balls[i];
                    Ball& B = Balls[Neighbour_index];
                    Physics::BalltoBallCollision(A,B);
                }
            }
            if (IsKeyDown(KEY_A)) {//If A is pressed accelerate
                for (int i = 0; i < n; i++) {
                    Balls[i].vel = Balls[i].vel * (1.0f + 2.0f * dt);
            }
        }
            if (IsKeyDown(KEY_B)) {//If B is pressed decelerate
                    for (int i = 0; i < n; i++){
                        Balls[i].vel = Balls[i].vel * (1.0f - 2.0f * dt);
                }
            }      
            DrawText("Hold D for Debug Mode", 10, 10, 20, WHITE);//We add a Debug mode for the Grid and coordinates of the balls
            DrawText("Press A to Accelerate/B to Decelerate", 10, height-40, 20, WHITE);
            if (IsKeyDown(KEY_D)) {
                DrawFPS(width-90, 10);
                for (int i = 0; i < n; i++) {//Show Coordinates
                    const char* coordText = TextFormat("(%d, %d)", (int)Balls[i].pos.x, (int)Balls[i].pos.y);
                    DrawText(coordText, (int)Balls[i].pos.x - 50, (int)Balls[i].pos.y + 15, 20, WHITE);
                }
                //With this we can debug if a ball is not being recognized inside the cell since we paint cells where there is a ball center in red 
                Draw(map);
            }
            //Finally clear the Hash in order to fill it in the next loop
            map.Clear();
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}