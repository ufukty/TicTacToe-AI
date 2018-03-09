# TicTacToe-AI
Visual C++ implementation of unbeatable TicTacToe game with Alpha-Beta Pruning.

Gameplay is available: https://youtu.be/X9GnQvv_bo4

## Features

- Two game modes: (**Player vs. Computer**) and (Player vs. Player)
- 3 difficulty levels for PvC (Easy, Medium and **Hard**)
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

- If board size is 5x5 and game mode is hard, it takes to much time to calculate first and a few next moves.
