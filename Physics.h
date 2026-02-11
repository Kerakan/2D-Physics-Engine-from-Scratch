#include "Ball.h"
#include <cmath>
namespace Physics{
    void BalltoBallCollision(Ball& A, Ball& B){
        float distance = sqrt(pow(A.pos.x - B.pos.x, 2) + pow(A.pos.y - B.pos.y, 2));
        if (distance < A.Radius + B.Radius) {
            //We solve the problem of the balls getting tangled by creating a vector from Ball I to Ball J and separating them in the same frame
            float overlap = A.Radius + B.Radius - distance;
            float nx = (B.pos.x - A.pos.x) / distance;
            float ny = (B.pos.y - A.pos.y) / distance;
            Vec2 IJ(nx * (overlap / 2), ny * (overlap / 2));
            A.pos = A.pos - IJ;
            B.pos = B.pos + IJ;
            //We change the velocity using the 2D elastic collision physics formulas
            Vec2 a = A.vel - (A.pos - B.pos) * ((2 * B.mass * (A.vel - B.vel).dot(A.pos - B.pos)) / ((A.mass + B.mass) * (A.pos - B.pos).distance() * (A.pos - B.pos).distance()));
            Vec2 b = B.vel - (B.pos - A.pos) * ((2 * A.mass * (B.vel - A.vel).dot(B.pos - A.pos)) / ((A.mass + B.mass) * (B.pos - A.pos).distance() * (B.pos - A.pos).distance()));
            A.vel = a;
            B.vel = b;
        }
    }
    void BalltoWallCollision(Ball& A, int width, int height){
        if (A.pos.x + A.Radius >= width){
            float overlap = A.pos.x + A.Radius - width; 
            A.pos.x -=overlap;
            A.vel.x *= -1;
        }
        if (A.pos.x - A.Radius <= 0) {
            float overlap = A.Radius - A.pos.x; 
            A.pos.x +=overlap;
            A.vel.x *= -1;
        }
        if(A.pos.y + A.Radius >= height){
            float overlap = A.pos.y + A.Radius - height;
            A.pos.y -= overlap;
            A.vel.y *= -1;
        }
        if (A.pos.y - A.Radius <= 0) {
            float overlap = A.Radius - A.pos.y;
            A.pos.y += overlap;
            A.vel.y *= -1;
        }
    }
}