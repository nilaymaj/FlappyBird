# Flappy Bird!

![Gameplay gif](flappy-bird.gif)

This is a very simple clone of the popular Flappy Bird game, built with C++ and SFML. Most part of this clone was made
alongside [this tutorial](https://www.youtube.com/playlist?list=PLRtjMdoYXLf7DB3--POF9lYzaZu0poT5V). Some improvements 
over the tutorial version are realistic bird jump and pixel-perfect collision detection.

### Build instructions

Requirements:
- **CMake**: The project uses the CMake build system, so you'll need this to build the project.
- **SFML**: The multimedia layer used for graphics, audio and user input.

Once you have the requirements installed, clone this repo and in the project directory, run
```
cmake .
make
```

This should create a binary executable `FlappyBird` in the project directory. Run it to play the game.

### How to play

Before you start playing, make sure your system's volume is not too high - there's
a little audio issue that sometimes causes bursts of static noise to be played instead of regular sound effects.

When playing, press Spacebar to flap your wings. The game speed increases progressively, but you should be able to
get past a score of 100 in around ten or twenty attempts.