class ent:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def pos(self):
        loc = list()
        loc.append(self.x)
        loc.append(self.y) 
        return loc
    