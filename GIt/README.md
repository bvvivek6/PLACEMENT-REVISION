# Git & GitHub Revision Notes

This directory contains comprehensive notes on Git version control and GitHub collaboration, including basic commands, advanced concepts, and real-world troubleshooting scenarios.

## Contents

1.  **[Basics & Setup](01-basics.md)**

    - Introduction & Configuration
    - Initialization (init, clone)
    - Basic Workflow (add, commit, push, pull)
    - Inspecting History

2.  **[Branching & Merging](02-branching-merging.md)**

    - Creating and switching branches
    - Fast-forward vs. Recursive merges
    - Visualizing merge strategies

3.  **[Advanced Concepts](03-advanced-concepts.md)**

    - Stashing changes
    - Rebase vs. Merge
    - Undoing changes (Reset, Revert)
    - Cherry-picking

4.  **[Real-World Scenarios](04-scenarios-and-conflicts.md)**
    - **Scenario 1**: Resolving Merge Conflicts (Step-by-step)
    - **Scenario 2**: Committed to the wrong branch
    - **Scenario 3**: Switching branches with work in progress (Stash)
    - **Scenario 4**: Detached HEAD state
    - **Scenario 5**: Squashing Commits (Cleaning History)

## Quick Reference Cheat Sheet

| Command                  | Description                  |
| :----------------------- | :--------------------------- |
| `git init`               | Initialize a new repo        |
| `git clone <url>`        | Clone a remote repo          |
| `git status`             | Check file status            |
| `git add .`              | Stage all changes            |
| `git commit -m "msg"`    | Commit staged changes        |
| `git push`               | Upload commits to remote     |
| `git pull`               | Download & merge from remote |
| `git branch`             | List branches                |
| `git checkout -b <name>` | Create & switch branch       |
| `git merge <branch>`     | Merge branch into current    |
| `git stash`              | Save uncommitted changes     |
| `git log --oneline`      | View compact history         |
