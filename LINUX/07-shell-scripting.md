# 07. Shell Scripting Basics

Automate boring tasks with Shell Scripts! A shell script is just a file containing a series of commands.

## The Shebang (`#!`)

Every script starts with a "Shebang". It tells the system which interpreter to use.

```bash
#!/bin/bash
echo "Hello, World!"
```

1.  Create file: `touch script.sh`
2.  Add content above.
3.  Make executable: `chmod +x script.sh`
4.  Run it: `./script.sh`

## Variables

Variables store data for later use. By default, all variables are strings.

```bash
NAME="Alice"
AGE=25
echo "Hello, $NAME. You are $AGE years old."
```

- **Assignment:** `VAR=value` (No spaces around `=`).
- **Access:** `$VAR` or `${VAR}`.
- **Command Substitution:** Store the output of a command.
  ```bash
  CURRENT_DATE=$(date)
  echo "Today is $CURRENT_DATE"
  ```

## Loops

Loops allow you to execute a block of code repeatedly.

### For Loop

Iterates over a list of items.

```bash
# Standard for loop
for i in {1..5}; do
   echo "Number: $i"
done

# C-style for loop
for ((i=0; i<5; i++)); do
   echo "Counter: $i"
done
```

### While Loop

Executes as long as the condition is **true**.

```bash
count=1
while [ $count -le 5 ]; do
    echo "Count: $count"
    ((count++))
done
```

### Until Loop

Executes as long as the condition is **false** (until it becomes true).

```bash
count=1
until [ $count -gt 5 ]; do
    echo "Count: $count"
    ((count++))
done
```

### Loop Control

- **break**: Exits the loop immediately.
- **continue**: Skips the rest of the current iteration and starts the next one.

```bash
for i in {1..10}; do
    if [ $i -eq 3 ]; then
        continue  # Skip 3
    fi
    if [ $i -eq 7 ]; then
        break     # Stop at 7
    fi
    echo "Number: $i"
done
```

## Conditionals (If/Else)

Make decisions based on conditions.

```bash
if [ -f "file.txt" ]; then
    echo "File exists."
elif [ -d "backup" ]; then
    echo "Backup directory exists."
else
    echo "Nothing found."
fi
```

### Common Comparisons

- `-eq`, `-ne`, `-gt`, `-lt`: Integer comparisons (equal, not equal, greater than, less than).
- `=`, `!=`: String comparisons.
- `-f`, `-d`: File and directory checks.

## Case Statements (Switch)

Useful when checking a variable against multiple patterns.

```bash
read -p "Enter a fruit: " FRUIT

case "$FRUIT" in
    "apple")
        echo "It's red."
        ;;
    "banana")
        echo "It's yellow."
        ;;
    *)
        echo "Unknown fruit."
        ;;
esac
```

## Functions

Group commands together.

```bash
greet() {
    echo "Hello, $1!"
}

greet "Bob"
```

## Common Exit Codes

- `0`: Success.
- `1` (or non-zero): Error.
- Check last exit code with `echo $?`.
