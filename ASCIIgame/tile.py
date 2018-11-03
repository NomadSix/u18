from obj import obj

class Tile(obj):
    def __init__(self, solid, block_sight = None):
        self.solid = solid

        if block_sight is None: 
            block_sight = solid

        self.block_sight = block_sight
        self.black = False
        self.floor = False
        self.enter = False
        self.exit = False
        self.wall = False
