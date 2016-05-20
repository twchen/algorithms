# Breadth First Search Algorithm

from enum import Enum
Mark = Enum('Mark', 'Undiscovered Discovered Finished');

class Graph:
	def __init__(self, size, adjacency_list):
		self.size = size
		self.adj = adjacency_list

def BFS(graph, source):
	# initialization
	mark = [Mark.Undiscovered] * graph.size
	distance = [float('inf')] * graph.size
	predecessor = [None] * graph.size
	
	queue = [source]
	distance[source] = 0
	mark[source] = Mark.Discovered

	while queue:
		v = queue.pop(0)
		for neighbour in graph.adj[v]:
			if mark[neighbour] == Mark.Undiscovered:
				mark[neighbour] = Mark.Discovered
				distance[neighbour] = distance[v] + 1
				predecessor[neighbour] = v
				queue.append(neighbour)
		mark[v] = Mark.Finished

