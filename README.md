# Hot Shot

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)


![Screenshot](screenshot.png)

**Hot Shot** is a fun game of basketball where the user can aim and shoot by mouse to score as many points as possible as
accurately as possible. It uses *OpenGL* for graphics to bring the game to life and simulate shooting hoops. 


### Dependencies
* [CMake](https://cmake.org/)
* [Cinder](https://libcinder.org/docs/index.html)
* [OpenGL](https://libcinder.org/docs/guides/opengl/index.html)

#### Mac OSX
* [CLion](https://www.jetbrains.com/clion/)

### Quick Start
1. Download Cinder for your platform and unzip into a folder `~/Cinder`.
2. Open `~/Cinder` folder in CLion and build. Create a directory in this folder called `hot-shot`. 
3. Clone this repository and unzip into this newly created folder.
4. Open this `hot-shot` in CLion.
5. Set the target to `cinder-myapp` and run the game!

### Controls

This simple game relies solely on a mouse click. Right click in the direction you want to aim the ball and sit back and
hope your shot goes in!

Button | Action
------------ | -------------
Right Mouse-Click | Move ball in direction of mouse-click

### How the game works

You have three lives and your goal is to score as much as possible. However, as your score increases so does the speed
of the backboard moving across the screen. Once you run out of lives the game is over :( .


**Author**: Parth Savla - [`psavla2@illinois.edu`](mailto:psavla2@illinois.edu)
