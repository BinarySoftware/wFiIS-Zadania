package MarkupParser

import AST._

/**
  * MarkupParser.Parser
  */
object Parser {
  private def findClosing(
    str: String,
    start: Int  = 0,
    delim: Char = '<'
  ): Int = {
    var counter = 1
    for (i <- start until str.length) {
      val current = str(i)
      counter = counter +
        (if (current == '>') 1
         else if (current == '<') -1
         else 0)
      if (counter == 0)
        return i
    }
    str.length
  }

  private def tagContent(str: String): String =
    str.substring(2, findClosing(str, 2))

  private def splitTags(str: String): List[String] =
    str.replaceAll("<(.)>", "<|$1>").split('|').toList

  private def parseElemContent(code: String): Element = {
    if (code.toCharArray.count(_ == '>') > 1) {
      val s = parseElemContent(tagContent(code))
      Composite(code.charAt(0).toString, List(s))
    } else {
      Text(code.charAt(0).toString, tagContent(code))
    }
  }

  /**
    * @param code - markup code to be parsed.
    * @return - AST
    */
  def parseToTree(code: String): Element = {
    val s = splitTags(tagContent(code))
    val s2 = s.map {
      parseElemContent
    }
    if (code.toCharArray.count(_ == '>') > 1) {
      Composite(code.charAt(0).toString, s2)
    } else {
      Text(code.charAt(0).toString, tagContent(code))
    }
  }
}
