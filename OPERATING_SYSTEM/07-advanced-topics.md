# Module 7: Advanced Topics

## 1. Distributed Systems

- A collection of physically separate, possibly heterogeneous computer systems that are networked to provide the users with access to the various resources that the system maintains.
- **Network Operating System (NOS):** Users are aware of the multiplicity of machines.
- **Distributed Operating System (DOS):** Users view the system as a single processor (Transparency).

## 2. Virtualization

- Technology that allows you to create multiple simulated environments or dedicated resources from a single, physical hardware system.
- **Hypervisor (VMM - Virtual Machine Monitor):** Software that creates and runs virtual machines.
  - **Type 1 (Bare Metal):** Runs directly on hardware (e.g., VMware ESXi, Hyper-V).
  - **Type 2 (Hosted):** Runs on top of a host OS (e.g., VMware Workstation, VirtualBox).

## 3. Security & Protection

- **Protection:** Mechanism for controlling access of processes or users to resources defined by the OS.
- **Security:** Defense of the system against internal and external attacks.
- **CIA Triad:** Confidentiality, Integrity, Availability.
- **Authentication:** Verifying the identity of a user (Passwords, Biometrics).
- **Authorization:** Determining what an authenticated user is allowed to do (Access Matrix, ACLs).

## 4. Real-Time Operating Systems (RTOS)

- Systems that must process data as it comes in, typically without buffering delays.
- **Hard Real-Time:** Critical tasks must complete on time (e.g., Pacemaker).
- **Soft Real-Time:** Critical tasks get priority over other tasks (e.g., Multimedia).
