from .csp import CSP


def map_coloring():
    # variables representing regions
    variables = ["WA", "NT", "SA", "Q", "NSW", "V", "T"]
    colors = ["red", "green", "blue"]
    domains = {var: list(colors) for var in variables}

    # adjacency constraints (no neighboring regions can share color)
    neighbors = {
        "WA": ["NT", "SA"],
        "NT": ["WA", "SA", "Q"],
        "SA": ["WA", "NT", "Q", "NSW", "V"],
        "Q": ["NT", "SA", "NSW"],
        "NSW": ["Q", "SA", "V"],
        "V": ["SA", "NSW"],
        "T": [],
    }

    constraints = {}
    for region, nbs in neighbors.items():
        for nb in nbs:
            constraints[(region, nb)] = lambda a, b: a != b

    csp = CSP(variables, domains, constraints)
    return csp.solve()

if __name__ == "__main__":
    solution = map_coloring()
    print(solution)
