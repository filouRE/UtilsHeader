<p align="center">
    <img src="https://i.ibb.co/gFfJ7YN/Frame-74.png" width="65%" style="">
</p>

# reUtils: Modern Utils Library

**reUtils**, your all-in-one utility header library designed to streamline your coding process by providing a comprehensive set of features without the hassle of multiple includes. Whether you're a seasoned developer or just starting out, reUtils has got you covered!

## Table of Content
- [**reUtils: Modern Utils Library**](#reutils--modern-utils-library)
  * [Getting Started](#getting-started)
  * [Documentation](#documentation)
    + [Strings](#strings)
  * [Roadmap](#roadmap)
  * [Todo List](#todo-list)
  * [Conventions and Guidelines](#conventions-and-guidelines)

## Getting Started
reUtils is currently in its early stages, so beware that it is not meant to be used in production now. While I'm actively developing and expanding its capabilities, I encourage you to contribute to my project if you can. Please follow the already established patterns, guidelines, and conventions to make the code homogenous!

## Prerequisites
- cmake version >=3.0

## Building/Compiling 🛠️
```bash
# Initialize the project
cmake .
# Compile the project
cmake --build .
```

## Documentation
Right now, the header is just starting out and therefore I haven't added a lot of features Currently. If you want to contribute you can do it for sure but I'll just make sure that the code is following the same patterns, guidelines and conventions. I'll post all of the conventions and guidelines in later commits.

### Strings
- Class Composition:
    - **Instantiation**
    - **Moving**
    - **ostream overload**

- Public Methods
    - **int Length()**
        - Returns the length (character count) of your string as an integer.

## Roadmap
- As of August 29, 2023, I've added more functionality to the Math's namespace and now the vector class is getting usable. Also added cmake.
- As of August 26, 2023, I've initiated our journey with the first commit, laying the foundation for the String class.

## Todo List
I'm currently dedicated to making reUtils a very nice tool for developers. Here's a glimpse of what's incoming:

- [x] Basic String
- [ ] Basic Math
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
