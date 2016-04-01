class program {
define north(){ while(notFacingNorth) turnleft(); }
define south(){ while(notFacingSouth) turnleft(); }
define east(){ while(notFacingEast) turnleft(); }
define west(){ while(notFacingWest) turnleft(); }
define goFront(){ while(frontIsClear) move(); }
define turn(x){ iterate(x){ turnleft(); }}
define go(){ if(frontIsClear) move(); }
define BuscaBeeper(){ while(notNextToABeeper && frontIsClear) move(); }
define put(){ if(notNextToABeeper) putbeeper(); }

    define MideBase( Ancho ){
        if(frontIsClear){
        move();
            MideBase( succ( Ancho) );
        }
        else {
        turn(2);
            iterate( pred( Ancho ) ){
            put();
            go();
            }
            north();
            move();
            turn(1);
            move();
            Forma( pred( pred( Ancho ) ) );
        }
    }

        define MideBaseAux( Ancho ){
        if(frontIsClear){
        move();
            MideBaseAux( succ( Ancho) );
        }
        else {
        turn(2);
            iterate( pred( Ancho ) ){
            put();
            go();
            }
            north();
            move();
            turn(1);
            move();
            Forma( pred( pred( Ancho ) ) );
        }
    }

    define Forma( N ){
        if(!iszero( N )){
            iterate( N ){
            put();
            go();
            }
            turn(2);
            iterate( N ){
            go();
            }
            if(anyBeepersInBeeperBag){
            turn(1);
            move();
            turn(1);
            move();
            }
            else {
            SubeCima(); 
            }
            if(iszero( pred( N ) ) ){
            Forma(  pred( N ) );
            }  else {
            Forma( pred( pred( N ) ) );
            }

        }
    }

    define SubeCima(){
        south();
        goFront();
        west();
        goFront();
        north();
        while(nextToABeeper){
        north();
        move();
        turn(3);
        move();
        }
        if(notNextToABeeper){
        south();
        move();
        turn(3);
        move();
        }
        turnoff();
    }

    program(){
      east();
      iterate(25){
      go();
      }
      turn(2);
      BuscaBeeper();
          MideBase(1);
          while(anyBeepersInBeeperBag){
          south();
          goFront();
          east();
          while(nextToABeeper) move();
          put();
          turn(2);
          BuscaBeeper();
              MideBaseAux(1);
          }
    }

}
