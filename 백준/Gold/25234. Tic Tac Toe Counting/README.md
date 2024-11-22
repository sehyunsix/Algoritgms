# [Gold IV] Tic Tac Toe Counting - 25234 

[문제 링크](https://www.acmicpc.net/problem/25234) 

### 성능 요약

메모리: 3584 KB, 시간: 2792 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 해시를 사용한 집합과 맵

### 제출 일자

2024년 11월 23일 04:03:09

### 문제 설명

<p>Tic Tac Toe is a simple children's game. It is played on a <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times 3$</span></mjx-container> grid. The first player places an <code>X</code> in any of the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>9</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$9$</span></mjx-container> cells. The next player places an <code>O</code> in any of the remaining 8 cells. The players continue to alternate placing <code>X</code>s and <code>O</code>s in unoccupied cells until either a player gets three of their symbols in a row, or the grid is full. If either player gets three in a row, in any of the three rows, three columns or two diagonals, that player wins and the game ends.</p>

<p>Fred and Sam are playing a game of Tic Tac Toe. In the middle of the game, Fred wonders: "How many games from this point in the game onward are winners for <code>X</code>? How many for <code>O</code>?" Two games are different if they have different sequences of moves, even if they result in the grid looking the same at any point.</p>

<p>Given a list of grids, determine first if they can be reached in a game of Tic Tac Toe, and if they can, how many games from that point on result in wins for <code>X</code>, and how many for <code>O</code>.</p>

### 입력 

 <p>The first line of input contains a single integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>t</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>t</mi><mo>≤</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le t \le 10^5$</span></mjx-container>), which is the number of test case grids.</p>

<p>Each of the next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>t</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t$</span></mjx-container> lines contains a single string <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi><mjx-texatom texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo></mjx-texatom><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">|</mo><mi>s</mi><mrow data-mjx-texclass="ORD"><mo stretchy="false">|</mo></mrow><mo>=</mo><mn>9</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$|s|=9$</span></mjx-container>) which consists of only the characters <code>'.'</code>, <code>'X'</code> and/or <code>'O'</code>. These are the test case grids. The first three characters represent the first row, the second three are the second row, and the last three are the last row, with <code>'.'</code> representing an empty cell. For example, the string <code>XX..O....</code> represents this grid:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2abda38c-13c7-455c-9ba3-50d730033a00/-/crop/504x504/115,136/-/preview/" style="width: 100px; height: 100px;"></p>

### 출력 

 <p>For each test case, output two space-separated integers. If the grid is not reachable in a game of Tic Tac Toe, output <code>-1 -1</code>. If the grid is reachable, output the number of games from that point on (including that grid) that are wins for <code>X</code>, followed by wins for <code>O</code>.</p>

