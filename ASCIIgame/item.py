class item:
    def __init__(self, x, y, key):
        self.x = x
        self.y = y
        self.key = key
        self.value = 0
        if key == 'yellow':
            self.value = 5
        elif key == 'green':
            self.value = 1
        elif key == 'red':
            self.value = -2
        elif key == 'orange':
            self.value = 3
        elif key == 'blue':
            self.value = 4
    
    def getLoc(self):
        return [self.x, self.y]
    
    def getColor(self, libtcod):
        if self.key == 'yellow':
            return libtcod.dark_yellow
        elif self.key == 'green':
            return libtcod.dark_green
        elif self.key == 'red':
            return libtcod.Color(200, 0, 0)
        elif self.key == 'orange':
            return libtcod.Color(255, 165, 0)
        elif self.key == "blue":
            return libtcod.Color(0,0,200)