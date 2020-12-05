object Task1 {
// Write class (with coveriantness in mind), which can be container for two
// items. Make sure that following code works and result is as described.

  //  Result:
  //  1 3 5
  //  k1 k2 k3
  //  k1 67 k3
  //  88765 67 78
  //  1 67 k3
  //  1 One k3
  //  1 One 3

  case class TripleContainer[+T](x: T, y: T, z: T) {
    def _1[U](nX: U) = {
      TripleContainer(nX, y, z)
    }

    def _2[U](nY: U) = {
      TripleContainer(x, nY, z)
    }

    def _3[U](nZ: U) = {
      TripleContainer(x, y, nZ)
    }

    override def toString() = {
      x.toString + " " + y.toString + " " + z.toString
    }
  }

  class SContainer(val str: String) {
    override def toString() = str
  }

  class ItoSContainer(val num: Int) extends SContainer(num.toString) {}

  def main(args: Array[String]): Unit = {
    val tc = new TripleContainer(1, 3, 5);

    println(tc)

    val sss = new TripleContainer(
      new SContainer("k1"),
      new SContainer("k2"),
      new SContainer("k3")
    )
    println(sss)
    val sis = new TripleContainer(
      new SContainer("k1"),
      new ItoSContainer(67),
      new SContainer("k3")
    )
    println(sis)
    val iii = new TripleContainer(
      new ItoSContainer(88765),
      new ItoSContainer(67),
      new ItoSContainer(78)
    )
    println(iii)
    val iis = sis._1(new ItoSContainer(1))
    println(iis)
    val iss = iis._2(new SContainer("One"))
    println(iss)
    val isi = iss._3(new ItoSContainer(3))
    println(isi)
  }

}
