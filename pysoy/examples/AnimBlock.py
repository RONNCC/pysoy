#!/usr/bin/env python
import soy
import blocks
from time import sleep

sce = soy.scenes.Scene()
cam = soy.bodies.Camera(sce)
cam.position = (0.0, 0.0, 2.0)
lig = soy.bodies.Light(sce)
lig.position = (-10.0,10.0,2.0)

lava = soy.transports.File('media/lava.soy')['gimp']
lava.animate=(.125,0,0)
dot3 = soy.transports.File('media/fieldstone-dot3.soy')['gimp']
dot3.animate=(.25,0,0)
colors = {
  'Marble' : (soy.materials.Textured(colormap=lava, bumpmap=dot3),
              soy.materials.Material(ambient=soy.colors.black,
                                     diffuse=soy.colors.Color('#222'),
                                     specular=soy.colors.Color('#222'),
                                     shininess=5.0),
              (0,0,0)),
}
bks = blocks.blocks(sce, colors)

fps = soy.textures.Print()

scr = soy.Screen()
win = soy.Window(scr, 'TexBlocks', background=soy.colors.cyan)
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
marble = bks['Marble']
key['Q'] = soy.actions.Force(marble, soy.atoms.Vector((-100,    0,    0)))
key['R'] = soy.actions.Force(marble, soy.atoms.Vector((   0,  100,    0)))
key['S'] = soy.actions.Force(marble, soy.atoms.Vector(( 100,    0,    0)))
key['T'] = soy.actions.Force(marble, soy.atoms.Vector((   0, -100,    0)))
key['U'] = soy.actions.Force(marble, soy.atoms.Vector((   0,    0, -100)))
key['V'] = soy.actions.Force(marble, soy.atoms.Vector((   0,    0,  100)))
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

