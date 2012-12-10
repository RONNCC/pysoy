#!/usr/bin/env python3

import soy
from time import sleep
from math import sqrt

scn = soy.scenes.Scene()
cam = soy.bodies.Camera(scn)
cam.position.z = 15
light = soy.bodies.Light(scn)
light.position = soy.atoms.Position((10, -3, 5))

client = soy.Client()
projector = soy.widgets.Projector(client.window, cam)
#kc = soy.controllers.Controller(win)
#wcn['close'] = soy.actions.Quit()
#key = soy.controllers.Keyboard(win)
#key['q'] = soy.quit()
#key[ 1 ] = soy.quit() #escape key

#bkgrnd = soy.bodies.Box(scn)
#bkgrnd.position.z = -10
#bkgrnd.size = soy.atoms.Size((40,40,1))
#bkgrnd.material = soy.materials.Colored()
#bkgrnd.material.ambient = soy.atoms.Color('blue')
#bkgrnd.material.diffuse = soy.atoms.Color('blue')
#bkgrnd.material.specular = soy.atoms.Color('blue')
#
wall = soy.bodies.Box(scn)
wall.size = soy.atoms.Size((5,.1,10))
wall.position = soy.atoms.Position((0.3, 1, 0))
wall.material = soy.materials.Colored()
wall.material.ambient = soy.atoms.Color('pink')
wall.material.diffuse = soy.atoms.Color('red')
wall.material.specular = soy.atoms.Color('red')

cube = soy.bodies.Box(scn)
cube.size = soy.atoms.Size((1,1,1))
cube.position = soy.atoms.Position((0,-3,0.5))
cube.material = soy.materials.Colored()
cube.material.ambient = soy.atoms.Color('green')
cube.material.diffuse = soy.atoms.Color('yellow')
cube.material.specular = soy.atoms.Color('yellow')

cont = soy.controllers.SpaceNavigator(scn, cube, soy.atoms.Position((0,3,5)), 0.5, 1, bounds=soy.atoms.Size((1,1,1)))

print(cont.path)
while not cont.finished:
    print(cont, "Current Position: {},".format(cube.position), "Next waypoint:", cont.path[0])
    sleep(1)
sleep(2)

del cont

print("\nNew Path\n")

cont = soy.controllers.SpaceNavigator(scn, cube, soy.atoms.Position((0.3,1,0.5)), 0.5, 1, bounds=soy.atoms.Size((1,1,1)))
print(cont.path)
while not cont.finished:
    print(cont, "Current Position: {},".format(cube.position), "Next waypoint:", cont.path[0])
    sleep(1)

del cont

cont = soy.controllers.GridNavigator(scn, cube, soy.atoms.Position((0,-3,0.5)), 0.5, 1, bounds=soy.atoms.Size((1,1,1)))
print(cont.path)
while not cont.finished:
    print(cont, "Current Position: {},".format(cube.position), "Next waypoint:", cont.path[0])
    sleep(1)

del cont
sleep(3)
soy.quit()
