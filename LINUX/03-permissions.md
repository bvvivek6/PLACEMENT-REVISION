# 03. Permissions & Ownership

Linux is a multi-user system. Permissions control who can read, write, or execute a file.

## Understanding `rwx`

When you run `ls -l`, you see something like this:
`-rwxr-xr-- 1 user group 4096 Dec 3 10:00 script.sh`

Let's break down the first part: `-rwxr-xr--`

1.  **Type:** The first character. `-` means file, `d` means directory.
2.  **User (Owner):** The next 3 chars (`rwx`). The owner can Read, Write, and Execute.
3.  **Group:** The next 3 chars (`r-x`). The group can Read and Execute, but not Write.
4.  **Others:** The last 3 chars (`r--`). Everyone else can only Read.

| Symbol | Meaning       | Value (Octal) |
| :----- | :------------ | :------------ |
| `r`    | **Read**      | 4             |
| `w`    | **Write**     | 2             |
| `x`    | **Execute**   | 1             |
| `-`    | No permission | 0             |

## Changing Permissions (`chmod`)

You can change permissions using symbols or numbers (octal).

### Symbolic Mode

- `u` = user, `g` = group, `o` = others, `a` = all
- `+` = add, `-` = remove, `=` = set

```bash
chmod u+x script.sh      # Add execute permission for User
chmod g-w file.txt       # Remove write permission for Group
chmod a+r public.doc     # Add read permission for All
```

### Octal (Numeric) Mode

Sum the values: Read(4) + Write(2) + Execute(1) = 7.

- `7` = `rwx` (4+2+1)
- `6` = `rw-` (4+2)
- `5` = `r-x` (4+1)
- `4` = `r--` (4)

```bash
chmod 777 file.txt  # Everyone can do everything (Dangerous!)
chmod 755 script.sh # User: rwx, Group: r-x, Others: r-x (Common for scripts)
chmod 644 data.txt  # User: rw-, Group: r--, Others: r-- (Common for files)
```

## Changing Ownership (`chown` & `chgrp`)

- **`chown`**: Change Owner.
- **`chgrp`**: Change Group.

```bash
chown alice file.txt             # Change owner to alice
chown alice:developers file.txt  # Change owner to alice AND group to developers
chgrp developers file.txt        # Change group to developers
```

## Users & Groups Commands

- `sudo`: Run command as Superuser (Root).
- `useradd username`: Create a new user.
- `passwd username`: Set password for a user.
- `groupadd groupname`: Create a new group.
- `usermod -aG group user`: Add a user to a group.
