# Dual Bare Metal Guest Demo

This demo runs **two** separate bare metal guest instances simultaneously on Bao.

## Description

*   **Guest 1 (VM0)**: A bare metal application running on a subset of cores.
*   **Guest 2 (VM1)**: Another instance of the same bare metal application running on a distinct subset of cores.

Both guests operate independently, demonstrating Bao's ability to isolate and manage multiple bare metal execution environments.

## Build Instructions

1.  **Select your target platform** and run the build command.

### For e3650 Platform (Automated)

The build system for `e3650` automatically compiles two separate bare metal binaries linked to their respective memory regions defined in `make.mk`.

*   **VM0 Base**: `0x00B00000`
*   **VM1 Base**: `0x00C00000`

Simply run:
```bash
make PLATFORM=e3650 DEMO=baremetal+baremetal CROSS_COMPILE=arm-none-eabi-
```

This will generate:
- `wrkdir/imgs/baremetal_vm0.bin`
- `wrkdir/imgs/baremetal_vm1.bin`
- `wrkdir/imgs/bao.bin` (Parameters embedded)


## Running

Load the generated Bao binary to the target platform.
*   **e3650**: Ensure the guest binaries are loaded to their respective addresses in memory if not bundled. (Note: standard Bao flow might require loading `bao.bin` which setup the guests if they are incbin'd, or loading guests separately).
