# Cross-Platform Graphics Project

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
and for windows the .exe file will be in `build/Debug` folder
