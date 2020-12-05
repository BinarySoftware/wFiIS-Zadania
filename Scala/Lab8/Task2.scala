object Task2 {
  def main(args: Array[String]): Unit = {
    // ("subjectName", degreeNumber, semesterNumber, ects, hasExam)
    // degreeNumber -> 1 = bachalor, 2 = masters
    val subjects = List(
      ("Matematyka dyskretna", 1, 1, 4, false),
      ("Algorytmy i struktury danych", 1, 2, 6, true),
      ("Teoria obwodów i sygnałów", 1, 3, 3, false),
      ("Układy elektroniczne", 1, 4, 5, true),
      ("Bazy danych 1", 1, 5, 5, false),
      ("Inżynieria oprogramowania", 1, 6, 5, true),
      ("Komputeryzacja pomiarów", 1, 7, 3, false),
      ("Modelowanie procesrów fizycznych", 2, 1, 5, true),
      ("Techniki mikroprocesorowe", 2, 2, 5, false),
      ("Programowanie zespołowe", 2, 3, 5, false)
    )

    case class Subject(
      name: String,
      degreeNumber: Int,
      semesterNumber: Int,
      ects: Int,
      hasExam: Boolean
    ) {
      override def toString: String = {
        "\n" + "Name: " + name + "\n" + "Degree: " + degreeNumber + "\n" + "Semester: " + semesterNumber + "\n" + "ECTS: " + ects + "\n" + "Has Exam?: " + hasExam + "\n"
      }
    }

    val matchedSubjects: List[Subject] =
      subjects.map(e => Subject(e._1, e._2, e._3, e._4, e._5))

    println("list of subjects for bachalor degree:")
    println(matchedSubjects.filter(_.degreeNumber == 1))
    println()

    println("list of subjects for masters degree:")
    println(matchedSubjects.filter(_.degreeNumber == 2))
    println()

    println("list of subjects with exams and ECTS > 5:")
    println(matchedSubjects.filter(_.hasExam).filter(_.ects > 5))
    println()

    println("list of subjects just with (name, ects):")
    println(matchedSubjects.map(e => (e.name, e.ects)))
    println()

    println(
      "list of subjects, where key is number of ECTS and value is list of subjects for that ECTS count (grouped by ECTS)"
    )
    println(matchedSubjects.map(s => (s.ects, s.name)).groupBy(_._1))
    println()

    println("number of ECTS points of all bachalors subjects:")
    println(matchedSubjects.filter(_.degreeNumber == 1).map(_.ects).sum)
    println()

    println(
      "number of ECTS points of all masters subjects, which doesn't have exam:"
    )
    println(
      matchedSubjects
        .filter(_.degreeNumber == 2)
        .filter(_.hasExam == false)
        .map(_.ects)
        .sum
    )
    println()

    println("sorted list of subjects (by name) for bachalors degree:")
    println(
      matchedSubjects.filter(_.degreeNumber == 1).sortWith(_.name < _.name)
    )
    println()
  }
}
