# TDMM_talking_digital_multimeter

This project shows how to build a multimeter with the following properties:

Voltage measurement: +/- 0 ... 85 volts, up to 850 volts with a separate probe (DC)
Current measurement: +/- 0 ... 5 ampere, option for 20 ampere (DC)
Power value (U x I measured)
Resistor measurement: ~ 0 Ω to 2 MΩ

All measurements are carried out at the same time.
You may select, what the values are, that will be spoken:
- voltage
- current and power (always together)
- resistance

Default language is German, but English is implemented too (see language settings in code)

Part 1 of this code does voltage measurement and displays the result on an OLED display
At the same time, all values are sent via USB-UART (19.200 baud).

Part of the project is the input voltage divider, shown in this repository.



