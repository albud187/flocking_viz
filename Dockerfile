FROM osrf/ros:humble-desktop

RUN apt update
RUN apt install nano

#install stuff
RUN apt-get update \
    && apt-get install -y \
    wget curl unzip \
    lsb-release \
    mesa-utils \
    build-essential \
    && apt-get clean

RUN apt update

RUN apt install -y g++ make freeglut3 freeglut3-dev libglew-dev libglew2.2 libmagick++-dev libassimp-dev libglfw3 libglfw3-dev libmeshoptimizer-dev libmeshoptimizer1d
RUN apt update
RUN apt-get install -y libglfw3 libglfw3-dev

ENTRYPOINT ["/bin/bash"]

# Clean up
RUN rm -rf /var/lib/apt/lists/*