package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ans := new(ListNode)
	c := 0
	var pre *ListNode
	for p := ans; l1 != nil || l2 != nil; {
		if l1 == nil {
			p.Val = l2.Val + c
		} else if l2 == nil {
			p.Val = l1.Val + c
		} else {
			p.Val = l1.Val + l2.Val + c
		}
		if p.Val >= 10 {
			p.Val -= 10
			c = 1
		} else {
			c = 0
		}
		p.Next = new(ListNode)
		pre = p
		p = p.Next
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if c > 0 {
		pre.Next.Val = 1
	} else if pre != nil {
		pre.Next = nil
	}
	return ans
}

func newListNode(a []int) *ListNode {
	head := new(ListNode)
	p := head
	var pre *ListNode
	for _, num := range a {
		p.Val = num
		p.Next = new(ListNode)
		pre = p
		p = p.Next
	}
	if pre != nil {
		pre.Next = nil
	}
	return head
}

func printListNode(l *ListNode) {
	for ; l != nil; l = l.Next {
		fmt.Printf("%v,", l.Val)
	}
}

// func main() {
// 	l1 := newListNode([]int{9, 9, 9, 9, 9, 9, 9})
// 	l2 := newListNode([]int{9, 9, 9, 9})
// 	l3 := addTwoNumbers(l1, l2)
// 	printListNode(l3)
// }
