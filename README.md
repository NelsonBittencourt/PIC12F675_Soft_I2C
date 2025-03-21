# PIC12F675_Soft_I2C

C code for implementing I2C communication on PIC12F675 microcontrollers (or similar devices without dedicated hardware)

Low-cost or older microcontrollers, such as PIC12F675, lack dedicated hardware modules for I2C communication. This poses a challenge when interfacing these devices with I2C devices, which are widely used for sensors, memory, lcds and other peripherals. 

To overcome this limitation, this project uses 'bit-banging' approach, controlling GPIO pins of the microcontroller to simulate the I2C protocol. Despite drawbacks (less efficient, slower compared to hardware implementations and consuming microcontroller memory), 'bit-banging' remains a viable solution for enabling I2C communication on microcontrollers that do not have native I2C support.

This C code, created within the MPLAB X integrated development environment, is designed to be highly portable to diverse microcontrollers, and can be used to add a supplemental I2C bus to devices that are already using their built-in I2C hardware.
