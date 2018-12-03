from obj import obj
from item import item
from random import *
# class for handeling all inputs the player would make
class player(obj):

    def __init__(self, x, y, char, color, libtcod):
        self.x = x
        self.y = y
        self.char = char
        self.color = color
        self.name = "Gordan Slimeman"
        self.strength = 0
        self.dexterity = 0
        self.intelligence = 0
        self.wisdom = 0
        self.charisma = 0
        self.points = 0
        self.inventory = dict()

    def handle_keys(self, dx, dy):
        # movement keys
        self.y += dy
        self.x += dx

    def roll(self):
        self.strength = sum(randint(1, 6) for _ in range(3))
        self.dexterity = sum(randint(1, 6) for _ in range(3))
        self.intelligence = sum(randint(1, 6) for _ in range(3))
        self.wisdom = sum(randint(1, 6) for _ in range(3))
        self.charisma = sum(randint(1, 6) for _ in range(3))
    
    def setLoc(self, loc):
        self.x = loc[0]
        self.y = loc[1]
    
    def getLoc(self):
        return [self.x, self.y]
    