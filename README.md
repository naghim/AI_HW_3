# AI_HW_3

_Alpha-beta pruning_

The __readme__ is also available in English [here](#task).

## Feladat
Írjunk egy programot, amely az alfa-béta algoritmust használva lehetővé teszi a számítógép elleni játékot. Grafikus interfész nem szükséges. Írjunk részletes leírást a heurisztikus függvényről.

A parancssor argumentumain keresztül legyen konfigurálható:
  * `-d <N>` – a program a játékfát pontosan `N` mélységig bontsa le
  * `-t <N>` – a program egy lépésen legfennebb `N` másodpercet gondolkozzék.

### Megoldás
A választott játék a Connect 4: rakjunk ki 4 "korongot" vízszintesen, átlósan vagy függőlegesen.

  
## Task  
Write a program that allows you to play against the computer using the alpha-beta pruning algorithm. No graphical interface required. Write a detailed description of the heuristic function.

It should be configured via the command line arguments:
  * `-d <N>` - maximum tree depth `N` 
  * `-t <N>` - maximum `N` seconds of thinking time

### Solution
The game of choice is Connect 4: lay out 4 "discs" horizontally, diagonally or vertically.
