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
 * 1. állapotok sorszáma
 * 2-5. állapotok leírása
 * 8-11. pesszimista megközelítések
 * 14-17. optimista megközelítések
 * 20. végeredmény, amit a 12-18. részeredményekből számolunk ki

Egy adott állapothoz rendelünk egy 0-tól 8-ig terjedő számértéket, ahol a 4 a semleges, a 8-as a gép biztos győzelme és a 0-ás a gép biztos vesztése.

A program C++ nyelven lett megírva.
  
## Task  
Write a program that allows you to play against the computer using the alpha-beta pruning algorithm. No graphical interface required. Write a detailed description of the heuristic function.

It should be configured via the command line arguments:
  * `-d <N>` - maximum tree depth `N` 
  * `-t <N>` - maximum `N` seconds of thinking time

### Solution
The game of choice is Connect 4: lay out 4 "discs" horizontally, diagonally or vertically.

The code was written in C++.
