from Tile import Tile
class room:
    
    def __init__(self, width, height, libtcod):
        self.width = width
        self.height = height
        color_dark_wall = libtcod.Color(0, 0, 100)
        color_dark_ground = libtcod.Color(50, 50, 150)
        map = [[ Tile(False)
        for y in range(height) ]
            for x in range(width) ]