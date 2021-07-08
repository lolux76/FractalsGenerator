/*
* c++ Mandelbrot fractals generator
*/

#include <fstream>
#include <iostream>
#include <complex>

float width = 600;
float height = 600;
unsigned int max_iter = 34; //Maximum number of iteration to check if the sequence converges

int value (int x, int y){ //Evaluating the red component for each point

  std::complex<float> point((float)x/width-1.5, (float)y/height-0.5);
  //Dividing by the image dimensions to get values smaller by 1

  std::complex<float> z(0, 0);
  unsigned int nb_iter = 0;
  while(abs(z) < 2 && nb_iter < max_iter){
    z = z * z + point;
    nb_iter++;
  }
  if(nb_iter < 34) return (255 * nb_iter)/33;
  else return 0;
}

int main(int argc, char const *argv[]) {

  //Writing a PPM image file

  std::ofstream mandelbrot ("mandelbrot.ppm");
  if(mandelbrot.is_open()){
    mandelbrot << "P3\n" << width << " " << height << " 255\n";
    for (int i = 0; i < width; i++){
      for (int j = 0; j < height; j++){

        int val = value(i,j);
        mandelbrot << val << ' ' << 0 << ' ' << 0 << "\n";
      }
    }
    mandelbrot.close();
  }
  else std::cout << "Could not open the file" << '\n';

  //Ending
  return 0;
}
