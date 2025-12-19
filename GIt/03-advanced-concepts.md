# Advanced Git Concepts

## 1. Stashing (The "Clean Desk" Button)

**Scenario**: You are working on a messy feature (files are modified). Suddenly, your boss asks you to fix a critical bug on `main`. You can't switch branches because Git forbids it when you have uncommitted changes.

**Solution**: `git stash` takes all your uncommitted changes and puts them in a temporary storage (a "drawer"), leaving your working directory clean.

- **`git stash`**: Save changes and clean directory.
- **`git stash list`**: See what's in the drawer.
- **`git stash pop`**: Take the changes out of the drawer and apply them back to your files (and delete the stash).
- **`git stash apply`**: Apply changes but keep a copy in the drawer.

## 2. Rebase vs. Merge

Both commands integrate changes from one branch into another, but they do it differently.

### Merge (The "True History")

- **Analogy**: Tying two ropes together with a knot.
- **Pros**: Preserves the exact history of when things happened. Non-destructive.
- **Cons**: History can become messy with lots of "Merge branch..." commits.

### Rebase (The "Clean History")

- **Analogy**: Ripping the pages of your chapter out of the book and pasting them at the _end_ of the book.
- **What it does**: It moves the entire base of your branch to the tip of the target branch.
- **Pros**: Creates a perfectly linear history. No extra merge commits.
- **Cons**: **Destructive**. It rewrites history.
- **GOLDEN RULE**: Never rebase a branch that you have pushed to a public repository (like GitHub) if others are working on it.

```bash
# Rebase feature onto main
git checkout feature
git rebase main
```

## 3. Undoing Changes (Reset vs Revert)

### Reset (The Time Machine)

Moves the `HEAD` pointer backward in time. It's like rewriting history to say the commits never happened.

- **`git reset --soft <commit>`**: "Undo commit, keep changes staged."
  - Use this if you want to fix the last commit message or add one more file to it.
- **`git reset --mixed <commit>`** (Default): "Undo commit, keep changes unstaged."
  - Use this if you want to keep your work but start the commit process over.
- **`git reset --hard <commit>`**: "Undo commit, DESTROY changes."
  - **DANGEROUS**. Use this only if you want to completely throw away your work and go back to a clean state.

### Revert (The "Safe Undo")

Creates a _new_ commit that does the exact opposite of a previous commit.

- **Analogy**: Instead of deleting an email you sent (impossible), you send a new email saying "Please ignore the previous email".
- **Use case**: Safe for public branches because it doesn't rewrite history.

```bash
git revert <commit-hash>
```

## 4. Cherry-Pick

**Scenario**: You fixed a bug on `feature-A`, but that bug also exists on `main`. You don't want to merge the whole branch yet, just that one specific fix.

- **`git cherry-pick <commit-hash>`**: Copies a specific commit from anywhere and applies it to your current branch.
