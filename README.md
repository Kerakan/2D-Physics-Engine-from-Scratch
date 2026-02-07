# 2D-Physics-Engine-from-Scratch
This is my first project I am working on with C++ and raylib, I plan to update and polish it in the following days

I have been working on this project and learning C++ in general for around a week now, although I know it isn't a really optimized engine and there are some bugs which I will fix shortly I am still really happy with how far I have come in such a little amount of time, I believe that by publishing this repository I can keep a log of the progress I make.

As for the Engine itself right now this is what i have, i have done it all from scratch(even the Vec2 struct found in Vector2.h or the CMake file).

Current Features:
  
Custom Math Library: Lightweight Vector2.h implementation.   
Dynamic Simulation: Real-time particle/ball physics.    
Debug Mode: Visual toggles to inspect velocities and collision boundaries.
Interactive UI: Adjustable parameters for object count and simulation settings.

Here is how the Engine looks when you first run it:

<img width="1410" height="878" alt="image" src="https://github.com/user-attachments/assets/e8c30daa-5bec-4d3e-895e-05dd88fb9e9f" />

Here you can choose how many balls you want to include, as of right now due to some optimization issues that i would like to solve using a Quadtree it gets messy with a large number of balls, for example with 1000 balls the engine runs at 10-30 FPS which is not ideal, this is what the Engine looks like when it's running(Including Debug Mode):

https://github.com/user-attachments/assets/3fd348a0-820b-4afc-a9f2-d7ace5d510b3

You can even see one of the bugs I have to fix where 2 balls that initiate nearby can get tangled until another ball pushes them.
