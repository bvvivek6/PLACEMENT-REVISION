# Git Basics & Setup

## 1. Introduction

Git is a distributed version control system. Think of it as a "time machine" for your code. It allows you to:

- **Track changes**: See exactly what changed, who changed it, and when.
- **Revert errors**: Go back to a previous working state if you break something.
- **Collaborate**: Work with others on the same project without overwriting each other's work.

## 2. Configuration

Before you start, you need to tell Git who you are. This information is attached to every commit you make.

```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

Check your configuration:

```bash
git config --list
```

## 3. Basic Workflow Commands

### Initialization

Start a new repository or get one.

- **`git init`**: Turns the current folder into a Git repository. It creates a hidden `.git` folder where Git stores all its tracking data.

  ```bash
  mkdir my-project
  cd my-project
  git init
  ```

- **`git clone <url>`**: Downloads an existing repository from a remote server (like GitHub) to your local machine.
  ```bash
  git clone https://github.com/user/repo.git
  ```

### Staging & Committing (The Core Loop)

Understanding the "Three States" is crucial in Git.

1.  **Working Directory**: Your actual files where you edit code.
2.  **Staging Area (Index)**: A "holding area" or "shopping cart". You pick which changes you want to include in the next snapshot.
3.  **Repository (Local Repo)**: The database of all your saved snapshots (commits).

**Analogy**:

- **Working Directory**: You are writing a letter on your desk.
- **Staging Area**: You put the letter in an envelope.
- **Commit**: You seal the envelope and drop it in the mailbox.

```mermaid
graph LR
    WD[Working Directory] -- git add --> SA[Staging Area]
    SA -- git commit --> LR[Local Repo]
    LR -- git push --> RR[Remote Repo]
```

- **`git status`**: The most important command! It tells you:

  - Which files are modified but not staged.
  - Which files are staged and ready to commit.
  - Which files are untracked (new).

- **`git add <file>`**: Moves changes from the Working Directory to the Staging Area.

  ```bash
  git add index.html  # Stage a specific file
  git add .           # Stage ALL changes in the current directory
  ```

- **`git commit -m "message"`**: Saves the snapshot of the Staging Area to the Repository.
  - Always write a clear, descriptive message (e.g., "Fix login bug" instead of "Update").
  ```bash
  git commit -m "Initial commit"
  ```

### Synchronization

Sync with remote repositories (like GitHub).

- **`git remote add origin <url>`**: Connects your local repo to a remote server. `origin` is just the default nickname for the remote URL.
- **`git push -u origin <branch>`**: Uploads your commits to the remote server. `-u` links your local branch to the remote one for future easy pushing.
- **`git pull`**: Downloads changes from the remote and **immediately merges** them into your local branch. (Equivalent to `git fetch` + `git merge`).
- **`git fetch`**: Downloads changes but **does not merge** them. It lets you see what others have done without affecting your files yet.

## 4. Inspecting History

- **`git log`**: Lists all commits in reverse chronological order.
- **`git log --oneline --graph --all`**: A powerful command to see a visual tree of your commit history and branches.

## 5. Ignoring Files (.gitignore)

You often have files you _don't_ want Git to track (e.g., build artifacts, passwords, `node_modules`).
Create a file named `.gitignore` and list patterns to ignore:

```text
# .gitignore example
node_modules/
*.log
.env
```
