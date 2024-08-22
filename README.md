# IMDB Sentiment Analysis Optimization using HLS

This project involves implementing a sentiment analysis model using Artificial Neural Networks (ANN) and synthesizing it for hardware using Vivado HLS. The project focuses on converting a trained Keras model to a hardware description language and optimizing it for resource-efficient implementation.

## Project Overview

The sentiment analysis model used in this project is designed to analyze movie reviews from the Internet Movie Database (IMDB). The model, initially developed in Keras, was converted into C code using the Keras2c tool. The C code was then synthesized and optimized for hardware using Vivado HLS 2018.2.

### Key Features:
- **Neural Network Architecture**: 
  - **Input Layer**: 10,000 input nodes.
  - **Dense Layer 1**: 16 neurons.
  - **Dense Layer 2**: 16 neurons.
  - **Output Layer**: 1 neuron for binary classification.

- **Optimizations**:
  - **Memory Allocation**: Static memory allocation was used to replace dynamic allocation, ensuring compatibility with Vivado HLS.
  - **Function Modifications**: 
    - Replaced `memset` and `memcpy` with manual loop operations.
    - Introduced flags to control activation functions (ReLU, Sigmoid).
  - **Tensor Struct**: Converted the Keras tensor struct into separate variables for better synthesis.
  
- **HLS4ML Integration**:
  - Downgraded TensorFlow version from 2.16.0 to 2.14.0 to ensure compatibility with HLS4ML.
  - Applied fixed-point arithmetic (`ap_fixed<6,2>`) for hardware optimization.
  - Removed specific HLS pragmas like `ARRAY_RESHAPE` and `ARRAY_PARTITION` due to resource constraints.

## Architecture

The architecture of the neural network is simple yet effective for sentiment analysis tasks. The model includes:
- **Input Layer**: Accepts input vectors of size 10,000.
- **Dense Layers**: Two fully connected layers with 16 neurons each, followed by the output layer.
- **Output Layer**: Single neuron for binary classification, suitable for determining sentiment.

## Changes Made

### Memory and Function Changes:
- **Static Allocation**: Replaced dynamic memory allocation with static allocation.
- **Manual Initialization**: Used loops instead of `memset` and `memcpy`.
- **Static Arrays**: Changed dynamic arrays to static arrays to optimize performance.

### HLS4ML Compatibility:
- **TensorFlow Version**: Downgraded to 2.14.0 for compatibility with HLS4ML.
- **Model Configuration**: Precision set to `ap_fixed<6,2>`, optimization strategy focused on minimizing hardware resources.

### Removed Pragmas:
- **ARRAY_RESHAPE**: Removed due to bit width limitations.
- **ARRAY_PARTITION**: Removed due to resource constraints.
- **UNROLL**: Removed loop unrolling in several functions to stay within resource limits.

## Results

### Performance Metrics:
- **Latency and Area Overhead**: 
  - Comparison of baseline, optimized, and HLS4ML generated designs.
  - **LUT**: Reduced from 1,511,943 (HLS4ML) to 24,259 (Optimized).
  - **FF**: Reduced from 3,667,900 (HLS4ML) to 5,447 (Optimized).
  - **DSP**: Reduced to 13 in the optimized design.
  - **BRAM**: Reduced from 1,537 to 20 in the optimized design.

### Final Comparison:
The optimized manual design showed significant improvements in resource utilization compared to the HLS4ML generated design, demonstrating the effectiveness of manual optimization techniques.

## Issues and Solutions

- **Dependencies and Versioning**: Addressed by downgrading TensorFlow and configuring model details for HLS4ML compatibility.
- **Optimizations**: Detailed justifications for each pragma used or removed to balance performance and resource usage.

## Contributors

- Abhrajyoti Kundu (234101003)
- Gorachand Mondal (234101015)
- Nihalbhai Shaikh (234101032)
- Pratik Sisodiya (234101040)
- Sayan Pal (234101048)
