# XO-Game Project using TM4C123GH6PM Microcontroller

![Gameplay](Project_Run.mp4)

This project simulates the classic XO (Tic-Tac-Toe) game using the TM4C123GH6PM microcontroller. The game supports two modes of play:
1. **Hardware Mode**: Two players use a potentiometer (slider) to navigate through the cells on a Nokia5110 screen and press buttons to place their marks (X or O).
2. **UART Mode**: Players use a computer keyboard to control the game via UART communication.

The project demonstrates the use of various peripherals and interrupts on the TM4C123GH6PM microcontroller, including UART, ADC, DAC, Timers, and GPIO.

---

## Table of Contents
1. [Hardware Components](#hardware-components)
2. [Software Components](#software-components)
3. [Project Structure](#project-structure)
4. [How It Works](#how-it-works)
5. [Setup and Usage](#setup-and-usage)

---

## Hardware Components
The following hardware components are used in this project:
- **TM4C123GH6PM Microcontroller**: The main controller for the project.
- **Nokia5110 Screen**: Used to display the game board and interface.
- **Potentiometer**: Acts as a slider for navigating cells in hardware mode.
- **LEDs and Resistors**: Used for visual feedback and status indication.
- **Buttons**: Used to place X or O on the game board.
- **Wires and Jumpers**: For connecting components.

---

## Software Components
The project utilizes the following software modules:
- **UART with Interrupts**: Used for communication between the microcontroller and the computer in UART mode. Interrupts ensure efficient data handling without blocking the main program.
- **Timers with Interrupts**: Used for timing operations, such as debouncing buttons and updating the game state. Interrupts ensure precise timing.
- **ADC with Interrupts**: Used to read the potentiometer value for cell navigation in hardware mode. Interrupts ensure real-time updates.
- **DAC with Interrupts**: Used to control LEDs for blinking effects. Interrupts ensure smooth LED transitions.
- **GPIO with Interrupts**: Used to handle button presses and LED control. Interrupts ensure responsive input handling.

---

## Project Structure
The project consists of the following files:
- **UART.h and UART.c**: Handles UART communication and interrupts.
- **ADC.h and ADC.c**: Manages ADC operations for the potentiometer.
- **DAC.h and DAC.c**: Controls the DAC for LED blinking.
- **Timer.h and Timer.c**: Manages timer operations and interrupts.
- **GPIO.h and GPIO.c**: Handles GPIO configurations and interrupts for buttons and LEDs.
- **XO Game.h and XO Game.c**: Contains all game logic and functions.
- **main.c**: The main program that initializes peripherals and runs the game.
- **Nokia5110.h and Nokia5110.c**: Manages the Nokia5110 screen display.

---

## How It Works
1. **Hardware Mode**:
   - Players rotate the potentiometer to navigate through the cells on the Nokia5110 screen.
   - Pressing a button places an X or O in the selected cell.
   - The game checks for a win or draw condition after each move.

2. **UART Mode**:
   - Players use a computer keyboard to send commands via UART.
   - The microcontroller processes the commands and updates the game state on the Nokia5110 screen.

---

## Setup and Usage
1. **Hardware Setup**:
   - Connect the Nokia5110 screen, potentiometer, buttons, and LEDs to the TM4C123GH6PM microcontroller as per the circuit diagram.
   - Ensure all connections are secure and properly wired.

2. **Software Setup**:
   - Compile the project using an IDE compatible with the TM4C123GH6PM (e.g., Keil, Code Composer Studio).
   - Flash the compiled binary to the microcontroller.

3. **Running the Game**:
   - Power on the microcontroller.
   - Select the desired mode (Hardware or UART) using the provided interface.
   - Follow the on-screen instructions to play the game.

---
