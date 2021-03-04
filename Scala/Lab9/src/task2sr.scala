object Task2 {
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
    ) {
      override def toString: String = {
        "name: " + name + " surname: " + surname + " age: " + age + " gender: " + gender + "\n"
      }
    }

    val mappedPeople = people.map(p => Person(p._1, p._2, p._3, p._4))

    val splitByGender = mappedPeople.partition(_.gender == "male")
    println("Males:")
    println(splitByGender._1)

    println("Females:")
    println(splitByGender._2)

    val aboveTwentryThree: List[String] =
      mappedPeople.filter(_.age >= 23).map(_.name)
    println("Above 23:")
    println(aboveTwentryThree)

    val isJoeRob = mappedPeople.count(p => p.name == "Rob" || p.name == "Joe")
    println("Is there Joe or Rob:")
    println(isJoeRob > 0)

    println("Are equal num of genders:")
    println(
      splitByGender._1.map(_ => 1).equals(splitByGender._2.map(_ => 1))
    )
    //
    //    val isEveryoneOlderThan20 = people.count(person => person._3 > 20)
    //    println("Is everyone older than 20:")
    //    println(isEveryoneOlderThan20 == people.length)
    //
    //    val nameAge = people.map(person => (person._1, person._3))
    //    println("Name&Age:")
    //    println(nameAge)
    //
    //    val groupByAge = people.groupBy(person => person._3)
    //    println("Group by Age:")
    //    println(groupByAge)
    //
    //    val (older, younger) = people.partition(person => person._3 > 23)
    //    println("Younger:")
    //    println(younger)
    //    println("Older:")
    //    println(older)
    //
    //    val youngest = people.reduce((acc, value) => {
    //      if (acc._3 > value._3) value else acc
    //    })
    //    val oldest = people.reduce((acc, value) => {
    //      if (acc._3 < value._3) value else acc
    //    })
    //    println("Youngest:")
    //    println(youngest)
    //    println("Oldest:")
    //    println(oldest)
    //
    //    println("Are equal num of genders:")
    //    println(splitByGender._1.length == splitByGender._2.length)
    //
    //    val sortedAboveThwentyThree =
    //      people.sortBy(_._3).dropWhile(person => person._3 < 23)
    //    println("Sorted above 23:")
    //    println(sortedAboveThwentyThree)
    //  }
  }
}
