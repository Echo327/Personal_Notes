// Disclaimer: This file's base was created by me, then fed to
// OpenAI's ChatGPT-4, February 2025
// to add new features, and debugged by ChatGPT itself
// This was done for fun and personal purposes, to get used to AI prompting

#pragma once
#include <vector>

struct Point
{
    int x, y;
};

struct Line
{
    Point start, end;
};

struct VectorRectangle
{
    std::vector<Line> lines;

    VectorRectangle(int x, int y, int width, int height)
    {
        lines.emplace_back(Line{ Point{ x, y }, Point{ x + width, y } });       // Top
        lines.emplace_back(Line{ Point{ x + width, y }, Point{ x + width, y + height } }); // Right
        lines.emplace_back(Line{ Point{ x + width, y + height }, Point{ x, y + height } }); // Bottom
        lines.emplace_back(Line{ Point{ x, y + height }, Point{ x, y } }); // Left
    }
};
