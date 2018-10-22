from obj import obj
# class for handeling all inputs the player would make
class player(obj):

    def __init__(self, x, y, char, color, libtcod):
        self.x = x
        self.y = y
        self.char = char
        self.color = color
        self.libtcod = libtcod

    def handle_keys(self):
        #movement keys
        if self.libtcod.console_is_key_pressed(self.libtcod.KEY_UP):
            self.y -= 1

        elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_DOWN):
            self.y += 1

        elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_LEFT):
            self.x -= 1

        elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_RIGHT):
            self.x += 1