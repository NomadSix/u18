#Class will handel drawling of objects on the game screen
#using libcod
from obj import obj

class batch():

    def __init__(self, console, libtcod):
        self.libtcod = libtcod
        self.con = console
        self.objects = []

    def add(self, object):
        self.objects.append(object)

    def remove(self, index):
        if len(self.objects) < index:
            del self.objects[index]

    def clear(self):
        for obj in self.objects:
            self.libtcod.console_put_char(self.con, obj.x, obj.y, ' ')

    def draw(self):
        for obj in self.objects:
            self.libtcod.console_set_default_foreground(self.con, obj.color)
            self.libtcod.console_put_char(self.con, obj.x, obj.y, obj.char)
        