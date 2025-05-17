#include <cuda_runtime.h>
#include <stdio.h>
int main() {
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    printf("Found %d CUDA-capable device(s)\n", deviceCount);
    return 0;
}