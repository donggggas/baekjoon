# [Gold V] Widening of Channels - 6247 

[문제 링크](https://www.acmicpc.net/problem/6247) 

### 성능 요약

메모리: 4460 KB, 시간: 16 ms

### 분류

그래프 이론, 그래프 탐색, 트리

### 제출 일자

2024년 9월 6일 16:15:10

### 문제 설명

<p>In the Waterland country, there are n lakes (numbered from 1 to n) and m channels between them. The width (in meters) of each channel is known. Navigation in the channels can be performed in both directions. It is known that a boat with width of one meter can reach any lake, starting from lake number 1.</p>

<p>Write program channels, which calculates the minimum number of channels that should be widened, so that a boat with width of k meters can make a trip between every two lakes (the boat can move from one lake to another, if its width is less than or equal to the width of the channel, connecting the lakes).</p>

### 입력 

 <p>On the first line of the standard input are given integers, n and m (1 < n ≤ 1000, 1 < m ≤ 100000).</p>

<p>On each of the next m lines are given three integers, i, j and w, showing that there is a channel of width w (1 ≤ w ≤ 200) between lakes, i and j (1 ≤ i, j ≤ n).</p>

<p>On the last line is given the integer k (1 ≤ k ≤ 200).</p>

### 출력 

 <p>On a line of the standard output the program have to write one integer: the minimum number of channels that should be widened.</p>

