"""
This is a exercise question from book title
Discrete Mathematics and Its Applications 7th Edition . 

on page no 742

13.Given the vertex pairs associated to the edges of a multi-
graph, determine whether it has an Euler circuit and, if
not, whether it has an Euler path. Construct an Euler path
or circuit if it exists.


"""

import copy 


Graph = {}  

odd_vertex = None


def dfs(graph,start_vertex,visited):   # depth first search
	for vertex in graph[start_vertex]:
		if not visited[vertex] : # if vertex is connected and not visited
			visited[vertex] = True
			dfs(graph,vertex,visited) # visit all vertices that is connected to current vertex


def Connected(graph):
	visited = {}  
	for vertex in graph:
		visited[vertex] = False # initially no vertices is visited  
	connected , connected_components = True,0
	for vertex in graph: # visit each vertex in graph once
		if not visited[vertex]: # if vertex is not visited
			visited[vertex] = True
			dfs(graph,vertex,visited) # visit all vertices that is connected to current vertex
			connected_components += 1
	connected = False if connected_components>1 else True # if connected_components==1 graph is connected
	return connected

def Valid_Degree(graph):
	global odd_vertex
	odd_degree  = 0 
	for vertex in graph:
		degree = 0
		for adjcent_vertex in graph[vertex]:
			degree  += 1
		if degree%2==1:
			odd_degree  = odd_degree + 1
			odd_vertex  = vertex
		if odd_degree>2:
			odd_vertex = None
			return (False,False)
	if odd_degree>0:
		return (False,True)
	else:
		return (True,True)



def Euler_Path(graph,start_vertex,path):
	for end_vertex in graph[start_vertex]: # iterate through each outgoing edge
		graph[start_vertex].remove(end_vertex) # remove it from graph
		graph[end_vertex].remove(start_vertex) # since graph is undirected 
		Euler_Path(graph,end_vertex,path)  # explore end vertex
	path.append(start_vertex)
	return path


def Euler_Circuit(graph,start_vertex,circuit):
	for end_vertex in graph[start_vertex]:
		graph[start_vertex].remove(end_vertex)
		graph[end_vertex].remove(start_vertex)
		Euler_Circuit(graph,end_vertex,circuit)
	circuit.append(start_vertex)
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
			if end_vertex not in graph[start_vertex]: # avoid duplicat vertices
				graph[start_vertex].append(end_vertex)
		else:
			graph[start_vertex] = [end_vertex] # if start vertex is not present in Graph add it
		if end_vertex in graph:
			if start_vertex not in graph[end_vertex]:
				graph[end_vertex].append(start_vertex)
		else:
			graph[end_vertex] = [start_vertex]
  
  
  
  

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


  

