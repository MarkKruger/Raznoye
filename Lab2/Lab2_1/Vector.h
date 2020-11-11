#pragma once
#include <stdlib.h>
class Vector
{
private:
    int array_length;
    float* vector_array;

public:
    Vector(int length) {
        vector_array = new float[length];
        array_length = length;
    }
    ~Vector() {
        free(vector_array);
    }

    int GetLength() {
        return array_length;
    }

    Vector & operator ++ () {
        for (int i = 0; i < array_length; i++) {
            vector_array[i]++;
        }
        return *this;
    }
    Vector operator ++ (int) {
        Vector temp_array(array_length);
        for (int i = 0; i < array_length; i++) {
            temp_array[i] = vector_array[i]++;
        }
        return temp_array;
    }

    Vector & operator -- () {
        for (int i = 0; i < array_length; i++) {
            vector_array[i]--;
        }
        return *this;
    }
    Vector operator -- (int) {
        Vector temp_array(array_length);
        for (int i = 0; i < array_length; i++) {
            temp_array[i] = vector_array[i]--;
        }
        return temp_array;
    }

    float & operator [] (int index) {
        return vector_array[index];
    }
};

