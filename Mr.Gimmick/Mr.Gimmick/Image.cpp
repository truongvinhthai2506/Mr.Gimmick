#include "Image.h"

Image::Image()
{
    
}

Image::Image(Dimension dimension, LPCWSTR filename)
{
    this->dimension = dimension;
    this->filename = filename;
}

Dimension Image::GetDimension()
{
    return this->dimension;
}

LPCWSTR Image::GetFilename()
{
    return this->filename;
}