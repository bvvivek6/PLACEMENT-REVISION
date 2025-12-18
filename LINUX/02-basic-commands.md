# 02. Basic Commands

Mastering the command line starts here. These are the bread-and-butter commands you'll use daily.

## Navigation

| Command | Name                                | Description                                       | Example                                             |
| :------ | :---------------------------------- | :------------------------------------------------ | :-------------------------------------------------- |
| `pwd`   | **P**rint **W**orking **D**irectory | Shows where you currently are.                    | `pwd` -> `/home/user`                               |
| `ls`    | **L**i**s**t                        | Lists files and folders in the current directory. | `ls -la` (list all, including hidden, with details) |
| `cd`    | **C**hange **D**irectory            | Moves you to a different folder.                  | `cd /var/log`                                       |

### `cd` Shortcuts

- `cd ~` or `cd`: Go to your home directory.
- `cd ..`: Go up one level (parent directory).
- `cd -`: Go back to the previous directory you were in.

## File & Directory Operations

| Command | Name                       | Description                                   | Example                                                                    |
| :------ | :------------------------- | :-------------------------------------------- | :------------------------------------------------------------------------- |
| `mkdir` | **M**a**k**e **Dir**ectory | Creates a new folder.                         | `mkdir my_folder`                                                          |
| `touch` | Touch                      | Creates an empty file or updates timestamp.   | `touch file.txt`                                                           |
| `cp`    | **C**o**p**y               | Copies files or directories.                  | `cp file.txt backup.txt` <br> `cp -r folder1 folder2` (recursive for dirs) |
| `mv`    | **M**o**v**e               | Moves or **renames** files/directories.       | `mv old.txt new.txt` (rename) <br> `mv file.txt /tmp/` (move)              |
| `rm`    | **R**e**m**ove             | Deletes files or directories. **Be careful!** | `rm file.txt` <br> `rm -rf folder` (force recursive delete)                |

## Viewing File Content

| Command | Description                                                        | Example                                                |
| :------ | :----------------------------------------------------------------- | :----------------------------------------------------- |
| `cat`   | Prints the whole file content to the screen. Good for small files. | `cat config.txt`                                       |
| `less`  | Opens file in a viewer. Allows scrolling. Press `q` to exit.       | `less huge_log.log`                                    |
| `head`  | Shows the **first** 10 lines of a file.                            | `head -n 5 file.txt` (first 5 lines)                   |
| `tail`  | Shows the **last** 10 lines of a file. Great for logs.             | `tail -f server.log` (follow new lines as they appear) |

## Pro Tips

- **Tab Completion:** Type the first few letters of a file/command and hit `Tab`. It will auto-complete!
- **History:** Use the `Up Arrow` key to see previous commands.
- **Man Pages:** Stuck? Type `man <command>` to see the manual (e.g., `man ls`).
