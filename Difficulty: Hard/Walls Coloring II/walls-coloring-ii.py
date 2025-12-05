class Solution:
    def minCost(self, costs : list[list[int]]) -> int:
        MAX_COST = 10**8
        n, k = len(costs), len(costs[0])
        if n == 0:
            return 0
        if k == 1:
            return costs[0][0] if n == 1 else -1
        best = (-1, 0)
        second = (-1, 0)
        for wall_costs in costs:
            new_best = (-1, MAX_COST)
            new_second = (-1, MAX_COST)
            for color, cost in enumerate(wall_costs):
                if color != best[0]:
                    new_wall = (color, best[1] + cost)
                else:
                    new_wall = (color, second[1] + cost)
                if new_wall[1] < new_best[1]:
                    new_second = new_best
                    new_best = new_wall
                elif new_wall[1] < new_second[1]:
                    new_second = new_wall
            best, second = new_best, new_second
        return best[1]