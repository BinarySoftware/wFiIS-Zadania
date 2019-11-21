################################################################################
#### Created by Maciej Mikołajek on 21.11.2019 - Prezenty ######################
################################################################################

# Dodaje rekord do bazy danych i wraca do pytania o następną osobę
def appendToDB(p1, p2):
    str = p1 + " - " + p2 + "\n"
    f = open("db.txt", "a+")
    f.write(str)
    f.close()

    print("Dodano do bazy danych.")
    print("Aby zakończyć program - wpisz 'stop' ")
    userInteraction()

def userInteraction():
    person1 = input("Podaj swoje imię: ")
    if person1 == "stop":
        exit()
    person2 = input("Podaj imię osoby której wręczasz prezent: ")
    appendToDB(person1, person2)

def main():
   userInteraction()

if __name__ == "__main__":
    main()