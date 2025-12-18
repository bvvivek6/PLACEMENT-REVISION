# 04. Process Management

Every running program in Linux is a **Process**. Managing them is crucial for system stability.

## Viewing Processes

| Command  | Description                                                       |
| :------- | :---------------------------------------------------------------- |
| `ps`     | Snapshot of current processes.                                    |
| `ps aux` | Detailed list of **all** running processes.                       |
| `top`    | Real-time view of system resources (CPU, RAM) and processes.      |
| `htop`   | A more colorful and interactive version of `top` (needs install). |

### Understanding `ps aux` Output

- **PID:** Process ID (Unique number for each process).
- **USER:** Who started the process.
- **%CPU / %MEM:** Resource usage.
- **COMMAND:** The command that started the process.

## Killing Processes

If a program freezes, you can kill it using its PID.

```bash
kill 1234        # Terminate process with PID 1234 (Polite kill - SIGTERM)
kill -9 1234     # Force kill process 1234 (Nuclear option - SIGKILL)
killall firefox  # Kill all processes named "firefox"
```

## Background & Foreground

- **Foreground:** The process takes over your terminal. You can't type until it finishes.
- **Background:** The process runs silently behind the scenes.

### Managing Jobs

1.  **Start in Background:** Add `&` at the end.
    ```bash
    python script.py &
    ```
2.  **Pause Foreground Job:** Press `Ctrl + Z`.
3.  **Move to Background:** Type `bg`.
4.  **Bring to Foreground:** Type `fg`.

## Systemd (Services)

Most modern Linux distros use `systemd` to manage services (background processes that start at boot, like web servers).

| Command                       | Description                      |
| :---------------------------- | :------------------------------- |
| `systemctl start <service>`   | Start a service (e.g., `nginx`). |
| `systemctl stop <service>`    | Stop a service.                  |
| `systemctl restart <service>` | Restart a service.               |
| `systemctl status <service>`  | Check if it's running or failed. |
| `systemctl enable <service>`  | Enable auto-start on boot.       |
