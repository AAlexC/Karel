class program {
void north(){ while(notFacingNorth) turnleft(); }
void south(){ while(notFacingSouth) turnleft(); }
void east(){ while(notFacingEast) turnleft(); }
void west(){ while(notFacingWest) turnleft(); }
void turn(x){ iterate(x){ turnleft(); }}
void go(){ if(frontIsClear) move(); }
void pickAll(){ while(nextToABeeper) pickbeeper(); }


    void InterCambiar( total ){
        if(anyBeepersInBeeperBag){
        putbeeper();
            InterCambiar( succ( total ) );
        }
        else {
            iterate( total ){
            pickbeeper();
            }
            pickAll();
            iterate( total ){
            putbeeper();
            }
           Contador( 1 );
        }
    }

    void Contador( X  ){
     east();
         while(frontIsClear && facingEast){
            if( iszero( X ) ){
            InterCambiar(0);
            }
            else {
            go();
                CuentaYCompara( 0 );
                    if(facingSouth){
                    Contador( pred( X ) );
                    }
                    else {
                    Contador( succ( X ) );
                    }
            }
        }
            if( iszero( X ) && facingEast){
            west();
            InterCambiar(0);
            }
        Verifica( 1 );


    }

    void Verifica( total ){
     west();
        while(frontIsClear && facingWest){
            CuentaYCompara2( 0 );
                if(facingSouth){
                west();
                    if(iszero( total ) ){
                    go();
                    Verifica(0);
                    }
                    else {
                    go();
                    Verifica( pred( total ) );
                    }
                }
                else {
                go();
                Verifica( succ( total ) );
                }
        }

        if( iszero( total ) ) {
        while(anyBeepersInBeeperBag) putbeeper();
        }
        turnoff();
    }

    void CuentaYCompara2( total ){
        if(anyBeepersInBeeperBag){
        putbeeper();
            CuentaYCompara2( succ( total ) );

        }
        else {
            iterate( total ){
            pickbeeper();
            }
            Comparar3( total );
        }
    }

    void Comparar3( total ){
        if(nextToABeeper && !iszero( total ) ){
        pickbeeper();
            Comparar3( pred( total ) );
            putbeeper();
        }
        else {
            if( !(notNextToABeeper && iszero( total ) ) ){
            south();
            }


        }
    }


    void CuentaYCompara( total ){
        if(anyBeepersInBeeperBag){
        putbeeper();
            CuentaYCompara( succ( total ) ) ;
        }
        else {
          iterate(total){
          pickbeeper();
          }
              Comparar( total );
        }
    }

    void Comparar( total ){
        if(nextToABeeper && !iszero( total ) ){
        pickbeeper();
            Comparar( pred( total ) );
                putbeeper();
        }
        else {
            if( !(notNextToABeeper && iszero( total ) ) ){
             south();
            }

        }
    }


    program() {
    east();
    if(frontIsBlocked){
    while(nextToABeeper) pickbeeper();
    turnoff();
    }
      Contador( 0 );
    }

}
