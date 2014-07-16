# search.py
# ---------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

"""
In search.py, you will implement generic search algorithms which are called 
by Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
  """
  This class outlines the structure of a search problem, but doesn't implement
  any of the methods (in object-oriented terminology: an abstract class).
  
  You do not need to change anything in this class, ever.
  """
  
  def getStartState(self):
     """
     Returns the start state for the search problem 
     """
     util.raiseNotDefined()
    
  def isGoalState(self, state):
     """
       state: Search state
    
     Returns True if and only if the state is a valid goal state
     """
     util.raiseNotDefined()

  def getSuccessors(self, state):
     """
       state: Search state
     
     For a given state, this should return a list of triples, 
     (successor, action, stepCost), where 'successor' is a 
     successor to the current state, 'action' is the action
     required to get there, and 'stepCost' is the incremental 
     cost of expanding to that successor
     """
     util.raiseNotDefined()

  def getCostOfActions(self, actions):
     """
      actions: A list of actions to take
 
     This method returns the total cost of a particular sequence of actions.  The sequence must
     be composed of legal moves
     """
     util.raiseNotDefined()
           

def tinyMazeSearch(problem):
  """
  Returns a sequence of moves that solves tinyMaze.  For any other
  maze, the sequence of moves will be incorrect, so only use this for tinyMaze
  """
  from game import Directions
  s = Directions.SOUTH
  w = Directions.WEST
  return  [s,s,w,s,w,w,s,w]



def depthFirstSearch(problem):
  """
  Search the deepest nodes in the search tree first [p 85].
  
  Your search algorithm needs to return a list of actions that reaches
  the goal.  Make sure to implement a graph search algorithm [Fig. 3.7].
  
  To get started, you might want to try some of these simple commands to
  understand the search problem that is being passed in:
  
  print "Start:", problem.getStartState()
  print "Is the start a goal?", problem.isGoalState(problem.getStartState())
  print "Start's successors:", problem.getSuccessors(problem.getStartState())
  """
  "*** YOUR CODE HERE ***"

  # ***********************************************************************
  #
  # Trabalho 1 - Inteligencia Artificial
  # Implementacao de Busca em Profundiade
  # 
  # Marcos Vinicius Treviso (121150107) 
  # marcosvtreviso@gmail.com
  # 
  # Detalhes:
  # ---------
  # usando matriz para estados visitados e seus predecessores
  # diminui a complexidade devido ao acesso imediato (O(1)) ao dado
  # porem usa mais memoria, pois aloca uma posicao booleana para cada estado
  #
  # ***********************************************************************

  if(problem.isGoalState(problem.getStartState())):
    return ['Stop']

  pilha = util.Stack()

  final = None
  inicial = problem.getStartState()
  
  walls = problem.getWalls()
  LARGURA, ALTURA = walls.width, walls.height

  caminho = []
  visitados = [[False for y in range(ALTURA+1)] for x in range(LARGURA+1)]
  predecessores = [[None for y in range(ALTURA+1)] for x in range(LARGURA+1)] 

  visitados[LARGURA][ALTURA] = True
  pilha.push((inicial, None, 0))

  while pilha.isEmpty() == False:
    
    aux = pilha.pop()
    u = aux[0]

    if(problem.isGoalState(u)):
      final = aux
      break

    for adj in problem.getSuccessors(u):
      v = adj[0]

      if visitados[v[0]][v[1]] == False:

        pilha.push(adj)
        visitados[v[0]][v[1]] = True

        if predecessores[v[0]][v[1]] == None:
          predecessores[v[0]][v[1]] = aux



  it = final[0]
  finicial = problem.getSuccessors(inicial)
  caminho.insert(0, final[1])

  while predecessores[it[0]][it[1]][0] != inicial:
    caminho.insert(0, predecessores[it[0]][it[1]][1])
    it = predecessores[it[0]][it[1]][0]


  return caminho



def breadthFirstSearch(problem):
  "Search the shallowest nodes in the search tree first. [p 81]"
  "*** YOUR CODE HERE ***"

  # ***********************************************************************
  #
  # Trabalho 1 - Inteligencia Artificial
  # Implementacao de Busca em Largura
  # 
  # Marcos Vinicius Treviso (121150107) 
  # marcosvtreviso@gmail.com
  # 
  # Detalhes:
  # ---------
  # usando dicionario para guardar os estados visitados e seus predecessores
  # aumenta a complexidade devido a colisoes de objetos no dicionario
  # porem usa menos memoria, pois so aloca estados visitados e predecessores
  #
  # ***********************************************************************

  if(problem.isGoalState(problem.getStartState())):
    return ['Stop']
  
  fila = util.Queue()

  final = None
  inicial = problem.getStartState()

  caminho = []
  predecessores = {}
  visitados = {}

  visitados[inicial] = True
  fila.push((inicial, None, 0))

  while fila.isEmpty() == False:
    
    aux = fila.pop()
    u = aux[0]

    if(problem.isGoalState(u)):
      final = aux
      break

    for adj in problem.getSuccessors(u):
      v = adj[0]

      if not(v in visitados):

        fila.push(adj)
        visitados[v] = True

        if not(v in predecessores):
          predecessores[v] = aux



  it = final[0]
  caminho.insert(0, final[1])

  while predecessores[it][0] != inicial:
    caminho.insert(0, predecessores[it][1])
    it = predecessores[it][0]


  return caminho

      
def uniformCostSearch(problem):
  "Search the node of least total cost first. "
  "*** YOUR CODE HERE ***"
  if(problem.isGoalState(problem.getStartState())):
    return ['Stop']
  
  fila = util.PriorityQueueWithFunction(lambda x: x[2])

  final = None
  inicial = problem.getStartState()

  caminho = []
  predecessores = {}
  visitados = {}

  visitados[inicial] = True
  fila.push((inicial, None, 0))
  import sys

  while fila.isEmpty() == False:
    
    aux = fila.pop()
    u = aux[0]

    if(problem.isGoalState(u)):
      final = aux
      break

    for adj in problem.getSuccessors(u):
      v = adj[0]

      if not(v in visitados):

        fila.push((adj[0], adj[1], aux[2]+adj[2]))
        visitados[v] = True

        if not(v in predecessores):
          predecessores[v] = aux

  it = final[0]
  caminho.insert(0, final[1])

  while predecessores[it][0] != inicial:
    caminho.insert(0, predecessores[it][1])
    it = predecessores[it][0]


  return caminho

def nullHeuristic(state, problem=None):
  """
  A heuristic function estimates the cost from the current state to the nearest
  goal in the provided SearchProblem.  This heuristic is trivial.
  """
  return 0

def aStarSearch(problem, heuristic=nullHeuristic):
  "Search the node that has the lowest combined cost and heuristic first."
  "*** YOUR CODE HERE ***"
  if(problem.isGoalState(problem.getStartState())):
    return ['Stop']
  
  fila = util.PriorityQueueWithFunction(lambda x: x[2] + heuristic(x[0], problem))

  final = None
  inicial = problem.getStartState()

  caminho = []
  predecessores = {}
  visitados = {}

  visitados[inicial] = True
  fila.push((inicial, None, 0))
  import sys

  while fila.isEmpty() == False:
    
    aux = fila.pop()
    u = aux[0]

    if(problem.isGoalState(u)):
      final = aux
      break

    for adj in problem.getSuccessors(u):
      v = adj[0]

      if not(v in visitados):

        fila.push((adj[0], adj[1], aux[2]+adj[2]))
        visitados[v] = True

        if not(v in predecessores):
          predecessores[v] = aux

  it = final[0]
  caminho.insert(0, final[1])

  while predecessores[it][0] != inicial:
    caminho.insert(0, predecessores[it][1])
    it = predecessores[it][0]


  return caminho
    
  
# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch