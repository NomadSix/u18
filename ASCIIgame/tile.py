from obj import obj

class Tile(obj):
    def __init__(self, solid, block_sight = None):
        self.solid = solid
        self.black = False

        if block_sight is None: 
            block_sight = solid

        self.block_sight = block_sight
