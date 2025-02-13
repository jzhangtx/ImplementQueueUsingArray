package main

import (
	"errors"
	"fmt"
)

type Queue struct {
	m_Capacity int
	m_Array    []int
	m_Size     int
}

func (q *Queue) SetCapacity(cap int) {
	q.m_Capacity = cap
	q.m_Array = make([]int, q.m_Capacity)
	q.m_Size = 0
}

func (q *Queue) IsEmpty() bool {
	return q.m_Size == 0
}

func (q *Queue) Size() int {
	return q.m_Size
}

func (q *Queue) Front() (int, error) {
	if q.IsEmpty() {
		return -1, errors.New("The queue is empty!")
	}

	return q.m_Array[0], nil
}

func (q *Queue) Back() (int, error) {
	if q.IsEmpty() {
		return -1, errors.New("The queue is empty!")
	}

	return q.m_Array[q.m_Size-1], nil
}

func (q *Queue) Push(element int) error {
	if q.m_Size == q.m_Capacity {
		return errors.New("The queue is full!")
	}

	q.m_Array[q.m_Size] = element
	q.m_Size++

	return nil
}

func (q *Queue) Pop() {
	if q.IsEmpty() {
		return
	}

	q.m_Size--
	for i := 0; i < q.m_Size; i++ {
		q.m_Array[i] = q.m_Array[i+1]
	}
}

func PrintTest(q *Queue) {
	// Commented is the normal implementation. The current code is as per the questions' requirement
	n, _ := q.Front()
	// n, err := q.Front()
	// if err != nil {
	// 	fmt.Print(err.Error(), "    ")
	// } else {
	fmt.Print(n, " ")
	// }
	n, _ = q.Back()
	//n, err = q.Back()
	// if err == nil {
	fmt.Print(n, " ")
	// } else {
	// 	fmt.Print(err.Error(), "    ")
	// }
	fmt.Println(q.IsEmpty(), q.Size())
}

func main() {
	q := Queue{0, []int{}, 0}
	q.SetCapacity(10)
	PrintTest(&q)

	q.Push(5)
	PrintTest(&q)

	q.Push(6)
	PrintTest(&q)

	q.Push(7)
	PrintTest(&q)

	q.Pop()
	PrintTest(&q)

	q.Pop()
	PrintTest(&q)

	q.Pop()
	PrintTest(&q)
}
