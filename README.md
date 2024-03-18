# TrafficJam

## TrafficJam este un minigame 2D reprezentat intr-u dictionar auto interactiv, unde user-ul trebuie sa selecteze ordinea in care autoturismele au prioritate in interiorul unei intersectii.

### -> Toate scenariile sunt generate random pe baza unui algoritm pe grafuri.
##### Fiecare directie de deplasare are ca frunze masinile asociate acesteia, acestea la randul lor sunt parcurse printr-un algoritm pe principiu BFS. Directiile sunt mapate pe numere astfel: UP -> 1 RIGHT -> 2 DOWN -> 3 RIGHT -> 4
##### Pe princiu BFS nodurle masinilor cu aceiasi destinatie sunt sortate crescator in ordinea prioritatii. Acestea sunt memorate intr-o structura std::deque ce ne va permite ulterior implementarea mecanicii de drum cu prioritate prin metoda push_front().
