# NuttX Patch Layout

This directory is used when `guests/nuttx/make.mk` builds NuttX from official
upstream repositories and then applies a Bao demos patch stack.

Expected layout:

```text
guests/nuttx/patches/
  nuttx/
    nuttx-12.12.0/
      0001-...
  apps/
    nuttx-12.12.0/
      0001-...
```

Current intended upstream baselines:

- `https://github.com/apache/nuttx.git` tag `nuttx-12.12.0`
- `https://github.com/apache/nuttx-apps.git` tag `nuttx-12.12.0`

If no patch files are present for a version, the upstream tree is used as-is.

Current NuttX patch export:

- `nuttx/nuttx-12.12.0/0001-armv8r-bao-guest-support.patch`
- `apps/nuttx-12.12.0/0001-add-bao-shared-memory-demo.patch`
- `apps/nuttx-12.12.0/0001-add-bao-shared-memory-demo.patch`

The current practical target is a single consolidated patch for the NuttX core
delta needed by this demo.

Verification status:

- fresh clone of official `apache/nuttx` `nuttx-12.12.0`: success
- fresh clone of official `apache/nuttx-apps` `nuttx-12.12.0`: success
- patch apply on the fresh upstream tree: success
- full `nuttx+baremetal` build: success
- hardware smoke test:
  - `help` works
  - `hello` works

Ongoing rule:

- out-of-tree E3650 integration stays under `guests/nuttx/boards/e3650` and
  `guests/nuttx/chips/e3650`
- NuttX core guest support changes stay in
  `nuttx/nuttx-12.12.0/0001-armv8r-bao-guest-support.patch`
- NuttX Apps guest demo additions stay in
  `apps/nuttx-12.12.0/0001-add-bao-shared-memory-demo.patch`
- NuttX Apps guest demo additions stay in
  `apps/nuttx-12.12.0/0001-add-bao-shared-memory-demo.patch`
