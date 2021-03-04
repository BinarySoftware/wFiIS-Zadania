object Task2LW {
  def main(args: Array[String]): Unit = {
    val people = List(
      ("John", "Doe", 23, "male"),
      ("Joan", "Doe", 23, "female"),
      ("Steve", "Jenkins", 24, "male"),
      ("Eva", "Robinson", 25, "female"),
      ("Ben", "Who", 22, "male"),
      ("Janet", "Reed", 21, "female"),
      ("Rob", "Jenkins", 26, "male"),
      ("Ella", "Dawson", 27, "female")
    )

    case class Person(
      name: String,
      surname: String,
      age: Int,
      gender: String
    )

    val matchedPeople: List[Person] =
      people.map(e => Person(e._1, e._2, e._3, e._4))

//    - Print list of females and list of males.
    println(matchedPeople.filter(_.gender == "male"))
    println(matchedPeople.filter(_.gender == "female"))

//    - Obtain names of all people of age above 23.
    println(matchedPeople.filter(_.age > 23).map(_.name))

//    - Check if among the people on the list there is someone of name Joe and John.
    println(matchedPeople.exists(p => p.name == "Joe" || p.name == "John"))

//    - Check if everyone is older than 20.
    println(matchedPeople.sortWith(_.age < _.age).head.age > 20)

//    - Obtain a list of First names and age.
    println(matchedPeople.map(p => (p.name, p.age)))

//    - Group all people by age.
    println(matchedPeople.groupBy(_.age))

//    - Split the list of people into younger and older than 23.
    println(matchedPeople.partition(_.age > 23))

//    - Find the oldest and youngest.
    println(matchedPeople.sortWith(_.age > _.age).head)
    println(matchedPeople.sortWith(_.age < _.age).head)

//    - In a single set of transformations check if the number of males and females in the list is identical.

    println(
      matchedPeople.partition(_.gender == "male")._1.length == matchedPeople
        .partition(_.gender == "male")
        ._2
        .length
    )
//    - Obtain a sorted list of people of age above 23 with dropWhile and sort.
    println(matchedPeople.sortWith(_.age < _.age).dropWhile(_.age <= 23))
  }
}
