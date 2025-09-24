# Cross-Platform Graphics Project

## Dependencies
To build this project you'll need 
- [cmake](https://cmake.org/)
- c++ compiler

>[!TIP]
> ### Standard compilers
> | *Platform* | Windows | Linux | MacOs |
> | ---------- | ------- | ----- | ----- |
> | *Compiler* |  MSVC   |  GCC  | Clang |


## 1. Clone the repo
The repo contains [glfw](https://www.glfw.org/download.html) as a submodule so you have to clone this recursively
```bash
git clone --recursive https://github.com/Davidvoklol/Graphics.git
```

## 2. Config the project

For the lsp to work correctly you have to config the repo with [cmake](https://cmake.org/).
```bash
cd Graphics
cmake -B build -S .
```

## 3. Build the project

Both for linux and windows you should build with
```bash
cmake --build build
```
and the executabke will be in `build/` for linux, and in `build/Debug` for windows
