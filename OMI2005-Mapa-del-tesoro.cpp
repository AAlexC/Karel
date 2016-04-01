class program {

void north(){ while(notFacingNorth){ turnleft();  } }
void south(){ while(notFacingSouth){ turnleft();  } }
void east(){ while(notFacingEast){ turnleft();  } }
void west(){ while(notFacingWest){ turnleft();  } }

void ToBack(){
east();
while(frontIsClear && nextToABeeper){
  move();
}
}


  void pasos(n){

   if(iszero(pred(n))){
          north();
          move();
      } else {
    if(iszero(pred(pred(n)))){
          east();
          move();
        }  else {

             if(iszero(pred(pred(pred(n))))){
          south();
          move();
            }  else {
                     if(iszero(pred(pred(pred(pred(n)))))){
                          west();
                      move();



                }

            }


        }
        }

  }



   void instructions(n){

        if(nextToABeeper){
              pickbeeper();
              instructions(succ(n));


        } else {
        if(frontIsBlocked){
          pasos(n);
        }  else {
           if(frontIsClear){
              move();
               if(nextToABeeper){
                  instructions(0);
                         pasos(n);
                     }
                  }
                 }

        }


   }



program(){



      ToBack();
      west();

  instructions(0);
        north();
    turnoff();


}
}
