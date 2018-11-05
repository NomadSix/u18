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
            self.value = -5
        elif key == 'orange':
            self.value = 3
        elif key == 'blue':
            self.value = 4
    
    def getLoc(self):
        return [self.x, self.y]