# Cross-Platform Graphics Project

## Clone the repo
The repo contains [glfw](https://www.glfw.org/download.html) as a submodule so you have to clone this recursively
```bash
git clone --recursive https://github.com/Davidvoklol/Graphics.git
cd Graphics
```

## Config the project

For the lsp to work correctly you have to config the repo with [cmake](https://cmake.org/).
```bash
cmake -B build -S .
```

## Build the project

Both for linux and windows you should build with
```bash
cmake --build build
```
and for windows the .exe file will be in `build/Debug` folder
