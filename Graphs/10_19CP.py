"""
This is a exercise question from book title
Discrete Mathematics and Its Applications 7th Edition . 

on page no 743

19. Given a list of students and the courses that they are en-
rolled in, construct a schedule of final exams.

courses = vertices
edge between two courses if students are common

"""


import random  

Graph = {}
slots = {}


def Coloring(graph):
    temp_slot = {}
    colors  = {}
    colored = {}
    for vertex in graph:
        colors[vertex]  = 0
        colored[vertex] = False
    chromatic_number = 1
    for vertex in graph: # iterate through each vertex
        if not colored[vertex]: # if current vertex is not colored yet
            found = False
            color = 1
            while not found: # until you not found appropriate color
                available = True
                for adjacent_vertex in graph[vertex] :
                    if colored[adjacent_vertex] and colors[adjacent_vertex]==color:
                        available = False # if color is already used by adjacent  vertex
                        break
                if available:
                    colors[vertex] = color # color of current vertex
                    found = True
                else:
                    color += 1
            chromatic_number = max(chromatic_number,color) # update maximum color
            colored[vertex] = True  # color current vertex
    for vertex in colors:# now store vertex color wise i.e. color is key and vertices are value of key 
        if colors[vertex] in temp_slot:
            temp_slot[colors[vertex]].append(vertex)
        else:
            temp_slot[colors[vertex]] = [vertex]
    return temp_slot


def Input_Edges():
    students = []
    courses  = {} 
    N = int(input("Enter Number of row in list of students and the courses : ")) # taking number of row in list as input 
    print(f'Enter data of {N} rows ')
    for row in range(N):
        student_id,course_id = input(f'student id and course  id  for row {row+1}  : ').strip().split() # input student id
        if course_id in courses:
            if student_id not in courses[course_id]:
                courses[course_id].append(student_id)
        else:
            courses[course_id] = [student_id]
        if student_id not in students:
            students.append(student_id)
        if course_id not in Graph: # create graph which vertex is course id
            Graph[course_id] = []

    for course1 in courses:
        for course2 in courses:
            if course1==course2:
                continue
            for student in courses[course1]:
                if student in courses[course2]: # if students are common in courses create edge between them
                    if course2 not in Graph[course1]:
                        Graph[course1].append(course2)
                        Graph[course2].append(course1)
                    break



def print_colors(colors):
    print('\nslots        courses   \n')
    for key in colors:
        print(f'slot  {key} :   { colors[key] } ')


Input_Edges()
slots = Coloring(Graph) 
print_colors(slots)