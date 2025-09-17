# [Gold II] 塗りつぶし (Painting) - 27337 

[문제 링크](https://www.acmicpc.net/problem/27337) 

### 성능 요약

메모리: 64760 KB, 시간: 260 ms

### 분류

구현, 그래프 이론, 자료 구조, 그래프 탐색, 집합과 맵, 분리 집합, 격자 그래프

### 제출 일자

2025년 9월 17일 17:06:01

### 문제 설명

<p>JOI くんはお絵かきソフトで遊んでいる．</p>

<p>お絵かきソフトでは，縦 <var>H</var> 行，横 <var>W</var> 列の長方形のマス目に絵を描くことができる．それぞれのマスには色が定められており，色は <var>1</var> 以上 <var>10<sup>9</sup></var> 以下の整数で表される．</p>

<p>上から <var>i</var> 行目 (<var>1 ≦ i ≦ H</var>)，左から <var>j</var> 列目 (<var>1 ≦ j ≦ W</var>) のマスをマス <var>(i,j)</var> と呼ぶ．現在，マス <var>(i,j)</var> の色は <var>A<sub>i,j</sub></var> である．</p>

<p>マス <var>(i,j)</var> から辺で接しているマスへの移動を繰り返し，マス <var>(i,j)</var> と色が異なるマスに入ることなく移動できるマスの集まりを，ここでは<strong>マス <var>(i,j)</var> の領域</strong>と呼ぶ．</p>

<p>お絵かきソフトには，<strong>塗りつぶし</strong>という機能がある．この機能では，あるマス <var>(x,y)</var> (<var>1 ≦ x ≦ H</var>，<var>1 ≦ y ≦ W</var>) と色 <var>c</var> (<var>1 ≦ c ≦ 10<sup>9</sup></var>) を指定すると，マス <var>(x,y)</var> の領域に含まれるマスの色がすべて <var>c</var> に変化する．</p>

<p>JOI くんはあるマス <var>(x,y)</var> と色 <var>c</var> を選び，そのマスと色を指定して塗りつぶしをちょうど <var>1</var> 回使う．塗りつぶしを使った後のマス <var>(x,y)</var> の領域に含まれるマスの個数が JOI くんの得点となる．</p>

<p>JOI くんの得点として達成可能な最大値を求めるプログラムを作成せよ．</p>

### 입력 

 <p>入力は以下の形式で与えられる．</p>

<pre><var>H</var> <var>W</var>
<var>A<sub>1,1</sub></var> <var>A<sub>1,2</sub></var> <var>…</var> <var>A<sub>1,W</sub></var>
<var>A<sub>2,1</sub></var> <var>A<sub>2,2</sub></var> <var>…</var> <var>A<sub>2,W</sub></var>
<var>:</var>
<var>A<sub>H,1</sub></var> <var>A<sub>H,2</sub></var> <var>…</var> <var>A<sub>H,W</sub></var></pre>

### 출력 

 <p>JOI くんの得点として達成可能な最大値を <var>1</var> 行に出力せよ．</p>

