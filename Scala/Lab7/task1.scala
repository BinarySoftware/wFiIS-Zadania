object task1 {

  object URL {
    def unapply(arg: String): Option[(String, String, String, String)] = {
      val pattern =
        "((([A-Za-z]{3,9}:(?:\\/\\/)?)(?:[-;:&=\\+\\$,\\w]+@)?[A-Za-z0-9.-]+|(?:www.|[-;:&=\\+\\$,\\w]+@)[A-Za-z0-9.-]+)((?:\\/[\\+~%\\/.\\w-_]*)?\\??(?:[-\\+=&;%@.\\w_]*)#?(?:[\\w]*))?)".r

      pattern.findFirstIn(arg) match {
        case None => None
        case Some(value) =>
          val arr      = value.split("://")
          val protocol = arr.head
          if (arr.tail.isEmpty) {
            return None
          }
          val arr2  = arr.tail.head.split("/")
          val host  = arr2.head
          var path  = ""
          var query = ""
          if (arr2.tail.nonEmpty) {
            val arr3 = arr2.tail.mkString("").split("\\?")
            path = arr3.head
            if (arr3.tail.nonEmpty) {
              val arr4                     = arr3.tail.mkString("").split("&")
              var map: Map[String, String] = Map()
              arr4.foreach(e => {
                val a = e.split("=")
                map += (a.head -> a.tail.head)
              })
              query = map.toString()
            }
          }
          Some(protocol, host, path, query)
      }
    }
  }

  def urlChecker(url: String): Unit = {
    url match {
      case URL(protocol, host, path, query) =>
        println(s"protocol=$protocol, host=$host, path=$path, query=$query")
      case _ => println("Wrong URL")
    }
  }

  def main(args: Array[String]): Unit = {
    urlChecker("http://fis.agh.edu.pl/dziekanat?test=true&asdf=false")
    urlChecker("me no URL :(")
    urlChecker("http://www.onet.pl/")
  }
}
