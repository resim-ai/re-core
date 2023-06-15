
# ReSim View Demo Scripts

This package contains some C++ programs for demonstration purposes that link to
a ReSim View shared object file and allow users to visualize transforms and
other 3D content in their web browser. This package is designed for
demonstration purposes only and has the following dependencies:
 - Eigen 3.4.0+
 - libuuid
 - cmake
 
On ubuntu, one can obtain these like so:
 
```
apt install libeigen3-dev uuid-dev cmake
```

Then, after unpacking this package and navigating to its root directory, one
can build the examples using:

```
mkdir build
cd build
cmake ..
make
```

Then one can run the first example like so:

```
./example_00_rigid_transform 
```
