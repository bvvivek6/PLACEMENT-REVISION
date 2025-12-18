# Module 6: I/O Systems

## 1. I/O Hardware

- **Port:** Connection point for device.
- **Bus:** Shared set of wires (PCI, SCSI, USB).
- **Controller:** Electronics that operate port, bus, device.

## 2. Communication Techniques

### a. Polling (Programmed I/O)

- CPU repeatedly checks the status register of the device controller to see if it is ready.
- **Cons:** Wastes CPU cycles (Busy Waiting).

### b. Interrupt-Driven I/O

- Device controller sends an interrupt signal to the CPU when it is ready.
- CPU saves its state and executes the Interrupt Service Routine (ISR).
- **Pros:** CPU is free to do other tasks while waiting for I/O.

### c. DMA (Direct Memory Access)

- Used for high-speed I/O devices.
- Device controller transfers an entire block of data directly to/from its own buffer storage to memory, with no intervention by the CPU.
- Only one interrupt is generated per block, rather than one interrupt per byte.

## 3. Kernel I/O Subsystem

- **I/O Scheduling:** Reordering I/O requests to improve efficiency (e.g., Disk Scheduling).
- **Buffering:** Store data in memory while transferring between devices. Handles speed mismatch.
- **Caching:** Fast memory holding copy of data.
- **Spooling:** Hold output for a device (like a printer) that cannot accept interleaved data streams.
- **Error Handling:** OS must handle I/O errors (e.g., disk read failure).
