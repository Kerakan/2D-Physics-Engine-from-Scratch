# 2D Physics Engine

A high-performance 2D physics simulation engine written in C++ from scratch. This project features a custom linear algebra library, semi-implicit Euler integration, and a Spatial Hash Grid broad-phase optimization to handle 1,000+ objects at 60 FPS.
Project Overview

The goal of this project was to understand the low-level mathematics and memory management behind game physics. Instead of relying on external math libraries or pre-built physics components, every aspect of the engine—from vector math to collision resolution—was implemented manually.

**Core Technologies: C++17, Raylib, CMake.**
## Key Features

  Spatial Hashing Optimization: Implemented a spatial partitioning grid to optimize collision detection. This reduces the time complexity from O(n²) (naive check) to amortized ~O(n), allowing for large-scale simulations.

  Custom Math Library: Lightweight, zero-dependency Vector2 implementation handling vector arithmetic, normalization, and dot products.

  Physics Solver: Handles elastic collisions with mass conservation, momentum transfer, and wall constraint resolution.

  Dynamic State Management: Real-time object insertion with randomized physical properties (mass, radius, velocity).

  Debug Visualization: Integrated debug modes to visualize the spatial grid, velocity vectors, and collision boundaries in real-time.

## Performance

The implementation of Spatial Hashing significantly improved performance compared to the naive O(n²) being now able to run 1000 balls in the simulation in between 40-60 FPS

## Getting Started
**Prerequisites**

  C++ Compiler (GCC/Clang/MSVC)

  CMake (3.11+)

## Build Instructions
    Bash
    git clone https://github.com/Kerakan/2D-Physics-Engine-from-Scratch.git
    cd 2D-Physics-Engine-from-Scratch
    mkdir build && cd build
    cmake ..
    cmake --build .
    ./Engine
    

## Gallery
1. Stress Test (1000 Objects)

Video here

2. Debug View (Spatial Grid)

Video here
