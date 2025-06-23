# VisualCode Photo Editor Prototype

This repository contains a minimal C++ photo editing prototype intended for use with Visual Studio Code. It demonstrates a basic catalog loader and simple brightness/contrast adjustments using OpenCV. The project is **not** a full replacement for professional tools like Photoshop or Lightroom, but it can serve as a foundation for further development.

## Features

- Scan a folder for common image files (`jpg`, `png`, `dng`, `tiff`, `bmp`).
- Apply basic brightness and contrast adjustments.
- Save processed images to the working directory.

Several advanced features requested (AI metadata insertion, generative AI, professional denoise, social media integration, etc.) are not implemented here. Stubs and TODO comments are provided where such functionality could be added.

## Building

This project uses CMake and requires OpenCV to be installed.

```bash
mkdir build
cd build
cmake ..
make
```

Run the executable by passing a path to a folder of images:

```bash
./photo_editor ../path/to/catalog
```

## Continuous Integration

The repository includes a GitHub Actions workflow that automatically
compiles the project on every push or pull request. The workflow installs
OpenCV, runs CMake configuration, and builds the executable to verify that
the code compiles successfully. You can find the configuration in
`.github/workflows/build.yml`.

## Future Work

- Implement mask adjustments and advanced AI tools.
- Add preset management and style libraries.
- Integrate with external editors and social media APIs.

