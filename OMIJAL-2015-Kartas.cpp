class program {
define go(){ if(frontIsClear) move(); }
    void Gaaus( N ){
        if( !iszero( N ) ){
            iterate( N ){
            putbeeper();
            }
                Gaaus( pred( N ) );
        }
    }

    define Recoger( Pasos ){
        if(nextToABeeper){                                      
            pickbeeper();
                Recoger( Pasos );
                    pickbeeper();
        }
        else {
        move();
        CuentaPasos( succ( Pasos ) );
        }
    }

    define CuentaPasos( Pasos ){
        while(nextToABeeper && facingEast){
        Recoger( Pasos );
        }
        if(frontIsBlocked && facingEast){
            while(notFacingNorth) turnleft();
            Gaaus( Pasos );
        }
    }

    program(){
        CuentaPasos( 1 );
    }
}
