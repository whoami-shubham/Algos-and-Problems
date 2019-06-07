"""
This is a exercise question from book title
Discrete Mathematics and Its Applications 7th Edition . 

on page no 742

14. Given the ordered pairs of vertices associated to the edges
of a directed multigraph, construct an Euler path or Euler
circuit, if such a path or circuit exists.


"""

import copy 


Graph = {}  

odd_vertex = None


def dfs(graph,start_vertex,visited,path):   # depth first search
	for vertex in graph[start_vertex]:
		if not visited[vertex] : # if vertex is connected and not visited
			visited[vertex] = True
			path.append(vertex)
			dfs(graph,vertex,visited,path) # visit all vertices that is connected to current vertex
	return path


def Connected(graph):
	visited = {}  
	for vertex in graph:
		visited[vertex] = False # initially no vertices is visited  
	connected , connected_components = True,0
	for vertex in graph: # visit each vertex in graph once
		path = []
		if not visited[vertex]: # if vertex is not visited
			visited[vertex] = True
			path = [vertex]
			path = dfs(graph,vertex,visited,path) # visit all vertices that is connected to current vertex
			connected_components += 1
		if len(path)>1 and path[0] not in graph[path[-1]]:
			return False
	connected = False if connected_components>1 else True # if connected_components==1 graph is connected
	return connected

def Valid_Degree(graph):
	global odd_vertex
	odd_degree = 0 
	in_degree = {}
	for vertex in graph:
		in_degree[vertex] = 0
	for vertex in graph:
		for adjcent_vertex in graph[vertex]:
			in_degree[adjcent_vertex] = in_degree[adjcent_vertex]+1
	for vertex in graph:    
		if in_degree[vertex] != len(graph[vertex]):
			odd_degree  = odd_degree + 1
		if in_degree[vertex] < len(graph[vertex]):
			odd_vertex  = vertex
		if odd_degree>2:
			odd_vertex = None
			return (False,False)
	if odd_degree>0:
		return (False,True)
	else:
		return (True,True)



def Euler_Path(graph,start_vertex,path):
	path.append(start_vertex)
	for end_vertex in graph[start_vertex]: # iterate through each outgoing edge
		graph[start_vertex].remove(end_vertex) # remove current edge from graph
		Euler_Path(graph,end_vertex,path)  # explore end vertex
	return path


def Euler_Circuit(graph,start_vertex,circuit):
	circuit.append(start_vertex)
	for end_vertex in graph[start_vertex]:
		graph[start_vertex].remove(end_vertex)
		Euler_Circuit(graph,end_vertex,circuit)
	return circuit


def print_graph(graph):
	for key in graph:
		print(graph[key])

def Input_Edges(graph):
	N = int(input("Enter Number of  Pair of Vertices in Graph : ")) # taking number of edges in Graph as input 
	print(f'Enter {N} Vertices Pair')
	for edge in range(N):
		start_vertex = input(f'first   vertex of  Pair {edge+1}  : ').strip() # input start vertex
		end_vertex   = input(f'second  vertex  of Pair {edge+1}  : ').strip() # input end vertex
		if start_vertex in graph:    # if start vertex is present in Graph
			graph[start_vertex].append(end_vertex)
		else:
			graph[start_vertex] = [end_vertex] # if start vertex is not present in Graph add it
		if end_vertex not in graph:
			graph[end_vertex] = []

  
  
  
  

Input_Edges(Graph)
vertices = list(Graph.keys()) # store vertices to use later


if Connected(Graph):
	contain_circuit,contain_path = Valid_Degree(Graph)
	if contain_circuit:
		circuit  = []
		graph    = copy.deepcopy(Graph) # create and use temporary graph
		circuit  = Euler_Circuit(graph,vertices[0],circuit)
		print(f'\nEuler Circuit is : {circuit}')
	if contain_path:
		path     = []
		graph    = copy.deepcopy(Graph)
		odd_vertex = odd_vertex if odd_vertex != None else vertices[0]
		path     = Euler_Path(graph,odd_vertex,path)
		print(f'\nEuler Path is : {path}')
	else:
		print('\nThere is neither Euler Path nor Euler Circuit in Graph.')
else:
	print('\nThere is neither Euler Path nor Euler Circuit in Graph.')


  

