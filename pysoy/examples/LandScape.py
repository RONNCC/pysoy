#!/usr/bin/env python
#LandScape Example
import soy
from time import sleep

### Start Heightmap Code
heightTex = soy.transports.File('media/Heightmap.soy')['gimp']
sleep(2) # HACK: this will wait while transportloop does his stuff
heightScene = soy.scenes.Landscape(heightTex,soy.materials.aventurine,height=32)
#heightScene = soy.scenes.Scene();# with normal scene, everything is peachy
### Start PySoy Code (Excerpt from pysoy-primer.py)
fps = soy.textures.Print()
# Initialize a window 
scr = soy.Screen()
win = soy.Window(scr, "A ball and landscape")

# Create a ball with a shape, material and a body.
ball = soy.shapes.Sphere(1)    # Step 1: Shape
mat = soy.materials.Material() # Step 2: Material
mat.shininess = 5 # (Optional) Looks nicer (modifies the applied specular lighting; play with this setting to see how it affects appearance)
body = soy.bodies.Body(scene=heightScene, model=soy.models.Shape(mat), 
                       shape=ball, position=(250,15,230)) # Step 3: Body
global camera
# Put a light and camera into the initialized screen
light = soy.bodies.Light(heightScene)
camera = soy.bodies.Camera(heightScene)
pro = soy.widgets.Projector(win, camera=camera)
can = soy.widgets.Canvas(win, texture=fps)

camera.position = (250, 10, 250.0) #50?
light.position = (0.5, 1.0, 5.0)
heightScene.gravity = (0,-1,0)

def addx() :
  camera.position[0] += 1
def addy() :
  camera.position[1] += 1
def addz():
  camera.position[2] += 1
def subz():
  camera.position[2] -= 1
def subx() :
  camera.position[0] -= 1
def suby():
  camera.position[1] -= 1
def toggleWireframe():
  camera.wireframe = not camera.wireframe

key = soy.controllers.Keyboard(win)
key['R'] = addy #up
key['Q'] = subx #left
key['T'] = suby #down
key['S'] = addx #right
key['V'] = addz #pgup
key['U'] = subz #pgdwn
key['w'] = toggleWireframe
key['q'] = soy.actions.Quit()
key[ 1 ] = soy.actions.Quit() # 9 = esc key
wcn = soy.controllers.Window(win)
wcn['close'] = soy.actions.Quit()

if __name__ == "__main__":
  #mainloop goes here
  while 1:
    sleep(0.1)
    fps.text = '%sfps' % str(int(camera.fps)).zfill(4)
