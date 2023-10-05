<p align="center">
    <img src="https://i.ibb.co/mhP0YdD/Frame-99.png" width="65%" style="">
</p>

# reUtils: Modern Utils Library

**reUtils**, your all-in-one utility header library designed to streamline your coding process by providing a comprehensive set of features without the hassle of multiple includes. Whether you're a seasoned developer or just starting out, reUtils has got you covered!

## Table of Content 📖
  * [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
      - CMake version >=3.15
      - Visual Studio >=2022 (Windows)
  * [Building/Compiling](#buildingcompiling)
      * On Windows, Linux and MacOS
  * [Documentation](#documentation)
      * [Strings](#strings)
      * [Math (namespace)](#math-namespace)
  * [Roadmap](#roadmap)
      * Development Milestones and Progress Updates
  * [Todos](#todos)
      * Upcoming Features and Enhancements
  * [Conventions and Guidelines](#conventions-and-guidelines)
      * Maintaining Consistency and Quality
      * Collaboration Principles

## Getting Started
reUtils is currently in its early stages, so beware that it is not meant to be used in production now. While I'm actively developing and expanding its capabilities, I encourage you to contribute to my project if you can. Please follow the already established patterns, guidelines, and conventions to make the code homogenous!

## Prerequisites
- CMake version >=3.15 [(Install latest version)](https://cmake.org/download/)
- **On windows:**
    - Visual Studio >=2022 [(Install latest version)](https://cmake.org/download/)

## Building/Compiling
### On windows
```bash
# Build the project and open visual studio
./build.bat # or you can just open it like an exe
```
### On Linux/MacOS
```bash
# Build the project
./build.sh
# Run the project
cd build && ./run.sh
```

## Documentation
Right now, the header is just starting out and therefore I haven't added a lot of features Currently. If you want to contribute you can do it for sure but I'll just make sure that the code is following the same patterns, guidelines and conventions. I'll post all of the conventions and guidelines in later commits.

### Strings
- Class Composition:
    - **Constructors**
    - **Public Getters**
    - **Public Modifiers**
    - **Operator Overloads**
    - **Externs/Overrides**
    - **Private Getters**
    - **Private Modifiers**

- Public Methods
    - **int Length()**
        - Returns the length (character count) of your string as an integer.
    - **String& pop_back()**
        - Remove the last character of the string
    - **String sub(int, int = 0)**
        - Substract a part of the string
    - **String substring(int, int = 0)**
        - See sub()
    - **String cut(int, int = 0)**
        - See sub()
    - **String& append(const char\*)**
        - Append character(s) to the end of the string
    - **String& replace(int, const char\*)**
        - Replace a part of the string with another string
    - **String& operator+=(int, const char\*)**
        - Add more characetrs to the string
    - **int operator--()**
        - see pop_back()

### Math (namespace)
- Namespace Composition:
    - **Math basic operations**
    - **List of Constants**
    - **Vectors 2D**

    #### Vectors2D (classes)
    - Class Composition:
        - **Constructors**
        - **Operator Overloads**
        - **Public Getters**

    - Public Methods
      - **todo**

## Roadmap
- As of October 2, 2023, I've almost completed the string class and started to document the codebase better.
- As of August 29, 2023, I've added more functionality to the Math's namespace and now the vector class is getting usable. Also added cmake.
- As of August 26, 2023, I've initiated our journey with the first commit, laying the foundation for the String class.

## Todos
I'm currently dedicated to making reUtils a very nice tool for developers. Here's a glimpse of what's incoming:

- [x] Basic String
- [x] Basic Math
- [ ] Advanced String: Elevate your string manipulation capabilities.
- [ ] Logging: Effortless logging for better debugging.
- [ ] File System: Simplified file operations.
- [ ] Advanced Math: Mathematical utilities for many different needs.
- [ ] Physics: Tools for physics-related calculations.
- [ ] PRNGs: Pseudorandom number generators for varied applications.
- [ ] Dates and Timer: Manage dates and times with ease.
- [ ] Networking: Simplified networking functionalities.

## Conventions and Guidelines
To maintain consistency and quality, I'll soon be sharing our conventions and guidelines. This ensures that contributions align with the reUtils philosophy and make collaboration smooth and effective.
