//
// Created by DCHIQUET on 21/10/2022.
//

#ifndef TPGAMEPROGREMI2223_IMAGE_H
#define TPGAMEPROGREMI2223_IMAGE_H

#include <vector>
#include <functional>

namespace Image {

    //struct pixel {
    //    unsigned char r;
    //    unsigned char g;
    //    unsigned char b;
    //};

// operator=
    //template<typename T>
    //pixel &operator=(pixel &p, T &t) {
    //    p.r = t.r;
    //    p.g = t.g;
    //    p.b = t.b;
    //    return p;
    //}

    using valueType = float;

    class Image {
    private:
        int m_width;
        int m_height;
        std::vector<valueType> m_pixels;
        //pixel *data;
    public:
        valueType& operator()(int i, int j){
            return m_pixels[i * m_width + j];
        }
        const valueType& operator()(int i, int j) const {
            return m_pixels[i * m_width + j];
        }

        Image(int width, int height) {
            this->m_width = width;
            this->m_height = height;
            //data = new pixel[width * height];
            m_pixels.resize(width * height);
            std::fill(m_pixels.begin(), m_pixels.end(), 0.0f);
        }

        const int& getWidth() const {
            return m_width;
        }
        const int& getHeight() const {
            return m_height;
        }

        //void clamp();

        //void brighten(int value){

        //}


    };




    class IImageProcessingAlgo{
    public:
        virtual Image compute(const Image& img) = 0;

    };

    class IImageProcessingAlgoNoNeiborhood : public IImageProcessingAlgo{
    public:
        virtual Image compute(const Image& src){
            Image dest(src.getWidth(), src.getHeight());
            for(int i = 0; i < src.getWidth(); ++i){
                for(int j = 0; j < src.getHeight(); ++j){
                    dest(i, j) = computeOnOnePixel(src(i, j));
                }
            }
        }

        virtual float computeOnOnePixel(const valueType& pixelValue) = 0;

    };

    class Clamp : public IImageProcessingAlgoNoNeiborhood{
    public:
        Clamp(const valueType min, valueType max) : m_min(min), m_max(max) {}
        virtual float computeOnOnePixel(const valueType& pixelValue) override {
            return std::clamp(pixelValue, m_min, m_max);
        }

        const valueType m_min;
        valueType m_max;
    };

}


#endif //TPGAMEPROGREMI2223_IMAGE_H
