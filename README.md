# Automated Window Blinds

Automated Window Blinds is a project aimed at automating the opening and closing of window blinds / shades. It is based around an ESP32 Microcontroller, a geared DC motor and a few sensors.

## Working
When the Microcontroller recieves a move up command it checks the current position of the blinds by checking the values of hall effect sensors. If the blind position is at the bottom it is moved up till the hall effect sensor reads the top position and stops. Moving the blinds down also happens in a similar fashion.

The blinds are moved using a Geared DC Motor coupled with a rotating mechanism to hold the strings of the window blind.

## Modes of Operation
### 1. Manual Mode
Controlling the opening and closing the blinds by pressing momentary switches or rocker switch. 

### 2. Webserver Mode
Controlling the blind from a website hosted on the ESP32 Microcontroller. The Microcontroller recieves the commands from the webserver and moves the blinds in accordance with the command.

### 3. Timed Operation (Work in Progress)
The blinds can be set to open and close at specific time of day by connecting the Microcontroller with a Real Time Clock module.

## Diagrams
### Circuit Diagram
![Circuit Diagram of Automated Window Blinds](/diagrams/Automated%20Blinds%20v1.1_bb.png)
### Block Diagram
![Block Diagram of Automated Window Blinds](/diagrams/Block%20Diagram.jpg)
### Flowchart
![Flowchart of Automated Window Blinds](/diagrams/Flowchart.jpg)