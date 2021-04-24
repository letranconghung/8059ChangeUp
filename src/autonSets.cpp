/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
  baseMove(48,.35,.02);
  waitBase(4000);
}
void skills(){

}
/** Autonomous routine for blue left spawn. */
void BHR(){

  //Goal 1 - G
  setMech(127,127,70,0);
  baseMove(8.5);
  waitBase(500);
  baseTurn(40);
  waitBase(400);//600
  setMech(0,0,70,0);
  baseMove(4.5);//5
  waitBase(500);
  setMech(0,0,127,127,350);
  delay(5);

  //Goal 2 - D
  baseMove(-19.5);//-20
  waitBase(750);//800
  baseTurn(0);
  waitBase(600);
  baseMove(-41);
  waitBase(1200);//1300
  baseTurn(90);
  waitBase(700);//800
  baseMove(7.5);//8
  waitBase(500);//800
  setMech(0,0,127,127,600);
  delay(5);

  //Goal 3 - A
  baseMove(-9.5);
  waitBase(500);//800
  baseTurn(160);//160
  waitBase(1000);
  setMech(127,127,70,0);//60
  baseMove(57);
  waitBase(1300);///1500
  baseTurn(135);//135
  waitBase(500);//800
  setMech(0,0,70,0);
  baseMove(7.5);
  waitBase(500);//1000
  setMech(0,0,127,127,600);
  delay(5);
  baseMove(-10);
  waitBase(800);
  setMech(0,0,0,0);

}

/** Autonomous routine for blue right spawn. */
void BMR(){
  //Goal 1 - G
  setMech(127,127,70,0);
  baseMove(8);
  waitBase(420); //420
  baseTurn(40); //face goal
  waitBase(400);//400
  setMech(0,0,70,0);
  baseMove(4.5); //allign
  waitBase(450);//500
  setMech(0,0,70,127,350);

  //Goal 2 - D
  baseMove(-18);//-19.5
  waitBase(680);//750
  baseTurn(0);
  waitBase(550);//600
  baseMove(-42.5);//40
  waitBase(1150);//1200
  baseTurn(90);//face goal
  waitBase(650);//700
  baseMove(5.5);//6.8
  waitBase(400);
  setMech(0,0,127,127,600);
  delay(5);

  //Goal 3 - A
  baseMove(-10.2); //-8.8
  waitBase(800);
  baseTurn(160);//face ball
  waitBase(900);//1000
  setMech(127,127,70,0);
  baseMove(59);//58
  waitBase(1300);
  baseTurn(135);//face goal
  waitBase(400);//450
  setMech(0,0,70,0);
  baseMove(6);//5
  waitBase(400);
  setMech(0,0,127,127,500);
  delay(5);
  //Goal 4
  setMech(0,0,0,0);
  baseMove(-28.5);//-26
  waitBase(1000);//800
  baseTurn(267,1.60,0);//face ball - 270
  waitBase(1000);//1000
  setMech(127,127,70,0);
  // go for standalone ball
  baseMove(28.2);//29 - intake ball
  waitBase(900);//1000
  baseTurn(356,1.6,0);
  waitBase(650); //650
  baseMove(29.5);//push ball in - 29
  waitBase(1000);//1000
  setMech(0, 127, 100, 0);//60
  timerBase(-56, 125, 450);//intake ball
  delay(5);
  baseTurn(240,1.6,0);//face goal(260=270)
  waitBase(450);//600
  baseMove(5);//5
  waitBase(400);//500
  setMech(0, 0, 90, 127);//shoot
}
/* Autonomous routine for red left spawn. */
void RHR(){

  //Goal 1 - G
  setMech(127,127,40,0);
  baseMove(8.5);
  waitBase(500);
  baseTurn(40);
  waitBase(600);
  baseMove(5);
  waitBase(500);
  setMech(0,0,127,127,450);
  delay(10);

  //Goal 2 - D
  baseMove(-22);
  waitBase(800);//800
  baseTurn(0);
  waitBase(600);
  baseMove(-41);
  waitBase(1500);///2000
  baseTurn(90);
  waitBase(800);//1000
  baseMove(8);
  waitBase(500);//800
  setMech(0,0,127,127,650);
  delay(20);

  //Goal 3 - A
  baseMove(-10);
  waitBase(700);//800
  baseTurn(160);
  waitBase(1000);
  setMech(127,127,60,0);
  baseMove(55);
  waitBase(1500);///2000
  baseTurn(135);
  waitBase(800);//1000
  baseMove(8);
  waitBase(500);//1000
  setMech(0,0,127,127,550);
  delay(20);
  baseMove(-10);
  waitBase(800);
  setMech(0,0,0,0);

}
/* Autonomous routine for red right spawn. */
void RMR(){
    //Goal 1 - G
    setMech(127,127,70,0);
    baseMove(8);
    waitBase(420); //420
    baseTurn(40); //face goal
    waitBase(400);//400
    setMech(0,0,70,0);
    baseMove(4.5); //allign
    waitBase(500);//500
    setMech(0,0,70,127,350);

    //Goal 2 - D
    baseMove(-19.5);//-19.5
    waitBase(750);//750
    baseTurn(0);
    waitBase(600);//600
    baseMove(-39);//38
    waitBase(1100);//1200
    baseTurn(90);//face goal
    waitBase(800);//700
    baseMove(5.5);//6.8
    waitBase(600);//750 x
    setMech(0,0,127,127,600);
    delay(5);

    //Goal 3 - A
    baseMove(-8); //-10
    waitBase(650);//700
    baseTurn(163);//face ball 161
    waitBase(900);//1000
    setMech(127,127,70,0);
    baseMove(60);//61
    waitBase(1300);//1300
    baseTurn(135);//face goal
    waitBase(400);//450
    setMech(0,0,70,0);
    baseMove(6);//5
    waitBase(400);
    setMech(0,0,127,127,500);
    delay(5);
    //Goal 4
    setMech(0,0,0,0);
    baseMove(-26);//-28.5
    waitBase(800);//800
    baseTurn(267,1.60,0);//face ball - 270
    waitBase(750);//1000
    setMech(127,127,70,0);
    // go for standalone ball
    baseMove(27.5);//28.7 - intake ball
    waitBase(900);//1000
    baseTurn(356,1.6,0);
    waitBase(650); //650
    setMech(0, 0, 127, 0);//70
    baseMove(28.5);//push ball in - 29
    waitBase(1000);//1000
    baseMove(-2,2.0,0);
    waitBase(400);//400
    baseTurn(313,2.0,0);
    waitBase(400);//500
    baseMove(7);//5
    waitBase(600);
    setMech(0, 0, 127, 127,500);
    baseMove(-5);
    waitBase(200);
}
