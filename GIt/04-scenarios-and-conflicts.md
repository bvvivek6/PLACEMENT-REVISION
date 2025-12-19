# Real-World Scenarios & Troubleshooting

## Scenario 1: Resolving Merge Conflicts

**Situation**: You and a teammate both edited the same line in the same file (e.g., `index.html`). Git doesn't know whose version is correct, so it pauses the merge and asks you to choose.

### The Conflict

When you run `git merge`, Git says:

```text
CONFLICT (content): Merge conflict in index.html
Automatic merge failed; fix conflicts and then commit the result.
```

### Visualizing the Conflict

Open `index.html` in VS Code. You will see special markers:

```html
<<<<<<< HEAD
<h1>My Title (Current Branch)</h1>
=======
<h1>Teammate's Title (Incoming Branch)</h1>
>>>>>>> feature-branch
```

- **`<<<<<<< HEAD`**: Start of your changes.
- **`=======`**: The divider between conflicting changes.
- **`>>>>>>> feature-branch`**: End of the incoming changes.

### Steps to Resolve

1.  **Decide**: Do you want your code, their code, or a combination?
2.  **Edit**: Delete the markers (`<<<<`, `====`, `>>>>`) and leave only the correct code.
    _Example Result:_
    ```html
    <h1>Our Awesome Title</h1>
    ```
3.  **Save**: Save the file.
4.  **Stage**: Tell Git you fixed it.
    ```bash
    git add index.html
    ```
5.  **Commit**: Finish the merge.
    ```bash
    git commit -m "Resolved merge conflict in index.html"
    ```

## Scenario 2: "I committed to the wrong branch!"

**Situation**: You were supposed to work on `feature-login`, but you forgot to switch and committed 3 times to `main`.

### The Fix

You need to move those commits to a new branch and reset `main`.

1.  **Create the branch** pointing to where you are now (keeping your work).
    ```bash
    git branch feature-login
    ```
2.  **Reset `main`** back 3 commits (to before you started).
    ```bash
    git reset --hard HEAD~3
    ```
    _(Warning: Make sure you created the branch in step 1, or you will lose work!)_
3.  **Switch** to your new branch.
    `bash
    git checkout feature-login
    `
    **Result**: `main` is clean, and `feature-login` has your 3 commits.

## Scenario 3: "I need to switch branches but I have work in progress"

**Situation**: You are halfway through a feature. Files are modified and broken. You can't commit. But you need to switch to `main` to fix a typo.

### The Fix (Stash)

1.  **Save your work** to the stash.
    ```bash
    git stash save "WIP: login feature"
    ```
    _Your directory is now clean (matches the last commit)._
2.  **Switch and Fix**.
    ```bash
    git checkout main
    # ... fix typo ...
    git commit -m "Fixed typo"
    ```
3.  **Return and Restore**.
    ```bash
    git checkout feature-login
    git stash pop
    ```
    _Your modified files are back!_

## Scenario 4: Detached HEAD State

**Situation**: You ran `git checkout <commit-hash>` to look at an old version.
Git warns: _You are in 'detached HEAD' state._

### What it means

HEAD (the "you are here" pointer) usually points to a **Branch Name**.
In this state, HEAD points directly to a **Commit**.
If you make new commits now, they belong to _no branch_. If you switch away, they will be lost (garbage collected).

### How to fix

If you made changes here and want to keep them:

```bash
git switch -c my-new-branch
```

This creates a branch at your current location, saving your work.

## Scenario 5: Squashing Commits (Cleaning History)

**Situation**: You made 5 tiny commits ("typo", "fix", "wip", "done", "oops"). You want to combine them into one clean commit before pushing.

### The Fix (Interactive Rebase)

1.  Start an interactive rebase for the last 5 commits.
    ```bash
    git rebase -i HEAD~5
    ```
2.  An editor opens. Change `pick` to `squash` (or `s`) for the commits you want to melt into the previous one.
    ```text
    pick a1b2c First commit
    squash d4e5f typo
    squash g7h8i fix
    ...
    ```
3.  Save and close. Git will ask you to write one new commit message for the whole group.
