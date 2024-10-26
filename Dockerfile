# Parent image from debian distribution
FROM debian:stable-slim

# Upgrade system and package manager
RUN apt-get update && apt-get upgrade

# Install tools for C++
RUN apt-get install -y cmake ninja-build build-essential

# Copy source code here
COPY . HelloWorldProject

# Create building directory
RUN mkdir HelloWorldProject/build

# Configure and build
RUN cd HelloWorldProject/build && cmake -G "Ninja" .. && ninja && ninja install

# Clean to keep the image small
RUN rm -rf HelloWorldProject && apt-get purge -y cmake ninja-build

# Tada
CMD HelloWorld