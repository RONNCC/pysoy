#!/usr/bin/env python
import soy
import blocks
from time import sleep
from random import random

def srand() :
  return random()-.5

black = soy.materials.Material()
black.ambient = soy.colors.black
black.diffuse = soy.colors.Color('#222')
black.specular= soy.colors.Color('#222')
black.shininess = 5.0
colors = {
  'Aventurine'     : (soy.materials.aventurine,    black, ( 0, 0, 0)),
  'Basalt'         : (soy.materials.basalt,        black, ( 4,-1,-4)),
  'Copper'         : (soy.materials.copper,        black, (-3,-2,-2)),
  'CopperSulfate'  : (soy.materials.copperSulfate, black, ( 0,-2,-1)),
  'DarkWood'       : (soy.materials.darkWood,      black, ( 5, 3,-6)),
  'Pearl'          : (soy.materials.pearl,         black, (-1, 2,-3)),
  'Rhodonite'      : (soy.materials.rhodonite,     black, (-4, 1,-5)),
  'VelvetyRed'     : (soy.materials.velvetyRed,    black, ( 3, 0,-8)),
}

sce = soy.scenes.Scene()
bks = blocks.blocks(sce, colors)
m = soy.fields.Monopole(sce)
m.position=(0,0,0)
m.multiplier=-10
cam = soy.bodies.Camera(sce)
cam.position = (0.3, 0.0, 15.0)
cam2 = soy.bodies.Camera(sce)
cam2.position = (-0.3, 0.0, 15.0)

lig = soy.bodies.Light(sce)
lig.position = (-10.0,10.0,2.0)

scr = soy.Screen()
win = soy.Window(scr, size=(1000,375))
win.title = 'Stereo Blocks'
stx = soy.widgets.StackX(win)
pro = soy.widgets.Projector(stx, camera=cam)
pro2 = soy.widgets.Projector(stx, camera=cam2)

key = soy.controllers.Keyboard(win)
key['q'] = soy.actions.Quit()
key[ 1 ] = soy.actions.Quit() # 9 = esc key
wcn = soy.controllers.Window(win)
wcn['close'] = soy.actions.Quit()

if __name__ == '__main__' :
  cname = ('aqua','teal','rose','jade','gold','grey','plum','pink')
  while True:
    sleep(random()*2)
    c = int(random()*8)
    #blocks[cname[c]].rotation = (srand(), srand(), srand())
