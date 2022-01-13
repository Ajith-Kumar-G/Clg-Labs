class Network:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, s, d, w):
        self.graph.append([s, d, w])

    def print_solution(self, dist, src, next_hop):
        print("\nRouting table for ", src)
        print("Dest \t Cost \t Next Hop")
        for i in range(self.V):
            if i in next_hop:
                print("{0} \t\t {1} \t\t {2}".format(i, dist[i], next_hop[i]))

    def bellman_ford(self, src, mode):
        dist = [99] * self.V
        dist[src] = 0
        next_hop = {src: src}
        for _ in range(self.V - 1):
            for s, d, w in self.graph:
                if dist[s] != 99 and dist[s] + w < dist[d]:
                    dist[d] = dist[s] + w
                    if s == src:
                        next_hop[d] = d
                    elif s in next_hop:
                        next_hop[d] = next_hop[s]
                if not mode :
                    self.print_solution(dist, src, next_hop)

        for s, d, w in self.graph:
            if dist[s] != 99 and dist[s] + w < dist[d]:
                print("Network contains negative weight cycle")
                return
        if mode:
            self.print_solution(dist, src, next_hop)


if __name__ == "__main__":
    n = int(input("Enter the no. of routers:"))
    c = int(input("Enter the no. of edges:"))
    g = Network(n)
    for i in range(c):
        src, dest, cost = [int(_) for _ in input(
            "Enter [SRC] [DEST] [WEIGHT]: ").split(' ')]
        g.add_edge(src, dest, cost)
        g.add_edge(dest, src, cost)
    print(g.graph)
    for k in range(0, n):
        g.bellman_ford(k,1)
    g.bellman_ford(2,0)

''' 0 2 99 3 99 99 99,2 0 5 99 4 99 99,99 5 0 99 99 4 3,3 99 99 0 5 99 99,99 4 99 5 0 2 99,99 99 4 99 2 0 1,99 99 3 99 99 1 0'''
'''
0 1 4
0 3 3
0 2 5
1 2 2
1 6 4
1 5 3
2 3 6
2 4 4
2 5 4
3 4 3
4 5 2
5 6 5
'''