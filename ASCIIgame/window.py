from batch import batch
from obj import obj
from player import player
from tile import Tile
from room import room
from item import item
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
        self.numWalls = 30
        self.gamestate = "Title"
        self.itemType = ['yellow', 'green']
        self.objs = []
        self.char = player(0, 0, '@', self.libtcod.amber, libtcod)
        self.items = []
        self.objs.append(self.char)
        self.loadcontent()

    def loadcontent(self):
        self.map = [[ Tile(False)
        for y in range(self.height) ]
            for x in range(self.width) ]
        for objd in self.objs:
            self.batch.add(objd)
        self.char.roll()
        
        self.tes = room(5, 5, 30, 25)
        enter = self.tes.getEnter()
        # self.char.setLoc([enter[0] + self.tes.getX(), enter[1] + self.tes.getY() - 2])
        self.rooms = []
        self.rooms.append(self.tes)
        self.drawRoom()
        self.char.inventory[item(0,0,'yellow').key] = 0
        self.char.inventory[item(0,0,'green').key] = 0

    def drawRoom(self):
        
        # removes items from inventory at the beinging of a new room and returns points
        self.items = []
        if len(self.char.inventory) > 0:
            items = self.char.inventory
            for key in items.keys():
                self.char.points = self.char.points + (items[key] * item(0,0,key).value)
                items.pop(key)
                self.char.inventory[item(0,0,'yellow').key] = 0
                self.char.inventory[item(0,0,'green').key] = 0

        map = self.tes.getMap()

        ## Random Walls ##
        # for n in range(self.numWalls):
        #     bound = 8
        #     x = randrange(bound, self.tes.getWidth() - bound)
        #     y = randrange(bound, self.tes.getHeight() - bound)
        #     self.tes.getMap()[x][y].block_sight = True

        for y in range(self.tes.getHeight()):
            for x in range(self.tes.getWidth()):
                if map[x][y].block_sight:
                    self.map[x + self.tes.getX()][y + self.tes.getY()].block_sight = True
                elif map[x][y].wall:
                    if not map[x][y-1].exit:
                        self.map[x + self.tes.getX()][y + self.tes.getY()].wall = True
                        self.map[x + self.tes.getX()][y + self.tes.getY()].block_sight = True
                else:
                    self.map[x + self.tes.getX()][y + self.tes.getY()].floor = True
                if map[x][y].enter:
                    self.map[x + self.tes.getX()][y + self.tes.getY()].block_sight = True
                    self.char.setLoc([x + self.tes.getX(), y + self.tes.getY() - 2])
                
                if map[x][y].exit:
                    self.map[x + self.tes.getX()][y + self.tes.getY()+1].exit = True
                    self.map[x + self.tes.getX()][y + self.tes.getY()+1].wall = False
                    self.map[x + self.tes.getX()][y + self.tes.getY()+1].block_sight = False
                
                    
        for y in range(self.height):
            for x in range(self.width):
                wall = self.map[x][y]
                if wall.exit or wall.enter:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 100), self.libtcod.BKGND_SET )
        for y in range(self.height):
            for x in range(self.width):
                wall = self.map[x][y]
                if wall.exit:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 100, 0), self.libtcod.BKGND_SET )
                elif wall.floor:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(50, 50, 150), self.libtcod.BKGND_SET )
                    if randrange(0,10) == 0:
                        key = self.itemType[randint(0, len(self.itemType)-1)]
                        slime = item(x, y, key)
                        self.items.append(slime)
                        self.libtcod.console_set_char_background(self.game, x, y, slime.getColor(self.libtcod), self.libtcod.BKGND_SET)
                    
                elif wall.wall:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 70), self.libtcod.BKGND_SET )
                elif wall.block_sight:
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 100), self.libtcod.BKGND_SET )
                else:
                    output = "      ~~``*         *-          ##          ....         .,,            ,,=                      "
                    self.batch.printStr(self.game, x, y, output[randrange(0, len(output))], self.libtcod.Color(0, 0, 200))
                    self.libtcod.console_set_char_background(self.game, x, y, self.libtcod.Color(0, 0, 0,), self.libtcod.BKGND_SET )
        
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
                self.char.points = 0
                self.loadcontent()
            elif key.vk == self.libtcod.KEY_2:
                self.gamestate = "Controls"
            elif key.vk == self.libtcod.KEY_3:
                return True
        if key.vk == self.libtcod.KEY_ESCAPE:
            self.gamestate = "Title"

    def update(self):
        loc = self.char.location()
        if self.map[loc[0]][loc[1]].exit == True:
            self.map[loc[0]][loc[1]].exit = False
            self.tes.newRoom()
            self.drawRoom()
        for item in self.items:
            if item.getLoc() == self.char.getLoc():
                self.items.remove(item)
                if self.char.inventory[item.key] != 0:
                    self.char.inventory[item.key] = self.char.inventory[item.key] + 1
                else: 
                    self.char.inventory[item.key] = 1
                self.libtcod.console_set_char_background(self.game, item.x, item.y, self.libtcod.Color(50, 50, 150), self.libtcod.BKGND_SET)
 
    def draw(self):
        while not self.libtcod.console_is_window_closed():
            if self.gamestate == "Title":
                output = "ASCII GAME 2018 CS400"
                x = self.width / 2 - len(output) / 2
                y = self.height / 2 - 7
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "1. Start"
                y = y + 5
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "2. Controls"
                y = y + 2
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                output = "3. Exit"
                y = y + 2
                self.batch.printStr(self.title, x, y, output, self.libtcod.white)
                self.libtcod.console_blit(self.title, 0, 0, self.width, self.height, 0, 0, 0)
            elif self.gamestate == "Controls":
                output = "CONTROLS"
                x = self.width / 2 - len(output) / 2
                y = self.height / 2 - 10
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                output = "ESCAPE - Returns the player to the title screen"
                x = x - 18
                y = y + 6
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                output = "UP_ARROW - up by one unit"
                y = y + 2
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                output = "UP_LEFT - left by one unit"
                y = y + 2
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                output = "UP_DOWN - down by one unit"
                y = y + 2
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                output = "UP_RIGHT - right by one unit"
                y = y + 2
                self.batch.printStr(self.controls, x, y, output, self.libtcod.white)
                self.libtcod.console_blit(self.controls, 0, 0, self.width, self.height, 0, 0, 0)
            elif self.gamestate == "Game":
                self.update()
                self.stats()
                self.batch.draw()
                self.libtcod.console_blit(self.game, 0, 0, self.width, self.height, 0, 0, 0)
                self.batch.clear()

            self.libtcod.console_flush()
            exit = self.handle_keys(self.map)
            if exit:
                break
    def stats(self):
        y = 5
        self.batch.printStr(self.game, self.width - 13, y, str(self.char.name), self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, self.width - 13, y, 'Str - ' + str(self.char.strength), self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, self.width - 13, y, 'Dex - ' + str(self.char.dexterity), self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, self.width - 13, y, 'Int - ' + str(self.char.intelligence), self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, self.width - 13, y, 'Wis - ' + str(self.char.wisdom), self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, self.width - 13, y, 'Chr - ' + str(self.char.charisma), self.libtcod.white)
        y = y + 5
        self.batch.printStr(self.game, self.width - 13, y, 'Points - ' + str(self.char.points), self.libtcod.white)

        #inventory
        y = 31
        self.batch.printStr(self.game, 5, y, "Inventory:", self.libtcod.white)
        y = y + 2
        self.batch.printStr(self.game, 5, y, str(self.char.inventory), self.libtcod.white)
