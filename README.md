# Stochastic Poetic Generator

A C++ program that generates evocative, dream-like text inspired by mathematical concepts, stochastic processes, and the poetry of Samuel Taylor Coleridge.

## Overview

This program creates surreal, poetic descriptions by merging mathematical concepts with literary aesthetics. It combines:

- **Randomization techniques** to ensure unique outputs each run
- **Markov chains** to create coherent transitions between concepts
- **Linear algebra** (via Eigen) to extract eigenvectors for structuring the narrative flow
- **Stochastic processes** like Poisson distributions to simulate the random appearance of visions

## Installation

### Prerequisites
- C++ compiler supporting C++11 or later
- [Eigen](https://eigen.tuxfamily.org) library for linear algebra operations

### Building the Project
```bash
# Clone the repository
git clone https://github.com/tpellissari/stochastic-poet.git
cd stochastic-poet

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
make
```

## Usage

Simply run the compiled executable:

```bash
./stochastic_poet
```

Each execution generates a unique sequence of poetically described mathematical concepts.

## Example Outputs

```
Coleridge's opium-drenched visions populate my daydreams like a chaotic dance, where patterns briefly emerge

Coleridge's opium-drenched visions populate my daydreams like eigenvectors of a shimmering covariance matrix, principal components whispering forgotten stanzas from the stochastic depths of Xanadu. The dominant eigenvector, (0.57, -0.33, 0.75), guides the dream's trajectory.

Coleridge's opium-drenched visions populate my daydreams following a Poisson process, λ=2.37 visions per hour, each a fleeting glimpse into the sublime and terrifying.

Coleridge's visions transition from a state of 'fractal' to singularities, points of infinite density where reality itself fractures
```

## Technical Architecture

### 1. Random Number Generation
The `randomDouble` function creates floating-point numbers within specified ranges, powering the stochastic aspects of the program.

### 2. Concept Description Generator
The `describeConcept` function takes mathematical concepts and transforms them into poetic phrases, varying based on random inputs.

### 3. Markov Chain Implementation
A probabilistic model guides transitions between concepts, creating a structured yet unpredictable evolution of the generated text.

### 4. Eigenvector Computation
For the "eigenvector" concept, the program generates a random covariance matrix and computes its eigenvectors using Eigen, incorporating these values directly into the output.

### 5. Poisson Process Modeling
The program uses Poisson distributions to model the frequency of dream visions, adding another layer of mathematical structure.

## Extending the Generator

You can add new concepts by extending the `describeConcept` function with additional mathematical or literary ideas:

```cpp
else if (concept == "your_new_concept") {
    ss << "description that incorporates " << (value > 0.5 ? "positive variant" : "alternative variant");
}
```

Don't forget to add your new concept to the `concepts` vector in both the `createTransitionMatrix` function and the `main` function.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
