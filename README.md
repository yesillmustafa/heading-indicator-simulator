# Heading Indicator Simulator (Modern OpenGL)

This project is a heading indicator simulator developed using Modern OpenGL. The heading indicator, also known as a directional gyro or gyrocompass, is a flight instrument used to display the aircraft's heading, which is the direction the aircraft is pointing with respect to magnetic north. Unlike a magnetic compass, the heading indicator is driven by a gyro mechanism and is not affected by magnetic deviations or external magnetic fields.

The heading indicator provides pilots with a reliable reference for maintaining the aircraft's desired heading during flight. It is a crucial tool for navigation, helping pilots to stay on course and make accurate turns. The instrument's stability and accuracy make it an essential component in modern aviation, enabling safe and precise heading control even in challenging weather conditions or areas with magnetic interference.

https://github.com/yesillmustafa/heading-indicator-simulator/assets/74787246/5a40942a-c722-49c3-aaf9-a6351159e6c4

https://github.com/yesillmustafa/heading-indicator-simulator/assets/74787246/2006b897-7d29-462d-bb71-150de5ce6177

## Libraries
The simulator uses the following libraries for OpenGL interactions and rendering.
- [GLAD](https://glad.dav1d.de/) (included in the project)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [stb image](https://github.com/nothings/stb) (included in the project)

## Features

- Realistic Heading Indicator Display
- User Interaction
- Customizable Appearance

  
## Prerequisites

Before you begin, ensure you have met the following requirements:

- [CMake](https://cmake.org/)
- OpenGL 3.3 or later
- [GLFW 3.3](https://www.glfw.org/)
- [glm](https://github.com/g-truc/glm) (OpenGL Mathematics)

## Installation and Usage

To get started, follow these steps:
1. Clone the repository:
```bash
git clone https://github.com/yesillmustafa/heading-indicator-simulator.git
```
2. Navigate to the repository folder:
```bash
cd heading-indicator-simulator
```
3. Create a build directory:
```bash
mkdir build
cd build
```
4. Generate build files using CMake:
```bash
cmake ..
```
5. Build the project:
```bash
cmake --build .
```
6. Run the simulator:
```bash
./HeadingIndicator
```
7. Change the direction with 'Left Arrow' and 'Right Arrow' keys


## FAQ

#### What is GLAD?

GLAD is a multi-language GL loader-generator aimed at making OpenGL initialization easier and more consistent across different platforms and graphics drivers.

#### What is GLFW?

GLFW is an open-source, multi-platform library for creating windows with OpenGL contexts and managing input, providing a foundation for building interactive graphical applications.

#### What is GLM?

GLM is a header-only C++ mathematics library designed for use in graphics programming and simulations, providing functions and classes for vector, matrix, and geometry operations.

#### What is stb_image?
stb_image is a single-header C library that provides a simple and fast way to perform image loading operations.

#### What is CMake?
CMake is a tool used for managing software projects; it simplifies the processes of compilation, configuration, and distribution of projects, enabling the creation of seamlessly functional projects on different platforms and compilers.
