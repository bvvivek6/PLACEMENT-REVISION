# 06. Package Management

Installing software in Linux is done via Package Managers, not by downloading `.exe` files from websites.

## Debian/Ubuntu (`apt`)

Used by Ubuntu, Debian, Kali Linux, Linux Mint.

| Action               | Command                            |
| :------------------- | :--------------------------------- |
| **Update Repo List** | `sudo apt update` (Do this first!) |
| **Upgrade Packages** | `sudo apt upgrade`                 |
| **Install Package**  | `sudo apt install <package_name>`  |
| **Remove Package**   | `sudo apt remove <package_name>`   |
| **Search Package**   | `apt search <keyword>`             |

**Example:**

```bash
sudo apt update
sudo apt install git
```

## RHEL/CentOS/Fedora (`yum` / `dnf`)

Used by Red Hat, CentOS, Fedora, Amazon Linux. `dnf` is the newer version of `yum`.

| Action              | Command                           |
| :------------------ | :-------------------------------- |
| **Update System**   | `sudo dnf update`                 |
| **Install Package** | `sudo dnf install <package_name>` |
| **Remove Package**  | `sudo dnf remove <package_name>`  |

**Example:**

```bash
sudo dnf install httpd
```

## Other Package Managers

- **`pacman`**: Used by Arch Linux.
- **`zypper`**: Used by OpenSUSE.
- **`snap`**: Universal package manager (works on most distros).
