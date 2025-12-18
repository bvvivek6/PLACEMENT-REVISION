# 05. Networking

Networking is vital for DevOps and Cloud Engineers. Here's how to check connectivity and transfer data.

## IP Addresses & Interfaces

| Command          | Description                                                                   |
| :--------------- | :---------------------------------------------------------------------------- |
| `ip addr`        | Show IP addresses and network interfaces (Modern replacement for `ifconfig`). |
| `hostname -I`    | Quickly show the IP address of the host.                                      |
| `netstat -tulpn` | Show active ports and listening services.                                     |
| `ss -tulpn`      | Modern, faster version of `netstat`.                                          |

## Connectivity Tools

| Command    | Description                                             | Example                             |
| :--------- | :------------------------------------------------------ | :---------------------------------- |
| `ping`     | Check if a host is reachable.                           | `ping google.com`                   |
| `curl`     | Transfer data from/to a server. Great for testing APIs. | `curl https://api.github.com`       |
| `wget`     | Download files from the web.                            | `wget https://example.com/file.zip` |
| `nslookup` | DNS query tool. Finds IP of a domain.                   | `nslookup google.com`               |
| `dig`      | Detailed DNS lookup tool.                               | `dig google.com`                    |

## SSH (Secure Shell)

SSH allows you to securely log into remote servers.

### Basic Usage

```bash
ssh user@192.168.1.10
```

### Key-Based Authentication (Passwordless Login)

1.  **Generate Key Pair:**
    ```bash
    ssh-keygen -t rsa -b 4096
    ```
2.  **Copy Public Key to Server:**
    ```bash
    ssh-copy-id user@192.168.1.10
    ```
3.  **Login:** Now you can login without a password!

### SCP (Secure Copy)

Copy files securely between hosts over SSH.

```bash
# Local to Remote
scp file.txt user@remote:/home/user/

# Remote to Local
scp user@remote:/var/log/syslog ./local_dir/
```
