# heap data structure related algorithms

def getLeft(index):
	return 2 * index + 1

def getRight(index):
	return 2 * index + 2

def getParent(index):
	return (index - 1) / 2

def buildMaxHeap(array):
	maxHeapArray = array[:] # copy the input array
	for i in xrange((len(array) - 1) / 2, -1, -1):
		maxHeapify(maxHeapArray, i)
	return maxHeapArray

def maxHeapify(array, index):
	largest = index
	left = 2 * index + 1
	right = 2 * index + 2
	if left < len(array) and array[left] > array[largest]: # bug before change: array[left] > array[index]
		largest = left
	if right < len(array) and array[right] > array[largest]: # bug before change: array[right] > array[index]
		largest = right
	if largest != index:
		array[index], array[largest] = array[largest], array[index]
		maxHeapify(array, largest)

def heapSort(input):
	if len(input) <= 1:
		return input[:]
	maxHeap = buildMaxHeap(input)
	sorted_array = []
	while True:
		sorted_array.append(maxHeap[0])
		if len(maxHeap) == 1:
			break
		else:
			maxHeap[0] = maxHeap.pop()
			maxHeapify(maxHeap, 0)
	return sorted_array

import random
numOfRuns = 30
while numOfRuns:
	a = []
	size = random.randint(1000, 30000)
	while size:
		a.append(random.randint(0, 10000000))
		size -= 1
	b = heapSort(a)
	print sorted(a, reverse=True) == b
	numOfRuns -= 1

