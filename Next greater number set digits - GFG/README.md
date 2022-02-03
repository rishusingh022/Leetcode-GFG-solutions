# Next greater number set digits
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a number n, find the smallest number that has same set of digits as n and is greater than n.&nbsp;If n&nbsp;is the greatest possible number with its set of digits, report it.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 143
<strong>Output:</strong> 314
<strong>Explanation</strong>: Numbers possible with digits 
1, 3 and 4 are: 134, <strong>143</strong>, <strong>314</strong>, 341, 413, 431.
The first greater number after 143 is 314.

</span></pre>

<p><span style="font-size:18px">â€‹<strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: 
N = 431
<strong>Output:</strong> not possible
<strong>Explanation</strong>: Numbers possible with digits
1, 3 and 4 are: 134, 143, 314, 341, 413, 431.
Clearly, there's no number greater than 431.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findNext ()&nbsp;</strong>which takes an integer N&nbsp;as input and returns the smallest number greater than N&nbsp;with the same set of digits as N. If such a number is not possible, return -1.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(LogN).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(LogN).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N&nbsp;≤ 100000</span></p>
 <p></p>
            </div>