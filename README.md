# Podstawy Informatyki

To repozytorium zawiera fragmenty kodu oraz pseudokodu
napisanego na potrzeby zajęć podstaw informatyki na wFiIS AGH.

### Jak uruchamiać moje programy?
1. Upewnij się że posiadasz na komputerze JDK, Scala Compiler oraz SBT
2. Otwórz Terminal i przejdź do wybranego programu, np `Horner`
3. Uruchom Scala Build Tools komendą `sbt`
4. Moje funkcje nie posiadają swoich implementacji, natomiast posiadają
   zestaw szerokich testów sprawdzających działanie przy różnych możliwych
   przypadkach. Dlatego aby sprawdzić czy dana funkcja działa należy ją
   uruchomić w środowisku testowym komendą `test`
   
## Horner

Prosta funkcja rekurencyjnie wyliczająca wynik wielomianu przy pomocy
schematu Hornera, zaprezentowanego poniżej

```
((...((An*x + An-1)*x + An-2) ... )*x + A1)*x + A0
```