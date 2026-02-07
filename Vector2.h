#include <cmath>
#include <iostream>
#pragma once
struct Vec2{
    float x{0.0};
    float y{0.0};
    Vec2(float x_val,float y_val) : x(x_val),y(y_val) {}
    Vec2()= default;
    Vec2 operator*(float k) const{
        return Vec2(x*k,y*k);
    }
    Vec2 operator+(const Vec2& other) const{
        return Vec2(x+other.x,y+other.y);
    }
    Vec2 operator-(const Vec2& other) const{
        return Vec2(x-other.x,y-other.y);
    }
    Vec2 normalize() const{
        float n=sqrt((x*x)+(y*y));
        if (n == 0.0f) return Vec2(0.0f, 0.0f);
        return Vec2(x/n,y/n);
    }
    float dot(const Vec2& v) const { return x * v.x + y * v.y; }
    float distance() const{
        return sqrt((x*x)+(y*y));
    }
};