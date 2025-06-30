# VisualCode Photo Editor Prototype

This repository contains a minimal C++ photo editing prototype intended for use with Visual Studio Code. It now includes a simple Qt GUI in addition to the command line functionality. The project is **not** a full replacement for professional tools like Photoshop or Lightroom, but it can serve as a foundation for further development.

## Features

- Scan a folder for common image files (`jpg`, `png`, `dng`, `tiff`, `bmp`).
- Apply basic brightness and contrast adjustments.
- Save processed images to the working directory.
- Insert simple AI metadata into processed images.

Several advanced features requested (generative AI, professional denoise, social media integration, etc.) are not implemented here. Stubs and TODO comments are provided where such functionality could be added.

## Building

This project uses CMake and requires OpenCV, Qt and Exiv2 to be installed.
On Ubuntu, install the development packages with:

```bash
sudo apt-get install libopencv-dev libexiv2-dev qtbase5-dev
```

```bash
mkdir build
cd build
cmake ..
make
```

Run the application:

```bash
./photo_editor
```

## Continuous Integration

The repository includes a GitHub Actions workflow that automatically
builds the project on every push or pull request. Jobs run on Linux,
Windows and macOS. The macOS job packages the release into a DMG file.
You can find the configuration in `.github/workflows/build.yml`.

## Future Work

- Implement mask adjustments and advanced AI tools.
- Add preset management and style libraries.
- Integrate with external editors and social media APIs.

