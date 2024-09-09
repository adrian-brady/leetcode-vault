package main

import "fmt"

// complement is target - current
// make map to hold complementary values
// check if map holds complement
// if not, hasnt been seen, add index to map
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		if _, ok := m[v]; ok {
			return []int{m[v], i}
		}

		complement := target - nums[i]
		m[complement] = i
	}
	return []int{0, 0}
}

func main() {
	// test := []int{2, 7, 11, 15}
	// ans := twoSum(test, 9)
	test := []int{3, 2, 4}
	ans := twoSum(test, 6)
	fmt.Printf("%+v\n", ans)
}
