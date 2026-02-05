# CS2413 Labs (Data Structures) — GitHub Workflow & Assignments

Welcome to the **CS2413 lab repository**.  
This repository contains the starter code, lab exercises, and programming assignments for this semester.

The main goals of this repo are:
- Use a consistent workflow for all labs and code assignments
- Help you practice professional software development habits (**Git + GitHub**)
- Provide a clean structure for compiling and running **C programs**

---

## Supported Environment (Required)

To ensure everyone can compile and run the same code successfully, this course officially supports:

✅ **Ubuntu Linux** (including **WSL Ubuntu** on Windows)  
✅ **macOS** (Terminal + Xcode Command Line Tools)

❌ **Not supported** (do not use these for this course):
- Native Windows builds (PowerShell / CMD)
- MinGW / MSVC
- Code::Blocks / Dev-C++

> All grading will be done in a Linux-compatible environment.  
> If your setup is not Ubuntu/macOS, your code may fail even if it works on your machine.

---

## Required Tools

### ✅ Ubuntu / WSL Ubuntu (Windows users must use WSL)

Install required packages:
```bash
sudo apt update
sudo apt install -y build-essential git
```

Verify installation:
```bash
gcc --version
make --version
git --version
```

---

### ✅ macOS (no WSL needed)

Install Apple Command Line Tools:
```bash
xcode-select --install
```

Verify installation:
```bash
clang --version
make --version
git --version
```

Recommended editor: **VS Code**

---

## How We Use GitHub in This Course

You will use GitHub for:
- Lab sessions
- Coding assignments
- Submitting your work

### Standard workflow (used every week)

1. **Fork** this repository to your GitHub account  
2. **Clone** your fork to your computer  
3. Work in the correct lab folder  
4. Commit and push your changes to GitHub

Example:
```bash
git add .
git commit -m "lab01: complete two_sum"
git push origin main
```

---

## Repository Structure

Each lab is in its own folder (example):

```
lab00/      -> starter demo (practice Git + compile/run)
lab01/      -> first real lab 
lab02/      -> future labs...
```

Inside each lab folder, you will typically see:

```
src/        -> where you write/modify code
tests/      -> runner / verification code
Makefile    -> compile/run commands
README.md   -> lab instructions
```

---

## How To Run a Lab

Go into the lab folder first. Example:
```bash
cd lab01
```

### Compile + Run (recommended)
```bash
make run
```

### Run without self-benchmark (optional)

Some labs include a small self-benchmark for **self-comparison only**.  
To disable it:
```bash
make run_nobench
```

### Clean build files
```bash
make clean
```

Notes:
- The self-benchmark is **NOT** used for grading.
- It is only for self-comparison (e.g., after optimizing your code).

---

## Submitting Your Work

Your submission is your **latest commit pushed to GitHub**.

Before you push, always check:
```bash
git status
```

Then submit:
```bash
git add .
git commit -m "labXX: complete"
git push origin main
```
You only need to submit your GitHub repo link for any code assignment.
---
## Updating Your Repo before each session
New labs (lab02, lab03, …) will be released by adding new folders to the course repository.

Your fork will NOT update automatically.

Step 1: Sync your fork on GitHub

- Go to your forked repo on GitHub

- Click Sync fork → Update branch

Step 2: Update your local repo (your laptop)

- Open Ubuntu/macOS Terminal inside your repo folder and run:
```
git pull

```
After that, you should see the new lab folder (for example lab02/) in your local files.

## Academic Integrity

You are encouraged to:
- discuss ideas
- ask questions
- help others understand concepts

You are NOT allowed to:
- copy another student’s code
- share your code publicly
- submit code that is not your own work

If you are unsure what is allowed, ask the instructor/TA before submitting.

---

## Troubleshooting

### “gcc / make not found”

Ubuntu/WSL:
```bash
sudo apt install -y build-essential
```

macOS:
```bash
xcode-select --install
```

---

### “fatal error: xxx.h: No such file or directory”

You are likely compiling in the wrong folder or missing the correct include path.

Try:
```bash
cd labXX
make clean
make run
```

---

### “git push” authentication issues

GitHub does not allow password login for command-line pushes.  
Use one of the following:
- GitHub web login prompt, or
- Personal Access Token (PAT), or
- SSH keys

We will cover this in class if needed.

---

## FQA 

### 1) Which Ubuntu version should I install?
Recommended: **Ubuntu 22.04 LTS** (stable and widely used)

Other LTS versions are also OK (ex: 24.04 LTS), but we recommend **22.04 LTS** to reduce unexpected issues.

---

### 2) My Ubuntu (WSL) does not open the first time
If Ubuntu fails to open, you may need to enable required Windows features first:

✅ Turn on these Windows Features:
- **Windows Subsystem for Linux**
- **Virtual Machine Platform**

After enabling them, restart your computer and try opening Ubuntu again.

---

### 3) Git name has “too many arguments” error
This happens because your folder name contains a space. You folder should be "cs2413" or "cs-2413", not "cs 2413"

---

### 4) Error: config.lock failed: Operation not permitted
https://www.youtube.com/watch?v=uTw50U9sMO8

---

### Copy/Paste in WSL Ubuntu
If Ctrl+V does not work, use **Ctrl+Shift+V** or **right-click** to paste.
Recommended: run Ubuntu inside **Windows Terminal** for normal copy/paste.

Open Windows Terminal, then type: wsl

---
## Contact / Help

If you run into setup issues, come a few minutes early to lab/class or ask during office hours.

