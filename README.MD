Here’s a README.md file for your project:

# Warpix

**Warpix** is a C++ program designed to align and overlay two images using **homography** and **perspective transformation** with the help of the OpenCV library. It is ideal for visualizing differences between images, such as historical comparisons, photo restoration, etc.

---

## Requirements

- C++ Compiler (e.g., g++ or clang++)
- OpenCV Library (4.x or higher)
- macOS, Linux, or Windows with OpenCV installed

---

## Installation

### Step 1: Install OpenCV
- On **macOS** (via Homebrew):
```bash
  brew install opencv
```

- On Linux (via APT):
```bash
  sudo apt-get install libopencv-dev
```

- On Windows:
Download and install OpenCV from opencv.org.

### Step 2: Clone the Repository
```bash
  git clone https://github.com/glebavladimir/warpix.git
  cd warpix
```

### Step 3: Compile the Program
```bash
  g++ warpix.cpp -o warpix `pkg-config --cflags --libs opencv4`
```

---

## Usage

```yaml
base_image: base_image.jpg
target_image: target_image.jpg
corresponding_points:
  base_image_points:
    - [100, 150]
    - [200, 80]
    - [250, 300]
    - [400, 250]
  target_image_points:
    - [110, 160]
    - [210, 90]
    - [260, 310]
    - [410, 260]
output_image: aligned_image.jpg
```

1. Modify path to your images (base_image.jpg and target_image.jpg) in the configuration file.
2. Modify the corresponding_points to specify at least 4 pairs of coordinates that correspond between the two images.
3. Save the configuration as configuration.json.
4. Run the program:
```bash
  ./warpix configuration.json
```

--- 
## Example Workflow

- Input images:
- Original: original.jpg
- New: new.jpg
- Define corresponding points and align them using the program.
- Output: aligned_image.jpg

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
