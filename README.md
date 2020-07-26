# Random pattern animations using Monte Carlo simulations

## Running instructions

### Dependencies

1. Bash

2. g++

3. GNUPlot

4. convert (imagemagick)

### How to run

1. On a terminal, run the command `bash autoplot.sh`, and wait till `animation.gif` gets generated.

2. To fine tune the speed and quality, consider running `bash autoplot.sh a b` where a = 1 for high quality and 2 for low quality, and b = 1 for a fast animation and 2 for a slow animation.

## About

This project arose from the study of the following problem:

Given a hexagon H, and a random point P inside H, we repeat the following steps a large number of times:
    
    Step 1. Choose a random side AB of H

    Step 2. Find a certain triangle center K of PAB, and replace P by K

Here K is chosen to be a weighted average of the vectors P, A and B, with the weights being symmetric functions of the sides of PAB.

Which regions can P lie in, and which regions can it not occupy (with a high probability)?

In this simulation, the weights were chosen to be proportional to appropriate powers of the opposite sides, with the exponents ranging from 0.35 to 0.60, with an animation demonstrating the shifting of the high-probability loci of the points P with the exponent changing in steps of 0.02 (or 0.01, based on the command-line arguments passed to the script).
