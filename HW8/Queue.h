#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <vector>

#include "Event.h"

using namespace std;


class Queue : public priority_queue<int, vector<Event>, greater<Event>>
{
private:
};

#endif // !QUEUE_H
