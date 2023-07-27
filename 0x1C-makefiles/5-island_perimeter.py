#!/usr/bin/python3
"""
Calculate the perimeter of a single island described in a rectangular grid.
"""

def island_perimeter(grid):
    """
    Grid cells are connected horizontally and vertically, not diagonally.

    Args:
        grid (list of list of int): A rectangular grid representing the island,
        with1 as land and 0 as water.

    Returns:
        int: The perimeter of the island.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1

                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1

        perimeter = (size * 4) - (edges * 2)
        return perimeter
