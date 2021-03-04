object Task69 {
  def main(args: Array[String]): Unit = {
    val r = new SPair(1, 3); // taka klase chcemy napisac
    println("" + r.one + " " + r.two)
    val z = new SPair(T("k1"), T("k2"))
    println(z)
    <<(z)
    val k = new SPair(T("k1"), T1I(67))
    <<(k)
    val kk = new SPair(T1I(88765), T1I(67))
    <<(kk)
    val krep1 = k._1(new T1I(1))
    <<(krep1)
    val krep2 = krep1._2(new T("One"))
    <<(krep2)
  }

  class SPair[+T, +U](val one: T, val two: U) {
    def _1[T](nX: T) = {
      new SPair(nX, two)
    }

    def _2[U](nY: U) = {
      new SPair(one, nY)
    }
  }

  class T(l: String) {
    override def toString: String = "T(" + l + ")"
  }

  object T {
    def apply(l: String): T = new T(l)
  }

  class T1I(key: Int) extends T(key.toString) {
    override def toString: String = "T1I(" + key.toString + ")"
  }

  object T1I {
    def apply(key: Int): T1I = new T1I(key)
  }

  def <<(t: SPair[T, T]): Unit = {
    println("" + t.one + " " + t.two)
  }

  /* expected result

    T(k1) T(k2)

    T(k1) T1I(67)

    T1I(88765) T1I(67)

    T1I(1) T1I(67)

    T1I(1) T(One)

   */
}
