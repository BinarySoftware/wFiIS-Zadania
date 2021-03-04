object Ania2 {
//  The goal is to exercise collections functionality.
//  We need to design classes that can keep track of our budget that is a list
//  of incomes and expenses. We will then have a few methods useful for tracking
//  what is going on in the budget. All of then have to be implemented with collections API.
//
//  You are free to decide if you want one or two classes for income and expense.
//  Whatever you find more convenient.

  class Budget() {
    var incomes: List[Income]              = Nil
    var expenses: List[Expense]            = Nil
    var allTransactions: List[Transaction] = Nil

    def +(income: Income): Unit = {
      incomes         = incomes :+ income
      allTransactions = allTransactions :+ income
    }
    def -(expense: Expense): Unit = {
      expenses        = expenses :+ expense
      allTransactions = allTransactions :+ expense
    }

    def total: Int = incomes.map(_.value).sum - expenses.map(_.value).sum

    def incomes(category: String): List[Income] =
      incomes.filter(_.category == category)
    def expenses(category: String): List[Expense] =
      expenses.filter(_.category == category)

    def maxExpense: Expense = expenses.sortWith(_.value > _.value).head

    def track: Unit = {
      var allMoney = 0
      allTransactions.foreach(t => {
        t match {
          case Expense(value, _, _) => allMoney -= value
          case Income(value, _, _)  => allMoney += value
        }
        println(allMoney)
      })
    }
  }

  abstract class Transaction(value: Int, category: String, synopsis: String)
  case class Income(value: Int, category: String, synopsis: String)
      extends Transaction(value, category, synopsis)
  case class Expense(value: Int, category: String, synopsis: String)
      extends Transaction(value, category, synopsis)

  def main(args: Array[String]): Unit = {
    val b = new Budget
    b + Income(3000, "main", "Corpo. salary Cucumber International")
    b - Expense(100, "investment", "Cucumbers for pickling")
    b + Income(2000, "main", "Corpo. salary Cucumber International")
    b - Expense(10, "investment", "Dill")
    b - Expense(750, "investment", "Barrel")
    b - Expense(5, "consumption", "Beer")

    b + Income(200, "side", "Cucumbers sale")
    b + Income(20, "side", "Barrel rental")

    println(b.total)    // total sum
    println(b.expenses) // list of all expenses
    println(b.expenses("investment"))
    println(b.incomes("main")) // print all in category
    println(
      b.track
    ) // list of amount of money after each transaction 3000, 2900, 5900
    println(b.maxExpense)
//    println(
//      b.trackWith(_.category)
//    ) // track with additional info collected by user provided function
  }

}
