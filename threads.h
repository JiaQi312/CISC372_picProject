#ifndef ___IMAGE
#define ___IMAGE
#include <stdint.h>
#include <pthread.h>

#define Index(x,y,width,bit,bpp) y*width*bpp+bpp*x+bit

typedef struct{
    uint8_t* data;
    int width;
    int height;
    int bpp;
} Image;

enum KernelTypes{EDGE=0,SHARPEN=1,BLUR=2,GAUSE_BLUR=3,EMBOSS=4,IDENTITY=5};

typedef double Matrix[3][3];

// holds all the arguments needed to perform image operations
struct image_args {
    int row;
    Image* srcImage;
    Image* dstImage;
    Matrix algorithm;
};

struct pthread_info {
    pthread_t thread_id;
    struct image_args thread_args;
};

void* getPixelValue(void* args);
void convolute(Image* srcImage,Image* destImage,Matrix algorithm);
int Usage();
enum KernelTypes GetKernelType(char* type);

#endif