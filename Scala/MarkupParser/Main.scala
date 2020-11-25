package MarkupParser

import AST._
import Parser._

object Main {

  /**
    * The goal is to write a simple markup language parser using extractors.
    * Specifically, the parseToTree function that converts the string like
    * in an example has to be written.
    */
  def main(args: Array[String]): Unit = {
    println("============")
    println(parseToTree("t>1234<")) // Text(t,1234)
    println("============")
    println(parseToTree("b>abcd<")) // Text(b,abcd)
    println("============")
    println(
      parseToTree("p>b>test1<b>test2<<")
    ) // Composite(p,List(Text(b,test1), Text(b,test2)))
    println("============")

    //a real  example

    val input =
      """p>

        p>

         h>Header<

        <

        p> t>Par 1<

         h>Par title<

         b>bold<

         i>italic<

        <

        p>t>simple par with more text<<

       <

    """.stripMargin
        .replaceAll("[\n]", "")
        .replaceAll("< +(.)>", "<$1>")
        .replaceAll("p> +", "p>")
        .replaceAll("< +<", "<<")

    //   ^ above is a simple normalisation to gte rid of extra spaces

    println("=== Input ===")
    println(input)

    val parsed = parseToTree(input)

    println("=== Parsed ===")
    println(parsed)

    val AST = Composite(
      "p",
      List(
        Composite("p", List(Text("h", "Header"))),
        Composite("p", List(Text("t", "Par 1"))),
        Text("h", "Par title"),
        Text("b", "bold"),
        Text("i", "italic"),
        Composite("p", List(Text("t", "simple par with more text")))
      )
    )

    println("=== Expected MarkupParser.AST ===")
    println(AST)

    assert(parsed.toString == AST.toString)

    println("=== Repr ===")
    println(AST.repr)

    println("=== HTML ===")
    println(toHTML(AST))

    val htmlRes =
      "<p><p><h>Header</h></p><p><t>Par 1</t></p><h>Par title</h><b>bold</b><i>italic</i><p><t>simple par with more text</t></p></p>"

    assert(toHTML(AST) == htmlRes)
  }
}
