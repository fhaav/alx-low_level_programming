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
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4

                if (i > 0 and grid[i - 1][j] == 1):
                    perimeter -= 2
                if ij > 0 and grid[i][j - 1] == 1):
                    perimeter -= 2

    return perimeter
