#!/usr/bin/env python
import soy
import blocks
from time import sleep

sce = soy.scenes.Scene()
cam = soy.bodies.Camera(sce)
cam.position = (0.0, 0.0, 15.0)
lig = soy.bodies.Light(sce)
lig.position = (-10.0,10.0,2.0)

rbow = soy.materials.Rainbow()
black = soy.materials.Material()
black.ambient = soy.colors.black
black.diffuse = soy.colors.Color('#222')
black.specular= soy.colors.Color('#222')
black.shininess = 5.0
colors = {
  'Aventurine'     : (rbow, black, ( 0, 0, 0)),
  'Basalt'         : (rbow, black, ( 4,-1,-4)),
  'Copper'         : (rbow, black, (-3,-2,-2)),
  'CopperSulfate'  : (rbow, black, ( 0,-2,-1)),
  'DarkWood'       : (rbow, black, ( 5, 3,-6)),
  'Pearl'          : (rbow, black, (-1, 2,-3)),
  'Rhodonite'      : (rbow, black, (-4, 1,-5)),
  'VelvetyRed'     : (rbow, black, ( 3, 0,-8)),
}

bks = blocks.blocks(sce, colors)

fps = soy.textures.Print()

scr = soy.Screen()
win = soy.Window(scr, 'CollideBlocks', background=soy.colors.gray)
pro = soy.widgets.Projector(win, camera=cam)
can = soy.widgets.Canvas(win, texture=fps)

def wireframeToggle() :
  if cam.wireframe :
    cam.wireframe = False
  else :
    cam.wireframe = True

def fullscreenToggle() :
  if scr.fullscreen :
    scr.fullscreen = None
  else :
    scr.fullscreen = win

def moreLight() :
  lig.diffuse = lig.diffuse + 1.0
  print(lig.diffuse) 

def lessLight() :
  lig.diffuse = lig.diffuse - 1.0
  print(lig.diffuse) 

key = soy.controllers.Keyboard(win)
pearl = bks['Pearl']
key['Q'] = soy.actions.Force(pearl, soy.atoms.Vector((-100,    0,    0)))
key['R'] = soy.actions.Force(pearl, soy.atoms.Vector((   0,  100,    0)))
key['S'] = soy.actions.Force(pearl, soy.atoms.Vector(( 100,    0,    0)))
key['T'] = soy.actions.Force(pearl, soy.atoms.Vector((   0, -100,    0)))
key['U'] = soy.actions.Force(pearl, soy.atoms.Vector((   0,    0, -100)))
key['V'] = soy.actions.Force(pearl, soy.atoms.Vector((   0,    0,  100)))
key['q'] = soy.actions.Quit()
key[ 1 ] = soy.actions.Quit() # 9 = esc key
key['f'] = fullscreenToggle
key['w'] = wireframeToggle
key['['] = lessLight
key[']'] = moreLight
wcn = soy.controllers.Window(win)
wcn['close'] = soy.actions.Quit()

if __name__ == '__main__' :
  while True:
    sleep(.1)
    fps.text = '%sfps' % str(int(cam.fps)).zfill(4)
    for bk in bks :
      p = bks[bk].position
      v = bks[bk].velocity
      v = [v[0], v[1], v[2]]
      if abs(p[0]) > 5 and ((p[0]>0 and v[0]>0) or (p[0]<0 and v[0]< 0)) : 
        v[0] = v[0]*-1
      if abs(p[1]) > 5 and ((p[1]>0 and v[1]>0) or (p[1]<0 and v[1]< 0)) : 
        v[1] = v[1]*-1
      if abs(p[2]) > 5 and ((p[2]>0 and v[2]>0) or (p[2]<0 and v[2]< 0)) : 
        v[2] = v[2]*-1
      bks[bk].velocity = v

