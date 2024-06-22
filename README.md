## Project Title
Design Patterns Demonstration

## Description
This C++ project demonstrates the implementation of several design patterns including Factory Method, Facade, and State Pattern. The program creates different types of sports objects using a factory, simplifies the interaction with multiple sports classes using a facade, and manages the state transitions in a context (such as an ATM machine) using the state pattern.

## Getting Started

### Dependencies
- C++ Compiler (e.g., GCC, Clang)

### Installation
1. Ensure you have a C++ compiler installed on your system.

### Executing Program
1. Compile the `project.cpp` file using your C++ compiler:
    ```bash
    g++ -o design_patterns_demo project.cpp
    ```
2. Run the compiled executable:
    ```bash
    ./design_patterns_demo
    ```

## Contents
- `project.cpp`: C++ source file containing the implementation of the design patterns.

## Assignment Details
This project includes implementations for:
1. **Factory Method Pattern**: Used to create different types of sports objects (`CricketSport`, `BasketBallSport`, `FootballSport`, `IndividualSports`) based on the provided input.
2. **Facade Pattern**: Simplifies the interaction with multiple sports classes to print the famous leagues for all sports.
3. **State Pattern**: Manages state transitions in a context (e.g., an ATM machine) through different states (`CardInsertion` and others to be defined).

### Example Execution
- The program will create a `CricketSport` object and call its `play` method.
- The program will use the `SportsFacade` to print the famous leagues of all sports.
- The program will demonstrate the `State Pattern` by setting the context state to `CardInsertion` and performing an action.

## Authors
- Saroj Raj
- [LinkedIn Profile](https://www.linkedin.com/in/saroj-raj-22831198/)

## Version History
- 0.1
    - Initial Releas
