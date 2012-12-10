import soy
from random import random

class BlockMesh(soy.models.Mesh) :
  def __init__(self, mats) :
    Vert = VertexGroup(self)
    # Create Faces
    # 2 Halves
    for a in (1.0, -1.0) :
      # 3 Sides in each half
      for b in (0, 1, 2) :
        # 4 Quarters in each side
        for c in (1.0, -1.0) :
          for d in (1.0, -1.0) :
            material = mats[a*c*d > 0]
            points = (
              Vert(b,                                      # 0
                   ( a*.500,     0,          0         ),
                   ( a,          0,          0         ),
                   ( 0,          a,          0         ),
                   ( 0,          0,          0         )),
              Vert(b,                                      # 1
                   ( a*.500,     0,          d*.450    ),
                   ( a,          0,          0         ),
                   ( 0,          a,          0         ),
                   ( 0,          d*.450,     0         )),
              Vert(b,                                      # 2
                   ( a*.500,     c*.450,     d*.450    ),
                   ( a,          0,          0         ),
                   ( 0,          a,          0         ),
                   ( c*.450,     d*.450,     0         )),
              Vert(b,                                      # 3
                   ( a*.500,     c*.450,     0         ),
                   ( a,          0,          0         ),
                   ( 0,          a,          0         ),
                   ( c*.450,     0,          0         )),
              Vert(b,                                      # 4
                   ( a*.485,     c*.485,     0         ),
                   ( a*.7071070, c*.7071070, 0         ),
                   ( 0,          c*1,          0       ), #wrong
                   (c*.485,      0,          0,        )),
              Vert(b,                                      # 5
                   ( a*.485,     c*.485,     d*.450    ),
                   ( a*.7071070, c*.7071070, 0         ),
                   ( 0,          c*1,        0         ), #wrong
                   (c*.485,      d*.450,     0         )),
              Vert(b,                                      # 6
                   ( a*.475,     c*.475,     d*.475    ),
                   ( a*.5773503, c*.5773503, d*.5773503),
                   ( 0,          c*1,        0         ), #wrong
                   (c*.475,      d*.475,     0         )),
              Vert(b,                                      # 7
                   ( a*.485,     c*.450,     d*.485    ),
                   ( a*.7071070, 0,          d*.7071070),
                   ( 0,          c*1,        0), #wrong
                   (c*.450,      d*.485,     0         )),
              Vert(b,                                      # 8
                   ( a*.485,     0,          d*.485    ),
                   ( a*.7071070, 0,          d*.7071070),
                   ( 0,          c*1,        0         ), #wrong
                   (0,           d*.485,     0         )))
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

  def __call__(self, shift, coord, normal, tangent, texcoord) :
    if   shift == 1 :
      coord = (coord[1], coord[2], coord[0])
      normal = (normal[1], normal[2], normal[0])
      tangent = (tangent[1], tangent[2], tangent[0])
    elif shift == 2 :
      coord = (coord[2], coord[0], coord[1])
      normal = (normal[2], normal[0], normal[1])
      tangent = (tangent[2], tangent[0], tangent[1])

    if not self.verts.has_key(coord) :
      self.verts[coord] = soy.atoms.Vertex(self.mesh, position=coord,
                                           normal=normal, tangent=tangent,
                                           texcoord=texcoord)
    return self.verts[coord]

def srand() :
  return random()-.5

def blocks(sce, colors):
  blocks = {}
  for color in colors :
    blocks[color] = soy.bodies.Body(sce,
                                    model=BlockMesh(colors[color][:2]),
                                    position=colors[color][2])
    blocks[color].rotation = (srand(), srand(), srand())
    blocks[color].shape = soy.shapes.Box(1,1,1)
    t = -0.5
    blocks[color].velocity = (blocks[color].position[0] * t, blocks[color].position[1] * t, blocks[color].position[2] * t)
  return blocks

