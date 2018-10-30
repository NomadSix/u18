
from tile import Tile
class room:
    
    def __init__(self, width, height, libtcod):
        self.width = width
        self.height = height
        color_dark_wall = libtcod.Color(0, 0, 100)
        color_dark_ground = libtcod.Color(50, 50, 150)
        self.map = [[ Tile(False)
        for y in range(height) ]
            for x in range(width) ]
        
        for n in range(width):
            self.map[n][3].block_sight = True
            self.map[n][10].block_sight = True
        for n in range(height):
            self.map[3][n].block_sight = True
            self.map[10][n].block_sight = True
    
    def getMap(self):
        return self.map