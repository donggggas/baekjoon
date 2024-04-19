# [Platinum I] Whitespace - 14393 

[문제 링크](https://www.acmicpc.net/problem/14393) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 그리디 알고리즘

### 제출 일자

2024년 4월 8일 22:58:34

### 문제 설명

<p>Whitespace는 공백과 줄 바꿈만으로 코딩하는 프로그래밍 언어이다. 공백은 "<code>SP</code>"로 나타내며, 줄 바꿈은 "<code>NL</code>"으로 나타낸다.</p>

<p>영선이는 Whitespace로 코딩한 프로그램을 가지고 있으며, 길이가 N인 수열 L로 나타낼 수 있다. L<sub>i</sub>는 i번 줄에 쓰여 있는 "<code>SP</code>"의 개수이며, 모든 줄은 "<code>NL</code>"로 끝난다. 즉, 소스 코드는 L<sub>0</sub>개의 <code>SP</code>, <code>NL</code>, L<sub>1</sub>개의 <code>SP</code>, ..., L<sub>N-1</sub>개의 <code>SP</code>, <code>NL</code> 으로 이루어져 있다.</p>

<p>오늘은 효빈이가 만든 에디터를 이용해서 코딩을 하려고 한다. 에디터의 커서는 문서의 처음이나 끝 또는 인접한 두 문자의 사이 아무데나 위치할 수 있다.</p>

<p>에디터는 아래와 같은 3가지 특별한 키를 가지고 있다.</p>

<ul>
	<li>SPACE: 현재 커서 위치에 <code>SP</code>를 삽입한다.</li>
	<li>DELETE: 커서의 오른쪽 위치에 있는 <code>SP</code> 문자를 삭제한다. 오른쪽 위치에 있는 문자가 <code>NL</code>인 경우에는 사용할 수 없다.</li>
	<li>RETURN: <code>NL</code>을 하나 입력하고, <code>SP</code>를 K개 입력한다. 이때, K는 커서가 있는 줄에 있는 <code>SP</code>의 개수와 같으며, 커서의 오른쪽 글자가 <code>NL</code>인 경우에만 사용할 수 있다. 예를 들어, 문서가 "<code>SP</code> <code>NL</code> <code>SP</code> <code>SP</code> <code>NL</code> <code>SP</code> <code>SP</code> <code>SP</code> <code>NL</code>" 인 경우에 두 번째 <code>NL</code>의 RETURN을 눌렀다면, "<code>SP</code> <code>NL</code> <code>SP</code> <code>SP</code> <code>NL</code> <code>SP</code> <code>SP</code> <code>NL</code> <code>SP</code> <code>SP</code> <code>SP</code> <code>NL</code>"이 된다.</li>
</ul>

<p>에디터에는 지금 NL 하나만 입력되어 있다. L이 주어졌을 때, 소스 코드를 완성하는데 필요한 키 입력 횟수의 최솟값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다. 둘째 줄에 L이 주어진다. (1 ≤ N ≤ 50, 0 ≤ L<sub>i</sub> ≤ 1,000,000)</p>

### 출력 

 <p>첫째 줄에 소스 코드를 완성하는데 필요한 키 입력 횟수의 최솟값을 출력한다.</p>

