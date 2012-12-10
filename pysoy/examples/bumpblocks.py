import soy
from random import random

mrbl = soy.transports.File('media/marble.soy')['gimp']
dot3 = soy.transports.File('media/fieldstone-dot3.soy')['gimp']


class BlockMesh(soy.models.Mesh) :
  def __init__(self, mycol) :
    black = soy.materials.Material()
    black.ambient = soy.colors.black
    black.diffuse = soy.colors.Color('#222')
    black.specular= soy.colors.Color('#222')
    black.shininess = 5.0
    black.normal = dot3
    Vert = VertexGroup(self)

    # Create Faces
    # 2 Halves
    for a in (1.0, -1.0) :
      # 3 Sides in each half
      for b in (0, 1, 2) :
        # 4 Quarters in each side
        for c in (1.0, -1.0) :
          for d in (1.0, -1.0) :
            if a*c*d > 0 :
              material = mycol
            else :
              material = black
            points = (Vert(b, (.500*a, .000*c, .000*d), (a, 0, 0)),    # 0
                      Vert(b, (.500*a, .000*c, .450*d), (a, 0, 0)),    # 1
                      Vert(b, (.500*a, .450*c, .450*d), (a, 0, 0)),    # 2
                      Vert(b, (.500*a, .450*c, .000*d), (a, 0, 0)),    # 3
                      Vert(b, (.485*a, .485*c, .000*d), (.7071070*a,   # 4
                                                         .7071070*c, 0)),
                      Vert(b, (.485*a, .485*c, .450*d), (.7071070*a,   # 5
                                                         .7071070*c, 0)),
                      Vert(b, (.475*a, .475*c, .475*d), (.5773503*a,   # 6
                                                         .5773503*c, 
                                                         .5773503*d)),
                      Vert(b, (.485*a, .450*c, .485*d), (.7071070*a,   # 7
                                                         0, .7071070*d)),
                      Vert(b, (.485*a, .000*c, .485*d), (.7071070*a,   # 8
                                                         0, .7071070*d)))
            faces = ([points[0], points[1], points[2]],
                     [points[0], points[2], points[3]],
                     [points[2], points[4], points[3]],
                     [points[2], points[5], points[4]],
                     [points[2], points[6], points[5]],
                     [points[2], points[7], points[6]],
                     [points[2], points[8], points[7]],
                     [points[2], points[1], points[8]])
            for face in faces :
              if a*c*d==1 :
                face.reverse()
              f = soy.atoms.Face(self, verts=face, material=material)


class VertexGroup :
  def __init__(self, mesh) :
    self.verts = {}
    self.mesh  = mesh

  def __call__(self, shift, coord, normal) :
    if   shift == 1 :
      coord = (coord[1], coord[2], coord[0])
      normal = (normal[1], normal[2], normal[0])
    elif shift == 2 :
      coord = (coord[2], coord[0], coord[1])
      normal = (normal[2], normal[0], normal[1]) 
    if not self.verts.has_key(coord) :
      self.verts[coord] = soy.atoms.Vertex(self.mesh,
                                           position=coord, texcoord=coord,
                                           normal=normal, tangent=(0,1,0))
    return self.verts[coord]

def srand() :
  return random()-.5

def blocks(sce):
  colors = {
    'Marble'     : (soy.materials.Material(color=mrbl, normal=dot3), (0,0,0)),
  }
  blocks = {}
  for color in colors :
    blocks[color] = soy.bodies.Body(sce,
                                    model=BlockMesh(colors[color][0]),
                                    position=colors[color][1])
    #blocks[color].rotation = (srand(), srand(), srand())
    blocks[color].rotation = (0,0,1)
    blocks[color].shape = soy.shapes.Box(1,1,1)
    t = -0.5
    blocks[color].velocity = (blocks[color].position[0] * t, blocks[color].position[1] * t, blocks[color].position[2] * t)
  return blocks
