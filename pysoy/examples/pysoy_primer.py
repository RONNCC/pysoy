#!/usr/bin/env python
# The PySoy Primer Tutorial - A Spinning Cube
#
# This version has been modified to work with the latest
# svn trunk.

import soy
from time import *

# Initialize a window and a 3D scene (empty space) for placing objects in
scr = soy.Screen()
win = soy.Window(scr, "A Spinning Cube")
sce = soy.scenes.Scene()

# Create a cube with a shape, material and a body.
cube = soy.shapes.Box(1, 1, 1) # Step 1: Shape
mat = soy.materials.Material() # Step 2: Material
mat.shininess = 5 # (Optional) Looks nicer (modifies the applied specular lighting; play with this setting to see how it affects appearance)
body = soy.bodies.Body(scene=sce, model=soy.models.Shape(material=mat), shape=cube) # Step 3: Body

# Put a light and camera into the initialized screen
light = soy.bodies.Light(sce)
camera = soy.bodies.Camera(sce)
pro = soy.widgets.Projector(win, camera=camera)

# Move them into appropriate positions (where they aren't directly in the middle of the cube)
camera.position = (0,0, 5.0)
light.position = (0.5, 1.0, 5.0)

# Rotate the cube 1 unit in the X-axis, 1 unit in the Y-axis and 1 unit in the Z-axis
body.rotation = (1, 1, 1)

#  Main loop: each run through this loop keeps the window open and rotates the cube
while True:
    sleep(.1)
