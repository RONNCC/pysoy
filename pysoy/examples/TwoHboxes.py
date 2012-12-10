#!/usr/bin/env python3

import soy 
from time import sleep

room = soy.scenes.Room(3.0)
room2 = soy.scenes.Room(3.0)
cam = soy.bodies.Camera(room)
cam.position.z = 15

cam2 = soy.bodies.Camera(room2)
cam2.position.z = 15

light = soy.bodies.Light(room)
light.position = soy.atoms.Position((-2, 3, 5))

light2 = soy.bodies.Light(room2)
light2.position = soy.atoms.Position((-2, 3, 5))

window = soy.widgets.Window()
hbox = soy.widgets.HBox(window)
hbox2 = soy.widgets.HBox(window)

projector = soy.widgets.Projector(hbox, cam)
projector2 = soy.widgets.Projector(hbox, cam2)

#kc = soy.controllers.Controller(win)
#wcn['close'] = soy.actions.Quit()
#key = soy.controllers.Keyboard(win)
#key['q'] = soy.quit()
#key[ 1 ] = soy.quit() #escape key

cube1 = soy.bodies.Body(room)
cube2 = soy.bodies.Body(room2)

cube1.position.x = -3
cube2.position.x = 3

cube1.model = soy.models.Cube()
cube2.model = soy.models.Cube()

cube1.model.material.ambient = soy.atoms.Color('red')
cube1.model.material.diffuse = soy.atoms.Color('red')
cube1.model.material.specular = soy.atoms.Color('pink')

cube2.model.material.ambient = soy.atoms.Color('blue')
cube2.model.material.diffuse = soy.atoms.Color('blue')
cube2.model.material.specular = soy.atoms.Color('cyan')

cube1.addTorque(0.05,  0.10,  0.03)
cube2.addTorque(0.03, -0.08, -0.05)

cube1.shape = soy.shapes.Box(1,1,1)
cube2.shape = soy.shapes.Box(1,1,1)

cube1.addForce(.05,0,0)
cube2.addForce(-.05,0,0)

print(room)

projector.size = soy.atoms.Size((180,320,0))
projector2.size = soy.atoms.Size((180,320,0))

print(projector)
print (projector.size)
print (window.size)
if __name__ == '__main__' :
	while True:
		sleep(10)


