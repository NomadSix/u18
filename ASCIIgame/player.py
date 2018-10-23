from obj import obj
# class for handeling all inputs the player would make
class player(obj):

    def __init__(self, x, y, char, color):
        self.x = x
        self.y = y
        self.char = char
        self.color = color

    def handle_keys(self, dx, dy):
        #movement keys
        self.y += dy
        self.x += dx