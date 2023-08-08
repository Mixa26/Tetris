# Tetris

![Gameplay](pictures/gameplay.mp4)



## Controls

The controls are the same as in the regular tetris: 

up arrow = rotate the falling tile

down arrow = speed up the falling of the tile

left arrow = moves tile left once

right arrow = moves tile right once

(You cant go left/ right multiple times by holding down the button left arrow/ right arrow)

## Realisation

I used a framework from a youtuber called ChiliTomatoNoodle (https://www.youtube.com/user/ChiliTomatoNoodle) which regulates the programs window,
and the communication with the OS(graphics, input...). 
All the graphics on the screen have been made with a "PutPixel" function, so each tile and the grid have been drawn pixel by pixel.
Collision with tiles has been realised with matrices, as well as color drawing.
Tiles are spawned randomly, and the next tile in cue is drawn on the screen on the right side.
Score is calculated by every row completed (each row 10 points).
The tiles movement speeds up slowly by time.
Movement speed is regulated by delta time.

## More info

The tile outside of the screen on the right side is the next tile coming up to the cue.

The number at the top is score, each row completed is 10 points.

The falling of tiles speeds up over time.

When the game is ended press enter to restart.
