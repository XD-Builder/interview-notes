package util

import (
	"container/heap"
)

type PriorityQueue []ImageResult

func (pq PriorityQueue) Len() int {
	return len(pq)
}
func (pq PriorityQueue) Less(i, j int) bool {
	// higher the expiry the higher the priority
	return pq[i].Value > pq[j].Value
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].Index = i
	pq[j].Index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	imageResult := x.(ImageResult)
	imageResult.Index = n
	*pq = append(*pq, imageResult)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	imageResult := old[n-1]
	imageResult.Index = -1 // for safety
	*pq = old[0 : n-1]
	return imageResult
}

// TopRank uses Golang's provided heap package
// and ranks top k int in the int array
// Time complexity Analysis
// Priority queue initialization => O(n), but it may take longer to allocate memory
// Init => O(n)
//		It iteratively constructs the max heap from the highest index to root
// Pop => O(log(n))
//      It removes the root element, O(1) and re-initializes the root, O(log(n))
// Total Time Complexity = O(n + log(n) * k)
// Space Complexity = O(n) where n is the image array to initialize priorityQueue
func RankTopKImage(imageResults []ImageResult, k int) []ImageResult {
	// start := time.Now()
	// instead of recreating the entire priorityQueue again, simply
	// make an array assignment to priorityQueue
	priorityQueue := make(PriorityQueue, len(imageResults))
	priorityQueue = imageResults
	// for i, imageResult := range imageResults {
	// 	imageResult.Index = i
	// 	priorityQueue[i] = imageResult
	// }
	// log.Println("Time spent creating priorityQueue: ", time.Since(start))
	// start = time.Now()
	heap.Init(&priorityQueue)
	// log.Println("Time spent initializing heap: ", time.Since(start))
	result := make([]ImageResult, k)
	count := 0

	// start = time.Now()
	for priorityQueue.Len() > 0 && count < k {
		imageResult := heap.Pop(&priorityQueue).(ImageResult)
		result[count] = imageResult
		count++
	}
	// log.Println("Time spent getting kth largest element from heap: ", time.Since(start))
	return result
}
