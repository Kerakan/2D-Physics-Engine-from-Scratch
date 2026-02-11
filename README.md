# 2D-Physics-Engine-from-Scratch
As of today 11/02/2026 I have succesfully finished this project, it has been 2 weeks since I first started working on this project and even though there have been some hard moments and pretty long nights I am proud of how far I have come in only a few weeks.

The Engine takes any amount of balls the user wants to input, I would recommend against using more than 250 since you might not be able to fully aprecciate what happens. As for the Math itself used in the engine I have done it all from scratch(even the Vec2 struct found in Vector2.h and every single formula used in Engine.cpp).

## Features 
Custom Math Library: Lightweight Vector2.h implementation.   
Dynamic Simulation: Real-time particle/ball physics.
Spatial Hashing: Implementation of a Spatial Hash in 2D in order to optimize ball to ball collision from O(n²) to ~O(n).
Random Selection: Every time you initialize the Engine it will pick a random starting position and random velocity, mass and radius(dependent on mass).
Debug Mode: Visual toggles to inspect velocities and collision boundaries.
Interactive UI: Adjustable parameters for object count and simulation settings.

Here is how the Ball selection looks when you run the Engine:

<img width="1410" height="878" alt="image" src="https://github.com/user-attachments/assets/e8c30daa-5bec-4d3e-895e-05dd88fb9e9f" />

Here you can choose how many balls you want to include, thanks to the Spatial Hash the engine works really well even with a large number of balls although it might crash if there are too many balls to fit in the screen, however this is no problem since you should be able to just resize it if you want by changing a few lines of code. The Engine can succesfully run with 1000 balls constantly collisioning with each other at a constant 40-60 FPS, this is what the Engine looks like when it's running(Including Debug Mode) for 100 balls:

Insert Video 1

And this is how it looks with 1000 balls:

Insert Video 2
