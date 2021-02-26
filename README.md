# TicTacToe-AI
Visual C++ implementation of unbeatable TicTacToe game with Alpha-Beta Pruning.

![In-game footage](img/TicTacToe.gif)

## Features

- 3 difficulty levels (Easy, Medium and **Hard**)
- Different board sizes: 3x3, 4x4, 5x5
- **Hint** mechanism available at all game scenarios.

## Algorithms

### Hard Mode

Hard mode uses popular approach **Alpha-Beta pruning** which often used by others. But with one modification: Instead of the creation of whole tree with thousands of possible board state, I created just one board and a move stack. That way, memory usage is reduced but total calculation count is increased.

### Medium Mode

Heuristic algorithm looking for next move and picks the best move.

Basically: WIN-state > LOSE-state (block) > other

### Easy Mode

Random moves

## Known issues

1. As board size increases, decision time is dramatically increases. For 3x3 board size, tree has 9! nodes at start. But for 4x4 board size, tree has 16! nodes, so, it takes 5 minutes to start. I literally never saw if 5x5-hard mode is working. Lol. (Numbers only for comparison, assumed there is no path has lower depth than others and no pruning) If anyone there trying to achieve this problem, I'll suggest a trick: Some board states at the tree are totaly same, for example, just one X token on the (upper-left) or (upper-right) or (bottom-left) or (bottom-right). Those same-states are sutiable to pruning. 
