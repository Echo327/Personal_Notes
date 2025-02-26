// Disclaimer: This file's base was created by me, then fed to
// OpenAI's ChatGPT-4, February 2025
// to add new features, and debugged by me to make it work
// This was done for fun and personal purposes, to get used to AI prompting

#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <cstdio>
#include "point2line.hpp"
#include "draw.hpp"
using namespace std;

// Note: converts a Line (vector-based representation)
// into Point objects (point-based representation),
// which can then be drawn using DrawPoints()
struct LineToPointAdapter
{
    typedef std::vector<Point> Points;
    static std::map<size_t, Points> cache;
    
    Points& points;

    LineToPointAdapter(Line& line) : points(cache[reinterpret_cast<size_t>(&line)])
    {
        if (!points.empty()) return;

        int left = std::min(line.start.x, line.end.x);
        int right = std::max(line.start.x, line.end.x);
        int top = std::min(line.start.y, line.end.y);
        int bottom = std::max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = bottom - top;

        if (dx == 0) // Vertical line
        {
            for (int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{ left, y });
            }
        }
        else if (dy == 0) // Horizontal line
        {
            for (int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{ x, top });
            }
        }
    }
};

// Define the static cache
std::map<size_t, std::vector<Point>> LineToPointAdapter::cache;

int main()
{
    vector<shared_ptr<VectorRectangle>> vectorObjects {
        make_shared<VectorRectangle>(10, 10, 10, 5),
        make_shared<VectorRectangle>(20, 15, 20, 10)
    };

    vector<Point> allPoints; // Store all points before drawing

    for (auto& o : vectorObjects)
    {
        for (auto& l : o->lines) // Directly access lines
        {
            LineToPointAdapter lpo{ l };
            allPoints.insert(allPoints.end(), lpo.points.begin(), lpo.points.end());
        }
    }

    DrawPoints(allPoints); // Draw all accumulated points at once

    return 0;
}
