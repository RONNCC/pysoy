#!/usr/bin/env python3

import soy
from time import sleep

room = soy.scenes.Room(3.0)
room['cam'] = soy.bodies.Camera(soy.atoms.Position((0, 0, 15)))
room['light'] = soy.bodies.Light(soy.atoms.Position((-2, 3, 5)))

client = soy.Client()
projector = soy.widgets.Projector(client.window, room['cam'])

#kc = soy.controllers.Controller(win)
#wcn['close'] = soy.actions.Quit()
#key = soy.controllers.Keyboard(win)
#key['q'] = soy.quit()
#key[ 1 ] = soy.quit() #escape key

room['cube1'] = soy.bodies.Box(soy.atoms.Position((-3, 0.25, 0)),
                               material=soy.materials.Colored('red'))
room['cube1'].addTorque(0.05, 0.10, 0.03)
room['cube1'].addForce(0.05, 0, 0)

room['cube2'] = soy.bodies.Box(soy.atoms.Position((3, -0.25, 0)),
                               material=soy.materials.Colored('green'))
room['cube2'].addTorque(0.03, -0.08, -0.05)
room['cube2'].addForce(-0.05, 0, 0)

if __name__ == '__main__' :
	while True:
		sleep(10)

