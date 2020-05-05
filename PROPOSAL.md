# Hot Shot

Author: Parth Savla

---
The project I want to do for the CS126 Final Project is a 2D basketball game that relies on the users ability to aim. The
player should be able to click in a direction to shoot the basketball and earn a point if it lands in the basket. The game would
end if the player misses their shot and their score would be displayed at the end. I aim to do this by having the 
ball roughly traveling in a linear path based on the user click. Every time the ball enters a certain set of
(x,y) coordinate range known as the basket they will be awarded a point. 

Although I do not have much background with creating a project like this, I have played games similar to this before 
(where the objective is to shoot the ball into the hoop) giving me some insight on how the game should be made. However,
through the snake assignment with some introduction to Cinder, I believe I can get this project to work. I also am 
motivated by the fact that this is my project as I chose the topic and it is something I am interested in. I enjoy 
playing games and basketball is my favorite sport. Combining these two interests provides extra motivation for me to get
this project to work. 

For this project I plan to have music in the background which can be done through using Cinder. I also will need to have 
graphics for the hoop, a background and the ball. Found [here is OpenGL](https://libcinder.org/docs/guides/opengl/index.html) which is a easy to use
C++ graphics library that I plan to use as it is interactive and easy to design basic shapes and figures that I would need.
Upon further research, they have also provided starter code [here](https://libcinder.org/docs/guides/opengl/part1.html)
that shows how to create shapes and how to insert images and textures which can definitely be helpful for me when creating
the basketball backboard and hoop, and the actual basketball itself. As this is a 2D game I only need to create a circle 
to represent the ball and a rectangular figure for the hoop.

I plan to work on detecting the input of the user's cursor with clicking by the first week. By the second
week I wish to get the physics down of shooting the ball in a linear path and registering a successful shot. By the last
week I want to add graphics for the basket and the ball along with a background and sound. 

If I was able to finish the project early I would try implementing features that affect the users play. One such feature
would be to add a score multiplier for consecutive shots made. I could also implement "lives" giving a user a chance to 
keep playing even if he/she misses a shot.