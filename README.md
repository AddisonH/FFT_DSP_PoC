# FFT_DSP_PoC

## Overview

The FFT_DSP_PoC project is a proof-of-concept (PoC) designed to showcase the usage of the ARM CMSIS DSP library and demonstrate the performance benefits of Helium (SIMD) instructions on the RA8 (Cortex-M85) microcontroller. This project demonstrates FFT and FIR filtering techniques to highlight the efficiency and capabilities of the ARM CMSIS DSP library and RA8D1 MCU.

## Features

- Demonstration of FFT using the ARM CMSIS DSP library.
- Demonstration of FIR filtering using the ARM CMSIS DSP library.
- Performance comparison of DSP operations with and without Helium (SIMD) instructions.
- Real-time data acquisition using ADC.
- Visualization of FFT results and filtered signals.

## Prerequisites

- Renesas e2 studio
- FSP Version 5.3
- Renesas RA8D1 (Cortex-M85) development board

## Getting Started

### Cloning the Repository

```sh
git clone https://github.com/AddisonH/FFT_DSP_PoC.git
```

### Building the Project

1. Open Renesas e2 studio.
2. Import the project into the workspace.
3. Generate project content.
4. Build the project using the provided configuration.

### Disabling Helium Instructions
Helium SIMD instructions can be disabled in the build settings so that performance can be measured and compared.

1. Go to Project Properties -> C/C++ Build -> Settings -> CPU
2. Change ARM family to "Toolchain default"
3. Add "-mcpu=cortex-m85+nomve" to Other CPU options.
4. Clean and rebuild

### Running the Project

1. Connect the RA8D1 development board to your computer.
2. Flash the compiled binary to the RA8D1 development board.
3. Connect to the running board with JLINK RTT Viewer to see terminal output.

## Usage

### Signal Generation and Plotting Script

The project contains a python script for easily generating a plotting signal data. See the included PDF for script usage instructions.

### Performance Comparison

The project demonstrates the performance benefits of using Helium (SIMD) instructions on the RA8 (Cortex-M85) microcontroller. The performance of DSP operations with and without Helium instructions can be compared by analyzing the execution time and output results.

## License

This project is licensed under the Renesas Electronics Corporation License. See the LICENSE file for more details.