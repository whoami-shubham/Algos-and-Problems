"""
This is a exercise question from book title
Discrete Mathematics and Its Applications 7th Edition . 

on page no 742

17. Given the list of edges and weights of these edges of a
weighted connected simple graph and two vertices in this
graph, find the length of a shortest path between them
using Dijkstra’s algorithm.Also, find a shortest path.

"""
import copy

Graph = {}
Weights = {}
Distance = {}
source_vertex = None
destination_vertex = None
path = []


def minimum_weighted_vertex(weights,visited): # extract minimum vertex 
	ans = None
	for vertex in weights:
		if vertex in visited:
			continue
		if ans==None or weights[vertex]<weights[ans]:
			ans = vertex
	return ans


def Dijkstra(graph,source_vertex,destination_vertex):
	global path,Distance
	temp_weights = {}
	temp_parent  = {}
	visited      = []
	temp_path = []
	for vertex in graph:
		temp_weights[vertex] = float("inf") # initialize distance to infinity
		temp_parent[vertex]  = None
	temp_weights[source_vertex] = 0 # distance of source is initialized to 0 
	temp_parent[source_vertex]  = 'source' 
	while len(visited)<len(graph):
		min_vertex = minimum_weighted_vertex(temp_weights,visited)
		visited.append(min_vertex)
		for vertex in graph[min_vertex]:
			if vertex in visited:
				continue
			if temp_weights[vertex]>temp_weights[min_vertex] + Weights[min_vertex+vertex]: # edge is relaxed
				temp_weights[vertex] = temp_weights[min_vertex] + Weights[min_vertex+vertex]
				temp_parent[vertex] = min_vertex
	vertex = destination_vertex
	while vertex != 'source':
		temp_path.append(vertex)
		vertex = temp_parent[vertex]
	path = list(reversed(temp_path)) # reverse path 
	Distance = temp_weights


		


def Input_Edges(graph):
	global source_vertex,destination_vertex,Weights
	N = int(input("Enter Number of Edges in Graph : ")) # taking number of edges in Graph as input 
	print(f'Enter {N} Edges and their weights ')
	for edge in range(N):
		start_vertex,end_vertex,edge_weight = input(f'enter start vertex end vertex and edge weight for edge {edge+1}  : ').strip().split() # input start vertex
		if start_vertex in graph:    # if start vertex is present in Graph
			if end_vertex not in graph[start_vertex]: # avoid duplicat vertices
				graph[start_vertex].append(end_vertex)
		else:
			graph[start_vertex] = [end_vertex] # if start vertex is not present in Graph add it
		if end_vertex in graph:
			if start_vertex not in graph[end_vertex]:
				graph[end_vertex].append(start_vertex)
		else:
			graph[end_vertex] = [start_vertex]
		Weights[start_vertex+end_vertex] = int(edge_weight)
		Weights[end_vertex+start_vertex] = int(edge_weight)
	source_vertex,destination_vertex = input("Enter source vertex and destination vertex : ").split(' ')


Input_Edges(Graph)

Dijkstra(Graph,source_vertex,destination_vertex)
print(f'\nLength of shortest path of destination vertex from source vertex is : {Distance[destination_vertex]}')
print(f'path : {path}')
