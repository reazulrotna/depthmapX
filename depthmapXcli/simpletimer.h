// Copyright (C) 2017 Christian Sailer

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H
#include <chrono>

class SimpleTimer
{
public:
    SimpleTimer() : _startTime(std::chrono::high_resolution_clock::now())
    {
    }

    double getTimeInSeconds() const
    {
         auto t2 = std::chrono::high_resolution_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(t2-_startTime).count()) / 1000.0;
    }

    void reset()
    {
        _startTime = std::chrono::high_resolution_clock::now();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;
};

#endif // SIMPLETIMER_H
