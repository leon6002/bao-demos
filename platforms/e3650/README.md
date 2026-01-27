# E3650 Platform Support

This directory contains the platform-specific configurations and build rules for the **Phytium E3650** platform.

## Supported Demos

Currently, the following demos are supported for E3650:

1.  **`baremetal`**
    *   A single baremetal guest (VM0) running on 4 cores.
    *   Features basic UART output and interrupt handling.
    *   Memory Base: `0x00B00000`

2.  **`baremetal+baremetal`**
    *   Two simultaneous baremetal guests.
    *   **VM0** (Master): Runs on Cores 0-1, Memory Base `0x00B00000`.
    *   **VM1** (Slave): Runs on Cores 2-3, Memory Base `0x00C00000`.
    *   Includes inter-vm communication and staggered UART output to demonstrate multi-core isolation.

## Build Instructions

To build a demo, use the standard `make` command from the root `bao-demos` directory. You must specify `PLATFORM=e3650` and the corresponding `CROSS_COMPILE`.

### Prerequisites
*   `arm-none-eabi-` toolchain (AArch32)

### Building Single Baremetal
```bash
make PLATFORM=e3650 DEMO=baremetal CROSS_COMPILE=arm-none-eabi-
```

### Building Dual Baremetal
```bash
make PLATFORM=e3650 DEMO=baremetal+baremetal CROSS_COMPILE=arm-none-eabi-
```

## Output Artifacts

The build system automatically fetches the external PAC tool (`e3650_pac_tool`) and packages the Bao Hypervisor and Guest images into a signed PAC file.

*   **Output Location**: `wrkdir/imgs/e3650/<DEMO_NAME>/bao_pack_output/bao.pac`
*   **Intermediate Binaries**: `wrkdir/imgs/e3650/<DEMO_NAME>/*.bin`

## Flashing

Flash the downloaded bootloader($BAO_DEMOS_WRKDIR_SRC/e3650_pac_tool/bootloader/e3650_bootloader.pac) and bao.pac package into the E3650 board using Semidrive's SDFactoryTool. Access to this tool requires an active support agreement or direct contact with [Semidrive](https://www.semidrive.com/).
