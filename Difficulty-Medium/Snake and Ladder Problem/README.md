<h2><a href="https://www.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1">Snake and Ladder Problem</a></h2><h3>Difficulty Level : Difficulty-Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);" bis_skin_checked="1"><p><span style="font-size: 18px;">Given an integer n such that there is <strong>n × n </strong>Snakes and Ladders board with cells numbered from 1 to n*n, find the minimum<strong> </strong>number of dice throws required to reach cell n*n starting from cell 1. G</span><span style="font-size: 18px;">iven two arrays of even<strong> </strong>lengths:</span></p>
<ul>
<li><span style="font-size: 18px;"><strong>lad[]</strong>, where each pair (lad[2*i], lad[2*i + 1]) represents the start and end of a ladder.</span></li>
<li><span style="font-size: 18px;"><strong>sn[]</strong>, where each pair (sn[2*i], sn[2*i + 1]) represents the start and end of a snake.</span><span style="font-size: 18px;"><br></span></li>
</ul>
<p><span style="font-size: 18px;">If you land on the start cell of a snake or ladder, you must immediately move to its corresponding end cell.</span></p>
<p><span style="font-size: 18px;">You have complete control over the outcome of each dice throw i.e., i</span><span style="font-size: 18px;">n a single move,&nbsp; you can move forward by any number of cells from 1 to 6.&nbsp;</span></p>
<p><span style="font-size: 18px;">If it is impossible to reach cell n*n, return <strong>-1. </strong></span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">n = 6, lad[] = [3, 22, 5, 8, 11, 35, 20, 32], sn[] = [17, 4, 19, 7, 34, 1, 21, 9]
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">3
</span><strong style="font-size: 18px;">Explanation: </strong></span><span style="font-size: 18px;">For the 6 × 6 board, the minimum number of dice throws needed to reach cell 36 from cell 1 is 3.
One optimal path is:
Throw 4 to move from<strong> </strong>1 to 5, then take the ladder to 8
Throw 3 to move from 8 to 11, then take the ladder to 35
Throw 1 to move from 35 to 36
So the destination is reached in 3 dice throws.<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/926473/Web/Other/blobid0_1781263877.webp" width="348" height="298"><br></span></pre>
<pre><span style="font-size: 18px;"><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:</strong><span style="font-size: 18px;"> n = 3, lad[] = [2, 8], sn[] = [7, 3]
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> 2
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">For the 3 × 3 board, the minimum number of dice throws needed to reach cell 9 from cell 1 is 2.
One optimal path is:
Throw 1 to move from 1 to 2, then take the ladder to 8.
Throw 1 to move from 8 to 9.<br>So the destination is reached in 2 dice throws.</span></span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>3</sup><br>1 ≤ lad.size(), sn.size(), lad[i], sn[i] ≤ n<sup>2</sup>&nbsp;</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>MAQ Software</code>&nbsp;<code>Adobe</code>&nbsp;<code>Nutanix</code>&nbsp;<code>Belzabar</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;