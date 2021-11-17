# Image To Co-occurrence Probability
These codes are written in C++ and have been verified to work with OpenCV 3.4.3.

Calculates the probability of co-occurrence from gray-scale images.
The obtained co-occurrence probability can be plotted as a 2D image or a 3D histogram.

## Demo
### Clone
~~~
$ git clone https://github.com/sakusakueva/ImageToCo-occurrenceProbability.git
$ cd ImageToCo-occurrenceProbability
~~~
### Compile
~~~
$ make
~~~
### Run
Please enter the following command to run the sample program.
~~~
$ ./Co-P -i <input image path>
~~~

If you want to try it out right now, try the following command.
~~~
$ ./Co-P -i MandrillGray.bmp
~~~


## Requirement
* c++17
* OpenCV 3.4.3
* Python 3.8.10
* matplotlib 3.4.2

## Note
I have only tested in the following environment:
* Ubuntu 20.04
* c++17
* OpenCV 3.4.3
* Python 3.8.10
* matplotlib 3.4.2
 
# Usage
 
Please create python code named "demo.py".
And copy &amp; paste [Day4 tutorial code](https://cpp-learning.com/pyxel_physical_sim4/).
 
Run "demo.py"
 
```bash
python demo.py
```
 

 
## Author
* Sakura Eba
* Chukyo University, Japan.
* Lab : http://asmi.sist.chukyo-u.ac.jp/m1/eba/
 
## License
"ImageToCo-occurrenceProbability" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).

