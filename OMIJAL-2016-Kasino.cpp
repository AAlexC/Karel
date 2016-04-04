class program {
define go(){ if(frontIsClear) move(); }
void turn(x){  iterate(x){ turnleft(); }}
void north(){ while(notFacingNorth) turnleft(); }
void south(){ while(notFacingSouth) turnleft(); }
void east(){ while(notFacingEast) turnleft(); }
void west(){ while(notFacingWest) turnleft(); }
void goFront(){ while(frontIsClear) move(); }

    void Ir_21(){
        west();
        goFront();
        north();
        move();
        south();
    }

    void Comparar2( total ){
        if(nextToABeeper && !iszero( total ) ){
        pickbeeper();
            Comparar2( pred( total ) );
        }        
        else {
            if(nextToABeeper && iszero( total )){
            south();
            turnoff();
            }
            if(!iszero( total ) && notNextToABeeper){
            north();
            turnoff();
            }
            if(notNextToABeeper && iszero( total )){
            east();
            turnoff();
            }
        }
    }

    void Comparar( Total ){
        if(nextToABeeper){
           pickbeeper();
               Comparar( succ( Total ) );
        }
        else {
        if(frontIsClear) move();
            Comparar2( Total );
        }
    }

    void ChecaCartas( t ){
        while(frontIsClear){
        move();
            if(nextToABeeper){
            ChecaCartas( succ( t ) );
            }
        }
        if( iszero( pred( t ) ) && frontIsBlocked){
        Ir_21();
        turn(1);
        while(notNextToABeeper) move();
        south();
        Comparar(0);
        }
        else { (*Haciendo las otras Comparaciones*)
          west();
          while(notNextToABeeper) move();
          Acomodalos();
          east();
          goFront();
          north();
          move();
          west();
          while(notNextToABeeper) move();
          Acomodalos();
          south();
          goFront();
          west();
          goFront();
          east();
            DefineGanador();
        }
    }

    void DefineGanador(){
        MetePila2(0);
        Ir_21();
        east();
        MetePila2(0);
        east();
        goFront();
        south();
            if(nextToABeeper){
                move();
                if(nextToABeeper){
                Ir_21();
                Comparar(0);
                }
                else {
                Ir_21();
                move();
                south();
                turnoff();
                }
            }
            else {
               move();
               if(nextToABeeper){
               Ir_21();
               move();
               north();
               turnoff();
               }
               else {
               Ir_21();
               Comparar(0);
               }

            }
    }

    void DejaMayor( total ){
        iterate( total ){
           if(nextToABeeper) pickbeeper();
        }
        iterate( total ){
        putbeeper();
        }
    }

    void ComparaCarta( Total ){
        if(nextToABeeper && !iszero( Total ) ){
            pickbeeper();
                ComparaCarta( pred ( Total ) );
                putbeeper();
        }
        else {
            if( !(notNextToABeeper && iszero( Total )) ){
            east();
            goFront();
           if(notNextToABeeper) putbeeper();
            west();
            goFront();
            }
            east();
        }
    }

    void ObtenCarta( Total ){
       if(nextToABeeper){
       pickbeeper();
           ObtenCarta( succ( Total ) );
       }
       else {
       west();
       goFront();
           ComparaCarta( Total );
           MetePila2( Total );
               DejaMayor( Total ); (*Comparandolos para ver que onda*)
       }
    }


    void MetePila2( total ){
        while(frontIsClear && facingEast){
        move();
            if(nextToABeeper && frontIsClear){
                ObtenCarta( 0 );
            }
        }
        if(frontIsBlocked && facingEast){
        west();
        goFront();
        }
    }

    void MetePila(){
        if(nextToABeeper){
            pickbeeper();
                MetePila();
                    putbeeper();
        }
        else {
          while(notNextToABeeper && frontIsClear) move();
            Acomodalos();
            if(frontIsClear){
            move();
            } else {
            east();
            }
        }
    }

    void Acomodalos(){
        while(frontIsClear && facingWest){
            if(nextToABeeper){
            MetePila();
            }
        }
    }
    program(){
         ChecaCartas(0);
    }
}
