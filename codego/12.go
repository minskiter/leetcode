package main

import (
	"bytes"
	"fmt"
)

var romans = []rune{'I', 'V', 'X', 'L', 'C', 'D', 'M'}

func rep(ch rune, cnt int) string {
	var b bytes.Buffer
	for ; cnt > 0; cnt-- {
		b.WriteRune(ch)
	}
	return b.String()
}

func calc(num int, i int, ans *bytes.Buffer) {
	if num <= 0 {
		return
	}
	calc(num/10, i+2, ans)
	n := num % 10
	switch {
	case n <= 3:
		ans.WriteString(rep(romans[i], n))
		break
	case n == 4:
		ans.WriteRune(romans[i])
		ans.WriteRune(romans[i+1])
		break
	case n >= 5 && n < 9:
		ans.WriteRune(romans[i+1])
		ans.WriteString(rep(romans[i], n-5))
		break
	case n == 9:
		ans.WriteRune(romans[i])
		ans.WriteRune(romans[i+2])
		break
	}

}

func intToRoman(num int) string {
	var ans bytes.Buffer
	calc(num, 0, &ans)
	return ans.String()
}

func main() {
	fmt.Println(intToRoman(1994))
}
