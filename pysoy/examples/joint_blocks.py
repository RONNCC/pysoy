#!/usr/bin/env python
import soy
import blocks
from time import sleep

sce = soy.scenes.Scene()
cam = soy.bodies.Camera(sce)
cam.shape=soy.shapes.Sphere(2)
cam.position = (0.0, 0.0, 10.0)
lig = soy.bodies.Light(sce)
lig.position = (-10.0,10.0,2.0)
bks = blocks.blocks(sce)

jnt = soy.joints.Fixed(sce, bks['Pearl'], bks['VelvetyRed'])

scr = soy.Screen()
win = soy.Window(scr, 'Collision Blocks', background=soy.colors.teal)
pro = soy.widgets.Projector(win, camera=cam)
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
wcn = soy.controllers.Window(win)
wcn['close'] = soy.actions.Quit()

if __name__ == '__main__' :
  while True:
    sleep(.1)
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
