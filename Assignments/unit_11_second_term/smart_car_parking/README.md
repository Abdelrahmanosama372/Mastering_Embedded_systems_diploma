# Smart Car Parking System

This project implements a **Smart Car Parking System** using the **STM32F103C6 microcontroller**. It simulates an automated parking lot with entry and exit gates, parking slots, and a system for user authentication and slot availability tracking. The project is designed and tested in **Proteus simulation software**.

## Project Overview

The Smart Car Parking System features controlled entry and exit for vehicles using UART communication, servo motors, sensors, and an admin dashboard for managing user access. The system provides alerts and notifications for both users and administrators regarding slot availability and authentication status.

### Key Features

1. **Admin Dashboard**: 
   - Upon startup, the system displays an admin dashboard where valid user IDs are entered.
   - The admin uses a dedicated LCD screen and keypad to input and manage valid IDs for both entry and exit.

2. **Entry and Exit Gates**: 
   - Each gate is operated by a servo motor, which opens or closes based on parking availability and user authentication.
   
3. **Slot Availability Check**:
   - Before allowing entry, the system checks if there are any available slots. If the parking lot is full, a notification is provided to the user, and an alert is triggered.

4. **User Authentication**:
   - Users swipe an access card, simulated by sending data via UART to the STM32 microcontroller.
   - The system verifies the card ID against the IDs set up by the admin and provides access if the ID is valid.

5. **LCD and LED Notifications**:
   - The system LCD displays feedback on access status and errors.
   - LED indicators provide visual alerts:
     - **Red LED** toggles on errors (e.g., invalid ID, full parking).
     - **Green LED** toggles on successful ID verification and gate opening.

6. **Security Alerts**:
   - Unauthorized access attempts trigger a red LED alert, as does a full parking lot.

7. **Presence Detection**:
   - A PIR sensor at each gate detects vehicle presence, ensuring the gate remains open as long as a vehicle is detected.

## System Workflow

1. **Admin Dashboard at Startup**:
   - When the system starts, it enters an "Admin Mode" where the admin can input valid user IDs using a keypad.
   - Admin data is displayed on a dedicated LCD separate from the system’s user-facing LCD.
   - After the admin configures valid IDs, the system proceeds to standard operation mode.

2. **User Card Swipe at Entrance**:
   - The user presents an access card, which is simulated by sending data via UART to the STM32.
   - The system checks for available slots:
     - If **slots are available**, it authenticates the card ID.
     - If **no slots are available**, it displays "Parking is Full" on the LCD, and the red LED alarm toggles twice.

3. **ID Verification**:
   - When slots are available, the system verifies the card ID:
     - If **ID is invalid**, the LCD displays "Wrong ID, Try Again," and the red LED toggles twice.
     - If **ID is valid**, the LCD displays "ID is Right, Entry Gate Opens," the green LED toggles twice, and the gate opens.

4. **Gate Control**:
   - The servo motor opens the entry gate when the ID is valid. The gate remains open as long as the PIR sensor detects the presence of a vehicle.
   - The exit gate operates similarly, checking for valid exit IDs and vehicle presence before closing.

## Hardware Components

- **STM32F103C6 Microcontroller**: Main control unit managing UART data, servos, LCDs, and sensors.
- **Servo Motors**: Operate the entry and exit gates.
- **UART Communication**: Simulates card reader input.
- **LCD Displays**: 
  - **Admin LCD**: Displays admin options and ID setup.
  - **System LCD**: Displays access status, errors, and slot availability to users.
- **Keypad**: Allows the admin to input valid IDs during startup.
- **LED Indicators**:
  - **Red LED**: Signals errors such as an invalid ID or full parking.
  - **Green LED**: Indicates successful ID verification and gate opening.
- **PIR Sensor**: Detects vehicle presence, ensuring gates remain open as long as vehicles are detected.

## Demostration video
https://github.com/user-attachments/assets/86755a37-c713-42d7-8483-a9ea31c58313
