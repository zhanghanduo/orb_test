//
// Created by zh on 10/19/17.
//

#ifndef FEATURE_TEST_LIB_H
#define FEATURE_TEST_LIB_H

#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std::chrono;

namespace Time{

    class Timer
    {
    public:
        Timer()
        {
            tic();
        }
        double end()
        {
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            start = std::clock();
            return duration;
        }
        void tic()
        {
            start = std::clock();
        }
        void toc(std::string section = " ")
        {
            end();
            printf("%s T: %g FPS: %gHz \r\n", section.c_str(), duration, 1/duration);
        }
        void hz(std::string section = " ")
        {
            ++num;
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            if (duration >= 1.0)
            {
                printf("%s: %f Hz\n", section.c_str(), double(num)/duration);
                num = 0;
                tic();
            }
        }
    private:
        std::clock_t start;
        double duration;
        unsigned int num;
    };


    class CPPTimer
    {
    public:
        CPPTimer()
        {
            tic();
        }
        double end()
        {
            time_span = duration_cast<duration<double>> (high_resolution_clock::now() - start);
            tic();
            return time_span.count();
        }
        void tic()
        {
            start = high_resolution_clock::now();
        }
        void toc(std::string section = " ")
        {
            end();
            printf("%s T: %g FPS: %gHz \r\n", section.c_str(), time_span.count(), 1/(time_span.count()));
        }
        void hz(std::string section = " ")
        {
            ++num;
            time_span = duration_cast<duration<double>> (high_resolution_clock::now() - start);

            if (time_span.count() >= 1.0)
            {
                printf("%s: %f Hz\n", section.c_str(), double(num)/(time_span.count()));
                num = 0;
                tic();
            }
        }
    private:
        high_resolution_clock::time_point start;
        duration<double> time_span;
        unsigned int num;
    };

}


#endif //FEATURE_TEST_LIB_H
