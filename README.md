# ESP32 ePaper Demo Project

This is a demo project showcasing the integration of an ESP32 with a Waveshare 1.9-inch ePaper display using PlatformIO. The project demonstrates the basic functionality of displaying text and graphics on the ePaper display.

## Hardware Requirements

- **ESP32 Development Board**: Any ESP32 development board should work.
- **Waveshare 1.9-inch ePaper Display**: Make sure to connect it properly to the ESP32.

## Software Requirements

- **PlatformIO**: This project is set up to be built and uploaded using PlatformIO. Make sure to have it installed.

## Wiring Instructions

Connect the Waveshare 1.9-inch ePaper display to the ESP32 development board according to the manufacturer's specifications. You will need to connect power, ground, the I2C pins and the two GPIOs used for RESET and BUSY.

## Project Structure

- **src**: Contains the source code of the ESP32 ePaper demo.
  - **main.cpp**: The main application file.
- **lib**: Library dependencies, managed by PlatformIO. The `waveshare-epd-1in9` lib is found in here

## Building and Uploading

1. Open the project in PlatformIO.
2. Build the project to check for any errors.
3. Upload the code to your ESP32 development board.

## Running the Demo

After uploading the code to your ESP32, open the serial monitor to view the output. The demo should initialize the ePaper display and show random temp and humidity vaules on screen.

## Troubleshooting

If you encounter any issues, double-check your wiring, ensure that the libraries are installed correctly, and consult the documentation of both the ESP32 board and the Waveshare ePaper display.

## Contributing

Feel free to contribute to the project by creating issues or submitting pull requests. Your feedback and improvements are highly appreciated.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to Waveshare for providing the 1.9-inch ePaper display.
- This project was built using the ESP32 platform and PlatformIO.

Happy Hacking!