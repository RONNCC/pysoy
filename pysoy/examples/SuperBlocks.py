#!/usr/bin/env python
import soy
import blocks
from time import sleep

sce = soy.scenes.Scene()
cam = soy.bodies.Camera(sce)
cam.position = (0.0, 0.0, 15.0)
lig = soy.bodies.Light(sce)
lig.position = (-10.0,10.0,2.0)

colors = {
  'Aventurine0'    : (soy.materials.aventurine,
                      soy.materials.aventurine, (-7, 2, 0)),
  'Basalt0'        : (soy.materials.basalt,
                      soy.materials.aventurine, (-5, 2, 0)),
  'Copper0'        : (soy.materials.copper,
                      soy.materials.aventurine, (-3, 2, 0)),
  'CopperSulfate0' : (soy.materials.copperSulfate,
                      soy.materials.aventurine, (-1, 2, 0)),
  'DarkWood0'      : (soy.materials.darkWood,
                      soy.materials.aventurine, ( 1, 2, 0)),
  'Pearl0'         : (soy.materials.pearl,
                      soy.materials.aventurine, ( 3, 2, 0)),
  'Rhodonite0'     : (soy.materials.rhodonite,
                      soy.materials.aventurine, ( 5, 2, 0)),
  'VelvetyRed0'    : (soy.materials.velvetyRed,
                      soy.materials.aventurine, ( 7, 2, 0)),

  'Aventurine1'    : (soy.materials.aventurine,
                      soy.materials.basalt, (-7, 4, 0)),
  'Basalt1'        : (soy.materials.basalt,
                      soy.materials.basalt, (-5, 4, 0)),
  'Copper1'        : (soy.materials.copper,
                      soy.materials.basalt, (-3, 4, 0)),
  'CopperSulfate1' : (soy.materials.copperSulfate,
                      soy.materials.basalt, (-1, 4, 0)),
  'DarkWood1'      : (soy.materials.darkWood,
                      soy.materials.basalt, ( 1, 4, 0)),
  'Pearl1'         : (soy.materials.pearl,
                      soy.materials.basalt, ( 3, 4, 0)),
  'Rhodonite1'     : (soy.materials.rhodonite,
                      soy.materials.basalt, ( 5, 4, 0)),
  'VelvetyRed1'    : (soy.materials.velvetyRed,
                      soy.materials.basalt, ( 7, 4, 0)),

  'Aventurine2'    : (soy.materials.aventurine,
                      soy.materials.copper, (-7, 0, 0)),
  'Basalt2'        : (soy.materials.basalt,
                      soy.materials.copper, (-5, 0, 0)),
  'Copper2'        : (soy.materials.copper,
                      soy.materials.copper, (-3, 0, 0)),
  'CopperSulfate2' : (soy.materials.copperSulfate,
                      soy.materials.copper, (-1, 0, 0)),
  'DarkWood2'      : (soy.materials.darkWood,
                      soy.materials.copper, ( 1, 0, 0)),
  'Pearl2'         : (soy.materials.pearl,
                      soy.materials.copper, ( 3, 0, 0)),
  'Rhodonite2'     : (soy.materials.rhodonite,
                      soy.materials.copper, ( 5, 0, 0)),
  'VelvetyRed2'    : (soy.materials.velvetyRed,
                      soy.materials.copper, ( 7, 0, 0)),

  'Aventurine3'    : (soy.materials.aventurine,
                      soy.materials.copperSulfate, (-7, -2, 0)),
  'Basalt3'        : (soy.materials.basalt,
                      soy.materials.copperSulfate, (-5, -2, 0)),
  'Copper3'        : (soy.materials.copper,
                      soy.materials.copperSulfate, (-3, -2, 0)),
  'CopperSulfate3' : (soy.materials.copperSulfate,
                      soy.materials.copperSulfate, (-1, -2, 0)),
  'DarkWood3'      : (soy.materials.darkWood,
                      soy.materials.copperSulfate, ( 1, -2, 0)),
  'Pearl3'         : (soy.materials.pearl,
                      soy.materials.copperSulfate, ( 3, -2, 0)),
  'Rhodonite3'     : (soy.materials.rhodonite,
                      soy.materials.copperSulfate, ( 5, -2, 0)),
  'VelvetyRed3'    : (soy.materials.velvetyRed,
                      soy.materials.copperSulfate, ( 7, -2, 0)),

  'Aventurine4'    : (soy.materials.aventurine,
                      soy.materials.darkWood, (-7, 2, 3)),
  'Basalt4'        : (soy.materials.basalt,
                      soy.materials.darkWood, (-5, 2, 3)),
  'Copper4'        : (soy.materials.copper,
                      soy.materials.darkWood, (-3, 2, 3)),
  'CopperSulfate4' : (soy.materials.copperSulfate,
                      soy.materials.darkWood, (-1, 2, 3)),
  'DarkWood4'      : (soy.materials.darkWood,
                      soy.materials.darkWood, ( 1, 2, 3)),
  'Pearl4'         : (soy.materials.pearl,
                      soy.materials.darkWood, ( 3, 2, 3)),
  'Rhodonite4'     : (soy.materials.rhodonite,
                      soy.materials.darkWood, ( 5, 2, 3)),
  'VelvetyRed4'    : (soy.materials.velvetyRed,
                      soy.materials.darkWood, ( 7, 2, 3)),

  'Aventurine5'    : (soy.materials.aventurine,
                      soy.materials.pearl, (-7, 4, -5)),
  'Basalt5'        : (soy.materials.basalt,
                      soy.materials.pearl, (-5, 4, -5)),
  'Copper5'        : (soy.materials.copper,
                      soy.materials.pearl, (-3, 4, -5)),
  'CopperSulfate5' : (soy.materials.copperSulfate,
                      soy.materials.pearl, (-1, 4, -5)),
  'DarkWood5'      : (soy.materials.darkWood,
                      soy.materials.pearl, ( 1, 4, -5)),
  'Pearl5'         : (soy.materials.pearl,
                      soy.materials.pearl, ( 3, 4, -5)),
  'Rhodonite5'     : (soy.materials.rhodonite,
                      soy.materials.pearl, ( 5, 4, -5)),
  'VelvetyRed5'    : (soy.materials.velvetyRed,
                      soy.materials.pearl, ( 7, 4, -5)),

  'Aventurine6'    : (soy.materials.aventurine,
                      soy.materials.rhodonite, (-7, 0, -2)),
  'Basalt6'        : (soy.materials.basalt,
                      soy.materials.rhodonite, (-5, 0, -2)),
  'Copper6'        : (soy.materials.copper,
                      soy.materials.rhodonite, (-3, 0, -2)),
  'CopperSulfate6' : (soy.materials.copperSulfate,
                      soy.materials.rhodonite, (-1, 0, -2)),
  'DarkWood6'      : (soy.materials.darkWood,
                      soy.materials.rhodonite, ( 1, 0, -2)),
  'Pearl6'         : (soy.materials.pearl,
                      soy.materials.rhodonite, ( 3, 0, -2)),
  'Rhodonite6'     : (soy.materials.rhodonite,
                      soy.materials.rhodonite, ( 5, 0, -2)),
  'VelvetyRed6'    : (soy.materials.velvetyRed,
                      soy.materials.rhodonite, ( 7, 0, -2)),

  'Aventurine7'    : (soy.materials.aventurine,
                      soy.materials.velvetyRed, (-7, -2, 5)),
  'Basalt7'        : (soy.materials.basalt,
                      soy.materials.velvetyRed, (-5, -2, 5)),
  'Copper7'        : (soy.materials.copper,
                      soy.materials.velvetyRed, (-3, -2, 5)),
  'CopperSulfate7' : (soy.materials.copperSulfate,
                      soy.materials.velvetyRed, (-1, -2, 5)),
  'DarkWood7'      : (soy.materials.darkWood,
                      soy.materials.velvetyRed, ( 1, -2, 5)),
  'Pearl7'         : (soy.materials.pearl,
                      soy.materials.velvetyRed, ( 3, -2, 5)),
  'Rhodonite7'     : (soy.materials.rhodonite,
                      soy.materials.velvetyRed, ( 5, -2, 5)),
  'VelvetyRed7'    : (soy.materials.velvetyRed,
                      soy.materials.velvetyRed, ( 7, -2, 5)),
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
pearl = bks['Pearl0']
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

