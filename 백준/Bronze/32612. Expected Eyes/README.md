# [Bronze I] Expected Eyes - 32612 

[문제 링크](https://www.acmicpc.net/problem/32612) 

### 성능 요약

메모리: 13220 KB, 시간: 0 ms

### 분류

수학, 확률론

### 제출 일자

2026년 2월 3일 17:26:57

### 문제 설명

<p>Once upon a time, in a small kingdom in the Faraway Province of Combinatorics the king was obsessed with dice. He had a collection of <em>multi-faced</em> dice from all over the world, and he loved to play games with them.</p>

<p>One day, the king came up with a new game. Every player would choose a number and then the king would roll all his dice at once. The player whose choice is closest to the value of all numbers on the dice wins. Since the king hates losing, he wanted to increase his winning chances by always choosing the expected value of his throw. Not very skilled with mathematics, he asked you to solve the following problem.</p>

<p>Given a list of dice and the number of faces of each one of them, calculate the expected value of throwing all of them at once.</p>

<p>The expected value of an event is the weighted average of all possible outcomes.</p>

<p>As an example, consider the second sample input. By throwing two (three- and two-sided) dice, you can get the following values:</p>

<ul>
	<li>$2$ by throwing $(1, 1)$</li>
	<li>$3$ by throwing $(1, 2)$ or $(2, 1)$</li>
	<li>$4$ by throwing $(2, 2)$ or $(3, 1)$</li>
	<li>$5$ by throwing $(3, 2)$</li>
</ul>

<p>We then sum all the outcomes and divide them by the number of possible throws.</p>

<p>$$E[X] = \frac{2 \cdot 1 + 3 \cdot 2 + 4 \cdot 2 + 5 \cdot 1}{6} = \frac{21}{6} = 3.5$$</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \leq n \leq 8$), the number of dice.</li>
	<li>One line with $n$ integers $x$ ($2 \leq x \leq 8$), the number of faces on each die.</li>
</ul>

### 출력 

 <p>Output the expected value of throwing all dice.</p>

<p>Your answer should have an absolute or relative error of at most $10^{-6}$.</p>

