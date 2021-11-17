# Image To Co-occurrence Probability
These codes are written in C++ and have been verified to work with OpenCV 3.4.3.

Calculates [the probability of co-occurrence]() from gray-scale images.
The obtained co-occurrence probability can be plotted as a 2D image or a 3D histogram.

![hierarchy](/image/image.pdf)

## Requirement
* c++17
* OpenCV 3.4.3
* Python 3.8.10
* matplotlib 3.4.2

## Demo
### 1. Clone
~~~
$ git clone https://github.com/sakusakueva/ImageToCo-occurrenceProbability.git
$ cd ImageToCo-occurrenceProbability
~~~
### 2. Compile
When you compile with `make`, you will have a build directory and a result directory.
~~~
$ make
~~~
### 3. Run
Please enter the following command to run the sample program.
~~~
$ ./Co-P -i <input image path>
~~~

If you want to try it out right now, try the following command.
~~~
$ ./Co-P -i MandrillGray.bmp
~~~

### 4. Visualization

If you want to show the 2D histogram with 3D histogram, run the following.
~~~
$ /usr/bin/python3 scripts/hist_3d.py
~~~


## Note
I have only tested in the following environment:
* Ubuntu 20.04
* c++17
* OpenCV 3.4.3
* Python 3.8.10
* matplotlib 3.4.2
 
# Usage
The output of the CoP class is as follows:
<table>
  <tr>
    <td>Mode</td>
    <td>Argument</td>
    <td>Default</td>
  </tr>
  <tr>
    <td>Save image</td>
    <td>image</td>
    <td>true</td>
  </tr>
  <tr>
    <td>1D text file</td>
    <td>text</td>
    <td>true</td>
  </tr>
  <tr>
    <td>Show image</td>
    <td>window</td>
    <td>true</td>
  </tr>
</table>

## Author
* Sakura Eba
* Chukyo University, Japan.
* Lab URL: http://asmi.sist.chukyo-u.ac.jp/m1/eba/
 
## License
"ImageToCo-occurrenceProbability" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).

