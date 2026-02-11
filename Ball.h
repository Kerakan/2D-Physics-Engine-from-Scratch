#pragma once
#include "Vector2.h"
struct Ball {//Define Ball which will be used later in main
        Vec2 pos;
        Vec2 vel;
        float mass;
        float Radius;
        Vec2 ind;
        Ball() : pos(Vec2()), vel(Vec2()), mass(0), Radius(0), ind(Vec2()) {}
    };