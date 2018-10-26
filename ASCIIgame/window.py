from batch import batch
from obj import obj
from player import player
from tile import Tile
from random import *

class window:
    def __init__(self, width, height, libtcod):
        self.width = width
        self.height = height
        self.libtcod = libtcod
        libtcod.console_set_custom_font('arial12x12.png', libtcod.FONT_TYPE_GREYSCALE | libtcod.FONT_LAYOUT_TCOD)
        libtcod.console_init_root(self.width, self.height, 'Hello World', False)
        self.game = libtcod.console_new(self.width, self.height)
        self.title = libtcod.console_new(self.width, self.height)
        self.controls = libtcod.console_new(self.width, self.height)
        self.batch = batch(self.game, libtcod)
        self.numWalls = 100
        self.gamestate = "Title"
        self.loadcontent()

    def loadcontent(self):
        self.map = [[ Tile(False)
        for y in range(self.height) ]
            for x in range(self.width) ]
        objs = []
        self.char = player(randrange(1, self.width - 16), randrange(1, self.height - 1), '@', self.libtcod.amber)
        objs.append(self.char)
        for objd in objs:
            self.batch.add(objd)
        for n in range(self.numWalls):
            self.map[randrange(1, self.width - 16)][randrange(1, self.height - 1)].block_sight = True
        
        for y in range(self.height):
            for x in range(self.width):
                self.map[x][0].black = self.map[x][0].block_sight = True
                self.map[x][self.height-1].black = self.map[x][self.height-1].block_sight = True
                self.map[0][y].black = self.map[0][y].block_sight = True

                if (x > self.width - 15):
                    self.map[x][y].black = self.map[x][y].block_sight = True

        for y in range(self.height):
            for x in range(self.width):
                wall = self.map[x][y]
                if wall.block_sight:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 100), self.libtcod.BKGND_SET )
                else:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(50, 50, 150), self.libtcod.BKGND_SET )
                if wall.black:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 0), self.libtcod.BKGND_SET )

    def changeFont(self, path):
        self.libtcod.console_set_custom_font(path, self.libtcod.FONT_TYPE_GREYSCALE | self.libtcod.FONT_LAYOUT_TCOD)

    def handle_keys(self, map):
        key = self.libtcod.console_wait_for_keypress(True)  #turn-based
        loc = self.char.location()
        if self.gamestate == "Game":
            if self.libtcod.console_is_key_pressed(self.libtcod.KEY_UP):
                if map[loc[0]][loc[1]-1].block_sight == False:
                    self.char.handle_keys(0, -1)
                
            elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_LEFT):
                if map[loc[0]-1][loc[1]].block_sight == False:
                    self.char.handle_keys(-1, 0)

            elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_DOWN):
                if map[loc[0]][loc[1]+1].block_sight == False:
                    self.char.handle_keys(0, 1)

            elif self.libtcod.console_is_key_pressed(self.libtcod.KEY_RIGHT):
                if map[loc[0]+1][loc[1]].block_sight == False:
                    self.char.handle_keys(1, 0)
        elif self.gamestate == "Title":
            if key.vk == self.libtcod.KEY_1:
                self.gamestate = "Game"
            elif key.vk == self.libtcod.KEY_2:
                self.gamestate = "Controls"
            elif key.vk == self.libtcod.KEY_3:
                return True
        if key.vk == self.libtcod.KEY_ESCAPE:
            self.gamestate = "Title"
            
        
        self.numWalls = self.numWalls + 1

    def update(self):
        pass
 
    def draw(self):
        
        while not self.libtcod.console_is_window_closed():
            if self.gamestate == "Title":
                output = "ASCII GAME 2018 CS400"
                x = self.width / 2 - len(output) / 2
                y = self.height / 2 - 10
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "1. Start"
                y = y + 15
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "2. Controls"
                y = y + 2
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "3. Exit"
                y = y + 2
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                self.libtcod.console_blit(self.title, 0, 0, self.width, self.height, 0, 0, 0)
            elif self.gamestate == "Controls":
                output = "UP_ARROW"
                x = self.width / 2 - len(output) / 2
                y = self.height / 2 - 10
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                
                self.libtcod.console_blit(self.controls, 0, 0, self.width, self.height, 0, 0, 0)
            elif self.gamestate == "Game":
                self.update()
                self.batch.draw()
                self.libtcod.console_blit(self.game, 0, 0, self.width + 15, self.height, 0, 0, 0)
                self.batch.clear()

            self.libtcod.console_flush()
            exit = self.handle_keys(self.map)
            if exit:
                break
    # def render_bar(self, x, y, total_width, name, value, maximum, bar_color, back_color, libtcod):
    #     #render a bar (HP, experience, etc). first calculate the width of the bar
    #     bar_width = int(float(value) / maximum * total_width)
    
    #     #render the background first
    #     libtcod.console_set_default_background(self.game, back_color)
    #     libtcod.console_rect(self.game, x, y, total_width, 100, False, libtcod.BKGND_SCREEN)
    
    #     #now render the bar on top
    #     libtcod.console_set_default_background(self.title, bar_color)
    #     if bar_width > 0:
    #         libtcod.console_rect(self.game, x, y, bar_width, 1, False, libtcod.BKGND_SCREEN)