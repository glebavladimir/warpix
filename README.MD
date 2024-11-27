Here’s a README.md file for your project:

# Warpix

**Warpix** is a C++ program designed to align and overlay two images using **homography** and **perspective transformation** with the help of the OpenCV library. It is ideal for visualizing differences between images, such as historical comparisons, photo restoration, etc.

---

## Requirements

- **C++ Compiler** (e.g., g++ or clang++)
- **OpenCV Library** (4.x or higher)
- **yaml-cpp Library** (for YAML configuration parsing)
- macOS, Linux, or Windows with OpenCV installed

---

## Installation

### Step 1: Install OpenCV
- On **macOS** (via Homebrew):
```bash
  brew install opencv yaml-cpp
```

- On Linux (via APT):
```bash
  sudo apt-get install libopencv-dev libyaml-cpp-dev
```

- On Windows:
  - Download and install OpenCV from opencv.org.
  - Install the yaml-cpp library manually or through vcpkg.


### Step 2: Clone the Repository
```bash
  git clone https://github.com/glebavladimir/warpix.git
  cd warpix
```

### Step 3: Compile the Program
#### G++
```bash
  g++ warpix.cpp -o warpix `pkg-config --cflags --libs opencv4`
```
#### CMake
```bash
  mkdir build
  cd build
  cmake ..
  make
```

---

## Usage

```yaml
base_image_points:
  - [x, y]
  - ...
target_image_points:
  - [x, y]
  - ...
```

1. Specify at least 4 pairs of coordinates that correspond between the two images.
2. Save the points as yaml file.
3. Run the program:
```bash
  ./warpix --base path/to/city_old.png --target path/to/city_new.png --output path/to/city_new_aligned.png --points path/to/points.yaml
```

---

## Future Enhancements

- Automate point selection using feature detection techniques (e.g., SIFT, ORB).
- Provide a graphical interface for interactive point selection.
- Add support for visualizing before-and-after comparisons with sliders.

---

## License

This project inherits OpenCV library Apache-2.0 Licence.

---

## Acknowledgments

This project uses the OpenCV library for image processing.
