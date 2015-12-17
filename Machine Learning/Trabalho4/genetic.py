import numpy as np
from random import randint, random

def column_vector(v):
	return v.reshape(max(v.shape), 1)

def individual(lower, higher, length):
	return np.random.randint(lower, higher, (length,))

def population(count, lower, higher, length):
	return np.random.randint(lower, higher, (count, length)) 
	# return np.array([individual(lower, higher, length) for _ in range(count)])

def fitness(individual, target):
	return np.abs(target - column_vector(np.sum(individual, axis=-1)))

def grade(population, target):
	return np.mean(fitness(population, target), axis=-1)

def evolve(population, target, retain=0.2, random_select=0.05, mutate=0.01):

	graded = grade(population, target)
	graded_indexes = np.argsort(graded)
	graded_population = np.array([population[i] for i in graded_indexes])

	retain_length = int(len(graded_population)*retain)
	parents = list(graded_population[:retain_length])

	# randomly add other individuals to promote genetic diversity
	r = random_select > np.random.random(retain_length)
	parents.extend(graded_population[r])


	# mutate some individuals
	for individual in parents:
		if mutate > random():
			pos_to_mutate = randint(0, len(individual)-1)
			individual[pos_to_mutate] = randint(np.min(individual), np.max(individual))

	# crossover parents to create children
	parents_length = len(parents)
	desired_length = len(population) - parents_length
	children = []
	while len(children) < desired_length:
		male = randint(0, parents_length-1)
		female = randint(0, parents_length-1)
		if male != female:
			male, female, child = parents[male], parents[female], []
			child.extend(male[:len(male)//2])
			child.extend(female[len(male)//2:])
			children.append(child)

	parents.extend(children)
	return np.array(parents)



# Example usage
target = 371
p_count = 100
i_length = 6
i_min = 0
i_max = 100
p = population(p_count, i_min, i_max, i_length)
fitness_history = [grade(p, target)]


for i in range(10):
	p = evolve(p, target)
	x = grade(p, target)
	print(np.sum(x))
	fitness_history.append(x)


