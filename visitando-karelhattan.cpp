class program {
   define turn(x){
    iterate(x){
     turnleft();
    }
   }
   define south(){ while(!facingSouth) turnleft(); }
   define north(){ while(!facingNorth) turnleft(); }
   define west(){ while(!facingWest) turnleft(); }
   define east(){ while(!facingEast) turnleft();}
   define goFront(){ while(frontIsClear) move(); }
    define pickAll(){ while(nextToABeeper) pickbeeper();}
   define Acomodate(){
    turn(3);
    move();
    south();
    goFront();
    north();
   }


   define medir(Base){
     if(frontIsClear){
      move();
      medir(succ(Base));
     } else {
      iterate(Base){
      putbeeper();
      turn(2);
      move();
      }
      Divide(0);
     }

   }

   define Divide(Base){
     if(nextToABeeper){
      pickbeeper();
      Divide(succ(Base));
     } else {
       turn(2);
       move();
       pickAll();
      west();
      goFront();
      south();
      goFront();
      north();
      Hazlo(Base);
     }

   }

       define Hazlo(Base){
          if(!iszero(Base)){
            Izquierda(Base);  (*Hazlo*)

               Ponle();
           if(facingSouth){
           turn(3);
           } else {
           putbeeper();
           turn(1);
           }
           if(frontIsBlocked) turnoff();
             move();
             north();

          }    else {
           east();
            goFront();
            north();

          }

       }

       define Izquierda(Total){
         if(frontIsClear){
            move();
             Izquierda(Total);
              if(facingNorth){
               goFront();
               turn(2);
              }
              putbeeper();
              putbeeper();
              move();
         } else {
          Acomodate();
          Hazlo(pred(Total));

         }

       }

       define Ponle(){
        if(!facingNorth){
        if(!nextToABeeper){
           putbeeper();
           }
           putbeeper();
                      
          }
          while(frontIsClear){
         if(!nextToABeeper) putbeeper();
           move();
          }
         if(!nextToABeeper) putbeeper();

       }


 program(){
 north();
 goFront();
 east();
 goFront();
 west();
  medir(1);
   if(!nextToABeeper){
    east();
    move();
    south();
    while(frontIsClear){
     if(!nextToABeeper)  putbeeper();
     move();
    }
  if(!nextToABeeper)  putbeeper();
   }

     turnoff();
 }
}
