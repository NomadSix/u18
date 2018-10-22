class obj:

    def __init__(self, x, y, color, char, solid, heavy):
        self.x = x
        self.y = y
        self.char = char
        self.color = color
        self.solid = solid
        self.heavy = heavy

    def setcolor(self, color):
        self.color = color

    def location(self):
        return [self.x, self.y]

    def setlocal(self, x, y):
        self.x = x
        self.y = y
