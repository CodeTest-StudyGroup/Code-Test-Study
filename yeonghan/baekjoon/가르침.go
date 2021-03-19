package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r     = bufio.NewReader(os.Stdin)
	w     = bufio.NewWriter(os.Stdout)
	n, k  int
	s     []string
	visit [30]bool
	ans   = 0
)

func test() int {
	cnt := 0
	for i := 0; i < n; i++ {
		check := true
		for j := 0; j < len(s[i]); j++ {
			if !visit[s[i][j]-'a'] {
				check = false
				break
			}
		}
		if check {
			cnt++
		}
	}

	return cnt
}

func sel(alpha int, cnt int) {
	if cnt == k {
		num := test()
		if ans < num {
			ans = num
		}
		return
	}
	for i := alpha; i < 26; i++ {
		if visit[i] == false {
			visit[i] = true
			sel(i, cnt+1)
			visit[i] = false
		}
	}
}

func main() {
	defer w.Flush()

	fmt.Fscan(r, &n, &k)
	if k < 5 {
		fmt.Fprintln(w, 0)
		return
	} else if k == 26 {
		fmt.Fprintln(w, n)
		return
	}
	s = make([]string, n)
	visit['a'-'a'] = true
	visit['c'-'a'] = true
	visit['i'-'a'] = true
	visit['n'-'a'] = true
	visit['t'-'a'] = true
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &s[i])
		s[i] = s[i][4 : len(s[i])-4]
	}

	k -= 5
	sel(0, 0)
	fmt.Fprintln(w, ans)

}
