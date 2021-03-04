# wFIiS AGH - Rozwiązania zadań

To repozytorium zawiera fragmenty kodu oraz pseudokodu
napisanego przeze mnie na potrzeby zajęć:
- Podstaw Informatyki (2019)
- Podstaw Programowania Proceduralnego (2020)
- Podstaw Programowaniia Obiektowego (2020)
- Functional Programming in Scala (2020)
- Programowania Obiektowego 1 (2021)
- Metod Numerycznych (2021)
- Python (2021)

<!-- ### Jak uruchamiać programy?

#### C
1. Skompiluj wybrany program przy pomocy GCC:
`gcc 'NAZWA'.c -o 'NAZWA'.o`
Gdzie 'NAZWA' - to nazwa wybranego programu
2. Uruchom program komendą:
`./'NAZWA'.o`

#### Scala
1. Upewnij się że posiadasz na komputerze JDK, Scala Compiler oraz SBT
2. Otwórz Terminal i przejdź do wybranego programu, np `Horner`
3. Uruchom Scala Build Tools komendą `sbt`
4. Moje funkcje nie posiadają swoich implementacji, natomiast posiadają
   zestaw szerokich testów sprawdzających działanie przy różnych możliwych
   przypadkach. Dlatego aby sprawdzić czy dana funkcja działa należy ją
   uruchomić w środowisku testowym komendą `test`

#### Python
1. Upewnij się że posiadasz na komputerze kompilator Pythona 3, w wersji >= 3.7
2. Dla łatwości obsługi i edycji kodu zainstaluj IDE PyCharm
3. W PyCharm po załadowaniu projektu wystarczy kliknąć zielony, trójkątny przycisk `run`

## Horner `Scala`

Prosta funkcja rekurencyjnie wyliczająca wynik wielomianu przy pomocy
schematu Hornera, zaprezentowanego poniżej

```
((...((An*x + An-1)*x + An-2) ... )*x + A1)*x + A0
```

#### Porównanie różnych podejść 

| Typ        | Dane           | Czas (ns)  |
| ------------- |:-------------:| -----:|
| rekurencja      | Binarny | 687851 |
| rekurencja     | Randomowy      |   8256 |
| rekurencja bez generyków |  Binarny      |    10254 |
| rekurencja bez generyków | Randomowy      |    5147 |
| Pętla while      | Binarny | 10382 |
| Pętla while     | Randomowy      |   4285 |
| Łopatologiczne potęgowanie i mnożenie  |  Binarny      |    325671 |
| Łopatologiczne potęgowanie i mnożenie      | Randomowy      |     52681 |

## Min `scala`

Prostsza od Hornera funkcja rekurencyjnie szukająca najmniejszej wartości w
zadanej liśce

## Search `Python`

Kod jest implementacją dwóch popularnych metod przeszukiwania tablic
binarnego, oraz liniowego, przy czym przeszukiwanie binarne rozwiązałem
dwoma metodami - pętlą while oraz rekurencyjnie. -->