import libtcodpy as libtcod
from window import window

WIDTH = 65
HEIGHT = 50

win = window(WIDTH, HEIGHT, libtcod)
#game loop
win.draw()
