This repo is a visualization of [reynold's boids](https://en.wikipedia.org/wiki/Boids). It is a flocking algorithm based on the swarm's cohesion, alignment and velocity. The visualization used OpenGL.


# File Structure
This repo contains the source code (c++), Dockerfile and bash scripts to build and run the container. This project is meant to be compiled and executed from the container.

```
/current_directory/flocking_viz/
├── CMakeLists.txt
├── Dockerfile
├── dockerbuild.sh
├── dockerrun.sh
├── src/
```
The `src/` directory contains the c++ source code to be compiled.

When running the container the file structure is as follows:
```
/workdir/
├── CMakeLists.txt
├── Dockerfile
├── dockerbuild.sh
├── dockerrun.sh
├── src/
```


# Setup

1 - Clone the repo and change directory into the repo:
```
git clone git@github.com:albud187/flocking_viz.git
```

```
cd flocking_viz
```

2 - Build the container:
```
sh dockerbuild.sh
```

3 - Run the container:
```
sh dockerrun.sh
```

4 - create build directory and change directory into `/workdir/build`

```
mkdir build
```

```
cd build
```

5 - initialize cmake and build the project. On the `/workdir/build` execute:

```
cmake ..
```

```
cmake --build.
```

6 - run the project:

```
./flocking_viz
```

# Usage

When the project is started ...s