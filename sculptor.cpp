#include <iostream>
#include <fstream>
#include <iomanip>
#include "sculptor.h"
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz){

  r = g = b = a = 0.0;
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel**[nx];
  for (int i=0; i<nx; i++){
    v[i] = new Voxel*[ny];
    for (int j=0; j<ny; j++){
      v[i][j] = new Voxel[nz];
    }
  }
}

Sculptor::~Sculptor(){
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      delete [] v[i][j];
    }
    delete [] v[i];
  }
  delete [] v;
}

void Sculptor::setColor(float r_, float g_, float b_, float alpha){
  r = r_;
  g = g_;
  b = b_;
  a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
  // Checando se voxel existe na matriz para pinta-lo
  if(x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
  }
}

void Sculptor::cutVoxel(int x, int y, int z){
  v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for (int i=x0; i<x1; i++){
    for (int j=y0; j<y1; j++){
      for (int k=z0; k<z1; k++){
        putVoxel(i,j,k);
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for (int i=x0; i<x1; i++){
    for (int j=y0; j<y1; j++){
      for (int k=z0; k<z1; k++){
        cutVoxel(i,j,k);
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
   for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if (((pow((i-xcenter),2)/(pow(radius,2))) + (pow((j-ycenter),2)/(pow(radius,2))) + (pow((k-zcenter),2)/(pow(radius,2))))<=1){
          putVoxel(i,j,k);
       }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if (((pow((i-xcenter),2)/(pow(radius,2))) + (pow((j-ycenter),2)/(pow(radius,2))) + (pow((k-zcenter),2)/(pow(radius,2))))<=1){
          cutVoxel(i,j,k);
       }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if (((pow((i-xcenter),2)/(pow(rx,2))) + (pow((j-ycenter),2)/(pow(ry,2))) + (pow((k-zcenter),2)/(pow(rz,2))))<=1){
          putVoxel(i,j,k);
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if (((pow((i-xcenter),2)/(pow(rx,2))) + (pow((j-ycenter),2)/(pow(ry,2))) + (pow((k-zcenter),2)/(pow(rz,2))))<=1){
          cutVoxel(i,j,k);
        }
      }
    }
  }
}

/**
* O método consiste em cada coordenada recebida (x,y,z) que  tiver sua propriedade isOn = true, o método de gravação do formato OFF deverá prever o desenho de um cubo com lado de comprimento igual a 1 com as mesmas propriedades de cor e transparência do voxel cujo centro coincide com o centro desse voxel. Criando assim um arquivo de computador escrito no formato OFF onde para um matriz com Nvoxels voxels com propriedade isOn=true, exista um total de '8*Nvoxels vértices' e '6*Nvoxels faces' para representar escultura digital equivalente às propriedades da matriz.
*/


void Sculptor::writeOFF(const char* filename){
  int qtdd_de_voxels_para_impressao = 0;
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      for (int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          qtdd_de_voxels_para_impressao++;
        }
      }
    }
  }
  std::ofstream arquivo_off;
  arquivo_off.open(filename);

  // Abrindo o arquivo:
  if (!arquivo_off.is_open()){
    std::cout << "Erro ao abrir arquivo :c" << std::endl;
  }
  arquivo_off<<"OFF"<< std::endl;
  arquivo_off<< (qtdd_de_voxels_para_impressao*8) << " " 
    << (qtdd_de_voxels_para_impressao*6) << " "
    << 0 << " " << std::endl;
  
  // Definindo as coordenadas dos vértices
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      for (int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          arquivo_off << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
            << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
            << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
            << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
            << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n"
            << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
            << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
            << i+0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
        }
      }
    }
  }

  // Definindo as faces:
  // Face 1: P0 P3 P2 P1
  // Face 2: P4 P5 P6 P7
  // Face 3: P0 P1 P5 P4
  // Face 4: P0 P4 P7 P3
  // Face 5: P7 P6 P2 P3
  // Face 6: P1 P2 P6 P5

  int contador_de_face = 0;
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      for (int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          arquivo_off 
            << "4" << " " << contador_de_face + 0 << " " << contador_de_face + 3 << " " << contador_de_face + 2 << " " << contador_de_face + 1 << " " << std::fixed << std::setprecision(1) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<"\n"
            << "4" << " " << contador_de_face + 4 << " " << contador_de_face + 5 << " " << contador_de_face + 6 << " " << contador_de_face + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
            << "4" << " " << contador_de_face + 0 << " " << contador_de_face + 1 << " " << contador_de_face + 5 << " " << contador_de_face + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
            << "4" << " " << contador_de_face + 0 << " " << contador_de_face + 4 << " " << contador_de_face + 7 << " " << contador_de_face + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
            << "4" << " " << contador_de_face + 7 << " " << contador_de_face + 6 << " " << contador_de_face + 2 << " " << contador_de_face + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
            << "4" << " " << contador_de_face + 1 << " " << contador_de_face + 2 << " " << contador_de_face + 6 << " " << contador_de_face + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a
            << std::endl;
  
          contador_de_face = contador_de_face + 8;
        }
      }
    }
  }

  arquivo_off.close();
}