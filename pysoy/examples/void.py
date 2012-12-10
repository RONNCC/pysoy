#!/usr/bin/env python
import soy
import blocks
from time import sleep

sce = soy.scenes.Scene()
cam = soy.bodies.Camera(sce)

scr = soy.Screen()
win = soy.Window(scr)
pro = soy.widgets.Projector(win, camera=cam)

while True :
  sleep(1)
