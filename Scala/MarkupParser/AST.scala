package MarkupParser

/**
  * MarkupParser.AST
  */
object AST {

  /**
    * Element
    */
  trait Element {
    def toHTML: String
    def repr:   String
  }

  /**
    * Text
    */
  class Text(tp: String, value: String) extends Element {
    override def toString: String = "Text(" + tp + "," + value + ")"

    def toHTML: String = "<" + tp + ">" + value + "</" + tp + ">"

    def repr: String = tp + ">" + value + "<"
  }

  object Text {
    def apply(tp: String, value: String): Text = new Text(tp, value)
  }

  /**
    * Composite
    */
  class Composite(tp: String, values: List[Element]) extends Element {
    override def toString: String =
      "Composite(" + tp + "," + values.map(_.toString) + ")"

    def toHTML: String =
      "<" + tp + ">" + values.map(_.toHTML).mkString("") + "</" + tp + ">"

    def repr: String =
      tp + ">" + values.map(_.repr).mkString("") + "<"
  }

  object Composite {
    def apply(tp: String, values: List[Element]): Composite =
      new Composite(tp, values)
  }

  def toHTML(AST: Element): String = AST.toHTML
}
