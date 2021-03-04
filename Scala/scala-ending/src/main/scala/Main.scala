import java.awt.Dimension

import scala.swing._
import akka.actor.{Actor, ActorRef, ActorSelection, ActorSystem, Props}

import scala.swing.event.{Key, KeyPressed}

case class BallPosition(x: Int, y: Int)

class Ball extends Actor {
  private val areaMessenger: ActorSelection = context.actorSelection("../Area")
  var allowMoving                           = true
  var x, y: Int                             = 0

  /** This methods changes position of "ball" on the "x" axis. Remember to disallow having x lower than 0
    * @param delta   Move delta
    */
  private def moveX(delta: Int): Unit = {
    x += delta
    if (x < 0) { x = 0 }

    areaMessenger ! BallPosition(x, y)
  }

  /** This methods changes position of "ball" on the "y" axis. Remember to disallow having x lower than 0
    * @param delta    Move delta
    */
  private def moveY(delta: Int): Unit = {
    y += delta
    if (y < 0) { y = 0 }

    areaMessenger ! BallPosition(x, y)
  }

  /** Overrides receive method from actor class. Should be pattern matching over possible messages.
    * @return
    */
  override def receive: Receive = {
    case "left"  => moveX(-1)
    case "right" => moveX(1)
    case "up"    => moveY(-1)
    case "down"  => moveY(1)
    case "toggle" => {
      x = 0
      y = 0
      areaMessenger ! BallPosition(x, y)
    }
    case s => println(s)
  }
}

class Area(val textPane: TextPane) extends Actor {

  /** Overrides receive method from actor class. Moves "ball" accordingly to message
    * @return
    */
  override def receive: Receive = {
    case b: BallPosition => textPane.text = "\n" * b.y + "\t" * b.x + "X"
    case s               => println(s);
  }
}

object Main extends SimpleSwingApplication {
  val actorSystem: ActorSystem = ActorSystem("Default")

  val textPane = new TextPane
  textPane.text        = "X"
  textPane.editable    = false
  textPane.minimumSize = new Dimension(600, 300)

  val area: ActorRef =
    actorSystem.actorOf(Props(new Area(textPane)), name = "Area")
  val ballMessenger: ActorRef =
    actorSystem.actorOf(Props(new Ball), name = "Ball")

  val leftButton = new Button(Action("a") {
    ballMessenger ! "left"
  })
  val rightButton = new Button(Action("d") {
    ballMessenger ! "right"
  })
  val upButton = new Button(Action("w") {
    ballMessenger ! "up"
  })
  val downButton = new Button(Action("s") {
    ballMessenger ! "down"
  })
  val toggleMove = new Button(Action("toggle move") {
    ballMessenger ! "toggle"
  })

  def top: MainFrame = new MainFrame {
    title = "Pimp my ball"
    contents = new BoxPanel(Orientation.Vertical) {
      focusable = true
      listenTo(keys)

      reactions += {
        case KeyPressed(_, Key.W, _, _) => ballMessenger ! "up"
        case KeyPressed(_, Key.S, _, _) => ballMessenger ! "down"
        case KeyPressed(_, Key.A, _, _) => ballMessenger ! "left"
        case KeyPressed(_, Key.D, _, _) => ballMessenger ! "right"
      }

//      this.requestFocus()

      contents += textPane
      contents += new BoxPanel(Orientation.Vertical) {
        override def size: Dimension = new Dimension(600, 100)
        contents += new BoxPanel(Orientation.Vertical) {
          contents += new BoxPanel(Orientation.Horizontal) {
            contents += Swing.VGlue
            contents += upButton
            contents += Swing.VGlue
          }
          contents += new BoxPanel(Orientation.Horizontal) {
            contents += Swing.VGlue
            contents += leftButton
            contents += downButton
            contents += rightButton
            contents += Swing.VGlue
          }
          contents += new BoxPanel(Orientation.Horizontal) {
            contents += Swing.VGlue
            contents += toggleMove
            contents += Swing.VGlue
          }
        }
      }
    }
    size = new Dimension(600, 400)

//    this.peer.addKeyListener(new KeyListener() {
//      override def keyTyped(e: KeyEvent) {
//        val c = e.getKeyChar
//        c match {
//          case 'a' => ballMessenger ! "left"
//          case 'd' => ballMessenger ! "right"
//          case 'w' => ballMessenger ! "up"
//          case 's' => ballMessenger ! "down"
//        }
//      }
//
//      override def keyPressed(e: KeyEvent): Unit = {}
//
//      override def keyReleased(e: KeyEvent): Unit = {}
//
//    })
  }

}
