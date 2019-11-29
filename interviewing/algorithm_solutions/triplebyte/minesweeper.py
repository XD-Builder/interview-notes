import random
from enum import Enum
import sys


class Difficulty(Enum):
    EASY = .15
    MEDIUM = .4
    HARD = .6


class BoardCell(object):

    """A cell in a board"""

    def __init__(self, cell_num, is_mine):
        """Initializes a cell not selected"""
        self.cell_num = cell_num
        self.is_mine = is_mine
        self.is_selected = False
        self.value = 0

    @property
    def is_mine(self):
        """
        is cell a mine or not
        """
        return self.__is_mine

    @is_mine.setter
    def is_mine(self, is_mine):
        """
        set cell is_mine property
        """
        # pylint: disable=W0201
        self.__is_mine = is_mine


class Board(object):

    """Board controls the entire board"""

    def __init__(self, size, num_mines):
        """Initialize board with correct num of mines"""
        self.size = size
        self.size_1d = self.size ** 2
        if not self.size_1d > num_mines:
            raise ValueError("num_mines must be less than total size")
        self.num_mines = num_mines
        self.board = {i: BoardCell(i, False) for i in range(self.size_1d)}
        self.winning = False
        self.total_selected_cells = 0
        self.game_over = False
        self.mine_locs = random.sample(range(self.size_1d), num_mines)
        for i in self.mine_locs:
            self.board[i].is_mine = True

    def select(self, x, y):
        """Assumes it will be called only when not game_over"""
        if x >= self.size or x < 0 or y >= self.size or y < 0:
            print("invalid x,y coordinate, make sure it's within {}".format(self.size))
            return False

        index_1d = self.get_index_1d(x, y)
        select_cell = self.board[index_1d]
        if not select_cell.is_selected and not select_cell.is_mine:
            self.select_neighbors(select_cell)
            if self.size_1d - self.total_selected_cells == self.num_mines:
                self.winning = True
                return True
        elif select_cell.is_mine:
            self.game_over = True
            return True

        return False

    def select_neighbors(self, source_cell):
        """BFS all neighbors and assign numbers for number of mines"""
        to_select_list = [source_cell]
        while to_select_list:
            i_source_cell = to_select_list.pop()
            if i_source_cell.is_selected:
                continue
            i_source_cell.is_selected = True
            self.total_selected_cells += 1
            neighbor_index_1ds = self.get_all_neightbor_index_1ds(
                i_source_cell)

            temp_select_list = []
            for i in neighbor_index_1ds:
                if self.board[i].is_mine:
                    i_source_cell.value += 1
                elif not self.board[i].is_selected:
                    temp_select_list.append(self.board[i])
            if i_source_cell.value == 0:
                to_select_list.extend(temp_select_list)

    def get_all_neightbor_index_1ds(self, cell):
        """Get all neighbors cell nums"""
        neighbor_nums = []
        x = cell.cell_num % self.size
        y = cell.cell_num // self.size
        for i in range(x-1, x+2):
            if i >= 0 and i < self.size:
                if y - 1 >= 0:
                    neighbor_nums.append(self.get_index_1d(i, y-1))
                neighbor_nums.append(self.get_index_1d(i, y))
                if y + 1 < self.size:
                    neighbor_nums.append(self.get_index_1d(i, y+1))
        return neighbor_nums

    def get_index_1d(self, x, y):
        """
        get 1d index using x and y coordinate
        """
        return x + y * self.size

    def __str__(self):
        """
        Prints the entire board, if game_over, make all cells visible
        Else, display cells that are only selected.
        """
        row = 1
        row_items = []
        lines = ["|\t" + "\t".join(map(str, range(1, self.size+1))) + "\t|\n"
                 "|\t" + "\t".join(["-"] * self.size) + "\t|"]
        for i in range(self.size_1d):
            if i // self.size == row:
                lines.append(str(row) + "|\t" +
                             "\t".join(row_items) + "\t|" + str(row))
                row_items = []
                row += 1
            if self.game_over:
                val = "X" if self.board[i].is_mine else self.board[i].value
                row_items.append(str(val))
            elif self.board[i].is_mine or not self.board[i].is_selected:
                row_items.append("U")
            else:
                row_items.append(str(self.board[i].value))

        lines.append(str(row) + "|\t" +
                     "\t".join(row_items) + "\t|" + str(row))
        lines.append("|\t" + "\t".join(["-"] * self.size) + "\t|\n" +
                     "|\t" + "\t".join(map(str, range(1, self.size+1))) + "\t|")
        return "\n\n".join(lines)


class MineSweeper(object):

    """MineSweeper With configurable game size and difficulty"""

    def __init__(self, size, difficulty):
        """Initialize board size and number of mines"""
        self.size = size
        self.difficulty = difficulty
        self.num_mines = int(self.size ** 2 * self.difficulty.value)
        self.board = Board(self.size, self.num_mines)

    def play(self):
        """
        play the game in a loop until user wins or loses
        """
        while True:
            print(self.board)
            print("Select next cell")
            try:
                x, y = map(int, input("input (x y): ").split(" "))
            except KeyboardInterrupt:
                break
            except:
                print("Unexpected error:", sys.exc_info()[0])
                continue

            if self.board.select(x-1, y-1):
                print(self.board)
                break

        if self.board.winning:
            print("You won!")
        else:
            print("You lost!")


if __name__ == "__main__":
    size = int(input("Enter size of the game(minimum 4 for 4 x 4 board): "))
    if (size < 4):
        print("can't play.. with size {} x {}".format(size, size))
        sys.exit(1)

    try:
        difficulty = Difficulty[input(
            "Enter difficulty (one of EASY, MEDIUM, HARD): ")]
    except KeyError as e:
        print("Invalid difficulty", e)
        sys.exit(2)

    MineSweeper(size, difficulty).play()
