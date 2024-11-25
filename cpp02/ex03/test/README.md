# BSP VISUALIZER

## Setup

Clone the repository and move all files in your directory. Compile your program with this main.cpp. Check in the config.json if the executable name is same as yours.

## Run

#### > python triangle_visualizer.py
if the visualizer doesn't works because matplotlib isn't install do :
#### > pip install matplotlib
#

## How works config.json

#### name :
The name of the executable.
#
#### own_input :
If true, the visualizer will ask you to enter manually all points. Else the visualizer will use the default point in the array.
#
#### point :
#### The points that the visualizer will test if own_input is false. The format is :
#### In a triangle ABC :
#### [[[xa, ya], [xb, yb], [xc, yc]], x_point, y_point]
#
