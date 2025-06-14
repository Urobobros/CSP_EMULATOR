import os
import sys
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from csp_emulator.example import map_coloring


def test_map_coloring_solution():
    solution = map_coloring()
    assert solution is not None
    neighbors = {
        "WA": ["NT", "SA"],
        "NT": ["WA", "SA", "Q"],
        "SA": ["WA", "NT", "Q", "NSW", "V"],
        "Q": ["NT", "SA", "NSW"],
        "NSW": ["Q", "SA", "V"],
        "V": ["SA", "NSW"],
        "T": [],
    }
    for region, nbs in neighbors.items():
        for nb in nbs:
            assert solution[region] != solution[nb]
