/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
  setMech(127,127,70,0);
  baseMove(3);
  waitBase(300);
  timerBase(-40,127,500);
  setMech(127,127,127,100);

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
  baseMove(8);//8.5
  waitBase(450);//500
  baseTurn(40);
  waitBase(400);//600
  setMech(0,0,70,0);
  baseMove(4.5);//5
  waitBase(500);
  setMech(0,0,70,127,350);//350
  delay(5);

  //Goal 2 - D
  baseMove(-21.5);//-19.5
  waitBase(1000);//750
  baseTurn(1.5);
  waitBase(450);//450
  baseMove(-40); //41
  waitBase(1200);//1300
  baseTurn(90);
  waitBase(700);//800
  baseMove(6.8);//7 into the goal
  waitBase(500);//800
  setMech(0,0,127,127,600);
  delay(5);

  //Goal 3 - A
  baseMove(-8.8);//-10
  waitBase(400);//500
  baseTurn(159);//161
  waitBase(1000);
  setMech(127,127,70,0);//60
  baseMove(58);//57
  waitBase(1300);///1500
  baseTurn(135);//135
  waitBase(400);//450
  setMech(0,0,70,0);
  baseMove(7.5);
  waitBase(400);//500
  setMech(0,0,127,127,500);
  delay(5);
  //Goal 4
  setMech(0,0,0,0);
  baseMove(-27.5);//-28
  waitBase(800);//1200
  baseTurn(267,1.60,0);//270
  waitBase(1000);//1200
  setMech(127,127,70,0);
  // baseMove(26.5);//27
  // waitBase(1500);
  // baseTurn(356,1.60,0);//357 ***
  // waitBase(750);//800
  // baseMove(27);//25.5
  // waitBase(1000);//1000
  // setMech(0,0,50,0);
  // timerBase(-50,127,450);//-40
  // baseTurn(450);
  // waitBase(200);
  // baseMove(5);
  // waitBase(300);
  // setMech(0,0,127,127);

  baseMove(25.7);
  waitBase(1500);
  baseTurn(356,1.6,0);
  waitBase(750);
  baseMove(29);
  waitBase(1000);
  setMech(0, 0, 50, 0);
  timerBase(-30, 127, 600);
  delay(500);
  timerBase(0, 40, 300);
  setMech(0, 0, 127, 127);
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

}
