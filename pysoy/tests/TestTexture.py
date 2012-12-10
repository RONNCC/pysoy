import soy
import unittest

class TestTexture(unittest.TestCase):
  def test_svg(self):
    t = soy.textures.Texture('TestTexture_image.svg')
    
def TestTextureSuite():
  return unittest.TestLoader().loadTestsFromTestCase(TestTexture)

if __name__=='__main__':
  unittest.main()
