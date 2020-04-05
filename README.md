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
A heurisztikus függvény mintákhoz rendel értékeket, minél jobb, előnyösebb helyzet a gép számára a vizsgált állapot, annál nagyobb számot térít vissza, minél rosszabb, annál kisebbet. Majd ezeket összegzi. További információk a következő fájlban találhatóak a "mintákkal" kapcsolatosan: [myTrick.xlsx](https://github.com/naghim/AI_HW_3/blob/master/myTrick.xlsx), ahol:
 * 1-es sor: állapotok sorszáma
 * 2-5 sorok: állapotok leírása
 * 8-11 sorok: pesszimista megközelítések
 * 14-17 sorok: optimista megközelítések
 * 20-as sor: végeredmény, amit a 12-18. részeredményekből számolunk ki

Egy adott állapothoz rendelünk egy 0-tól 8-ig terjedő számértéket, ahol a 4 a semleges, a 8-as a gép biztos győzelme és a 0-ás a gép biztos vesztése.

A program C++ nyelven lett megírva.

___
___

  
## Task  
Write a program that allows you to play against the computer using the alpha-beta pruning algorithm. No graphical interface required. Write a detailed description of the heuristic function.

It should be configured via the command line arguments:
  * `-d <N>` - maximum tree depth `N` 
  * `-t <N>` - maximum `N` seconds of thinking time

### Solution
The game of choice is Connect 4: lay out 4 "discs" horizontally, diagonally or vertically. The heuristic function assigns values to patterns, better situations for the machine returns higher numbers. We will then summarize these numbers. For more information about these "patterns," see [myTrick.xlsx](https://github.com/naghim/AI_HW_3/blob/master/myTrick.xlsx), where:

 * row #1 - numbers of states
 * rows 2-5 - description of states
 * rows 8-11 - pessimistic approaches
 * rows 14-17 - optimistic approaches
 * row #20 - final result, which is calculated from partial results (rows 12-18)

A given state is assigned a numeric value from 0 to 8, where 4 is the neutral, 8 is the sure victory of the machine, and 0 is the sure loss of the machine.

The code was written in C++.
