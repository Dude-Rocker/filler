# [filler](https://github.com/Dude-Rocker/resources/blob/master/filler/filler.pdf)
## The school 42 project of algorithms branch
### In this project you need to write your bot, which will play against other bots and try to win them.
### There is also a bonus visualization
## Game rules
* In this game, two players fight each other. They play one after the other.
* The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, player will receive their game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in his piece) covers the cell of a shape placed previously (his territory).
* The shape must not exceed the dimensions of the board
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

## Few example:

### without visual mode

![without visual](https://github.com/Dude-Rocker/resources/blob/master/filler/vgladuhs_vs_carli.gif)

### Visual

![Visual](https://github.com/Dude-Rocker/resources/blob/master/filler/grati_vs_vgladush.gif)

![Visual](https://github.com/Dude-Rocker/resources/blob/master/filler/vgladush_vs_hcao.gif)
