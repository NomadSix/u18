
from tile import Tile
from random import *

class room:
    
    def __init__(self, x, y, width, height):
        self.width = width
        self.height = height
        self.x = x
        self.y = y
        self.d1 = 0
        self.d2 = 0
        self.map = [[ Tile(False)
        for y in range(self.height) ]
            for x in range(self.width) ]
        self.newRoom()
    
    def newRoom(self):
        
        # clear old doors
        self.map[self.d1][self.height - 1].enter = False
        self.map[self.d2][0].exit = False

        # pos new doors
        d1 = randrange(1, self.width - 1)
        d2 = randrange(1, self.width - 1)
        self.d1 = d1
        self.d2 = d2
        
        # init new doors
        self.map[d1][self.height - 1].enter = True
        self.map[d2][0].exit = True

        # make walls
        for n in range(0, self.width):
            self.map[n][0].block_sight = True
            self.map[n][1].wall = True

            self.map[n][self.height-2].block_sight = True
            self.map[n-1][self.height-1].wall = True

        for n in range(0, self.height-1):
            self.map[0][n].block_sight = True
            self.map[self.width-1][n].block_sight = True


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
    
    def getEnter(self):
        return [self.d1, self.height]
    
    def getExit(self):
        return [self.d2, 0]