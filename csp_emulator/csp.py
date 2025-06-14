class CSP:
    """Simple backtracking solver for Constraint Satisfaction Problems."""
    def __init__(self, variables, domains, constraints):
        self.variables = variables
        self.domains = domains
        self.constraints = constraints

    def is_consistent(self, assignment, var, value):
        """Check if assigning value to var is consistent with current assignment."""
        for other in assignment:
            if (other, var) in self.constraints:
                if not self.constraints[(other, var)](assignment[other], value):
                    return False
            if (var, other) in self.constraints:
                if not self.constraints[(var, other)](value, assignment[other]):
                    return False
        return True

    def backtrack(self, assignment):
        """Recursive backtracking search."""
        if len(assignment) == len(self.variables):
            return assignment
        # choose unassigned variable
        var = next(v for v in self.variables if v not in assignment)
        for value in self.domains[var]:
            if self.is_consistent(assignment, var, value):
                assignment[var] = value
                result = self.backtrack(assignment)
                if result is not None:
                    return result
                del assignment[var]
        return None

    def solve(self):
        return self.backtrack({})
