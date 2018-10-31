
from tile import Tile
class room:
    
    def __init__(self, x, y, width, height, libtcod, con):
        self.width = width
        self.height = height
        self.x = x
        self.y = y
        color_dark_wall = libtcod.Color(0, 0, 100)
        color_dark_ground = libtcod.Color(50, 50, 150)
        self.map = [[ Tile(False)
        for y in range(self.height) ]
            for x in range(self.width) ]
        for n in range(0, width):
            self.map[n][0].block_sight = True
            self.map[n][height-1].block_sight = True
        for n in range(0, height):
            self.map[0][n].block_sight = True
            self.map[width - 1][n].block_sight = True
        for y in range(self.height):
            for x in range(self.width):
                wall = self.map[x][y]
                # if wall.block_sight:
                    # libtcod.console_set_char_background(con, x, y, libtcod.Color(0, 0, 0), libtcod.BKGND_SET )
    
    def getMap(self):
        return self.map
    
    def getWidth(self):
        return self.width

    def getHeight(self):
        return self.height

    def getX(self):
        return self.x
    
    def getY(self):
        return self.y