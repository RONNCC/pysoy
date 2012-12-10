#!/usr/bin/env python3

import soy
from time import sleep

#room = soy.scenes.Room(3.0)
#room['cam'] = soy.bodies.Camera(soy.atoms.Position((0, 0, 15)))
#room.ambient = soy.atoms.Color((15,15,15,0))
#room.ambient = soy.atoms.Color('black')
#room['light'] = soy.bodies.Light(soy.atoms.Position((-2, 3, 5)))

def without_light():
    _on=1
    room = soy.scenes.Room(3.0)
    room['cam'] = soy.bodies.Camera(soy.atoms.Position((0, 0, 15)))
    client = soy.Client()
    projector = soy.widgets.Projector(client.window, room['cam'])
#    c1gm = soy.textures.Texture('circ_glow.png')
#    c1cm = soy.textures.Texture('circ.png')
    c1cm = soy.textures.Texture('redhex.png')
    c1gm = soy.textures.Texture('orangehalfhex_dark.png')
    c1tex = soy.materials.Textured(colormap=c1cm,glowmap=c1gm)
    room['cube1'] = soy.bodies.Box(soy.atoms.Position((-3, 0.25, 0)),
                                   material=c1tex)
    room['cube1'].addTorque(0.05, 0.10, 0.03)
    room['cube1'].addForce(0.05, 0, 0)
    if __name__ == '__main__' :
        while True:
            sleep(5)
            _on, room.ambient = (1,soy.atoms.Color('black')) if not _on else (0,soy.atoms.Color((127,127,127,255)))
without_light()
