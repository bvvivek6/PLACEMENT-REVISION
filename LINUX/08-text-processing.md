# 08. Text Processing & Redirection

The real power of Linux comes from chaining commands together.

## Pipes (`|`)

Pass the output of one command as input to another. This allows you to chain simple tools to perform complex tasks.

```bash
ls -la | grep "txt"  # List files, then find lines containing "txt"
cat file.txt | less  # Read file, then open in pager
```

- `command1 | command2`: The standard output (stdout) of `command1` becomes the standard input (stdin) of `command2`.
- In the example `ls -la | grep "txt"`, `ls` lists all files, and `grep` filters that list to show only lines with "txt".

## Redirection (`>`, `>>`)

Control where the output of a command goes (usually to a file instead of the screen).

- `>`: **Overwrite**. Creates a new file or replaces existing content.
- `>>`: **Append**. Adds content to the end of an existing file without deleting it.

```bash
echo "Hello" > file.txt   # Creates file.txt with "Hello"
echo "World" >> file.txt  # Appends "World" to file.txt
```

- `command > file`: Redirects standard output to `file`.
- `command 2> file`: Redirects standard error (error messages) to `file`.

## Grep (Global Regular Expression Print)

Search for specific text patterns within files or output.

```bash
grep "error" server.log          # Find "error" in server.log
grep -r "config" /etc/           # Recursive search in /etc/
grep -i "User" file.txt          # Case-insensitive search
```

- `grep "pattern" file`: Prints lines in `file` that match "pattern".
- `-r`: **Recursive**. Searches all files inside a directory and its subdirectories.
- `-i`: **Ignore case**. Matches "user", "USER", "User", etc.
- `-v`: **Invert match**. Shows lines that do _not_ match the pattern.

## Sed (Stream Editor)

Find and replace text in a stream or file.

```bash
sed 's/old/new/' file.txt        # Replace first "old" with "new" per line (prints to screen)
sed -i 's/old/new/g' file.txt    # Replace ALL "old" with "new" inside the file
```

- `s/find/replace/`: The substitution command.
- `g`: **Global**. Replaces all occurrences on a line, not just the first one.
- `-i`: **In-place**. Edits the file directly instead of just printing the result to the terminal.

## Awk

A powerful programming language for pattern scanning and processing, especially useful for columns of data.

```bash
# Print the first column of a file
awk '{print $1}' data.txt

# Print the user (1st col) and shell (7th col) from /etc/passwd
awk -F: '{print $1, $7}' /etc/passwd
```

- `'{print $1}'`: The action block. `$1` refers to the first field (column), `$2` to the second, etc. `$0` is the whole line.
- `-F:`: **Field Separator**. Tells awk to split lines by `:` instead of the default whitespace (spaces/tabs). Useful for CSVs or system files like `/etc/passwd`.
