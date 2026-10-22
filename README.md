# TicTacToe-AI

The unbeatable TicTacToe.

![In-game footage](img/TicTacToe.gif)

## Features

- Difficulty levels: easy, medium and hard
- Board sizes: 3x3, 4x4, 5x5
- Hint the next move
- User interface

## Requirements

- Windows

## How the computer can play?

At the hard difficulty level the game uses calculates the all endings at each move and picks the one that for future. At the medium level, the game looks only for the one-move posibilities and chooses the one randomly among the all that doesn't cause immediate loss.

## How the hard mode works?

Hard mode equips two optimizations. One for the calculations and another for the memory. To reduce the number of calculations, the program passes calculating those possibilities further that there is already another possibility is known, better for the player or opponent dependening on the phase of alternation of the recursive algorithm. To reduce the memory allocations, the program avoid copying the board again for calculating the next move but does undo the last move and uses the same board representation.

## Build and run

```sh
make build/TicTacToe
./build/TicTacToe
```

## Known issues

Decision time follows $n^2!$ which means that it increases with the factorial of the number of squares in the board. For 3x3 board size, tree has 9! nodes at start. But for 4x4 board size, tree has 16! nodes, so, it takes 5 minutes to start. I literally never saw if 5x5-hard mode is working. Lol. (Numbers only for comparison, assumed there is no path has lower depth than others and no pruning) If anyone there trying to achieve this problem, I'll suggest a trick: Some board states at the tree are totaly same, for example, just one X token on the (upper-left) or (upper-right) or (bottom-left) or (bottom-right). Those same-states are sutiable to pruning.

## License

Presented under GNUv3 terms. Check the LICENSE file for description.
