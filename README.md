# 24-Game
GAME

<br>

LeetCode Problem=679 Hard problem
<br>
Problem Name=24 Game  
<br>

<br>

You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
<br>
You are restricted with the following rules:
<br>
The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.


<br>
 
<br>


Example 1:

Input: cards = [4,1,8,7]
<br>
Output: true
<br>
Explanation: (8-4) * (7-1) = 24

<br>
<br>


Example 2:

Input: cards = [1,2,1,2]
<br>
Output: false
 
<br>

<br>


Constraints:
<br>
cards.length == 4
<br>
1 <= cards[i] <= 9

<br>

<br>

APPROACH

<br>

(1) We'll define two functions: valid to check if given numbers can result in 24 when combined, and get_perm to generate all permutations of the given numbers and check if any permutation satisfies the condition.
<br>

<br>


(2) In the valid function, we'll check if the given numbers can result in 24 by performing addition, subtraction, multiplication, and division while considering floating-point precision.
<br>

<br>


(3)In the get_perm function, we'll generate all permutations of the given numbers using backtracking. We'll swap numbers at different positions to explore all possible combinations. Once we find a permutation that results in 24, we'll return true; otherwise, we'll return false.
<br>



 Time complexity:
 <br>
 <br>

 <br>
(1) O(1) for the valid function as it performs a constant number of operations. For the get_perm function, it depends on the number of permutations, which is at most 4!, so it's also constant.

<br>

<br>


Space complexity:
<br>

<br>

(2) O(1) for the valid function as it uses constant space. For the get_perm function, it uses a set to track seen numbers during backtracking, which can have at most 4 elements, so it's also constant.
Code

