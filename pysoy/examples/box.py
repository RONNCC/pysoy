#!/usr/bin/env python3
import soy
from time import sleep

client = soy.Client()
scene = soy.scenes.Scene()

box = soy.bodies.Body(scene)
box.model = soy.models.Box(1.0, 1.0, 1.0)
box.model.material.ambient = soy.atoms.Color('red')
box.model.material.diffuse = soy.atoms.Color('red')
box.model.material.specular = soy.atoms.Color('pink')

box.addTorque(0.1,0.05,0.0)

camera = soy.bodies.Camera(scene)
camera.position.z = 5.0

light = soy.bodies.Light(scene)
light.position = soy.atoms.Position((0, 10, 0))
light.addForce(0,-0.1,0)

projector = soy.widgets.Projector(client.window, camera=camera)

if __name__ == '__main__' :
    while True:
        sleep(10)


