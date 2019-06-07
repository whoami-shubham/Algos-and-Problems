"""
This is a exercise question from book title
Discrete Mathematics and Its Applications 7th Edition . 

on page no 743

10. Generate at random simple graphs with 10 vertices. Stop
when you have constructed one with a Hamilton circuit.
Display a Hamilton circuit in this graph.


"""


import random  


VERTICES = 10  
  
def initialize_Graph(graph):  
	for vertex in range(0,VERTICES):  
		key = str(vertex)    # convert vertex from int to string  
		value = [0]*VERTICES # initialize array of length VERTICES with 0 value  
		graph[key] = value   # assign key to value  
		 
  
  
def generate_Graph(graph):  
	for vertex in range(VERTICES):  
		for index in range(len(graph[str(vertex)])):  
			if index==int(vertex) or index<vertex: # index is less than or equal to vertex then do not change it because we already filled that  
				continue  
			graph[str(vertex)][index] = random.getrandbits(1) # random.getrandbits(1) assign value 0 or 1  
			graph[str(index) ][vertex] = graph[str(vertex)][index]  # if vertex A is connected to vertex B then B is also connected to A 
		#print(graph[str(vertex)])
	return graph


def dfs(graph,visited,key):   # depth first search
	for vertex in range(VERTICES):
		if not visited[vertex] and graph[key][vertex]==1: # if vertex is connected and not visited
			visited[vertex] = True
			dfs(graph,visited,str(vertex)) # visit all vertices that is connected to current vertex


def Connected(graph):
	visited = [False]*VERTICES  # initially no vertices is visited
	connected , connected_components = True,0
	for key in graph: # visit each vertex in graph once
		vertex = int(key)
		if not visited[vertex]: # if vertex is not visited
			visited[vertex] = True
			dfs(graph,visited,key) # visit all vertices that is connected to current vertex
			connected_components += 1
	connected = False if connected_components>1 else True # if connected_components==1 graph is connected
	return connected





def Hamiltonian_Circuit(graph,start_vertex,path):

	if len(path)==VERTICES:
		if graph[path[-1]][int(path[0])]==1: # if last vertex of circuit is connected to first vertex 
			path.append(path[0])             #  append first vertex again to make circuit
			return True
		else:
			return False

	for next_vertex in range(VERTICES):
		if graph[str(start_vertex)][next_vertex]==1 and  not visited[next_vertex]: # if next_vertex is connected to start_vertex and not visited yet
			path.append(str(next_vertex))    # include next_vertex into path
			visited[next_vertex] = True      # mark it visited
			if Hamiltonian_Circuit(graph,next_vertex,path): # check path is Hamiltonian Circuit
				return True
			path.remove(str(next_vertex)) # remove next_vertex from path since if it was present in path then previous statement should return True 
			visited[next_vertex] = False  # mark it unvisited since we removed it from path
	return False   


def print_graph(graph):
	for key in graph:
		print(graph[key])

Graph = {}  
  
  
  
initialize_Graph(Graph)  
  
  
found = False  
path  = []
while not found:
	path = ['0']  # if graph contains Hamiltonian circuit then we can start at any point
	visited = [False]*VERTICES
	visited[0] = True 
	Graph = generate_Graph(Graph)  
	if Connected(Graph):
		if Hamiltonian_Circuit(Graph,0,path):
			found = True
	
print('\n Graph  \n')
print_graph(Graph)
print(f'\n Hamiltonian Circuit :  {path} \n')
