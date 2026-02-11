#include <string>
#include "raylib.h"
#include <vector>
#include "Ball.h"
#pragma once
std::string Number="";
int n; int width = 1280; int height = 720;
bool gamestarted = false;
std::vector <Ball> Balls;
//We define the GetInput() function which we use in main to get the user's desired ball number
std::vector <Ball> GetInput(){
    while (not gamestarted and not WindowShouldClose()) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 48) && (key <= 57)) { // They correspond to numbers 0-9
                Number += (char)key;
            }
            key = GetCharPressed(); // Check the next character
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (Number.size() >= 1) {
            Number = Number.substr(0, Number.size() - 1);
            }
        }
        if (IsKeyPressed(KEY_ENTER)) {//If the user presses enter we start teh simulation with n balls
                gamestarted = true;
                if (Number.size() > 0) {
                    n = std::stoi(Number);
                }
                else {
                    n = 0;
                }
                Balls.reserve(n);
                int j; j = 0;
                int z; z = 0;
                for (int i = 0; i < n; i++) {//get random x and y positions and initialize the n balls used on the simulation
                    int x = GetRandomValue(20, width-20);
                    int y = GetRandomValue(20, height-20);
                    Vec2 B(x, y);//With a large number of balls we get some balls initializing on each which leads to some unwanted bugs, will have to look for a workaround while I add Quadtree
                    float m = GetRandomValue(1, 2); float r = (10 * (sqrt(m)));
                    Vec2 ballVel(GetRandomValue(-200, 200), GetRandomValue(-100, 100));
                    Ball b; b.pos = B; b.vel = ballVel; b.mass = m; b.Radius = r;//We give the same initial velocity to each ball in order to simplify
                    Balls.push_back(b);
                    gamestarted=true;   
                }
        }
        // Draw a simple user interface so the user knows how many balls they are trying to add
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Enter number of balls:(Recommended<250)", 300, 300, 30, WHITE);
        DrawText(Number.c_str(), 600, 350, 40, YELLOW);
        DrawText("(Press ENTER to start)", 1000, 680, 20, GRAY);
        EndDrawing();
    }
    return Balls;
}