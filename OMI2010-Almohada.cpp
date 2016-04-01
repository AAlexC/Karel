class program {


  void north(){
   while(notFacingNorth){
     turnleft();
   }
  }

  void south(){
   while(notFacingSouth){
     turnleft();
   }
  }

  void east(){
   while(notFacingEast){
     turnleft();
   }
  }

  void west(){
   while(notFacingWest){
     turnleft();
   }
  }

  void go(){
   if(frontIsClear){
   move();
   }
  }

   void goFront(){
   while(frontIsClear){
   move();
   }
  }


     void veinicio(){
       west();
       goFront();
       south();
       goFront();
     }

       void pick() {
           if(nextToABeeper){
            pickbeeper();
            }

            }

          void mira(n){
          
                   veinicio();
                  iterate(n){

                    if(!anyBeepersInBeeperBag){
                       east();
                       turnoff();
                    }
                    putbeeper();

                  }
                if(anyBeepersInBeeperBag){
                  west();
                  turnoff();

                }  else {

                 north();
                 turnoff();
                }
          }


     void sumale(n){

        if(facingWest){
          north();

                if(frontIsBlocked){
                    south();
                       goFront();
                       east();

                          if(frontIsBlocked){
                             mira(n);

                                    } else {

                                      move();
                                      north();
                                    }
                         } else {

                          move(); (*El north mueve*)

                         }

                    }

                 if(nextToABeeper && facingNorth){
                    pickbeeper();
                    west();
                      sumale(n);
                      mira(n);
                 }

           if(!nextToABeeper && facingNorth){
           west();
                 sumale(succ(n));
                 mira(n);
           }

     }
     
    program() {
    veinicio();
    north();
              sumale(0);
    }
}
