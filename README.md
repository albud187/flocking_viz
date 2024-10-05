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

The project will render a 3D environment with objects (cubes) whose movement is governed by reynold's boids, centered around the selected cube. It will initially start with 3 cubes:

![start](https://github.com/albud187/flocking_viz/blob/main/.images/initial_run.JPG)

Additional cubes can be added / removed / selected. The selected cube can be moved, which will cause the rest of the cubes to move as well. 

The camera can also be moved / rotated:

![test](https://github.com/albud187/flocking_viz/blob/main/.images/test_run.JPG)


| Index | Key         | Description                                                                                                                                          | 
|-------|----------------|------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1     | mouse click | selects an object using ray casting and [triangle ray intersection test]([url](https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm)) |
| 2     | mouse hold/movement | rotate camera |
| 3     | mouse wheel | zoom camera in / out (move camera forwards / backwards |
| 4     | A / D | move camera left / right | 
| 5     | W / S  | move camera up / down | 
| 6     | + / -  | increase / decrease camera movement speed | 
| 7     | I / K | moves the selected cube along the z axis | 
| 8     | J / L  | moves the selected cube along the x axis | 
| 9     | N / M | moves the selected cube along the y (vertical) axis | 
| 10     | E | spawns additional cube | 
| 11    | R | removes most recently added cube | 


