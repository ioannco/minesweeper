# Mine Sweeper c++ game project

### Features
- My self-implemented UI and window management system

## Dependencies
- `CMake`
- `SFML`

## Build from source on Windows
1. Install `CMake`

2. Install [`vcpkg`](https://github.com/microsoft/vcpkg)
   ```shell
   cd C:/
   git clone https://github.com/microsoft/vcpkg
   cd vcpkg
   ./bootstrap-vcpkg.bat
   ```

3. Install dependencies via `vcpkg`:
   ```shell
   vcpkg install SFML
   ```

4. Build CMake project
   ```shell
   mkdir cmake-build && cd cmake-build
   cmake ..
   make
   ```

## Build from source on macOS via Brew
1. Install `brew`
   ```shell
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. Install dependencies via `brew`
   ```shell
   brew install cmake sfml
   ```

3. Build CMake project
   ```shell
   mkdir cmake-build && cd cmake-build
   cmake ..
   make
   ```

## ToDo
- Implement UI configure tool with layout generation
- Design UI elements
- Implement basic mine sweeper engine
- Make game fun
- Polish it out