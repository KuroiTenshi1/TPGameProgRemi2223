//
// Created by DCHIQUET on 21/10/2022.
//


#include <iostream>
#include <vector>

// ObjectPool design pattern
// -------------------------
// The object pool design pattern is a creational design pattern that
// manages a set of objects that can be reused. It is used to reduce
// the cost of initializing and destroying objects by recycling them.


class Sound {
private:
    float frequence;
    float amplitude;
    float duration;
    bool inUse;

public:
    Sound() : frequence(0), amplitude(0), duration(0), inUse(false) {}

    void init(float frequence, float amplitude, float duration) {
        this->frequence = frequence;
        this->amplitude = amplitude;
        this->duration = duration;
        this->inUse = true;
    }

    void destroy() {
        this->inUse = false;
    }

    bool isInUse() const {
        return inUse;
    }

};

class SoundPool {
    Sound* pool[100];

    void create(float frequence, float amplitude) {
        for(int i = 0; i < 100; ++i) {
            if (!pool[i]->isInUse()) {
                pool[i]->init(frequence, amplitude, 1.0f);
                return;
            }
        }
    }

    void destroy(Sound* sound) {
        sound->destroy();
    }

    void render() {
        for(int i = 0; i < 100; ++i){
            if (pool[i]->isInUse()) {
                // render the sound
            }
        }
    }
};

int main()
{
    return 0;
}