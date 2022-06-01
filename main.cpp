#include <iostream>
#include "sculptor.h"

int main(void) {
  Sculptor write(12,30,10);

  // Corpo do plankton
  write.setColor(15/255.0, 148/255.0, 95/255.0, 0);
  write.putBox(0,10,0,19,4,8);
  write.cutBox(0,3,18,19,4,8);// Cortes esquerdo da parte de cima
  write.cutBox(0,2,17,18,4,8);
  write.cutBox(0,1,10,18,4,8);
  write.cutBox(7,10,18,19,4,8);// Cortes direito da parte de cima
  write.cutBox(8,10,17,18,4,8);
  write.cutBox(9,10,10,18,4,8);
  write.cutBox(0,3,0,3,4,8);// Cortes de baixo
  write.cutBox(0,2,3,4,4,8);
  write.cutBox(0,1,4,5,4,8);
  write.cutBox(4,6,0,2,4,8);
  write.cutBox(7,10,0,3,4,8);
  write.cutBox(8,10,3,4,4,8);
  write.cutBox(9,10,4,5,4,8);
  write.cutBox(0,1,5,10,4,5);// Corte dos braços
  write.cutBox(0,1,5,10,7,8);
  write.cutBox(9,10,5,10,4,5);
  write.cutBox(9,10,5,10,7,8);
  write.cutBox(3,7,0,3,4,5);// Corte das pernas
  write.cutBox(3,7,0,3,7,8);
  write.cutBox(3,7,18,19,4,5);// Corte do topo da cabeça
  write.cutBox(3,7,18,19,7,8);
  
  // Antena do plankton
  write.setColor(11/255.0, 51/255.0, 35/255.0, 0);
  write.putBox(3,7,19,22,5,7);
  write.cutBox(4,6,19,22,5,7);
  write.putBox(2,8,22,24,5,7);
  write.cutBox(3,7,22,24,5,7);
  write.putBox(1,9,24,26,5,7);
  write.cutBox(2,8,24,26,5,7);
  write.putBox(0,10,26,27,5,7);
  write.cutBox(1,9,26,27,5,7);

  //  Sobrancelha
  write.setColor(0.0,0.0,0.0,1.0);
  write.putVoxel(3,16,8);
  write.putVoxel(4,16,8);
  write.putVoxel(5,17,8);
  write.putVoxel(6,17,8);
  write.putVoxel(7,17,8);

  //  Olho
  write.setColor(22/255.0, 189/255.0, 100/255.0, 1);
  write.putVoxel(3,13,8);
  write.putVoxel(3,12,8);
  write.putVoxel(4,14,8);
  write.putVoxel(5,14,8);
  write.putVoxel(6,14,8);
  write.setColor(1.0,0.0,0.0,1.0);
  write.putBox(4,6,12,14,8,9);
  write.setColor(1.0,1.0,0.0,1.0);
  write.putVoxel(4,11,8);
  write.putVoxel(5,11,8);
  write.putVoxel(6,13,8);
  write.putVoxel(6,12,8);

  //  Boca
  write.setColor(1.0,1.0,1.0,1.0);
  write.putVoxel(2,9,7);
  write.putVoxel(3,8,7);
  write.putVoxel(4,8,7);
  write.putVoxel(5,8,7);
  write.putVoxel(6,8,7);
  write.putVoxel(7,9,7);
  write.setColor(129/255.0, 0/255.0, 0/255.0, 1);
  write.putVoxel(3,7,7);
  write.putVoxel(4,7,7);
  write.putVoxel(5,7,7);
  write.putVoxel(6,7,7);
  write.setColor(1.0,0.3,0.3,1.0);
  write.putVoxel(4,6,7);
  write.putVoxel(5,6,7);

  //  Deixando mais arredondado
  write.cutVoxel(1,16,7);
  write.cutVoxel(8,16,7);
  write.cutVoxel(1,16,4);
  write.cutVoxel(8,16,4);

  write.writeOFF("write.off");
}